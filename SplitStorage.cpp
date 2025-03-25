#include "SplitStorage.h"
#include <filesystem>
#include <iostream>
#include <fstream>

namespace fs = std::filesystem;

void SplitStorage::Save(const RestorePoint& point) {
    const std::string backupFolder = "BackupFolder";

    if (!fs::exists(backupFolder)) {
        fs::create_directory(backupFolder);
        std::cout << "Создана бэкап папка: " << backupFolder << std::endl;
    }

    for (const auto& obj : point.GetObjects()) {
        std::ostringstream dirPath;
        dirPath << backupFolder << "/" << fs::path(obj.GetPath()).stem().string();

        if (!fs::exists(dirPath.str())) {
            if (!fs::create_directory(dirPath.str())) {
                std::cerr << "Ошибка создания директории: " << dirPath.str() << std::endl;
                continue;
            }
            std::cout << "Созданная директория: " << dirPath.str() << std::endl;
        }

        std::string filePath = dirPath.str() + "/" + fs::path(obj.GetPath()).filename().string();

        try {
            std::ofstream outFile(filePath, std::ios::binary);
            if (!outFile) {
                std::cerr << "Ошибка создания файла: " << filePath << std::endl;
                continue;
            }

            outFile << "Файл " << obj.GetPath() << " создан";
            std::cout << "Созданный файл: " << filePath << std::endl;
        }
        catch (const std::exception& e) {
            std::cerr << "Ошибка записи файла " << obj.GetPath() << ": " << e.what() << std::endl;
        }
    }
}
