// Default empty project template
#include "LazyScholar.hpp"
#include "Paint.hpp"

#include <bb/cascades/Application>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/AbstractPane>
#include <bb/cascades/Image>
#include <bb/ImageData>
using namespace bb::cascades;

namespace {
QSize workingImageSize(700, 700);
}

LazyScholar::LazyScholar(bb::cascades::Application *app) :
		QObject(app),  maxStrokes(4) {
	// create scene document from main.qml asset
	// set parent to created document to ensure it exists for the whole application lifetime
	QmlDocument *qml = QmlDocument::create("asset:///main.qml").parent(this);

	// Set the context property we want to use from inside the QML file. Functions exposed
	// via Q_INVOKABLE will be found with the property and the name of the function.
	qml->setContextProperty("learn", this);

	// create root object for the UI
	AbstractPane *root = qml->createRootObject<AbstractPane>();
	// set created root object as a scene
	app->setScene(root);
	strokes = 0;

}

//! [1]
void LazyScholar::setObject(const QString &object) {
	if (m_object == object)
		return;

	m_object = object;
	emit objectChanged();

}
//! [1]

QString LazyScholar::object() const {
	return m_object;
}

bb::cascades::Image LazyScholar::image() const {
	return m_image;
}

int LazyScholar::getWidth(){
	return workingImageSize.width();
}
int LazyScholar::getHeight(){
	return workingImageSize.height();
}


//Language Component
void LazyScholar::setLanguage(QString language){
	m_language = language;
}



//Drawing Component

void LazyScholar::resetImage(){
	q_image = Paint::initImageBorder(workingImageSize);

	//q_image = Paint::drawFont(workingImageSize, "A", "English");
    bb::ImageData imageData = bb::ImageData::fromPixels(q_image.bits(), bb::PixelFormat::RGBX, q_image.width(), q_image.height(), q_image.bytesPerLine());

    m_image = bb::cascades::Image(imageData);

	strokes = 0;
	emit imageChanged();
}


void LazyScholar::paintImage(){
	//reset image if there are more strokes
	if (strokes > maxStrokes){
		resetImage();
	}

	Paint::paintImage(q_image, lastPoint, endPoint);
    bb::ImageData imageData = bb::ImageData::fromPixels(q_image.bits(), bb::PixelFormat::RGBX, q_image.width(), q_image.height(), q_image.bytesPerLine());
    m_image = bb::cascades::Image(imageData);
	lastPoint = endPoint;
	emit imageChanged();
}


void LazyScholar::setLastPoint(float x, float y){
	lastPoint = QPoint(x,y);
}

void LazyScholar::setEndPoint(float x, float y){
	endPoint = QPoint(x,y);
}

void LazyScholar::updateStroke(){
	strokes++;
}



