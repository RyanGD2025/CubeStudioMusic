#ifndef AUDIO_SETTINGS_H
#define AUDIO_SETTINGS_H

namespace AudioConfig {
    const int DEFAULT_SAMPLE_RATE = 48000;

    const int PREFERRED_FRAMES_PER_BUFFER = 256; 
    const int MAX_TRACKS = 64; 
    using AudioSampleType = float; 
}

#endif // AUDIO_SETTINGS_H
