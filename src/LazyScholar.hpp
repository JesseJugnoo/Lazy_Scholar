// Default empty project template
#ifndef LazyScholar_HPP_
#define LazyScholar_HPP_

#include <QObject>
#include <bb/cascades/Image>
#include <bb/data/JsonDataAccess>
#include <bb/cascades/GroupDataModel>
#include "soundmanager.h"

namespace bb {
namespace cascades {
class Application;
}
}

/*!
 * @brief Application pane object
 *
 *Use this object to create and init app UI, to create context objects, to register the new meta types etc.
 */
class LazyScholar: public QObject {
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
	LazyScholar(bb::cascades::Application *app);
	virtual ~LazyScholar();
	//Language component
	Q_INVOKABLE
	void setLanguage(QString language);


	//The drawing component
	Q_INVOKABLE
	//The cascade part calls this function to draw the lines made from the hand tracing
	void paintImage();

	Q_INVOKABLE
	//Set the last point(which is also the start point) of the drawing component when drawing for the first time
	void setLastPoint(float x, float y);

	Q_INVOKABLE
	//Set the end point of the drawing component
	void setEndPoint(float x, float y);

	Q_INVOKABLE
	//initialize the drawing page
	void initDrawPage();

	Q_INVOKABLE
	//updating the number of strokes when drawing is done. Will also provide the feedback if there are enough strokes to finish a character
	void updateStroke();

	Q_INVOKABLE
	//changing the character to draw by index
	void setCharacterByIndex(int selectedIndex);



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

	bb::cascades::Image m_text_image; //the outline of the character to draw
	bb::cascades::Image m_rating;  //the feedback of the drawing

	//the list of characters and their information
	QVariantList lst;
	int index;

	//The soundmanager, taken from one of the sample code
	SoundManager *soundMng;

};

#endif /* LazyScholar_HPP_ */
