/*
 * quiz.h
 *
 *  Created on: 2013-02-27
 *      Author:
 */

#ifndef QUIZ_H_
#define QUIZ_H_
#include <bb/data/SqlDataAccess>
//#include <QMetaType>
//#include <bb/data/SqlConnection>
#include <QObject>
using namespace bb::data;
//using namespace bb::cascades;
class quiz: public QObject {
	Q_OBJECT
	//Q_PROPERTY(QString setCorrect READ setCorrect)
	//Q_PROPERTY(Notify test2)
	Q_PROPERTY(QString test READ test NOTIFY valueChanged)
public:
    quiz(QObject *parent = 0);

    virtual ~quiz();

    Q_INVOKABLE
    void loadTheQuestions();

	Q_INVOKABLE
	QString setCorrect();

	Q_INVOKABLE
	QString test();

	Q_INVOKABLE
	void test2();

	Q_SIGNALS:
		void valueChanged();

private:
    	QVariantList questions;
    	SqlDataAccess *sda;
    	//GroupDataModel *model;
    	QString word;
};

#endif /* QUIZ_H_ */
