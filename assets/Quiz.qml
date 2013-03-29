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
       
    /*Container {  Label {
                   text: "What is the English translation?"
                       
               }
                   ListView {
				        dataModel: dataModel
				        listItemComponents: [
				          ListItemComponent {
				            type: "item"
	                        Label {
	                            text: ListItemData.Word
	                            horizontalAlignment: HorizontalAlignment.Center
	                            verticalAlignment: Verticalalignment.Center
	                        }
                       
                   
				   } ]
				      //...
				      }
				       ListView {
	      				        dataModel: randomWords
	      				        listItemComponents: [
	      				          ListItemComponent {
	      				            type: "item"
	      	                        Button {
	      	                            text: ListItemData.Guess
	      	                            horizontalAlignment: HorizontalAlignment.Center
	      	                            verticalAlignment: Verticalalignment.Center
	      	                        }
				                             
				                         
				      				   } ]
				      				      //...
				      				     
				      				      }    
         
  }
  
      attachedObjects: [
        GroupDataModel {
          id: dataModel
          //sortingKeys: ["ID","Word","Check"]
          
        },
       
	    GroupDataModel{
	        id: randomWords
	    
	    },
        DataSource {
          id: dataSource
          source: "test"
          //query: "select * from Words order by ID DESC"
          query: "SELECT * FROM Words ORDER BY RANDOM() LIMIT 1" //it is "4" for now for show
          onDataLoaded: {
              
            dataModel.insertList(data);
         }
        },
        DataSource {
            id: randomWord
            source: "test"
            query: "Select Guess from Random ORDER BY RANDOM() LIMIT 4"
           
            onDataLoaded: {
                    randomWords.insertList(data);
                 }
        }
      ]
      onCreationCompleted: { dataSource.load();randomWord.load(); }*/
}

