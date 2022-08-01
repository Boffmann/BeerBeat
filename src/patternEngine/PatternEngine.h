#pragma once

#include <memory>
#include <thread>
#include <functional>
#include "IOutputDevice.h"
#include "Pattern.h"

class PatternEngine {

public:

    PatternEngine(std::function<bool()>);
    ~PatternEngine();
    int run_on_output_device();
    
private:

    std::shared_ptr<Pattern> _current_pattern;
    std::function<bool()> _should_update;
    std::atomic<bool> _running;

    void main_loop(const std::shared_ptr<IOutputDevice> output_device);
    void update_pattern();
};