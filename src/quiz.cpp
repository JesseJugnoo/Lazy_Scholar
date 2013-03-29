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

using namespace bb::cascades;
using namespace bb::data;

Quiz::Quiz(QObject* parent):QObject(parent) {
	sda = new SqlDataAccess(QDir::currentPath() + "/app/native/assets/test");
}

Quiz::~Quiz() {
	delete sda;
}

void Quiz::loadTheQuestions() { //execute the sql statement and use it

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

	int randNum = rand()%4; //create a random number for 0-3
	 QVariantMap mapGuesses; //transform the Qvariant to a map, so that we can access it
	 bool choice[]  ={false, false, false, false}; //this is used to so that we can randomly select spots for the guesses, so its not always the same
	 bool choseOne = false;
	 for(int i =0; i < guessesSQL.size(); i++){ //we go through the
		 mapGuesses = guessesSQL[i].toMap(); //transform the QVariant to a map, so that we can access it

		 while(!choseOne){ //Must choose a value to assign to
			 randNum = rand() %4;
			 switch(randNum){
			case 0:
				if(!choice[0]){guess1 = mapGuesses["Guess"].toString();choice[0] = true; choseOne = true;}
				break;
			case 1:
				if(!choice[1]){guess2 = mapGuesses["Guess"].toString();choice[1] = true;choseOne = true;}
				break;
			case 2:
				if(!choice[2]){guess3 = mapGuesses["Guess"].toString();choice[2] = true;choseOne = true;}
				break;
			default:
				if(!choice[3]){guess4 = mapGuesses["Guess"].toString();choice[3] = true;choseOne = true;}
				break;
			}


			 qDebug() <<"this is rand: "<< randNum << endl;
		 }

		 choseOne = false;
	 }

	 for(int i =0; i < 4; i++){
	 				 qDebug() << choice[i]<<endl;
	 			 }

	 for(int i =0; i < 4; i++) { //make sure to choose the "guess" variable with the correct choice
		 if(!choice[i]){
			  switch(i){
			case 0:
				guess1 = correct;
				break;
			case 1:
				guess2 = correct;
				break;
			case 2:
				guess3 = correct;
				break;
			default:
				guess4 = correct;
				break;
			}
			 break;
		 }
	 }
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


