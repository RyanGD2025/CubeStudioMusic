#include <napi.h>
#include <memory>
#include "../../core/cpp/AudioManager.h"

static std::unique_ptr<AudioManager> g_audioManager = nullptr;


Napi::Value InitializeAudioEngine(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (!g_audioManager) {
        g_audioManager = std::make_unique<AudioManager>();
    }

    int sampleRate = info[0].As<Napi::Number>().Int32Value();
    int framesPerBuffer = info[1].As<Napi::Number>().Int32Value();

    bool result = g_audioManager->initialize(sampleRate, framesPerBuffer);
    
    return Napi::Boolean::New(env, result);
}


Napi::Value StartPlayback(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    
    if (g_audioManager) {
        g_audioManager->startPlayback();
    }

    return env.Undefined();
}

Napi::Value StopPlayback(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    
    if (g_audioManager) {
        g_audioManager->stopPlayback();
    }

    return env.Undefined();
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
    exports.Set(Napi::String::New(env, "initializeAudioEngine"),
                Napi::Function::New(env, InitializeAudioEngine));
    
    exports.Set(Napi::String::New(env, "startPlayback"),
                Napi::Function::New(env, StartPlayback));

    exports.Set(Napi::String::New(env, "stopPlayback"),
                Napi::Function::New(env, StopPlayback));

    return exports;
}

NODE_API_MODULE(audiocore_addon, Init)
