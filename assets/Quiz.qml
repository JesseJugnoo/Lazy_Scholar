import bb.cascades 1.0

Page {
    Button {
        id: b
        text: _quiz.test
         onTouch:{
               _quiz.test2()               
            }

    }
}

