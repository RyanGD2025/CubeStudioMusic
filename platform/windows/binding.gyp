{
    "targets": [
        {
            "target_name": "audiocore_addon",
            "sources": [
                "node_addon_wrapper.cpp",
                "../../core/cpp/AudioManager.cpp",
                "../../core/cpp/DSP_Filters.cpp"
            ],
            "include_dirs": [
                "<!@(node -p \"require('node-addon-api').include\")",
                "../../core/cpp"
            ],
            "dependencies": [
                "<!(node -p \"require('node-addon-api').gyp\")"
            ],
            "defines": [
                "NAPI_DISABLE_CPP_EXCEPTIONS"
            ]
        }
    ]
}
