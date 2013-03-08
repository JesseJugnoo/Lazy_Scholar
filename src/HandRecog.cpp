/*
 * HandRecog.cpp
 *
 *  Created on: 2013-03-07
 *      Author: pascua
 */

#include "HandRecog.hpp"

double HandRecog::compareDrawnImageByImage(QImage drawnImage, QImage source) {
	if (drawnImage.size() != source.size()) {
		//resize source to the dimension of the drawnImage
		source = source.scaled(drawnImage.size());
	}

	double total = 0;
	double maxTotal = 1;

	for (int i = 1; i < drawnImage.width(); i++) {

		for (int j = 1; j < drawnImage.height(); j++) {

			QColor drawnPixel = QColor::fromRgba(drawnImage.pixel(i, j));
			QColor sourcePixel = QColor::fromRgba(source.pixel(i, j));

			//source is priority
			if (sourcePixel.alpha() != 0) {
				maxTotal++;
				if (drawnPixel.alpha() != 0) {
					total++;
				}
			}

			//drawnImage is priority
			if (drawnPixel.alpha() != 0) {
				maxTotal++;
				if (sourcePixel.alpha() != 0) {
					total++;
				}
			}

		}
	}
	double bumpUp = 1.5;
	return total / maxTotal * bumpUp;
}


