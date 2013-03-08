import bb.cascades 1.0

Page {
    Container {
        layout: DockLayout {
        }
        topMargin: 50.0
        ImageView {
            id: border
            imageSource: "images/border.png"
            preferredHeight: 700
            preferredWidth: 700
            verticalAlignment: VerticalAlignment.Center
            horizontalAlignment: HorizontalAlignment.Center
        }
        
        ImageView {
            id: textImage
            image: paint.textImage
            //imageSource: "images/chinese_outline/one.png"
            scalingMethod: ScalingMethod.Fill
            minWidth: 15.0
            preferredHeight: 700
            preferredWidth: 700
            verticalAlignment: VerticalAlignment.Center
            horizontalAlignment: HorizontalAlignment.Center
        }
        ImageView {
            id: paintImage
            image: paint.image
            //imageSource: "images/picture.png"
            scalingMethod: ScalingMethod.Fill
            minWidth: 15.0
            preferredHeight: 700
            preferredWidth: 700
            verticalAlignment: VerticalAlignment.Center
            horizontalAlignment: HorizontalAlignment.Center
            onTouch: {
                var moveX = event.localX;
                var moveY = event.localY; //touch event is in wrong location if there is no offset

                // _scratchpad.object = "move";
                if (event.touchType == TouchType.Move) {
                    paint.setEndPoint(moveX, moveY);
                    paint.paintImage();
                } else if (event.touchType == TouchType.Down) {
                    paint.setLastPoint(moveX, moveY);
                    paint.setEndPoint(moveX, moveY);
                    paint.paintImage();
                } else if (event.touchType == TouchType.Up) {
                    paint.updateStroke();
                }
            }
        }
        Label {
            id: translate
            text: paint.translation
            horizontalAlignment: HorizontalAlignment.Center
            textStyle {
                fontSize: FontSize.XXLarge
            }
        }
        Button {
            text: "New Char"
            horizontalAlignment: HorizontalAlignment.Center
            verticalAlignment: VerticalAlignment.Bottom
            onClicked: {
                paint.initDrawPage();
            }
        }
        ImageView {
            id: rating
            image: paint.rating
        }
    }
}
