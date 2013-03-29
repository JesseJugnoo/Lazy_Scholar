import bb.cascades 1.0

Page {
    Container{
       Label{
           text: _quiz.getToBeAnswered
       }
	    Button {
	        id: a
	        text: _quiz.getGuess1
	        onTouch:{
	                    if(a.text == _quiz.getCorrect){
	                    a.text = "Correct";
	                    _quiz.loadTheQuestions();
	                    a.text = _quiz.getGuess1;
	                    }               
	               }
	    }
    Button {
            id: b
            text: _quiz.getGuess2
            onTouch:{
                        if(b.text == _quiz.getCorrect){
                        b.text = "Correct";
                        _quiz.loadTheQuestions();
                        b.text = _quiz.getGuess2;
                        }               
                   }
        }
        Button {
                id: c
                text: _quiz.getGuess3
                onTouch:{
                        if(c.text == _quiz.getCorrect){
                            c.text = "Correct";
                            _quiz.loadTheQuestions();
                            c.text = _quiz.getGuess3;
                        }               
                       }
                }
        Button {
                id: d
                text: _quiz.getGuess4
                onTouch:{
                        if(d.text == _quiz.getCorrect){
                            d.text = "Correct";
                            _quiz.loadTheQuestions();
                            d.text = _quiz.getGuess4;
                        }               
                       }
                }
                        
}
       
}

