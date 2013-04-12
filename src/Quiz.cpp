/*
 * Quiz.cpp
 *
 *  Created on: 2013-02-27
 *      Author: William, Jesse, Wayne
 */

#include "Quiz.hpp"
#include <bb/cascades/Application>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/AbstractPane>
#include <algorithm>
#include <vector>
using namespace bb::cascades;
using namespace bb::data;
using namespace std;
Quiz::Quiz(QObject* parent):QObject(parent) {
	//sda = new SqlDataAccess(QDir::currentPath() + "/app/native/assets/lazy_scholar.sqlite");
	numQuestions = 0;
	numCorrect = 0;
	numWrong = 0;
here1 = false;

}

Quiz::~Quiz() {
	delete sda;
}

void Quiz::loadTheQuestions() { //execute the sql statement and use it

	if(sda == NULL){delete sda;}

	sda = new SqlDataAccess(QDir::currentPath() + "/app/native/assets/lazy_scholar.sqlite");
	//This is to get the queries for the guesses
	QString sql = "Select Guess from Random ORDER BY RANDOM() LIMIT 3";
	QVariant result = sda->execute(sql);
	if (sda->hasError()) {
			qDebug() << sda->error() << endl;
		}
	 guessesSQL = result.value<QVariantList>();

	 //This is to get the query for the Correct word
	QString sqlCorrect = "Select Word,Correct from Words ORDER BY RANDOM() LIMIT 1";
	 result = sda->execute(sqlCorrect);
	if (sda->hasError()) {
			qDebug() << sda->error() << endl;
		}
	correctSQL = result.value<QVariantList>();

	QVariantMap mapCorrect = correctSQL[0].toMap();

	QString temp;
	correct = mapCorrect["Correct"].toString(); //set the "correct" variable to the correct translation

	mapCorrect = correctSQL[0].toMap(); //this is to get the chinese translation to be guessed
	toBeAnswered = mapCorrect["Word"].toString();

	//int randNum = rand()%4; //create a random number for 0-3
	 QVariantMap mapGuesses; //transform the Qvariant to a map, so that we can access it
	 QString theChoices[] = {"", "","",""};
vector<QString> theWords;
	 mapGuesses = guessesSQL[0].toMap();
	 //theGuesses[0] = mapGuesses["Guess"].toString();
	 theWords.push_back(mapGuesses["Guess"].toString());

	 mapGuesses = guessesSQL[1].toMap();
	// theGuesses[1] = mapGuesses["Guess"].toString();
	 theWords.push_back(mapGuesses["Guess"].toString());

	 mapGuesses = guessesSQL[2].toMap();
	// theGuesses[2] = mapGuesses["Guess"].toString();
	 theWords.push_back(mapGuesses["Guess"].toString());

	 //theGuesses[3] = correct;
	 theWords.push_back(correct);

	 int randNum = rand() %4;
	 int counter = 0;
	 vector<int> v; //to check if we used that element

	 while(counter <4){

		 if(find(v.begin(), v.end(), randNum) != v.end()){
			 //Element is in vector
			 //choose another random
			 randNum = rand()%4;
		 }
		 else {
			 theChoices[randNum] = theWords.back();
			 theWords.pop_back();
			 v.push_back(randNum);
			 randNum = rand()%4;

			 counter++;
		 }
	 }


	 guess1 = theChoices[0];

	 guess2 = theChoices[1];

	 guess3 = theChoices[2];

	 guess4 = theChoices[3];

	 numQuestions++; //everytime we load a new question, add to the total number of questions

	 emit valueChanged();
}

QString Quiz::getCorrect() {

	return correct;
}
QString Quiz::getGuess1(){

	return guess1;

}
QString Quiz::getGuess2(){

	return guess2;

}
QString Quiz::getGuess3(){

	return guess3;

}
QString Quiz::getGuess4(){

	return guess4;
}
QString Quiz::getToBeAnswered(){

	return toBeAnswered;

}
int Quiz::getTotal(){

	return numQuestions;

}
void Quiz::correctCounter(){
	emit valueChanged();
	numCorrect++;

}
void Quiz::incorrectCounter(){
	emit valueChanged();
	numWrong++;

}
int Quiz::getCorrectCounter(){

	return numCorrect;

}
int Quiz::getIncorrectCounter(){

	return numWrong;

}
void Quiz::reset(){

		numQuestions = 0;
		numCorrect = 0;
		numWrong = 0;
		here1 = false;
		emit valueChanged();
}
void Quiz::loadToDatabase(){

	QVariant tmp(numCorrect);
	QVariant tmp2(numWrong);
		QString numberCorrect = tmp.toString();
		QString numberWrong = tmp2.toString();

		QString sql = "INSERT INTO Quiz (Correct, Wrong, Level) VALUES (" + numberCorrect +", " + numberWrong + " , 1);";
		QVariant result = sda->execute(sql);
		if (sda->hasError()) {
				qDebug() << sda->error() << endl;
			}
		qDebug() << sql <<endl;
		emit valueChanged();
}
void Quiz::changeHere(bool a){
	here1 = a;
	emit valueChanged();
}

bool Quiz::getHere(){
	return here1;
}


