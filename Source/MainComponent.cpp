/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"


//==============================================================================
MainContentComponent::MainContentComponent()
{

    
    notificationManager = new NotificationManager(200);
    notificationManager->addListener(this);
    
    controlWindow = new Controls();
    addAndMakeVisible( controlWindow );
    controlWindow->addListener(this);
    
    setSize (600, 400);
    
   

}

MainContentComponent::~MainContentComponent()
{
}

void MainContentComponent::paint (Graphics& g)
{
    g.fillAll (Colour (0xff001F36));
}

void MainContentComponent::resized()
{
    controlWindow->setTopLeftPosition(10, 10);
   
}

void MainContentComponent::messageButtonClicked(juce::String message, int priority)
{
    if ( priority == 2 )
        messageResult = notificationManager->showNotification( message, priority );
    else
        notificationManager->showNotification( message, priority );
}

void MainContentComponent::notificationFinished(const NotificationMessage& message)
{
    if (messageResult.get() == &message)
    {
        DBG(messageResult->result);
        messageResult.reset();
    }
}

