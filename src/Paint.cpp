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

    const int w = size.width();
    const int h = size.height();

    // Draw the image with border!
    QPainter painter(&image);
    QPen pen(Qt::black, 5, Qt::SolidLine);
    painter.setPen(pen);
    painter.drawRect(5,5, w-10, h-10);
    return image;
}
//! [1]


void Paint::paintImage(QImage &image, QPoint lastPoint, QPoint endPoint){

    // Draw a line on the image
    QPainter painter(&image);
    QPen pen(Qt::black, 6, Qt::SolidLine);
    painter.setPen(pen);
    painter.setBrush(QBrush("000000"));
    painter.drawLine(lastPoint, endPoint);
}

