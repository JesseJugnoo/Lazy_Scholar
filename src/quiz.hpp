/*
 * quiz.h
 *
 *  Created on: 2013-02-27
 *      Author:
 */

#ifndef QUIZ_H_
#define QUIZ_H_
#include <bb/data/SqlDataAccess>
#include <bb/cascades/GroupDataModel>
#include <bb/data/SqlConnection>
#include <QObject>

using namespace bb::data;

namespace bb
{
    namespace data
    {
        class SqlConnection;
    }
}
class quiz: public QObject {
	Q_OBJECT
private:
    	QVariantList questions;
    	SqlDataAccess *sda;
public:

    quiz(QObject *parent = 0);
    virtual ~quiz();
	Q_INVOKABLE
    /**
     * This function loads all items in the database where favorite=true to the model.
     */
    void loadTheQuestions();

	Q_INVOKABLE
	/**
     * This function sets a new continent based on the parameter passed.
     *
     * @param continent A QString of the name of the new continent
     */
    QString setCorrect();


};

#endif /* QUIZ_H_ */
