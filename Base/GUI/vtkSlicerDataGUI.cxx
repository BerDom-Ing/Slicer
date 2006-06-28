#include "vtkObject.h"
#include "vtkObjectFactory.h"
#include "vtkCommand.h"

#include "vtkSlicerApplication.h"
#include "vtkSlicerModuleLogic.h"
#include "vtkSlicerDataGUI.h"

#include "vtkKWWidget.h"
#include "vtkKWFrameWithLabel.h"


//---------------------------------------------------------------------------
vtkStandardNewMacro (vtkSlicerDataGUI );
vtkCxxRevisionMacro ( vtkSlicerDataGUI, "$Revision: 1.0 $");


//---------------------------------------------------------------------------
vtkSlicerDataGUI::vtkSlicerDataGUI ( )
{
  MRMLTreeWidget = vtkSlicerMRMLTreeWidget::New();
    //this->Logic = NULL;

}


//---------------------------------------------------------------------------
vtkSlicerDataGUI::~vtkSlicerDataGUI ( )
{
  if (this->MRMLTreeWidget)
    {
    this->MRMLTreeWidget->RemoveWidgetObservers ( );
    this->MRMLTreeWidget->Delete ( );
    }
    // class not yet defined!
    //this->SetModuleLogic ( NULL );
}


//---------------------------------------------------------------------------
void vtkSlicerDataGUI::PrintSelf ( ostream& os, vtkIndent indent )
{
    this->vtkObject::PrintSelf ( os, indent );

    os << indent << "SlicerDataGUI: " << this->GetClassName ( ) << "\n";
    //os << indent << "Logic: " << this->GetLogic ( ) << "\n";
    // print widgets?
}



//---------------------------------------------------------------------------
void vtkSlicerDataGUI::RemoveGUIObservers ( )
{
    // Fill in
}

//---------------------------------------------------------------------------
void vtkSlicerDataGUI::AddGUIObservers ( )
{
    // Fill in
}


//---------------------------------------------------------------------------
void vtkSlicerDataGUI::ProcessGUIEvents ( vtkObject *caller,
                                          unsigned long event, void *callData )
{
    // Fill in
}


//---------------------------------------------------------------------------
void vtkSlicerDataGUI::ProcessLogicEvents ( vtkObject *caller,
                                            unsigned long event, void *callData )
{
    // Fill in
}

//---------------------------------------------------------------------------
void vtkSlicerDataGUI::ProcessMRMLEvents ( vtkObject *caller,
                                           unsigned long event, void *callData )
{
    // Fill in
}

//---------------------------------------------------------------------------
void vtkSlicerDataGUI::Enter ( )
{
    // Fill in
}

//---------------------------------------------------------------------------
void vtkSlicerDataGUI::Exit ( )
{
    // Fill in
}




//---------------------------------------------------------------------------
void vtkSlicerDataGUI::BuildGUI ( )
{

    vtkSlicerApplication *app = (vtkSlicerApplication *)this->GetApplication();

    // ---
    // MODULE GUI FRAME 
    // configure a page for a model loading UI for now.
    // later, switch on the modulesButton in the SlicerControlGUI
    // ---
    // create a page
    this->UIPanel->AddPage ( "Data", "Data", NULL );
    
    // HELP FRAME
    vtkKWFrameWithLabel *modHelpFrame = vtkKWFrameWithLabel::New ( );
    modHelpFrame->SetParent ( this->UIPanel->GetPageWidget ( "Data" ) );
    modHelpFrame->Create ( );
    modHelpFrame->CollapseFrame ( );
    modHelpFrame->SetLabelText ("Help");
    app->Script ( "pack %s -side top -anchor nw -fill x -padx 2 -pady 2 -in %s",
                  modHelpFrame->GetWidgetName(), this->UIPanel->GetPageWidget("Data")->GetWidgetName());
    
    this->MRMLTreeWidget->SetAndObserveMRMLScene(this->GetMRMLScene() );
    this->MRMLTreeWidget->SetParent ( this->UIPanel->GetPageWidget ( "Data" ) );
    this->MRMLTreeWidget->Create ( );
    app->Script ( "pack %s -side top -anchor nw -fill x -padx 2 -pady 2 -in %s",
                  this->MRMLTreeWidget->GetWidgetName(), this->UIPanel->GetPageWidget( "Data" )->GetWidgetName());
      
    modHelpFrame->Delete ( );
}





