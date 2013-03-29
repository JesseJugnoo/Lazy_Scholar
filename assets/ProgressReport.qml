import bb.cascades 1.0

Page {
    Button {
        id: totalquiztaken
        text: Progress_Report.getTotal_Quiz_Taken
         onTouch:{
               Progress_Report.updateTotal_Quiz_Taken()               
            }

    }
}