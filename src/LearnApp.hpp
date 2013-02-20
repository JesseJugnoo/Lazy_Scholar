#ifndef APP_H
#define APP_H

#include <QObject>

/*!
 * @brief Application GUI object
 */
class LearnApp : public QObject
{
    Q_OBJECT
public:
    LearnApp();
    ~LearnApp();
private:

    /**
     * Function used to create and set the SceneCover of the application,
     * the cover is shown when the app is running in minimized mode.
     */
    void addApplicationCover();
};


#endif // ifndef APP_H
