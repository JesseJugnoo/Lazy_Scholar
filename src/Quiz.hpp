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

	//This is to return guess4's assigned value
		Q_INVOKABLE
		QString getToBeAnswered();

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

    	//This is to keep track of the correct wor, it will always be updated when we load new questions
    	QString correct;

    	//The word/character to be translated
    	QString toBeAnswered;
};

#endif /* QUIZ_HPP_ */
