import bb.cascades 1.0

Page {
    Container {
        layout: DockLayout {
        }
        ImageView {
            id: paintImage
            image: learn.image
            // imageSource: "images/picture.png"
            scalingMethod: ScalingMethod.Fill
            minWidth: 15.0
            preferredHeight: 1280
            preferredWidth: 760
            
            verticalAlignment: VerticalAlignment.Center
            horizontalAlignment: HorizontalAlignment.Center
            
            
            onTouch: {
                var moveX = event.localX;
                var moveY = event.localY - 100; //touch event is in wrong location if there is no offset
                
                // _scratchpad.object = "move";
                if (event.touchType == TouchType.Move) {
                    learn.setEndPoint(moveX, moveY);
                    learn.paintImage();
                } else if (event.touchType == TouchType.Down) {
                    learn.setLastPoint(moveX, moveY);
                    learn.setEndPoint(moveX, moveY);
                    learn.paintImage();
                } else if (event.touchType == TouchType.Up) {
                }
            }
        }
    }
}
