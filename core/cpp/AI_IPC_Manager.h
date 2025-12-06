#ifndef AI_IPC_MANAGER_H
#define AI_IPC_MANAGER_H

#include <string>
#include <vector>

class AI_IPC_Manager {
public:
    bool initializePythonEnvironment();
    
    bool requestMastering(const std::string& inputFilePath, const std::string& outputFilePath);
    
    bool requestStemSeparation(const std::string& inputFilePath, const std::vector<std::string>& stemsToExtract);

private:
    std::string m_pythonExecutablePath;
    
    int executePythonScript(const std::string& scriptName, const std::string& args);
};

#endif // AI_IPC_MANAGER_H
