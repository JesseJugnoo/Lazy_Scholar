/* The title page of the app


*/import bb.cascades 1.0

NavigationPane {
    id: titleNav
    Page {
        Container {
            layout: StackLayout {
                topPadding: 300
            }
            Label {
                id: "title"
                text: "Learn App"
                textStyle {
                    size: 100
                }
                bottomMargin: 100
                layoutProperties: StackLayoutProperties {
                    horizontalAlignment: HorizontalAlignment.Center
                }
            }//end label
            DropDown {
                id: "language_choose"
                onSelectedIndexChanged: {
                    console.log("SelectedIndex was changed to " + selectedIndex);
                }
                //use a json file to populate data
                Option {
                    text: "Chinese"
                    value: "Chinese"
                    selected: true
                    onSelectedChanged: {
                        if (selected == true) {
                            console.log("Setting alarm to 5 minutes.");
                        }
                    }
                }
                
                // text + description
                Option {
                    text: "English"
                    value: "English"
                }
                preferredWidth: 400
                layoutProperties: StackLayoutProperties {
                    horizontalAlignment: HorizontalAlignment.Center
                }
                expanded: false
            }//end dropdown
            Button {
                id: startButton
                text: "Start"
                layoutProperties: StackLayoutProperties {
                    horizontalAlignment: HorizontalAlignment.Center
                }
                onClicked: {
                    console.log("started game");
                    var newPage = hub;// hubDefn.createObject();
                    titleNav.push(newPage);
                }
            }//end button
            Button {
                id: menuButton
                text: "Menu"
                layoutProperties: StackLayoutProperties {
                    horizontalAlignment: HorizontalAlignment.Center
                }
                onClicked: {
                    console.log("Get to menu");
                    //var newPage = hubDefn.createObject();
                    titleNav.push(menu);
                }
            }//end button
        }
        attachedObjects: [
            // Create the ComponentDefinition that represents the custom
            // component in myPage.qml
            
            Hub {
                id: hubDefn            
                
                    
               // source: "Hub.qml"
            },
            Page {
                id: menu
                content: Container {
                    Label {
                        text: "Setting coming soon"
                    }
                }
            },
            Page{
                id: hub
                content: Container{
                    Label{
                        text: "Hub coming soon"
                    }
                }
            }
        ] //end attachedObject
    } //end page
}//end container
