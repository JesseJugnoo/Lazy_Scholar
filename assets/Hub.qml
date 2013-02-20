import bb.cascades 1.0

NavigationPane {
    id: nav
    Page {
        id: hubPage
        Container {
            ListView {
                id: hubList
                objectName: "hubList"
                layout: GridListLayout {
                }
            
                listItemComponents: [
                    ListItemComponent {
                        Container {
                            id: paint
                            layout: StackLayout {
                            }
                            Label {
                                text: "Paint"
                            }
                            ImageView {
                                imageSource: "asset:///images/picture.png"
                                scalingMethod: ScalingMethod.AspectFill
                            }
                        }
                    }
                /*,
                    ListItemComponent {
                        Container {
                            id: quiz
                            layout: StackLayout {
                            }
                            Label {
                                text: "Quiz"
                            }
                            ImageView {
                                imageSource: "asset:///images/picture.png"
                                scalingMethod: ScalingMethod.AspectFill
                            }
                        }
                    },
                    ListItemComponent {
                        Container {
                            id: report
                            layout: StackLayout {
                            }
                            Label {
                                text: "Progress Report"
                            }
                            ImageView {
                                imageSource: "asset:///images/picture.png"
                                scalingMethod: ScalingMethod.AspectFill
                            }
                        }
                    },
                    ListItemComponent {
                        Container {
                            id: setting
                            layout: StackLayout {
                            }
                            Label {
                                text: "Settings"
                            }
                            ImageView {
                                imageSource: "asset:///images/picture.png"
                               scalingMethod: ScalingMethod.AspectFill
                            }
                        }
                    }
                    */
                ]
                onTriggered: {
                    // When an item is selected we push the recipe Page in the chosenItem file attribute.
                    // var chosenItem = dataModel.data(indexPath);

                    // The _contentView property can be resolved in by the ContentPage since it will
                    // share the same context as the main file.
                    // _contentView = chosenItem;                    
                    
                    // Push the Content Page on top to drill down and show details about the stamp.
                    // nav.deprecatedPushQmlByString("ContentPage.qml");
                }
            }
        }
    }
}
