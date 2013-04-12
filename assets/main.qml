// The title page of the app
import bb.cascades 1.0
import com.paint 1.0
NavigationPane {
    id: titleNav
    peekEnabled: false
    Page { 
        Container {
            
            layout: StackLayout {
            }
            
            background: back.imagePaint
            topPadding: 200
            
            ImageView {
                imageSource: "images/logo.png" 
                horizontalAlignment: HorizontalAlignment.Center
            } //end ImageView (used to display logo)
            
            Label {
                id: "title"
                text: "Chinese Edition 1"
                bottomMargin: 100
                horizontalAlignment: HorizontalAlignment.Center
            } //end label
            
            //temp remove dropdown to make the page look clearner
            /*DropDown {
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
            } //end dropdown*/
            
            Button {
                id: startButton
                text: "Start"
                horizontalAlignment: HorizontalAlignment.Center
                onClicked: {
                    var newPage = hubDefn.createObject();
                    titleNav.push(newPage);
                }
            } //end button
            
            //temp removed feature until implemented
            /*Button {
                id: menuButton
                text: "Menu"
                horizontalAlignment: HorizontalAlignment.Center
                onClicked: {
                    var newPage = emptyDefn.createObject();
                    newPage.label = "Menu Coming Soon"
                    titleNav.push(newPage);
                }
            } //end button*/
        }
    } //end page
    attachedObjects: [
        //to add background image
	    ImagePaintDefinition {
	        id: back
	        repeatPattern: RepeatPattern.XY
	        imageSource: "asset:///images/tiled_image.amd"
	    },
	    
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
        ComponentDefinition {
            id: progressreportDefn
            source: "ProgressReport.qml"
        },
        ComponentDefinition { //component for an empty page
            id: resultDefn
            source: "Result.qml"
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
