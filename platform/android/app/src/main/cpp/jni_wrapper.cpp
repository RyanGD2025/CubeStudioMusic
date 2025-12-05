#include <jni.h>
#include <memory>
#include "../../../../../core/cpp/AudioManager.h"

static std::unique_ptr<AudioManager> g_audioManager = nullptr;

extern "C" JNIEXPORT jboolean JNICALL
Java_com_cubemusic_studio_MainActivity_initializeAudioEngine(
        JNIEnv* env,
        jobject,
        jint sampleRate,
        jint framesPerBuffer) {

    if (!g_audioManager) {
        g_audioManager = std::make_unique<AudioManager>();
    }

    return g_audioManager->initialize(sampleRate, framesPerBuffer);
}

extern "C" JNIEXPORT void JNICALL
Java_com_cubemusic_studio_MainActivity_startPlayback(
        JNIEnv* env,
        jobject) {

    if (g_audioManager) {
        g_audioManager->startPlayback();
    }
}

extern "C" JNIEXPORT void JNICALL
Java_com_cubemusic_studio_MainActivity_stopPlayback(
        JNIEnv* env,
        jobject) {

    if (g_audioManager) {
        g_audioManager->stopPlayback();
    }
}

extern "C" JNIEXPORT void JNICALL
Java_com_cubemusic_studio_MainActivity_applyReverbToTrack(
        JNIEnv* env,
        jobject,
        jint trackId,
        jfloat dryWet) {
            
}
