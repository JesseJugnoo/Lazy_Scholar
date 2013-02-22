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

//#include "Paint.hpp"

/*
 * Draw a circle in an image of the specified size.
 */
//! [0]
/*QImage Paint::drawCircle(const QSize &size)
{
    // Create an image of the appropriate size.
    // The underlying data is reference counted so is cleaned up as needed.
    QImage image(size, QImage::Format_RGB32);
    image.fill(Qt::blue);

    // Pick an arbitrary size for the circle
    const int centerX = size.width() / 2;
    const int centerY = size.height() / 2;
    const int radius = std::min(centerX, centerY) * 2 / 3;
    const int diameter = radius * 2;

    // Draw the circle!
    QPainter painter(&image);
    painter.setPen(Qt::yellow);
    painter.drawEllipse(centerX-radius, centerY-radius, diameter, diameter);

    return image;
}
//! [0]

 * Draw a rectangle in an image of the specified size.

é/! [1]
QImage Paint::drawSquare(const QSize &size)
{
    QImage image(size, QImage::Format_RGB32);
    image.fill(Qt::blue);

    // Pick an arbitrary size for the square
    const int centerX = size.width() / 2;
    const int centerY = size.height() / 2;
    const int w = size.width()  * 2 / 3;
    const int h = size.height() * 2 / 3;

    // Draw the square!
    QPainter painter(&image);
    painter.setPen(Qt::yellow);
    painter.drawRect(centerX - w/2, centerY - h/2, w, h);

    return image;
}
//! [1]


void Paint::paintImage(QImage &image, QPoint lastPoint, QPoint endPoint){

    // Draw a line on the image
    QPainter painter(&image);
    painter.setPen(Qt::black);
    painter.drawLine(lastPoint, endPoint);
}*/

