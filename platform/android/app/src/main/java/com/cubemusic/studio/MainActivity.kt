package com.cubemusic.studio

import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent

class MainActivity : ComponentActivity() {

    companion object {
        init {
            System.loadLibrary("audiocore") 
        }
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContent {
            
        }
        
        val initialized = initializeAudioEngine(44100, 512)
        if (initialized) {
            startPlayback()
            
        }
    }
    
    private external fun initializeAudioEngine(sampleRate: Int, framesPerBuffer: Int): Boolean
    private external fun startPlayback()
    private external fun stopPlayback()
    private external fun applyReverbToTrack(trackId: Int, dryWet: Float)
    private external fun masterProject(inputPath: String, outputPath: String): Boolean
}
