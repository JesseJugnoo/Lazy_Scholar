#ifndef PROGRESSREPORT_HPP_
#define PROGRESSREPORT_HPP_

#include <bb/data/SqlDataAccess>
#include <QObject>
using namespace bb::data;

class ProgressReport: public QObject {
	Q_OBJECT

	//Q_PROPERTY(QString getTotal_Quiz_Taken READ getTotal_Quiz_Taken NOTIFY valueChanged)

public:
	ProgressReport(QObject *parent = 0);

	virtual ~ProgressReport();

	Q_INVOKABLE
	QString loadTotalQuizTaken();

	Q_INVOKABLE
	QString getTotal_Quiz_Taken();

	Q_INVOKABLE
	void updateTotal_Quiz_Taken();

	Q_SIGNALS:
		void valueChanged();

private:
		QVariantList Total_Quiz_Taken;
		SqlDataAccess *sda;
		QString Str_Total_Quiz_Taken;
};

#endif /* PROGRESSREPORT_HPP_ */
