#ifndef DSP_FILTERS_H
#define DSP_FILTERS_H

#include <vector>

using AudioBuffer = std::vector<float>;

void applyLowPassFilter(AudioBuffer& buffer, float cutoffFreq, int sampleRate);

#endif // DSP_FILTERS_H
