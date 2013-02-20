#include "LearnApp.hpp"

#include <bb/cascades/Application>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/AbstractPane>
#include <bb/cascades/ListView>
#include <bb/cascades/GroupDataModel>
#include <bb/data/JsonDataAccess>

#include <bb/cascades/Page>
#include <QSettings>


using namespace bb::cascades;

LearnApp::LearnApp()
{

    // We set up the application Organization and name, this is used by QSettings
    // when saving values to the persistent store.
    QCoreApplication::setOrganizationName("Lazy Scholar");
    QCoreApplication::setApplicationName("Learn App");

    // Then we load the application
    QmlDocument *qml = QmlDocument::create().load("main.qml");
    qml->setContextProperty("_learnApp", this);

    if (!qml->hasErrors()) {
        Page *appPage = qml->createRootNode<Page>();
        if (appPage) {
            Application::setScene(appPage);
        }
    }

}
//add a cover when the app is minimized
void LearnApp::addApplicationCover(){

}

LearnApp::~LearnApp(){

}
