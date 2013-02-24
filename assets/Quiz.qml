import bb.cascades 1.0
import bb.data 1.0
Page {
     content: ListView {
        id: myListView
        dataModel: dataModel
        listItemComponents: [
          ListItemComponent {
            type: "item"
            StandardListItem {
                title: ListItemData.ID + " " + ListItemData.Word + " " + ListItemData.Correct
                
                
            }
          }
        ]
      //...
      }
      attachedObjects: [
        GroupDataModel {
          id: dataModel
          //sortingKeys: ["ID"]
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
}