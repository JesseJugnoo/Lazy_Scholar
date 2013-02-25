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
        /*
        Label {
            multiline: true
            text: "<html><head><style>
                                       h1
                                       {
                                           background-color:black;
                                           color: white; 
                                           
                                       }
                                   </style></head>
                                   <h1>A</h1>
                                   </html>"
            horizontalAlignment: HorizontalAlignment.Center
            verticalAlignment: VerticalAlignment.Center
            textStyle {
                fontSize: FontSize.XXLarge
                fontFamily: "Helvectica"
            }
        }
        */
    }
}
