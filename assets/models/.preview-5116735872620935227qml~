import bb.cascades 1.0
import bb.data 1.0
Page {
     content: ListView {
        id: myListView
        dataModel: dataModel
        listItemComponents: [
          ListItemComponent {
            type: "header"
            StandardListItem {
               title:ListItemData.id + ' ' + ListItemData.guess
              // imageSource: "asset:///" + ListItemData.image
               //description: ListItemData.title
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
          query: "select guess from Random order by id"
          onDataLoaded: {
            dataModel.insertList(data);
         }
        }
      ]
      onCreationCompleted: { dataSource.load(); }
}