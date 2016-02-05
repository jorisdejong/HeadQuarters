/*
  ==============================================================================

    NotificationManager.cpp
    Created: 4 Feb 2016 5:38:57pm
    Author:  Joris

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "NotificationManager.h"

//==============================================================================
NotificationManager::NotificationManager( int width )
{
    addToDesktop(ComponentPeer::windowIsTemporary);
    setAlwaysOnTop(true);

    setVisible(true);

    
    Rectangle<int> screenArea (Desktop::getInstance().getDisplays().getMainDisplay().userArea);
    setBounds(screenArea.removeFromRight(width));
  
}

NotificationManager::~NotificationManager()
{
}

void NotificationManager::paint (Graphics& g)
{
   
}

void NotificationManager::resized()
{
 

}

void NotificationManager::notificationFinished(NotificationWindow *window, const NotificationMessage& message)
{
    
    //let the listeners know
    Component::BailOutChecker checker (this);
    if (! checker.shouldBailOut())
        listeners.callChecked ( checker, &NotificationManager::Listener::notificationFinished, message );
    
    //clean up the object
    if ( notificationWindows.contains( window ))
        notificationWindows.removeObject( window );
    
    //erase message from our vector
    for (int i=0; i<messages.size();++i)
    {
        if (messages[i].get() == &message)
        {
            messages.erase(messages.begin()+i);
            break;
        }
    }
    
    //make sure there are no other animations still running
    if ( ! Desktop::getInstance().getAnimator().isAnimating() )
    {
        //go through the list of growls and position them correctly
        for ( int i = 0; i < notificationWindows.size(); i++ )
        {
            NotificationWindow* growl = notificationWindows[i];
            Rectangle<int> target ( 0, i * growlHeight, getWidth(), growlHeight );
            Desktop::getInstance().getAnimator().animateComponent(growl, target, 1.0, 250, false, 1.0, 0.1);
        }
    }
}

NotificationMessage::Ptr NotificationManager::showNotification(juce::String message, int priority)
{
    
    NotificationMessage::Ptr notificationMessage( new NotificationMessage() );
    messages.push_back( notificationMessage );
    
    //the NotificationWindow will delete itself once it's done
    NotificationWindow* growl = new NotificationWindow(*this, *notificationMessage);
    addAndMakeVisible(growl);

    
    //create the window at the bottom of the lowest current window
    int lowestY = 0;
    for ( int i = 0; i < notificationWindows.size(); i++ )
        lowestY = fmaxf(notificationWindows[i]->getBottom(),lowestY);
    growl->setBounds(0, lowestY, getWidth(), growlHeight );

    switch ( priority )
    {
        case 0:
            growl->showSimpleMessage( message );
            break;
        case 1:
            growl->showOkMessage( message );
            break;
        case 2:
            growl->showOkCancelMessage(message);
            break;
        default:
            break;
    }
    
    notificationWindows.add(growl);
    return notificationMessage;
}


