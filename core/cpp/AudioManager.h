#ifndef AUDIOMANAGER_H
#define AUDIOMANAGER_H

#include <cstdint>
#include <vector>

using AudioBuffer = std::vector<float>;

class AudioManager {
public:
    bool initialize(int sampleRate, int framesPerBuffer);
    void processAudio(AudioBuffer& input, AudioBuffer& output);
    bool loadAIModel(const char* modelPath);
    void startPlayback();
    void stopPlayback();
    void applyEffect(int trackId, const char* effectName, float dryWet);

private:
    int m_sampleRate;
    void* m_aiProcessorHandle = nullptr; 
};

#endif // AUDIOMANAGER_H
