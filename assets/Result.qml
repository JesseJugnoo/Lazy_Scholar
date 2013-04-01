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
			                color: Color.Black
			            }
            }
            Label{
                
	                text: "Incorrect: " +_quiz.getIncorrectCounter
	                horizontalAlignment: HorizontalAlignment.Center
	                verticalAlignment: VerticalAlignment.Center
	                textStyle {
	                    base: SystemDefaults.TextStyles.BigText
	                    color: Color.Black
	                }
            }
           
    }
    
}
