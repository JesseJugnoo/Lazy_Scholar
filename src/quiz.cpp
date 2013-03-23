/*
 * quiz.cpp
 *
 *  Created on: 2013-02-27
 *      Author: William, Jesse, Wayne
 */

#include "quiz.hpp"
#include <bb/cascades/Application>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/AbstractPane>
#include <bb/cascades/Image>
#include <bb/ImageData>
using namespace bb::cascades;
using namespace bb::data;
quiz::quiz(QObject* parent) : QObject(parent) {
			sda = new SqlDataAccess(QDir::currentPath() + "/app/native/assets/test");
}

quiz::~quiz() {
	delete sda;
}

void quiz::loadTheQuestions(){ //execute the sql statement and use it
	QString sql = "Select * from Random ORDER BY RANDOM() LIMIT 4";


		QVariant result = sda->execute(sql);

		if (sda->hasError()){
			qDebug() << sda->error() << endl;
		}
		questions = result.value<QVariantList>();
}

QString quiz::setCorrect(){

	QVariantMap map;
	map = questions[0].toMap();

	return map.key("Correct");
}

