// Default empty project template
#include "LazyScholar.hpp"
#include "Paint.hpp"
#include "Quiz.hpp"
#include <bb/cascades/Application>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/AbstractPane>
#include <bb/cascades/Image>
#include <bb/ImageData>
using namespace bb::cascades;
using namespace bb::data;


LazyScholar::LazyScholar(bb::cascades::Application *app) :
		QObject(app){


    // Registration of the CustomControl which will show the current speed and
    // the WordChecker object that is used for checking if the entered text is
    // correct or not. qmlRegisterType will make the objects recongnizable by the
    // QML parsing engine.
    qmlRegisterType < Paint > ("com.paint", 1, 0, "Paint");

	// create scene document from main.qml asset
	// set parent to created document to ensure it exists for the whole application lifetime
	QmlDocument *qml = QmlDocument::create("asset:///main.qml").parent(this);


	Quiz *question = new Quiz(); //the object quiz, to control all of the quiz component stuff
	question->loadTheQuestions();
	// Set the context property we want to use from inside the QML file. Functions exposed
	// via Q_INVOKABLE will be found with the property and the name of the function.
	qml->setContextProperty("learn", this);
	qml->setContextProperty("_quiz", question);


	// create root object for the UI
	AbstractPane *root = qml->createRootObject<AbstractPane>();
	// set created root object as a scene
	app->setScene(root);
}

LazyScholar::~LazyScholar(){
}
