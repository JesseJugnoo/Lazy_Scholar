import bb.cascades 1.0
// To use the MediaPlayer, we must include
// the multimedia library.
import bb.multimedia 1.0
Page {
    
    Container {
        layout: DockLayout {
        }
        topMargin: 50.0
        
        
        Container{
            layout:StackLayout {
            
            } 
            verticalAlignment: VerticalAlignment.Center
            horizontalAlignment: HorizontalAlignment.Center
            
            
            ImageView {
                id: rating
                image: paint.rating
                verticalAlignment: VerticalAlignment.Center
                horizontalAlignment: HorizontalAlignment.Center
                bottomMargin: 50
            
            }
            Container{
                layout:DockLayout {                
                }  
                
                
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
                    scalingMethod: ScalingMethod.Fill
                    minWidth: 15.0
                    preferredHeight: 700                    
                    preferredWidth: 700
                    verticalAlignment: VerticalAlignment.Center
                    horizontalAlignment: HorizontalAlignment.Center
                    onTouch: {
                        //cancel fade animation if it exist
                        fadeAnim.stop();
                        
                        //set opacity to 1
                        paintImage.setOpacity(1);
                        paintImage.opacity = 1;
                        
                        var moveX = event.localX;
                        var moveY = event.localY;
                        
                        switch(event.touchType){
                            case TouchType.Down:
                                paint.startDraw(moveX, moveY);
                            //FALL THROUGH
                            case TouchType.Move:
                                paint.draw(moveX, moveY);
                                
                                
                                break;
                            case TouchType.Up:
                                var isFade = paint.finishDraw();
                                if (isFade){
                                    var rating_src = rating.imageSource;
                                    
                                    /*
                                    if (rating_src == "assets/images/rating/green.png"){
                                    player.setSourceUrl("asset:///sounds/ding.wav");
                                    
                                    }else if(rating_src == "assets/images/rating/yellow.png"){
                                    player.setSourceUrl("asset:///sounds/average.wav");
                                    
                                    }else{
                                    player.setSourceUrl("asset:///sounds/fail-buzzer.wav"); 
                                    
                                    }
                                    ding_sound.play();
                                    */
                                    fadeAnim.play();
                                }
                                break;
                        }
                    
                    }
                    animations: [
                        FadeTransition {
                            id: fadeAnim
                            duration: 5000 //5 seconds
                            easingCurve: StockCurve.Linear
                            fromOpacity: 1.0
                            toOpacity: 0
                        }
                    ]
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
        }
        
        ImageView{
            id: prev_char
            imageSource: "images/arrow.png"
            horizontalAlignment: HorizontalAlignment.Left
            verticalAlignment: VerticalAlignment.Bottom
            onTouch: {
                
                if (event.touchType == TouchType.Down){
                    paint.navigateNextCharacter(-1);
                }
            }
        
        }
        
        ImageView{
            id: next_char
            imageSource: "images/arrow.png"
            horizontalAlignment: HorizontalAlignment.Right
            verticalAlignment: VerticalAlignment.Bottom
            rotationZ: 180
            onTouch: {
                
                if (event.touchType == TouchType.Down){
                    paint.navigateNextCharacter(1);
                }
            }
        
        }
    
    
    
    }
}
