import bb.cascades 1.0

NavigationPane {
    id: navigationPane
    Page {
        id: pgMain
        content: Container {
            layout: DockLayout {
            }
            ListView {
                id: listView
                objectName: "listView"
                layout: GridListLayout {
                }
                //-- define own itemType function to overide data model itemType one
                function itemType (data, indexPath) {
                    return "myItem";
                }
                listItemComponents: [
	                //-- define component which will represent list item GUI appearence
	                ListItemComponent {
	                    type: "myItem"
	                    //-- list item GUI appearence component is defined in external MyListItem.qml file
	                    MyListItem {}
	                }
                ]
                layoutProperties: DockLayoutProperties {
                    horizontalAlignment: HorizontalAlignment.Center
                    verticalAlignment: VerticalAlignment.Center
                }
                onTriggered: {
                    console.log("selected_index: " + indexPath)
                    var curr_item = dataModel.data(indexPath)
                    //-- show detail page for selected item
                    setDetailItem(curr_item)
                }
            }
        }
    }
    
    property Page secondPage: Page {
        id: pgDetail
        paneProperties: NavigationPaneProperties {
            backButton: ActionItem {
                onTriggered: { navigationPane.pop(); }
            }
        }
        content: Container {
            layout: StackLayout {
            }
            Label {
                id: lblText
                layoutProperties: StackLayoutProperties {
                    horizontalAlignment: HorizontalAlignment.Center
                }
                textStyle.base: SystemDefaults.TextStyles.TitleText
            }
            ImageView {
                id: imgView
                scalingMethod: ScalingMethod.AspectFit
                layoutProperties: StackLayoutProperties {
                    spaceQuota: 1.0 //-- the image fills rest of the Page
                    horizontalAlignment: HorizontalAlignment.Center
                    verticalAlignment: VerticalAlignment.Center
                }
            }
        }
    }

    function setDetailItem(item) {
        //-- show detail page
        lblText.text = item.text
        imgView.imageSource = item.image
        navigationPane.push(pgDetail)
    }
}
