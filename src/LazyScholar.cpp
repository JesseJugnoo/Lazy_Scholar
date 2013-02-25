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
	strokes = 1;

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
	            		/*;
	            //-- find cascades component of type ListView with an objectName property set to the value 'listView'
	            ListView *list_view = root->findChild<ListView*>("listView");
	            //-- assign data model object (m) to its GUI representation object (list_view)
	            if(list_view) list_view->setDataModel(m);
//				*/
	        }

	    }


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


void LazyScholar::initDrawPage(){
	resetImage();
	int size = lst.size();
	setCharacterByIndex(rand() % size);
}




//Drawing Component

void LazyScholar::setCharacterByIndex(int selectedIndex){
	QVariantMap map =  lst[selectedIndex].toMap();

	m_translate = map.value("text").toString();
	emit translateChanged();

	m_text_image = Image(QUrl(map.value("image").toString()));
	emit textImageChanged();

	maxStrokes = map["strokes"].toInt();


}

void LazyScholar::resetImage(){
	q_image = Paint::initImageBorder(workingImageSize);

	//q_image = Paint::drawFont(workingImageSize, "A", "English");
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
}



