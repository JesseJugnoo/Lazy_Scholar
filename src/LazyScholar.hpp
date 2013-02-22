// Default empty project template
#ifndef LazyScholar_HPP_
#define LazyScholar_HPP_

#include <QObject>
#include <bb/cascades/Image>

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

	// The object that should be painted (either file name of 'circle' or 'square')
Q_PROPERTY(QString object READ object WRITE setObject NOTIFY objectChanged)

// The rendered image
Q_PROPERTY(bb::cascades::Image image READ image NOTIFY imageChanged)




public:
	LazyScholar(bb::cascades::Application *app);
	virtual ~LazyScholar() {
	}

	//The drawing component
	Q_INVOKABLE
	//The cascade part calls this function to draw the lines made from the hand tracing
	void paintImage();

	Q_INVOKABLE
	void setLastPoint(float x, float y);

	Q_INVOKABLE
	void setEndPoint(float x, float y);

	//static function for printing debug statements
	static void printMessage(const char* msg){
        fprintf(stdout, "%s\n", msg);
        fflush(stdout);
	}


Q_SIGNALS:
	// The change notification signals for the properties
	void objectChanged();
	void imageChanged();

private:

	// The accessor methods for the properties
	void setObject(const QString &object);
	QString object() const;


	bb::cascades::Image image() const;

	// A helper method that is called whenever an input parameter has changed
	void updateImage();

	// A helper method to calculate the size of a single replicant image
	QSize desiredReplicantSize() const;

private:
	QString m_object;

	//parts of the drawing component
	bb::cascades::Image m_image;
	QImage q_image;
	QPoint lastPoint;
	QPoint endPoint;

};

#endif /* LazyScholar_HPP_ */
