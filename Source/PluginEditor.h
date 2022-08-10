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
class DSPTestAudioProcessorEditor  : 
    public juce::AudioProcessorEditor,
    public juce::Slider::Listener,
    public juce::ComboBox::Listener
{
public:
    DSPTestAudioProcessorEditor (DSPTestAudioProcessor&);
    ~DSPTestAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;


    void sliderValueChanged(juce::Slider* slider) override
    {
        if (slider == &mGain) 
        {
            audioProcessor.gain = mGain.getValue();

        }
        if (slider == &mFreq) 
        {
            audioProcessor.freq = mFreq.getValue();
        }
        if (slider == &mRes) 
        {
            audioProcessor.res = mRes.getValue();
        }
    }

    void comboBoxChanged(juce::ComboBox* box) 
    {
        audioProcessor.filtChoice = box->getSelectedId();
    }

private:
    juce::Slider mGain;
    juce::Slider mFreq;
    juce::Slider mRes;
    juce::ComboBox filterChoice;

    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    DSPTestAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DSPTestAudioProcessorEditor)
};
