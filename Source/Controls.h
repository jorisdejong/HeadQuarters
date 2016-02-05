/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 4.1.0

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

#ifndef __JUCE_HEADER_7E49606CC1E6A40__
#define __JUCE_HEADER_7E49606CC1E6A40__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class Controls  : public Component,
                  public ButtonListener
{
public:
    //==============================================================================
    Controls ();
    ~Controls();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    class JUCE_API  Listener
    {
    public:
        /** Destructor. */
        virtual ~Listener()  {}
        
        /** Called when the button is clicked. */
        virtual void messageButtonClicked (String message, int priority ) = 0;
    };
    
    void addListener (Listener* newListener) { listeners.add(newListener); }
    void removeListener (Listener* listener) { listeners.remove(listener); }
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void buttonClicked (Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    ListenerList<Listener> listeners;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<TextButton> sendRegular;
    ScopedPointer<TextButton> sendConfirm;
    ScopedPointer<TextButton> sendOkCancel;
    ScopedPointer<TextEditor> textEditor;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Controls)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_7E49606CC1E6A40__
