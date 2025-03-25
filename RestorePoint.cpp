#include "RestorePoint.h"
#include <ctime>

RestorePoint::RestorePoint(const std::vector<BackupObject>& objects) : objects_(objects) {
    time_t now = time(nullptr);
    char buffer[26];
    ctime_s(buffer, sizeof(buffer), &now);
    creationTime_ = buffer;
}

std::string RestorePoint::GetCreationTime() const {
    return creationTime_;
}

const std::vector<BackupObject>& RestorePoint::GetObjects() const {
    return objects_;
}