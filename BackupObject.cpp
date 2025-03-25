#include "BackupObject.h"

BackupObject::BackupObject(const std::string& path) : path_(path) {}

std::string BackupObject::GetPath() const {
    return path_;
}