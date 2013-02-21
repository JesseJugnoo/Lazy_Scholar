//an empty page

import bb.cascades 1.0

// A common RecipePage used by all recipes containing a TitleBar
Page {
    property alias label: emptyLabel.text;
    Label {
        id: emptyLabel
        text: "Coming Soon"
    }
}
