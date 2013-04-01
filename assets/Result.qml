import bb.cascades 1.0

Page {
    Container {
        background: back.imagePaint
        Label{
            text: _quiz.getCorrectCounter
            }
            Label{
                text: _quiz.getIncorrectCounter
            }
    }
}
