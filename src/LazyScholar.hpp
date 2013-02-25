// Default empty project template
#ifndef LazyScholar_HPP_
#define LazyScholar_HPP_

#include <QObject>
#include <bb/cascades/Image>
#include <bb/data/JsonDataAccess>
#include <bb/cascades/GroupDataModel>

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

// The rendered text image
Q_PROPERTY(bb::cascades::Image textImage READ textImage NOTIFY textImageChanged)




public:
	LazyScholar(bb::cascades::Application *app);
	virtual ~LazyScholar() {
	}

	//Language component
	Q_INVOKABLE
	void setLanguage(QString language);


	//The drawing component
	Q_INVOKABLE
	//The cascade part calls this function to draw the lines made from the hand tracing
	void paintImage();

	Q_INVOKABLE
	void setLastPoint(float x, float y);

	Q_INVOKABLE
	void setEndPoint(float x, float y);

	Q_INVOKABLE
	void initDrawPage();

	Q_INVOKABLE
	void updateStroke();

	Q_INVOKABLE
	void setCharacterByIndex(int selectedIndex);


	Q_INVOKABLE
	int getWidth();

	int getHeight();

Q_SIGNALS:
	// The change notification signals for the properties
	void imageChanged();
	void translateChanged();
	void textImageChanged();


private:

	// The accessor methods for the properties
	bb::cascades::Image image() const;
	bb::cascades::Image textImage() const;
	QString translation() const;

	void resetImage();


private:
	QString m_language;
	QString m_translate;

	//parts of the drawing component
	bb::cascades::Image m_image;
	bb::cascades::Image m_text_image;

	QImage q_image;
	QPoint lastPoint;
	QPoint endPoint;
	int strokes;
	int maxStrokes;
	//storing chinese chars in JSON format
	QVariantList lst;
	bb::cascades::GroupDataModel *m;
};

#endif /* LazyScholar_HPP_ */
