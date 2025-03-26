#pragma once
#include "IStorage.h"

class SingleStorage : public IStorage {
public:
    void Save(const RestorePoint& point) override;
};
