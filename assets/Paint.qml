import bb.cascades 1.0

Page {
    Container {
        layout: DockLayout {
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
            text: learn.translation
            horizontalAlignment: HorizontalAlignment.Center
            verticalAlignment: VerticalAlignment.Bottom
            textStyle {
                fontSize: FontSize.XXLarge
            }
        }
        Button {
            text: "New Char"
            horizontalAlignment: HorizontalAlignment.Center
            onClicked: {
                learn.initDrawPage();
            }
        }
    }
}
