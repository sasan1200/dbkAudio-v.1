/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class DbkAudioAudioProcessorEditor  : public AudioProcessorEditor,
public Slider::Listener


{
public:
    DbkAudioAudioProcessorEditor (DbkAudioAudioProcessor&);
    ~DbkAudioAudioProcessorEditor() override;

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    
    
    void sliderValueChanged (Slider* slider) override;

private:
    
    Slider mGainSlider;
    
    DbkAudioAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DbkAudioAudioProcessorEditor)
};
