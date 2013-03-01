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

#include <bb/cascades/Application>
#include <bb/cascades/QmlDocument>
#include <algorithm>


//Draw a font


QImage Paint::drawFont(const QSize &size, QString font, QString locale ){

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
QImage Paint::initImageBorder(const QSize &size)
{
    QImage image(size, QImage::Format_ARGB32);
    image.fill(qRgba(0,0,0,0));
    return image;
}
//! [1]


void Paint::paintImage(QImage &image, QPoint lastPoint, QPoint endPoint){

    // Draw a line on the image
    QPainter painter(&image);
    QPen pen(Qt::black, 15, Qt::SolidLine);
    painter.setPen(pen);
    painter.drawLine(lastPoint, endPoint);
}


double Paint::compareDrawnImageByImage(QImage drawnImage, QImage source){
	if (drawnImage.size() != source.size()){
		//resize source to the dimension of the drawnImage
		source = source.scaled(drawnImage.size());
	}


	double total = 0;
	double maxTotal = 1;

	for (int i = 1; i < drawnImage.width(); i++){

		for(int j = 1; j < drawnImage.height(); j++){

			QColor drawnPixel = QColor::fromRgba(drawnImage.pixel(i,j));
			QColor sourcePixel = QColor::fromRgba(source.pixel(i,j));

			//source is priority
			if (sourcePixel.alpha() != 0){
				maxTotal++;
				if (drawnPixel.alpha() != 0){
					total++;
				}
			}


			//drawnImage is priority
			if (drawnPixel.alpha() != 0){
				maxTotal++;
				if (sourcePixel.alpha() != 0){
					total++;
				}
			}



		}
	}
    double bumpUp = 1.5;
	return  total / maxTotal * bumpUp ;
}


