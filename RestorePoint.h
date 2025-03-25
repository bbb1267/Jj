#pragma once
#include <vector>
#include <string>
#include "BackupObject.h"

class RestorePoint {
public:
    explicit RestorePoint(const std::vector<BackupObject>& objects);
    std::string GetCreationTime() const;
    const std::vector<BackupObject>& GetObjects() const;

private:
    std::string creationTime_;
    std::vector<BackupObject> objects_;
};