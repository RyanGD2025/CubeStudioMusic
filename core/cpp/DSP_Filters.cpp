#include "DSP_Filters.h"
#include <cmath>

void applyLowPassFilter(AudioBuffer& buffer, float cutoffFreq, int sampleRate) {
    static float a = 0.0f;
    float alpha = cutoffFreq * 2.0f * M_PI / sampleRate;
    
    if (alpha > 0.99f) { 
        alpha = 0.99f;
    }
    
    for (float& sample : buffer) {
        a = (alpha * sample) + (1.0f - alpha) * a;
        sample = a;
    }
}
