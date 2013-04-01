import bb.cascades 1.0
import bb.multimedia 1.0
Page {
    
    Container{
        background: back.imagePaint
        // layout: StackLayout{}
        Container{
            layout: AbsoluteLayout{}
            
            Label {
                text: _quiz.getToBeAnswered
                //text: "example"
                layoutProperties: AbsoluteLayoutProperties {
                    positionX: 328
                    positionY: 50    
                }
                textStyle {
                    base: SystemDefaults.TextStyles.BigText
                    color: Color.Black
                }
            }
        }
        
        Container {
            layout: AbsoluteLayout{}
            bottomPadding:30
            Button {
                id: a
                imageSource: "asset:///images/quiz.png"
                layoutProperties: AbsoluteLayoutProperties {
                    positionX: 25
                    positionY: 450    
                }
                text: _quiz.getGuess1
                onClicked:{
                    if(a.text == _quiz.getCorrect){
                        itsCorrect.visible = true
                        youAreRight.play()
                        correctPlay.play()
                        
                        if(!_quiz.getHere) {
                            _quiz.correctCounter();
                        }
                         _quiz.loadTheQuestions();
                        if(_quiz.getTotal == 11 ){
                            var next = resultDefn.createObject();
                            titleNav.push(next);
                        }
                        _quiz.changeHere(false);
                        a.text = _quiz.getGuess1;
                        b.text = _quiz.getGuess2;
                        c.text = _quiz.getGuess3;
                        d.text = _quiz.getGuess4;
                    }   
                    else {
                        itsIncorrect.visible = true
                        youAreWrong.play();
                        incorrectPlay.play();
                        
                        if(!_quiz.getHere) {
                        _quiz.incorrectCounter();
                        _quiz.changeHere(true);
                        }
                    }            
                }
            }
            Button {
                id: b
                imageSource: "asset:///images/quiz.png"
                text: _quiz.getGuess2
                layoutProperties: AbsoluteLayoutProperties {
                    positionX: 380
                    positionY: 450    
                }
                onClicked:{
                    if(b.text == _quiz.getCorrect){
                        itsCorrect.visible = true
                       youAreRight.play() //play sounds
                        correctPlay.play()
                        
                        if(!_quiz.getHere) {
                            _quiz.correctCounter();
                        }
                        
                        _quiz.loadTheQuestions();
                        if(_quiz.getTotal == 11 ){
                            var next = resultDefn.createObject();
                            titleNav.push(next);
                        }
                        _quiz.changeHere(false);
                        a.text = _quiz.getGuess1;
                        b.text = _quiz.getGuess2;
                        c.text = _quiz.getGuess3;
                        d.text = _quiz.getGuess4;
                    }
                    else {
                        itsIncorrect.visible = true
                        youAreWrong.play();
                        incorrectPlay.play();
                        if(!_quiz.getHere){
                            _quiz.incorrectCounter();
                            _quiz.changeHere(true);
                        }
                    }               
                }
            }
            
            Button {
                id: c
                imageSource: "asset:///images/quiz.png"
                text: _quiz.getGuess3
                layoutProperties: AbsoluteLayoutProperties {
                    positionX: 25
                    positionY: 300    
                }
                onClicked:{
                    if(c.text == _quiz.getCorrect){
                        itsCorrect.visible = true
                        youAreRight.play();
                        correctPlay.play();
                       
                        if(!_quiz.getHere) {
                            _quiz.correctCounter();
                        }
                        
                        _quiz.loadTheQuestions();
                         if(_quiz.getTotal == 11 ){
                             var next = resultDefn.createObject();
                             titleNav.push(next);
                        }
                        _quiz.changeHere(false);
                        a.text = _quiz.getGuess1;
                        b.text = _quiz.getGuess2;
                        c.text = _quiz.getGuess3;
                        d.text = _quiz.getGuess4;
                    }
                    else {
                        itsIncorrect.visible = true;
                        youAreWrong.play();
                        incorrectPlay.play();
                        if(!_quiz.getHere){
                            _quiz.incorrectCounter();
                            _quiz.changeHere(true);
                        }
                    }               
                }
            }
            Button {
                id: d
                imageSource: "asset:///images/quiz.png"
                text: _quiz.getGuess4
                layoutProperties: AbsoluteLayoutProperties {
                    positionX: 380
                    positionY: 300    
                }
                onClicked:{
                    if(d.text == _quiz.getCorrect){
                        itsCorrect.visible = true
                        youAreRight.play();
                        correctPlay.play();
                        
                       if(!_quiz.getHere) {
                            _quiz.correctCounter();
                        }
                        
                        _quiz.loadTheQuestions();
                        
                        if(_quiz.getTotal == 11 ){
                            var next = resultDefn.createObject();
                            titleNav.push(next);
                        }
                        _quiz.changeHere(false);
                        a.text = _quiz.getGuess1;
                        b.text = _quiz.getGuess2;
                        c.text = _quiz.getGuess3;
                        d.text = _quiz.getGuess4;
                    } 
                    else {
                        itsIncorrect.visible = true 
                        youAreWrong.play();
                        incorrectPlay.play();
                       if(!_quiz.getHere){
                            _quiz.incorrectCounter();
                            _quiz.changeHere(true);
                        }
                    }              
                }
            }
            ImageView {
                id: itsIncorrect
                imageSource: "asset:///images/wrong.png"
                layoutProperties: AbsoluteLayoutProperties {
                    positionX: 269
                    positionY: 650  
                }
                visible: false
                animations: [
                    FadeTransition {
                        id: incorrectPlay
                        duration: 1000 //5 seconds
                        fromOpacity: 1.0
                        toOpacity: 0
                    }
                ]
            }
            ImageView {
                id: itsCorrect    
                imageSource: "asset:///images/correct.png"
                layoutProperties: AbsoluteLayoutProperties {
                    positionX: 269
                    positionY: 650   
                }
                visible: false
                animations: [
                    FadeTransition {
                        id: correctPlay
                        duration: 1000 //5 seconds
                        fromOpacity: 1.0
                        toOpacity: 0
                    }
                ]
            }
        
        
        
        }
    
    }
    attachedObjects: [
            MediaPlayer{
                id: youAreRight
                sourceUrl: "asset:///sounds/ding.wav"
            },
            MediaPlayer{
                id: youAreWrong
                sourceUrl: "asset:///sounds/BUZZER.wav"
            }          
        ]
}

