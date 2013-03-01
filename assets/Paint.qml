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
            image: learn.textImage
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
            image: learn.image
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
                    learn.setEndPoint(moveX, moveY);
                    learn.paintImage();
                } else if (event.touchType == TouchType.Down) {
                    learn.setLastPoint(moveX, moveY);
                    learn.setEndPoint(moveX, moveY);
                    learn.paintImage();
                } else if (event.touchType == TouchType.Up) {
                    learn.updateStroke();
                }
            }
        }
        Label {
            id: translate
            text: learn.translation
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
                learn.initDrawPage();
            }
        }
        ImageView {
            id: rating
            image: learn.rating
        }
    }
}
