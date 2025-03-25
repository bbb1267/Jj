#pragma once
#include "RestorePoint.h"

class IStorage {
public:
    virtual void Save(const RestorePoint& point) = 0;
    virtual ~IStorage() = default;
};