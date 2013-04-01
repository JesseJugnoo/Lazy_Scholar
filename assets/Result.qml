import bb.cascades 1.0

Page {
    
    Container {
        background: back.imagePaint
        Label{
            
			            text:"Correct: " + _quiz.getCorrectCounter
			            horizontalAlignment: HorizontalAlignment.Center
			            verticalAlignment: VerticalAlignment.Center
			            textStyle {
			                base: SystemDefaults.TextStyles.BigText
			                color: Color.Green
			            }
            }
            Label{
                
	                text: "Incorrect: " +_quiz.getIncorrectCounter
	                horizontalAlignment: HorizontalAlignment.Center
	                verticalAlignment: VerticalAlignment.Center
	                textStyle {
	                    base: SystemDefaults.TextStyles.BigText
	                    color: Color.Red
	                }
            }
            
            Label{
                
                text: "Try Again"
                horizontalAlignment: HorizontalAlignment.Center
                verticalAlignment: VerticalAlignment.Center
                textStyle {
                    base: SystemDefaults.TextStyles.BigText
                    color: Color.Black
                }
            }
           
    }
    paneProperties: NavigationPaneProperties {
        backButton: ActionItem {
            onTriggered: {
                _quiz.loadToDatabase();
                _quiz.reset();
                var page = hubDefn.createObject();
                titleNav.pop();
                   
            }
        }
    }
    
}
