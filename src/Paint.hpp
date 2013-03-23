/* Copyright (c) 2012 Stuart MacMartin.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

//FROM SCRATCHPATH sample code
#ifndef PAINT_HPP
#define PAINT_HPP

class QImage;
#include <QObject>
#include <bb/cascades/Image>
#include <bb/data/JsonDataAccess>
#include <bb/cascades/GroupDataModel>
#include "soundmanager.h"
#include "sql/DictionaryVO.hpp"

#include <ctime> //for time
#include <time.h>

class Paint: public QObject {
Q_OBJECT

// The rendered image
Q_PROPERTY(bb::cascades::Image image READ image NOTIFY imageChanged)


// The English meaning and the translation
Q_PROPERTY(QString translation READ translation  NOTIFY translateChanged)

// The rendered text outline image
Q_PROPERTY(bb::cascades::Image textImage READ textImage NOTIFY textImageChanged)

// The rating image to be shown as feedback
Q_PROPERTY(bb::cascades::Image rating READ rating NOTIFY ratingChanged)




public:
	Paint(QObject *parent = 0);
	virtual ~Paint();

	//Language component
	Q_INVOKABLE
	void setLanguage(QVariant language);


	//The drawing component
	//The function to draw the lines made from the hand tracing
	void paintImage();

	Q_INVOKABLE
	//Set the last point(which is also the start point) of the drawing component when drawing for the first time
	void startDraw(float x, float y);

	Q_INVOKABLE
	//Set the end point of the drawing component
	void draw(float x, float y);

	Q_INVOKABLE
	//initialize the drawing page
	void initDrawPage(QVariant level);



	Q_INVOKABLE
	//updating the number of strokes when drawing is done. Will also provide the feedback if there are enough strokes to finish a character
	//returns true if it receives the result from the hand recog, false otherwise
	bool finishDraw();

	Q_INVOKABLE
	//changing the character to draw by index
	void setCharacterByIndex(int selectedIndex);

	Q_INVOKABLE
	//navigate to next character
	void navigateNextCharacter(int addIndex);

Q_SIGNALS:
	// The change notification signals for the properties
	void imageChanged();
	void translateChanged();
	void textImageChanged();
	void ratingChanged();


private:

	// The accessor methods for the properties
	bb::cascades::Image image() const;
	bb::cascades::Image textImage() const;
	bb::cascades::Image rating() const;
	QString translation() const;

	void resetImage();
	void setRating(double rating);

	QImage initImageBorder(const QSize &size);
	void paintImage(QImage &image, QPoint lastPoint, QPoint endPoint);



private:
	//The specific language to practice
	QString m_language;
	//The translation of the character
	QString m_translate;

	//parts of the drawing component
	bb::cascades::Image m_image;   //the hand free drawing
	QImage q_image;	   //the QImage version of m_image
	//the points that is used to draw a line within the hand free drawing
	QPoint lastPoint;
	QPoint endPoint;
	//the number of strokes to complete a character
	int strokes;
	int maxStrokes;
	clock_t timer; //timer
	QTimer timer2;

	bb::cascades::Image m_text_image; //the outline of the character to draw
	bb::cascades::Image m_rating;  //the feedback of the drawing

	//the list of characters and their information
	vector<DictionaryVO> dictVOs;
	vector<DictionaryVO> tmp;
	int index;

	//The soundmanager, taken from one of the sample code
	SoundManager *soundMng;

};






#endif
