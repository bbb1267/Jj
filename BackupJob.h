#pragma once
#include "IStorage.h"
#include "BackupObject.h"
#include "RestorePoint.h"
#include <vector>
#include <memory>

class BackupJob {
public:
    explicit BackupJob(std::unique_ptr<IStorage> storage);
    void AddObject(const BackupObject& object);
    void RemoveObject(const std::string& path);
    void CreateRestorePoint();

private:
    std::vector<BackupObject> objects_;
    std::vector<RestorePoint> restorePoints_;
    std::unique_ptr<IStorage> storage_;
};