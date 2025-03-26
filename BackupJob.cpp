#include "BackupJob.h"

BackupJob::BackupJob(std::unique_ptr<IStorage> storage)
    : storage_(std::move(storage)) {}

void BackupJob::AddObject(const BackupObject& object) {
    objects_.push_back(object);
}

void BackupJob::RemoveObject(const std::string& path) {
    objects_.erase(std::remove_if(objects_.begin(), objects_.end(),
        [&path](const BackupObject& obj) { return obj.GetPath() == path; }),
        objects_.end());
}

void BackupJob::CreateRestorePoint() {
    RestorePoint point(objects_);
    restorePoints_.push_back(point);
    storage_->Save(point);
}