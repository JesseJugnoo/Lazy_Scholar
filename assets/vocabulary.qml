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
                        title: "Dictionary"
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
                
            },
            
            DataSource {
                id: dataSource
                source: "lazy_scholar.sqlite"
                query: "select Word, Correct from Words "
                onDataLoaded: {
                    dataModel.insertList(data);
                }
            }
        ]
        onCreationCompleted: { dataSource.load(); }
        
    } //end of container
} //end of Page
