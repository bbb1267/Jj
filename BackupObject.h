#pragma once
#include <string>

class BackupObject {
public:
    explicit BackupObject(const std::string& path);
    std::string GetPath() const;

private:
    std::string path_;
};