#pragma once

#include <memory>
#include "Pattern.h"

class IOutputDevice {

public:
    virtual ~IOutputDevice() = 0;
    virtual void showPattern(const std::shared_ptr<const Pattern> pattern) = 0;
};
inline IOutputDevice::~IOutputDevice() {}
