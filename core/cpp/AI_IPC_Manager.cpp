#include "AI_IPC_Manager.h"
#include <cstdio>
#include <iostream>

bool AI_IPC_Manager::initializePythonEnvironment() {
    #ifdef _WIN32
        m_pythonExecutablePath = "python";
    #else
        m_pythonExecutablePath = "/usr/bin/python3";
    #endif
    return true; 
}

int AI_IPC_Manager::executePythonScript(const std::string& scriptName, const std::string& args) {
    std::string command = m_pythonExecutablePath + " ../core/python/" + scriptName + " " + args;
    
    int result = std::system(command.c_str());

    return result;
}

bool AI_IPC_Manager::requestMastering(const std::string& inputFilePath, const std::string& outputFilePath) {
    std::string args = "--task master --input " + inputFilePath + " --output " + outputFilePath;
    int result = executePythonScript("ai_runner.py", args);
    return result == 0;
}

bool AI_IPC_Manager::requestStemSeparation(const std::string& inputFilePath, const std::vector<std::string>& stemsToExtract) {
    std::string args = "--task separation --input " + inputFilePath;
    for (const auto& stem : stemsToExtract) {
        args += " --stem " + stem;
    }
    int result = executePythonScript("ai_runner.py", args);
    return result == 0;
}
