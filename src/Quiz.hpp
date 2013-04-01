/*
 * Quiz.hpp
 *
 *  Created on: 2013-02-27
 *      Author:
 */

#ifndef QUIZ_HPP_
#define QUIZ_HPP_
#include <bb/data/SqlDataAccess>

#include <QObject>
using namespace bb::data;

class Quiz: public QObject {
	Q_OBJECT

	//These are the properties that are given to QML to let QML know how to "kind" of use it
	Q_PROPERTY(QString getGuess1 READ getGuess1 NOTIFY valueChanged)
	Q_PROPERTY(QString getGuess2 READ getGuess2 NOTIFY valueChanged )
	Q_PROPERTY(QString getGuess3 READ getGuess3 NOTIFY valueChanged )
	Q_PROPERTY(QString getGuess4 READ getGuess4 NOTIFY valueChanged )
	Q_PROPERTY(QString getCorrect READ getCorrect NOTIFY valueChanged)
	Q_PROPERTY(int getTotal READ getTotal NOTIFY valueChanged)
	Q_PROPERTY(int getCorrectCounter READ getCorrectCounter NOTIFY valueChanged)
	Q_PROPERTY(int getIncorrectCounter READ getIncorrectCounter NOTIFY valueChanged)

	Q_PROPERTY(bool getHere READ getHere WRITE changeHere NOTIFY valueChanged)


	Q_PROPERTY(QString getToBeAnswered READ getToBeAnswered NOTIFY valueChanged)

public:
    Quiz(QObject *parent = 0);

    virtual ~Quiz();

    //This is to reload the new questions
    Q_INVOKABLE
    	void loadTheQuestions();

    //This is to get the answer to the multiple question
	Q_INVOKABLE
		QString getCorrect();

	//This is to return guess1's assigned value
	Q_INVOKABLE
		QString getGuess1();

	//This is to return guess2's assigned value
	Q_INVOKABLE
		QString getGuess2();

	//This is to return guess3's assigned value
	Q_INVOKABLE
		QString getGuess3();

	//This is to return guess4's assigned value
	Q_INVOKABLE
		QString getGuess4();

	//This is to return the question to be answered assigned value
		Q_INVOKABLE
		QString getToBeAnswered();

	//This is to increase correctCounter assigned value
		Q_INVOKABLE
		void correctCounter();
	//This is to increase incorrectCounter assigned value
		Q_INVOKABLE
		void incorrectCounter();

	//This is to return the total number of questions
		Q_INVOKABLE
		int getCorrectCounter();

	//This is to return the total number of questions
		Q_INVOKABLE
		int getIncorrectCounter();

	//This is to return the total number of questions
		Q_INVOKABLE
		int getTotal();
	//This is reset the variables to start state!!!!
		Q_INVOKABLE
		void reset();
		Q_INVOKABLE
		void changeHere(bool a);
		Q_INVOKABLE
		bool getHere();

		Q_INVOKABLE
		void loadToDatabase();


	Q_SIGNALS:
		void valueChanged();

private:
    	//These are needed for the database access, sda -> to connect and execute the database, we store this into "questions" (QVariantList)
		QVariantList guessesSQL;
		QVariantList correctSQL;
    	SqlDataAccess *sda;

    	//These are the private members that will be used to assign the guess words from the table, with one of them being the correct one
    	QString guess1;
    	QString guess2;
    	QString guess3;
    	QString guess4;

    	bool here1;

    	int numQuestions;// keep track of how many questions were asked, were just making the user do only 10 questions.
    	int numCorrect; //keep track of how many questions were correct
    	int numWrong; //keep track of how many questions were wrong
    	//This is to keep track of the correct word, it will always be updated when we load new questions
    	QString correct;

    	//The word/character to be translated
    	QString toBeAnswered;
};

#endif /* QUIZ_HPP_ */
