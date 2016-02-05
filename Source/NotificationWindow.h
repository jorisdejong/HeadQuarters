/*
  ==============================================================================

    NotificationWindow.h
    Created: 4 Feb 2016 12:09:24pm
    Author:  Joris

  ==============================================================================
*/

#ifndef NOTIFICATIONWINDOW_H_INCLUDED
#define NOTIFICATIONWINDOW_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "Controls.h"

class NotificationMessage
{
public:
    NotificationMessage(){}
    ~NotificationMessage(){}
    
    int result = 0;
    String message = String().empty;
    
    typedef std::shared_ptr<NotificationMessage> Ptr;
};

class NotificationManager;


class NotificationWindow    :   public Component,
                                public Button::Listener,
                                public Timer,
                                public ChangeListener
{
public:
    NotificationWindow(NotificationManager& parent, NotificationMessage& message_);
    ~NotificationWindow();

    void paint (Graphics&) override;
    void resized() override;

    virtual void buttonClicked (Button*) override;
    virtual void timerCallback() override;
    virtual void changeListenerCallback (ChangeBroadcaster* source) override;
   
    //different functions that will show the window with different options
    void showSimpleMessage(String message);
    void showOkMessage(String message);
    void showOkCancelMessage(String message);
    void dismissMessage();
    

    

private:
    void animateIn();
    
    NotificationManager& parent;
    
    NotificationMessage& message;
   
    //Label that shows the text
    ScopedPointer<Label> messageLabel;

    //to keep track of the time to auto-dismiss a message
    Time startTime;
    
    //a button to immediately dismiss the window
    ScopedPointer<Button> ok;
    ScopedPointer<Button> cancel;
   
    
    bool isDismissed = false;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (NotificationWindow)
};


#endif  // NOTIFICATIONWINDOW_H_INCLUDED
