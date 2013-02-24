import bb.cascades 1.0

Page {
    id: hubPage
    Container {
        ListView {
            id: hubList
            objectName: "hubList"
            layout: GridListLayout {
                columnCount: 2
                headerMode: ListHeaderMode.Standard
                cellAspectRatio: 1
                verticalCellSpacing: 20
            }
            dataModel: XmlDataModel {
                source: "models/hub.xml"
            }

            // Add appearance definitions for the list items using the
            // listItemComponents list
            listItemComponents: [

                // The first ListItemComponent defines how "header" items
                // should appear. These items use a Label.
                ListItemComponent {
                    type: "header"
                    Header {
                        title: ListItemData.title
                    }
                },

                // The second ListItemComponent defines how "listItem" items
                // should appear. These items use a Container that includes a
                // CheckBox and a Label.
                ListItemComponent {
                    type: "item"
                    Container {
                        id: "hubContainer"
                        layout: StackLayout {
                        }
                        topPadding: 50
                        Label {
                            text: ListItemData.title
                            horizontalAlignment: HorizontalAlignment.Center
                        }
                        ImageView {
                            imageSource: ListItemData.picture
                            scalingMethod: ScalingMethod.AspectFill
                            horizontalAlignment: HorizontalAlignment.Center
                            opacity: 1.0
                        }
                    } // end of Container
                } // end of second ListItemComponent
            ] // end of listItemComponents list
            onTriggered: {
                //When an item is selected we push the recipe Page in the chosenItem file attribute.
                var chosenItem = dataModel.data(indexPath);
                // console.log(chosenItem);
                var name = chosenItem.title;
                var newPage = null;
                if (name == "Draw"){
                    
                    newPage = paintDefn.createObject();
                    learn.resetImage();
                }else{
                     newPage = emptyDefn.createObject();
                     newPage.label =  chosenItem.title + " Coming Soon"
                }
                titleNav.push(newPage);
            }
        }
    }
}
