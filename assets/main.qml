// The title page of the app
import bb.cascades 1.0
import com.paint 1.0
import com.quiz 1.0

NavigationPane {
    id: titleNav
    peekEnabled: false
    Page {
        Container {
            layout: StackLayout {
            }
            topPadding: 300
            Label {
                id: "title"
                text: "Learn App"
                textStyle.fontSizeValue: 50
                bottomMargin: 100
                horizontalAlignment: HorizontalAlignment.Center
            } //end label
            DropDown {
                id: "language_choose"
                onSelectedIndexChanged: {
                    paint.setLanguage(selectedValue);
                }
                bottomMargin: 100
                //use a json file to populate data
                Option {
                    text: "Chinese"
                    value: "Chinese"
                    selected: true
                }
                
                // text + description
                Option {
                    text: "English"
                    value: "English"
                }
                preferredWidth: 400
                horizontalAlignment: HorizontalAlignment.Center
                expanded: false
                layoutProperties: StackLayoutProperties {
                }
            } //end dropdown
            Button {
                id: startButton
                text: "Start"
                horizontalAlignment: HorizontalAlignment.Center
                onClicked: {
                    var newPage = hubDefn.createObject();
                    titleNav.push(newPage);
                }
            } //end button
            Button {
                id: menuButton
                text: "Menu"
                horizontalAlignment: HorizontalAlignment.Center
                onClicked: {
                    var newPage = emptyDefn.createObject();
                    newPage.label = "Menu Coming Soon"
                    titleNav.push(newPage);
                }
            } //end button
        }
    } //end page
    attachedObjects: [
        
        // Non-visual objects are added to QML as attached objects.
        // The Paint is the object that contains the logics for drawing hand traces
        //
        Paint {
            id: paint
        },
        
        //Create the ComponentDefinition that represents the custom
        // component
        ComponentDefinition { //component for the hub
            id: hubDefn
            source: "Hub.qml"
        },
        ComponentDefinition {
            id: paintDefn
            source: "Paint.qml"
        },
        ComponentDefinition {
            id: quizDefn
            source: "Quiz.qml"
        },
        ComponentDefinition { //component for an empty page
            id: vocabularyDefn
            source: "vocabulary.qml"
        },
        ComponentDefinition { //component for an empty page
            id: emptyDefn
            source: "Empty.qml"
        }
    ] //end attachedObject
    onPopTransitionEnded: {
        page.destroy();
    }
}//end navigation pane
