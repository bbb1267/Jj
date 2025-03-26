#include "SplitStorage.h"
#include <filesystem>
#include <iostream>
#include <sstream>
#include <ctime>
#include <iomanip>

namespace fs = std::filesystem;

void SplitStorage::Save(const RestorePoint& point) {
    const std::string backupFolder = "BackupFolder";

    if (!fs::exists(backupFolder)) {
        fs::create_directory(backupFolder);
        std::cout << "Created backup folder: " << backupFolder << std::endl;
    }

    for (const auto& obj : point.GetObjects()) {
        std::string sourcePath = obj.GetPath();

        if (!fs::exists(sourcePath)) {
            std::cerr << "Source file does not exist: " << sourcePath << std::endl;
            continue;
        }

        std::string zipName = fs::path(obj.GetPath()).stem().string() + ".zip";
        std::string zipPath = backupFolder + "/" + zipName;

        std::stringstream zipCommand;

#ifdef _WIN32
        zipCommand << "powershell Compress-Archive -Path \"" << sourcePath
            << "\" -DestinationPath \"" << zipPath << "\"";
#else
        zipCommand << "zip -j \"" << zipPath << "\" \"" << sourcePath << "\"";
#endif

        int result = std::system(zipCommand.str().c_str());
        if (result != 0) {
            std::cerr << "Error creating zip archive for file: " << sourcePath << std::endl;
            continue;
        }

        time_t now = time(nullptr);
        std::tm localTime;
        localtime_s(&localTime, &now);
        std::cout << "File archived: " << zipPath << " at "
            << std::put_time(&localTime, "%Y-%m-%d %H:%M:%S") << std::endl;
    }
}