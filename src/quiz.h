/*
 * quiz.h
 *
 *  Created on: 2013-02-27
 *      Author:
 */

#ifndef QUIZ_H_
#define QUIZ_H_

#include <bb/cascades/GroupDataModel>
#include <bb/data/SqlConnection>

using namespace bb::data;

namespace bb
{
    namespace data
    {
        class SqlConnection;
    }
}
class quiz {

public:
	quiz();
	virtual ~quiz();

    /**
     * The constructor is similar to the GroupDataModel constructor but in addition
     * it has a connectionName parameter used for setting up a unique SQL connection.
     *
     * @param keys Value to set on GroupDataModel::sortingKeys.
     * @param connectionName The name of the connection to the SQL database.
     * @param parent The data model owner or @c 0. Optional parameter; defaults to @c 0, if not specified.
     */
    quiz(const QStringList &keys, const QString& connectionName,
            QObject *parent = 0);

    /**
     * This function loads all items in the database where favorite=true to the model.
     */
    void loadFavoriteCities();

    /**
     * This function sets a new continent based on the parameter passed.
     *
     * @param continent A QString of the name of the new continent
     */
    void setContinent(QString continent);

    QString continent();

};

#endif /* QUIZ_H_ */
