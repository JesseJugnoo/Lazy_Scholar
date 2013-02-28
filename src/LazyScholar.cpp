// Default empty project template
#include "LazyScholar.hpp"
#include "Paint.hpp"

#include <bb/cascades/Application>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/AbstractPane>
#include <bb/cascades/Image>
#include <bb/ImageData>
using namespace bb::cascades;
using namespace bb::data;

namespace {
QSize workingImageSize(700, 700);
}

LazyScholar::LazyScholar(bb::cascades::Application *app) :
		QObject(app){
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
	{
	        //-- load JSON data from file to QVariant

		JsonDataAccess jda;
	        lst = jda.load("app/native/assets/models/chinese_data.json").toList();
	        if (jda.hasError()) {
	            DataAccessError error = jda.error();
	            qDebug() << "JSON loading error: " << error.errorType() << ": " << error.errorMessage();
	        }
	        else {
	            qDebug() << "JSON data loaded OK!";

	            GroupDataModel *m = new GroupDataModel(this);
	            m->setParent(this);
	            //-- insert the JSON data to model
	            m->insertList(lst);
	            //-- make the model flat
	            m->setGrouping(ItemGrouping::None);
	        }

	    }

	soundMng = new SoundManager("sounds/");
}

LazyScholar::~LazyScholar(){
	delete soundMng;
}
QString LazyScholar::translation() const{
	return m_translate;
}

bb::cascades::Image LazyScholar::image() const {
	return m_image;
}

bb::cascades::Image LazyScholar::textImage() const {
	return m_text_image;
}
bb::cascades::Image LazyScholar::rating() const {
	return m_rating;
}

//Language Component
void LazyScholar::setLanguage(QString language){
	m_language = language;
}


void LazyScholar::initDrawPage(){
	int size = lst.size();
	setCharacterByIndex( rand() % size);
	resetImage();

	//reset rating system
	m_rating = Image();
	emit ratingChanged();
}




//Drawing Component

void LazyScholar::setCharacterByIndex(int selectedIndex){
	QVariantMap map =  lst[selectedIndex].toMap();

	m_translate = map["text"].toString();
	emit translateChanged();

	m_text_image = Image(QUrl(map["outline"].toString()));
	emit textImageChanged();

	maxStrokes = map["strokes"].toInt();

	index = selectedIndex;


}

void LazyScholar::resetImage(){
	q_image = Paint::initImageBorder(workingImageSize);

    bb::ImageData imageData = bb::ImageData::fromPixels(q_image.bits(), bb::PixelFormat::RGBA_Premultiplied, q_image.width(), q_image.height(), q_image.bytesPerLine());

    m_image = bb::cascades::Image(imageData);

	strokes = 1;
	emit imageChanged();

}


void LazyScholar::paintImage(){
	//reset image if there are more strokes
	if (strokes > maxStrokes){
		resetImage();
	}

	Paint::paintImage(q_image, lastPoint, endPoint);
    bb::ImageData imageData = bb::ImageData::fromPixels(q_image.bits(), bb::PixelFormat::RGBA_Premultiplied, q_image.width(), q_image.height(), q_image.bytesPerLine());
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
	if (strokes > maxStrokes){
		QString srcLocation = lst[index].toMap().value("image").toString();
		QImage srcImage(QString::fromLatin1("app/native/%1").arg(srcLocation));
		//show accuracy rating
		double result = Paint::compareDrawnImageByImage(q_image, srcImage);

        qDebug() << "Result of compare: " << result;
        setRating(result);
	}
}

//Feedback system
void LazyScholar::setRating(double rate){
	QString soundFile = "";
	if (rate > .75){
		m_rating = Image(QUrl("assets/images/rating/green.png"));
		soundFile = "ding.wav";
	}else if (rate > .3){
		m_rating = Image(QUrl("assets/images/rating/yellow.png"));
		soundFile = "average.wav";
	}else{
		m_rating = Image(QUrl("assets/images/rating/red.png"));
		soundFile = "fail.wav";
	}

	bool result = soundMng->play(soundFile, 2.0f, 2.0f);
	qDebug() << result;
	emit ratingChanged();


}



