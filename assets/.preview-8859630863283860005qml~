import bb.cascades 1.0
//import com.quiz 1.0
Page {
    Button {
        id: b
        text: _quiz.test
         onTouch:{//function calls are needed to be called in here, because onTouch are function based
               _quiz.test2()               
            }
            //attachedObjects:[ quiz {
                   //     id: _quiz
                   // }]
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

