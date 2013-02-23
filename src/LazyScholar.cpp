// Default empty project template
#include "LazyScholar.hpp"
//#include "Paint.hpp"

#include <bb/cascades/Application>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/AbstractPane>
#include <bb/cascades/Image>
#include <bb/ImageData>

using namespace bb::cascades;

namespace {
QSize workingImageSize(700, 500);
}

LazyScholar::LazyScholar(bb::cascades::Application *app) :
		QObject(app) {
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

}

//! [1]
void LazyScholar::setObject(const QString &object) {
	if (m_object == object)
		return;

	m_object = object;
	emit objectChanged();

	updateImage();
}
//! [1]

QString LazyScholar::object() const {
	return m_object;
}

bb::cascades::Image LazyScholar::image() const {
	return m_image;
}

/*
 * Return the size we need for the image that is to be replicated
 */
//! [4]
QSize LazyScholar::desiredReplicantSize() const {
	const int numPixelsX = workingImageSize.width();
	const int numPixelsY = workingImageSize.height();
	return QSize(numPixelsX, numPixelsY);
}
//! [4]
/*
 * Update the ImageView with the replicated stamps or images
 */
//! [5]
void LazyScholar::updateImage() {
	/*
	QImage replicant;

	if (m_object == QLatin1String("circle"))
		replicant = Paint::drawCircle(desiredReplicantSize());
	else if (m_object == QLatin1String("square"))
		replicant = Paint::drawSquare(desiredReplicantSize());
	else {
		// Load from file
		replicant.load(
				QString::fromLatin1("app/native/assets/%1").arg("images/picture.png"));
		replicant = replicant.scaled(desiredReplicantSize());
	}

	const bb::ImageData imageData = bb::ImageData::fromPixels(replicant.bits(),
			bb::PixelFormat::RGBX, replicant.width(), replicant.height(),
			replicant.bytesPerLine());
	*/

	//m_image = bb::cascades::Image(imageData);

	m_image = bb::cascades::Image(QUrl("asset:///images/picture.png"));

	emit imageChanged();
}
//! [5]

//Drawing Component


void LazyScholar::paintImage(){
	if (q_image.isNull()){
		q_image = QImage(workingImageSize, QImage::Format_RGB32);
		q_image.fill(Qt::white);
	}

    // Draw a line on the image
    QPainter painter(&q_image);
    painter.setPen(Qt::black);
    painter.drawLine(lastPoint, endPoint);

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



