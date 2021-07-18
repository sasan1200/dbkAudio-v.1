/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
DbkAudioAudioProcessorEditor::DbkAudioAudioProcessorEditor (DbkAudioAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    //Slider Style
    mGainSlider.setSliderStyle (Slider::SliderStyle::LinearVertical);
    
    //Slider Text Style
    mGainSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 50 , 20);
    
    //Setting the Range
    mGainSlider.setRange (0.0f, 1.0f, 0.01f);
    
    //This is the default value that is initialized
    mGainSlider.setValue (0.5f);
    
    //Listner pointing to current audio processor editor/ this class
    mGainSlider.addListener (this);
    
    //Letting program know that mGainSlider is the child component of our Editor
    addAndMakeVisible (mGainSlider);
    
    //Plugin editor's size
    setSize (200, 300);
}
    

DbkAudioAudioProcessorEditor::~DbkAudioAudioProcessorEditor()
{
}

//==============================================================================
void DbkAudioAudioProcessorEditor::paint (Graphics& g)
{
    // Background set to black, Text set to white, Font set to 15, intialization message centered
    g.fillAll (Colours::black);
    g.setColour (Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Yeh Dast Balah        Yeh Dast Beh Kir!", getLocalBounds(), Justification::centred, 1);
}



void DbkAudioAudioProcessorEditor::resized()
{
    mGainSlider.setBounds (getWidth() / 2 - 50, getHeight() / 2 - 75, 100, 150);
}



void DbkAudioAudioProcessorEditor::sliderValueChanged (Slider* slider)
{
    if(slider == &mGainSlider)
    {
        audioProcessor.mGain = mGainSlider.getValue();
    }
}
