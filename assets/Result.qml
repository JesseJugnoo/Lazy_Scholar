import bb.cascades 1.0

Page {
    
    Container {
        background: back.imagePaint
        topPadding: 300
        Label{
            
            text:"Correct: " + _quiz.getCorrectCounter
            horizontalAlignment: HorizontalAlignment.Center
            verticalAlignment: VerticalAlignment.Center
            textStyle {
                
                base: SystemDefaults.TextStyles.BigText
                color: Color.create("#96B800");
            }
        }
        Label{
            
            text: "Incorrect: " +_quiz.getIncorrectCounter
            horizontalAlignment: HorizontalAlignment.Center
            verticalAlignment: VerticalAlignment.Center
            textStyle {
                base: SystemDefaults.TextStyles.BigText
                color: Color.create("#CC3F10");
            }
        }
        
        Label{
            
            text: "Play Again"
            horizontalAlignment: HorizontalAlignment.Center
            verticalAlignment: VerticalAlignment.Center
            textStyle {
                base: SystemDefaults.TextStyles.BigText
                color: Color.create("#121212");
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
