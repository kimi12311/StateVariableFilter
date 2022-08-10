/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
DSPTestAudioProcessorEditor::DSPTestAudioProcessorEditor (DSPTestAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    //Visible
    addAndMakeVisible(mGain);
    addAndMakeVisible(mFreq);
    addAndMakeVisible(mRes);
    addAndMakeVisible(filterChoice);
    //Listeners
    mGain.addListener(this);
    mFreq.addListener(this);
    mRes.addListener(this);
    filterChoice.addListener(this);
    //Sets min, max and interval
    mGain.setRange(0, 10, 0.01f);
    mFreq.setRange(20, 20000, 1);
    mRes.setRange(0.1f, 8, 0.01f);

    filterChoice.addItem("HighPass", 1);
    filterChoice.addItem("LowPass", 2);
    filterChoice.addItem("BandPass", 3);


    setSize (400, 300);
}

DSPTestAudioProcessorEditor::~DSPTestAudioProcessorEditor()
{
}

//==============================================================================
void DSPTestAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
}

void DSPTestAudioProcessorEditor::resized()
{
    mGain.setBounds(100, 100, 200, 25);
    mFreq.setBounds(100, 150, 200, 25);
    mRes.setBounds(100, 200, 200, 25);
    filterChoice.setBounds(100, 250, 200, 25);
}


