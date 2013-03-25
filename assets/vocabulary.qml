import bb.cascades 1.0
import bb.data 1.0
Page {
    Container {
        background: back.imagePaint
        
        ListView {
            dataModel: dataModel
            
            listItemComponents: [
                ListItemComponent {
                    type: "header"
                    Header {
                        title: "Vocabulary"
                    }
                },
                
                ListItemComponent {
                    type: "item"
                    Label {
                        text:ListItemData.Word + " " + ListItemData.Correct
                        horizontalAlignment: HorizontalAlignment.Center
                        verticalAlignment: Verticalalignment.Center
                    }
                }
            ]
            //...
        }   
        
        attachedObjects: [
            GroupDataModel {
                id: dataModel
                //sortingKeys: ["ID","Word","Check"]
            },
            
            DataSource {
                id: dataSource
                source: "test"
                query: "select * from Words order by ID DESC"
                onDataLoaded: {
                    dataModel.insertList(data);
                }
            }
        ]
        onCreationCompleted: { dataSource.load(); }
        
    } //end of container
} //end of Page
