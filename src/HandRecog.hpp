


#ifndef _HAND_RECOG_
#define _HAND_RECOG_

#include <Qt/qimage.h>
#include <Qt/qpainter.h>
/*
 * Class that handles hand recognition
 */
class HandRecog{
public:
	static double compareDrawnImageByImage(QImage drawnImage, QImage source);
};




#endif
