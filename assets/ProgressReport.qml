import bb.cascades 1.0


/*Page {
Button {
id: totalquiztaken
text: Progress_Report.getTotal_Quiz_Taken
onTouch:{
Progress_Report.updateTotal_Quiz_Taken()               
}

}
}

import bb.data 1.0
Page {
Container {  
background: back.imagePaint
Label {
text: "History"

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


}
]
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
}
]
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
query: "SELECT * FROM Quiz" // ORDER BY RANDOM() LIMIT 1" //it is "4" for now for show
onDataLoaded: {
dataModel.insertList(data);
}
},
DataSource {
id: randomWord
source: "test"
query: "Select * from Random ORDER BY RANDOM() LIMIT 4"

onDataLoaded: {
randomWords.insertList(data);
}
}
]
onCreationCompleted: { dataSource.load(); randomWord.load(); }
}*/

import bb.data 1.0
Page {
    Container {
        background: back.imagePaint
        horizontalAlignment: HorizontalAlignment.Center
        verticalAlignment: VerticalAlignment.Center
        ListView {
            dataModel: dataModel
            
            listItemComponents: [
                ListItemComponent {
                    type: "header"
                    Header {
                        title: "Correct\tWrong\tLevel"
                    }
                },
                
                ListItemComponent {
                    type: "item"
                    Label {
                        multiline: true
                        text: ListItemData.Correct + "\t\t" + ListItemData.Wrong + "\t\t" + ListItemData.Level + "\n"
                        //horizontalAlignment: HorizontalAlignment.Center
                        //verticalAlignment: Verticalalignment.Center
                    }
                
                }
            ]
        }   
        
        attachedObjects: [
            GroupDataModel {
                id: dataModel
                //sortingKeys: ["ID","Word","Check"]
            },
            
            DataSource {
                id: dataSource
                source: "lazy_scholar.sqlite"
                query: "select * from Quiz"
                onDataLoaded: {
                    dataModel.insertList(data);
                }
            }
        ]
        onCreationCompleted: { dataSource.load(); }
    
    } //end of container
} //end of Page
