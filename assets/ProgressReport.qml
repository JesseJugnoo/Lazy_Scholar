import bb.cascades 1.0
import bb.data 1.0
Page {
     
    Container {
        
        Container {
            horizontalAlignment: HorizontalAlignment.Center
            verticalAlignment: VerticalAlignment.Center
            
            Button {   
                text: "RESET"   
                onClicked:{
                    Progress_Report.loadTotalQuizTaken();
                    dataModel.clear(); 
                    
                } 
            }
        }
        
        background: back.imagePaint
        horizontalAlignment: HorizontalAlignment.Center
        verticalAlignment: VerticalAlignment.Center
       
        ListView {
            dataModel: dataModel
            
            listItemComponents: [
                ListItemComponent {
                    type: "header"
                    Container {
                    leftPadding: 100
                        Label {
                            text: "\tCorrect\tWrong\tLevel"
                            textStyle {
                                base: SystemDefaults.TextStyles.BodyText
                                color: Color.create("#121212");
                            }
                        }
                    }
                
                },
                
                ListItemComponent {
                    type: "item"
                    Container {
                        topPadding: 10
                        leftPadding: 65
                        Label {
                            multiline: true
                            text: "\t\t" + ListItemData.Correct + "\t\t" + ListItemData.Wrong + "\t\t" + ListItemData.Level + "\n"
                        
                        }
                    }
                }
            ]
        }   
        
       
        
        attachedObjects: [
            GroupDataModel {
                id: dataModel
                
            },
            
            DataSource {
                id: dataSource
                source: "lazy_scholar.sqlite"
                query: "select * from Quiz"
                onDataLoaded: {
                    dataModel.insertList(data);
                }
            }
        ]
        onCreationCompleted: { dataSource.load(); }
    
    } //end of container
} //end of Page
