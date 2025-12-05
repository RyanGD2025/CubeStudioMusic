#include "AudioManager.h"
#include "DSP_Filters.h"

bool AudioManager::initialize(int sampleRate, int framesPerBuffer) {
    m_sampleRate = sampleRate;
    return true; 
}

void AudioManager::processAudio(AudioBuffer& input, AudioBuffer& output) {
    output = input;
    applyLowPassFilter(output, 5000.0f, m_sampleRate);
}

bool AudioManager::loadAIModel(const char* modelPath) {
    return true;
}

void AudioManager::startPlayback() {
  
}

void AudioManager::stopPlayback() {
    
}

void AudioManager::applyEffect(int trackId, const char* effectName, float dryWet) {
    
}
