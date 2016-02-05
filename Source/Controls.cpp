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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "Controls.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
Controls::Controls ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (sendRegular = new TextButton ("Send Regular"));
    sendRegular->setConnectedEdges (Button::ConnectedOnRight);
    sendRegular->addListener (this);

    addAndMakeVisible (sendConfirm = new TextButton ("Send Confirm"));
    sendConfirm->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight);
    sendConfirm->addListener (this);

    addAndMakeVisible (sendOkCancel = new TextButton ("Send OKCancel"));
    sendOkCancel->setButtonText (TRANS("Send OkCancel"));
    sendOkCancel->setConnectedEdges (Button::ConnectedOnLeft);
    sendOkCancel->addListener (this);

    addAndMakeVisible (textEditor = new TextEditor ("message"));
    textEditor->setMultiLine (false);
    textEditor->setReturnKeyStartsNewLine (false);
    textEditor->setReadOnly (false);
    textEditor->setScrollbarsShown (true);
    textEditor->setCaretVisible (true);
    textEditor->setPopupMenuEnabled (true);
    textEditor->setText (TRANS("Message to send..."));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (580, 380);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

Controls::~Controls()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    sendRegular = nullptr;
    sendConfirm = nullptr;
    sendOkCancel = nullptr;
    textEditor = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void Controls::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void Controls::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    sendRegular->setBounds ((proportionOfWidth (0.8504f) + roundFloatToInt (proportionOfWidth (0.1004f) * -1.0000f)) + roundFloatToInt (proportionOfWidth (0.1004f) * -1.0000f), 56, proportionOfWidth (0.1004f), 24);
    sendConfirm->setBounds (proportionOfWidth (0.8504f) + roundFloatToInt (proportionOfWidth (0.1004f) * -1.0000f), 56, proportionOfWidth (0.1004f), 24);
    sendOkCancel->setBounds (proportionOfWidth (0.8504f), 56, proportionOfWidth (0.1004f), 24);
    textEditor->setBounds (8, 8, proportionOfWidth (1.0000f), 40);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void Controls::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    String message = textEditor->getText();
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == sendRegular)
    {
        //[UserButtonCode_sendRegular] -- add your button handler code here..
        Component::BailOutChecker checker (this);
        if (! checker.shouldBailOut())
            listeners.callChecked ( checker, &Controls::Listener::messageButtonClicked, (message == "Message to send...")? "A thing happened! Just so you know..." : message, 0 );

        //[/UserButtonCode_sendRegular]
    }
    else if (buttonThatWasClicked == sendConfirm)
    {
        //[UserButtonCode_sendConfirm] -- add your button handler code here..
        Component::BailOutChecker checker (this);
        if (! checker.shouldBailOut())
            listeners.callChecked ( checker, &Controls::Listener::messageButtonClicked, (message == "Message to send...")? "A thing happened! I want to be sure you know about it!" : message, 1 );

        //[/UserButtonCode_sendConfirm]
    }
    else if (buttonThatWasClicked == sendOkCancel)
    {
        //[UserButtonCode_sendOkCancel] -- add your button handler code here..
        Component::BailOutChecker checker (this);
        if (! checker.shouldBailOut())
            listeners.callChecked ( checker, &Controls::Listener::messageButtonClicked,  (message == "Message to send...")? "A thing happened! Do you want me to act on it?" : message, 2 );

        //[/UserButtonCode_sendOkCancel]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="Controls" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="580" initialHeight="380">
  <BACKGROUND backgroundColour="ffffff"/>
  <TEXTBUTTON name="Send Regular" id="29832b4b4013e74c" memberName="sendRegular"
              virtualName="" explicitFocusOrder="0" pos="0% 56 10.039% 24"
              posRelativeX="afd25e4358894d62" buttonText="Send Regular" connectedEdges="2"
              needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="Send Confirm" id="afd25e4358894d62" memberName="sendConfirm"
              virtualName="" explicitFocusOrder="0" pos="-1843.19% 56 10.039% 24"
              posRelativeX="7994e9eae6923fb2" buttonText="Send Confirm" connectedEdges="3"
              needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="Send OKCancel" id="7994e9eae6923fb2" memberName="sendOkCancel"
              virtualName="" explicitFocusOrder="0" pos="85.039% 56 10.039% 24"
              buttonText="Send OkCancel" connectedEdges="1" needsCallback="1"
              radioGroupId="0"/>
  <TEXTEDITOR name="message" id="6a121b00727b979f" memberName="textEditor"
              virtualName="" explicitFocusOrder="0" pos="8 8 100% 40" initialText="Message to send..."
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
