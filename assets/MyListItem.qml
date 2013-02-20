import bb.cascades 1.0

//-- Item used by the list to present a small thumbnail image with text.
Container {
    id: myItemContainer
    layout: DockLayout {
    }
    Container {
        //-- this container is used to show selection background when item is selected
        id: mySelectionContainer
        layoutProperties: DockLayoutProperties {
            horizontalAlignment: HorizontalAlignment.Fill
            verticalAlignment: VerticalAlignment.Fill
        }
        background: Color.create ("#00AFF0")
        visible: false
    }
    Container {
        layoutProperties: DockLayoutProperties {
            horizontalAlignment: HorizontalAlignment.Fill
            verticalAlignment: VerticalAlignment.Fill
        }
        layout: StackLayout {
        }
        //-- show image
        ImageView {
            imageSource: ListItemData.thumb
            scalingMethod: ScalingMethod.AspectFit
            layoutProperties: StackLayoutProperties {
                spaceQuota: 1.0
                horizontalAlignment: HorizontalAlignment.Center
            }
        }
        //-- and text below
        Label {
            text: ListItemData.text
            layoutProperties: StackLayoutProperties {
                horizontalAlignment: HorizontalAlignment.Center
            }
            textStyle.base: SystemDefaults.TextStyles.SmallText
        }
    }
    
    //-- Set visual appearance of activated and selected item.
    function setHighlight (selected, active) {
        var opacity = selected ? 1.0 : 0.5
        var visible = selected || active
        mySelectionContainer.visible = visible
        mySelectionContainer.opacity = opacity
    }
    
    //-- Signal handler for list item activation.
    ListItem.onActivationChanged: {
        setHighlight (ListItem.selected, ListItem.active);
    }
    
    //-- Signal handler for list item selection.
    ListItem.onSelectionChanged: {
        setHighlight (ListItem.selected, ListItem.active);
    }
}
