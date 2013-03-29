#include "ProgressReport.hpp"
#include <bb/cascades/Application>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/AbstractPane>

using namespace bb::cascades;
using namespace bb::data;

ProgressReport::ProgressReport(QObject* parent):QObject(parent) {
	sda = new SqlDataAccess(QDir::currentPath() + "/app/native/assets/lazy_scholar.sqlite");
	Str_Total_Quiz_Taken = "Not initialized";
}

ProgressReport::~ProgressReport() {
	delete sda;
}

QString ProgressReport::loadTotalQuizTaken() {
	QString sql = "Select COUNT(*) AS SUM from Quiz LIMIT 4";

	QVariant temp = sda->execute(sql);
	if (sda->hasError()) {
		qDebug() << sda->error() << endl;
	}
	Total_Quiz_Taken = temp.value<QVariantList>();

	QVariantMap map;

	map = Total_Quiz_Taken[0].toMap();

	QString ret;

	ret = map["SUM"].toString();

	qDebug("lol2.....");

	return ret;
}

QString ProgressReport::getTotal_Quiz_Taken(){
	return Str_Total_Quiz_Taken;
}
void ProgressReport::updateTotal_Quiz_Taken(){
	Str_Total_Quiz_Taken = loadTotalQuizTaken();
	qDebug("lol.....");
	emit valueChanged();
}
