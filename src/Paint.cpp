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
#include "sql/DictionaryDAO.hpp"
#include "sql/DictionaryVO.hpp"

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
Paint::Paint(QObject *parent) :
		QObject(parent), m_language("Chinese") {
	//-- load JSON data from file to QVariant

	soundMng = new SoundManager("sounds/");

	  /* initialize random seed: */
	  srand (time(NULL));

		timer2.start();

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
void Paint::setLanguage(QVariant language) {
	m_language = language.toString();
}

void Paint::initDrawPage(QVariant level) {

	DictionaryDAO dictDAO;
	dictVOs = dictDAO.getDictionaryByLanguageAndLevelVO(m_language, level.toString());


	int size = dictVOs.size();
	if (size != 0){
		setCharacterByIndex(rand() % size);
	}
}

//Drawing Component

void Paint::setCharacterByIndex(int selectedIndex) {
	DictionaryVO dict = dictVOs[selectedIndex];

	QString pronun = " (" + dict.getPronunciation() + ")";
	m_translate = dict.getTranslate() + pronun;
	maxStrokes = dict.getStrokes();



	QString srcLocation = dict.getImage();
	QImage srcImage(QString::fromLatin1("app/native/assets/images/%1").arg(srcLocation));
	srcImage.invertPixels();

	bb::ImageData imageData = bb::ImageData::fromPixels(srcImage.bits(),
			bb::PixelFormat::RGBA_Premultiplied, srcImage.width(),
			srcImage.height(), srcImage.bytesPerLine());

	m_text_image = Image(imageData);

	emit translateChanged();
	emit textImageChanged();


	//reset stuff
	resetImage();
	//stroke start at maxStroke + 1 to automatically resets itself
	strokes = maxStrokes + 1;

	//reset rating system
	m_rating = Image();
	emit ratingChanged();
	//reset timer
	timer = clock();

	index = selectedIndex;

}

void Paint::navigateNextCharacter(int addIndex){
	if (dictVOs.size()){
		index = (index + addIndex + dictVOs.size()) % dictVOs.size();
		setCharacterByIndex(index);
	}
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


void Paint::paintImage() {
	//reset image if there are more strokes
	if (strokes > maxStrokes) {
		resetImage();
		timer = clock();
	}

	paintImage(q_image, lastPoint, endPoint);
	bb::ImageData imageData = bb::ImageData::fromPixels(q_image.bits(),
			bb::PixelFormat::RGBA_Premultiplied, q_image.width(),
			q_image.height(), q_image.bytesPerLine());
	m_image = bb::cascades::Image(imageData);
	lastPoint = endPoint;
	emit imageChanged();
}

void Paint::startDraw(float x, float y) {
	lastPoint = QPoint(x, y);
}

void Paint::draw(float x, float y) {
	endPoint = QPoint(x, y);
	paintImage();
}

bool Paint::finishDraw() {

	bool check_result = false;

	strokes++;
	if (strokes > maxStrokes) {
		QString srcLocation = dictVOs[index].getImage();
		QImage srcImage(QString::fromLatin1("app/native/assets/images/%1").arg(srcLocation));
		//show accuracy rating
		double result = HandRecog::compareDrawnImageByImage(q_image, srcImage);

		qDebug() << "Result of compare: " << result;

		//calculate the time rate
		float time_elapsed = ((float)(clock() - timer)) / CLOCKS_PER_SEC;

		double SEC_PER_STROKE = 1.75; 	//constant of the second it took to draw 1 stroke

		double time_rate = SEC_PER_STROKE * maxStrokes / time_elapsed;

		//multiply the accuracy rate and time rate to get the resulting rate
		result = result * time_rate;


		setRating(result);

		check_result = true;

	}
	return check_result;
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
		soundFile = "BUZZER.wav";
	}

	bool result = soundMng->play(soundFile, 2.0f, 2.0f);
	qDebug() << result;
	emit ratingChanged();

}

