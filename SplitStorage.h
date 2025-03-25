#pragma once
#include "IStorage.h"

class SplitStorage : public IStorage {
public:
    void Save(const RestorePoint& point) override;
};