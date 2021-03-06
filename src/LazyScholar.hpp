// Default empty project template
#ifndef LazyScholar_HPP_
#define LazyScholar_HPP_

#include <QObject>
#include <bb/cascades/Image>
#include <bb/data/JsonDataAccess>
#include <bb/cascades/GroupDataModel>
#include "soundmanager.h"

namespace bb {
namespace cascades {
class Application;
}
}

/*!
 * @brief Application pane object
 *
 *Use this object to create and init app UI, to create context objects, to register the new meta types etc.
 */
class LazyScholar: public QObject {
Q_OBJECT


public:
	LazyScholar(bb::cascades::Application *app);
	virtual ~LazyScholar();

};

#endif /* LazyScholar_HPP_ */
