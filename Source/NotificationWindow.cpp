/*
  ==============================================================================

    NotificationWindow.cpp
    Created: 4 Feb 2016 12:09:24pm
    Author:  Joris

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "NotificationWindow.h"
#include "NotificationManager.h"

//==============================================================================
NotificationWindow::NotificationWindow(NotificationManager& parent, NotificationMessage& message_) :
    parent ( parent ), message(message_)
{
    messageLabel = new Label();
    messageLabel->setText("No messages yet...", dontSendNotification);
    messageLabel->setColour(Label::textColourId, Colours::darkgrey);
    addAndMakeVisible(messageLabel);
    
    ok = new TextButton("Ok!");
    ok->addListener(this);
    addAndMakeVisible(ok);
    
    cancel = new TextButton("Nooo!");
    cancel->addListener(this);
    addChildComponent(cancel);
    
    Desktop::getInstance().getAnimator().addChangeListener(this);
}

NotificationWindow::~NotificationWindow()
{
    Desktop::getInstance().getAnimator().removeChangeListener(this);
    ok = nullptr;
    cancel = nullptr;
    messageLabel = nullptr;
}

void NotificationWindow::paint (Graphics& g)
{
    g.fillAll (Colours::lightgrey.withAlpha(0.85f));   // clear the background

    g.setColour (Colours::grey);
    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component
}

void NotificationWindow::resized()
{
    Rectangle<int> bounds ( getLocalBounds());
    Rectangle<int> rightSide (bounds.removeFromRight( proportionOfWidth(0.25)));
    messageLabel->setBounds(bounds.reduced(10));
    if ( cancel->isVisible() )
        cancel->setBounds(rightSide.removeFromTop( proportionOfHeight(0.5) ));
    ok->setBounds(rightSide);
}



void NotificationWindow::showSimpleMessage(juce::String message)
{
    messageLabel->setText(message, dontSendNotification);
    
    animateIn();
    
    //start a timer that will auto-dimiss the window
    startTime = Time::getCurrentTime();
    startTimer(100);
}

void NotificationWindow::showOkMessage(juce::String message)
{
    messageLabel->setText(message, dontSendNotification);
    
    //animate to the final position
    animateIn();
    
    //no autodismiss for this type of message
}

void NotificationWindow::showOkCancelMessage(juce::String message)
{
    messageLabel->setText(message, dontSendNotification);
    
    //add a cancel button
    cancel->setVisible( true );
    resized();
    
    //animate to the final position
    animateIn();
    
    //no autodismiss for this type of message
}

void NotificationWindow::animateIn()
{
    //place the window 100 pixels to the right
    setBounds(getBounds().translated(100, 0));
    
    //animate to the final position
    Desktop::getInstance().getAnimator().animateComponent(this, getBounds().translated(-100, 0), 1.0, 250, false, 1.0, 0.1);
}

void NotificationWindow::timerCallback()
{
    if (Time::getCurrentTime().toMilliseconds() > startTime.toMilliseconds() + 3000 )
        dismissMessage();
    
}

void NotificationWindow::dismissMessage()
{
    //animate the window 100 pixels to the right
    Rectangle<int> finalPosition(getBounds().translated(100, 0));
    Desktop::getInstance().getAnimator().animateComponent(this, finalPosition, 0.0, 500, false, 1.0, 1.0);
    
    //stop the timer, because the message has been dismmissed
    stopTimer();
    
    isDismissed = true;
}

void NotificationWindow::buttonClicked(juce::Button *b)
{
    if ( b == ok )
    {
        //if we had a cancel option
        //return 1 to let the listener know it needs to take action
        //else this is just the same as canceling
        if ( cancel->isVisible() )
            message.result = 1;
        else
            message.result = 0;
        dismissMessage();
    }
    
    else if ( b == cancel )
    {
        message.result = 0;
        dismissMessage();
    }
}

void NotificationWindow::changeListenerCallback(juce::ChangeBroadcaster *source)
{
    //this gets called when an animation has finished,
    //so if the message is also dismissed
    //we can safely delete the object
    if ( !Desktop::getInstance().getAnimator().isAnimating( this ) && isDismissed )
    {
        parent.notificationFinished(this, message);
    }
}