#include "SingleStorage.h"
#include <filesystem>
#include <iostream>
#include <sstream>
#include <ctime>
#include <iomanip>

namespace fs = std::filesystem;

void SingleStorage::Save(const RestorePoint& point) {
    const std::string backupFolder = "BackupFolder";

    if (!fs::exists(backupFolder)) {
        fs::create_directory(backupFolder);
        std::cout << "Created backup folder: " << backupFolder << std::endl;
    }

    const std::string zipPath = backupFolder + "/SingleBackup.zip";

    std::stringstream zipCommand;
    bool firstFile = true;

    for (const auto& obj : point.GetObjects()) {
        std::string sourcePath = obj.GetPath();

        if (!fs::exists(sourcePath)) {
            std::cerr << "Source file does not exist: " << sourcePath << std::endl;
            continue;
        }

#ifdef _WIN32
        if (firstFile) {
            zipCommand << "powershell Compress-Archive -Path \"" << sourcePath
                << "\" -DestinationPath \"" << zipPath << "\"";
            firstFile = false;
        }
        else {
            zipCommand << " ; powershell Compress-Archive -Path \"" << sourcePath
                << "\" -Update -DestinationPath \"" << zipPath << "\"";
        }
#else
        if (firstFile) {
            zipCommand << "zip -j \"" << zipPath << "\" \"" << sourcePath << "\"";
            firstFile = false;
        }
        else {
            zipCommand << " && zip -j -u \"" << zipPath << "\" \"" << sourcePath << "\"";
        }
#endif
    }

    int result = std::system(zipCommand.str().c_str());
    if (result != 0) {
        std::cerr << "Error creating/updating zip archive" << std::endl;
        return;
    }

    time_t now = time(nullptr);
    std::tm localTime;
    localtime_s(&localTime, &now);
    std::cout << "Backup created in: " << zipPath << " at "
        << std::put_time(&localTime, "%Y-%m-%d %H:%M:%S") << std::endl;
}