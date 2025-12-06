#include <iostream>
#include <vector>
#include "../DSP_Filters.h"

bool run_test(const char* testName, bool condition) {
    if (condition) {
        return true;
    } else {
        return false;
    }
}

bool test_low_pass_filter() {
    std::vector<float> buffer = {1.0f, 1.0f, 1.0f, 1.0f, 1.0f};
    int sampleRate = 48000;
    float cutoffFreq = 100.0f;

    applyLowPassFilter(buffer, cutoffFreq, sampleRate);
    
    bool start_ok = (buffer[0] > 0.9f);
    
    bool attenuation_ok = (buffer.back() < 0.9f); 

    return run_test("LowPassAttenuation", start_ok && attenuation_ok);
}

int main() {
    int passed = 0;
    int failed = 0;

    if (test_low_pass_filter()) {
        passed++;
    } else {
        failed++;
    }
    
    return (failed > 0);
}
