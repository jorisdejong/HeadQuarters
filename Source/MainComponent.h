/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

#include "Controls.h"
#include "NotificationManager.h"


//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainContentComponent   :  public Component,
                                public Controls::Listener,
                                public NotificationManager::Listener

{
public:
    //==============================================================================
    MainContentComponent();
    ~MainContentComponent();

    void paint (Graphics&) override;
    void resized() override;
    
    virtual void notificationFinished (const NotificationMessage& message) override;
    virtual void messageButtonClicked (String message, int priority ) override;

private:
   
    ScopedPointer<Controls> controlWindow;
    ScopedPointer<NotificationManager> notificationManager;
    NotificationMessage::Ptr messageResult;
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};


#endif  // MAINCOMPONENT_H_INCLUDED
