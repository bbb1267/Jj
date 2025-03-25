#include "SingleStorage.h"
#include <filesystem>
#include <iostream>
#include <fstream>

namespace fs = std::filesystem;

void SingleStorage::Save(const RestorePoint& point) {
    const std::string backupFolder = "BackupFolder";

    if (!fs::exists(backupFolder)) {
        fs::create_directory(backupFolder);
        std::cout << "Создана бэкап папка: " << backupFolder << std::endl;
    }

    const std::string singleBackupDir = backupFolder + "/SingleBackup";

    if (!fs::exists(singleBackupDir)) {
        if (!fs::create_directory(singleBackupDir)) {
            std::cerr << "Ошибка создания директории: " << singleBackupDir << std::endl;
            return;
        }
        std::cout << "Созданная директория: " << singleBackupDir << std::endl;
    }

    for (const auto& obj : point.GetObjects()) {
        std::string filePath = singleBackupDir + "/" + fs::path(obj.GetPath()).filename().string();

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
