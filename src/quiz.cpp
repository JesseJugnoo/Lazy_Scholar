/*
 * quiz.cpp
 *
 *  Created on: 2013-02-27
 *      Author: William, Jesse, Wayne
 */

#include "quiz.h"
#include <bb/cascades/Application>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/AbstractPane>

//#include <bb/cascades/Image>
//#include <bb/ImageData>
using namespace bb::cascades;
using namespace bb::data;

quiz::quiz(QObject* parent):QObject(parent) {
	sda = new SqlDataAccess(QDir::currentPath() + "/app/native/assets/test");
	//sda = new SqlDataAccess("test");
	word = "hello";
}

quiz::~quiz() {
	delete sda;
}

void quiz::loadTheQuestions() { //execute the sql statement and use it
	//QString sql = "Select * from Random ORDER BY RANDOM() LIMIT 4";
	QString sql = "Select Guess from Random ORDER BY RANDOM() LIMIT 4";

	QVariant result = sda->execute(sql);
//questions = sda->execute(sql);
	if (sda->hasError()) {
		qDebug() << sda->error() << endl;
	}
	 questions = result.value<QVariantList>();
	//model = new GroupDataModel(QStringList() << "ID" << "Guess");
	//model->insertList(result.value<QVariantList>());
	//questions->insert(result.value<QVariantList>());
}

QString quiz::setCorrect() {
	QVariantMap map;

	map = questions[0].toMap();

	//return map.key("Correct");
	//GroupDataModel *model =  new GroupDataModel(QStringList() << "firstname" << "lastname");

	qDebug("asdas");

	QString fart;
	if(map.size() == 0){
		fart = "its zero";
	}
	if(map.size() < 0){
		fart = "its less";
	}
	if(map.size() > 0) {
		fart = "its more";
	}
	//QString blah = questions.size().toQString();
	return fart;
}
QString quiz::test(){
	//word = "You basterd son";
	return word;
	//return questions.size();
}
void quiz::test2(){
	word = "You basterd son";
	qDebug("hahaahahsfsadfsda were in test2");
	emit valueChanged();
}
//void quiz::nothing(){
//}

