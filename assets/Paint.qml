import bb.cascades 1.0

Page {
    Container {
        layout: DockLayout {
        }
        topMargin: 50.0
        
        ImageView {
            id: textImage
            image: paint.textImage
            scalingMethod: ScalingMethod.Fill
            minWidth: 15.0
            preferredHeight: 700
            preferredWidth: 700
            verticalAlignment: VerticalAlignment.Center
            horizontalAlignment: HorizontalAlignment.Center
        }
        
        ImageView {
            id: border
            imageSource: "images/border.png"
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
                
                switch(event.touchType){
                    case TouchType.Down:
                        paint.startDraw(moveX, moveY);
                    //FALL THROUGH
                    case TouchType.Move:
                        paint.draw(moveX, moveY);
                        break;
                    case TouchType.Up:
                        paint.finishDraw();
                        break;
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
                paint.navigateNextCharacter(1);
            }
        }
        ImageView {
            id: rating
            image: paint.rating
        }
    }
}
