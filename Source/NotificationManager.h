/*
  ==============================================================================

    NotificationManager.h
    Created: 4 Feb 2016 5:38:57pm
    Author:  Joris

  ==============================================================================
*/

#ifndef NOTIFICATIONMANAGER_H_INCLUDED
#define NOTIFICATIONMANAGER_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

#include "NotificationWindow.h"



//==============================================================================
/*
*/
class NotificationManager    :  public Component

{
public:
    NotificationManager( int width );
    ~NotificationManager();

    void paint (Graphics&) override;
    void resized() override;
    
    void notificationFinished (NotificationWindow* window, const NotificationMessage& message );
    
    //Message is the string to display
    //Priority expects a value between 0-2
    //0 auto dismisses after a fixed time (3 seconds)
    //1 requires a confirmation
    //2 gives an ok and cancel option, and will trigger a callback from this object
    NotificationMessage::Ptr showNotification ( String message, int priority );
    
    class JUCE_API  Listener
    {
    public:
        /** Destructor. */
        virtual ~Listener()  {}
        
        /** Called when the button is clicked. */
        virtual void notificationFinished (const NotificationMessage& message ) = 0;
    };
    
    void addListener (Listener* newListener) { listeners.add(newListener); }
    void removeListener (Listener* listener) { listeners.remove(listener); }

private:
    int growlHeight = 100;
    OwnedArray<NotificationWindow> notificationWindows;
    std::vector< NotificationMessage::Ptr > messages;
    ListenerList<Listener> listeners;
    
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (NotificationManager)
};


#endif  // NOTIFICATIONMANAGER_H_INCLUDED
