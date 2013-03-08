/* Copyright (c) 2012 Stuart MacMartin.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

//from scratchpad sample code
//TODO: this code doent
#include <Qt/qimage.h>
#include <Qt/qpainter.h>
#include "Paint.hpp"
#include "HandRecog.hpp";

#include <algorithm>

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
//Draw a font

QImage Paint::drawFont(const QSize &size, QString font, QString locale) {

	QImage image(size, QImage::Format_RGB32);
	image.fill(Qt::white);

	const int w = size.width();
	const int h = size.height();

	QPoint pt = QPoint(w / 2, h / 2);
	//QFont qfont;
	//qfont.setPixelSize(h);

	// Draw the image with border!
	QPainter painter(&image);
	QPen pen(Qt::black, 5, Qt::SolidLine);
	painter.setPen(pen);
	//painter.setFont(qfont);
	painter.drawText(pt, font);
	return image;

}

//! [0]

// Draw a rectangle in an image of the specified size.
// [1]
QImage Paint::initImageBorder(const QSize &size) {
	QImage image(size, QImage::Format_ARGB32);
	image.fill(qRgba(0, 0, 0, 0));
	return image;
}
//! [1]

void Paint::paintImage(QImage &image, QPoint lastPoint, QPoint endPoint) {

	// Draw a line on the image
	QPainter painter(&image);
	QPen pen(Qt::black, 15, Qt::SolidLine);
	painter.setPen(pen);
	painter.drawLine(lastPoint, endPoint);
}

Paint::Paint(QObject *parent) :
		QObject(parent) {
	//-- load JSON data from file to QVariant

	JsonDataAccess jda;
	lst = jda.load("app/native/assets/models/chinese_data.json").toList();
	if (jda.hasError()) {
		DataAccessError error = jda.error();
		qDebug() << "JSON loading error: " << error.errorType() << ": "
				<< error.errorMessage();
	} else {
		qDebug() << "JSON data loaded OK!";

		GroupDataModel *m = new GroupDataModel(this);
		m->setParent(this);
		//-- insert the JSON data to model
		m->insertList(lst);
		//-- make the model flat
		m->setGrouping(ItemGrouping::None);
	}

	soundMng = new SoundManager("sounds/");
}

Paint::~Paint() {
	delete soundMng;
}
QString Paint::translation() const {
	return m_translate;
}

bb::cascades::Image Paint::image() const {
	return m_image;
}

bb::cascades::Image Paint::textImage() const {
	return m_text_image;
}
bb::cascades::Image Paint::rating() const {
	return m_rating;
}

//Language Component
void Paint::setLanguage(QString language) {
	m_language = language;
}

void Paint::initDrawPage() {
	int size = lst.size();
	setCharacterByIndex(rand() % size);
	resetImage();

	//reset rating system
	m_rating = Image();
	emit ratingChanged();
}

//Drawing Component

void Paint::setCharacterByIndex(int selectedIndex) {
	QVariantMap map = lst[selectedIndex].toMap();

	m_translate = map["text"].toString();
	emit translateChanged();

	m_text_image = Image(QUrl(map["outline"].toString()));

	emit textImageChanged();

	maxStrokes = map["strokes"].toInt();

	index = selectedIndex;

}

void Paint::resetImage() {
	q_image = initImageBorder(workingImageSize);

	bb::ImageData imageData = bb::ImageData::fromPixels(q_image.bits(),
			bb::PixelFormat::RGBA_Premultiplied, q_image.width(),
			q_image.height(), q_image.bytesPerLine());

	m_image = bb::cascades::Image(imageData);

	strokes = 1;
	emit imageChanged();

}

void Paint::paintImage() {
	//reset image if there are more strokes
	if (strokes > maxStrokes) {
		resetImage();
	}

	paintImage(q_image, lastPoint, endPoint);
	bb::ImageData imageData = bb::ImageData::fromPixels(q_image.bits(),
			bb::PixelFormat::RGBA_Premultiplied, q_image.width(),
			q_image.height(), q_image.bytesPerLine());
	m_image = bb::cascades::Image(imageData);
	lastPoint = endPoint;
	emit imageChanged();
}

void Paint::setLastPoint(float x, float y) {
	lastPoint = QPoint(x, y);
}

void Paint::setEndPoint(float x, float y) {
	endPoint = QPoint(x, y);
}

void Paint::updateStroke() {
	strokes++;
	if (strokes > maxStrokes) {
		QString srcLocation = lst[index].toMap().value("image").toString();
		QImage srcImage(QString::fromLatin1("app/native/%1").arg(srcLocation));
		//show accuracy rating
		double result = HandRecog::compareDrawnImageByImage(q_image, srcImage);

		qDebug() << "Result of compare: " << result;
		setRating(result);
	}
}

//Feedback system
void Paint::setRating(double rate) {
	QString soundFile = "";
	if (rate > .75) {
		m_rating = Image(QUrl("assets/images/rating/green.png"));
		soundFile = "ding.wav";
	} else if (rate > .3) {
		m_rating = Image(QUrl("assets/images/rating/yellow.png"));
		soundFile = "average.wav";
	} else {
		m_rating = Image(QUrl("assets/images/rating/red.png"));
		soundFile = "fail.wav";
	}

	bool result = soundMng->play(soundFile, 2.0f, 2.0f);
	qDebug() << result;
	emit ratingChanged();

}

