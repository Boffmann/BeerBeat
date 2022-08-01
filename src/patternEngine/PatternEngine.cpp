#include "PatternEngine.h"
#include "visualization.h"

#include <memory>
#include <chrono>
#include <thread>
#include <iostream>

PatternEngine::PatternEngine(std::function<bool()> should_update) : _running(true) {
    this->_should_update = should_update;
    _current_pattern = std::make_shared<Pattern>();
    Color new_color;
    new_color.red = 0;
    new_color.green = 0;
    new_color.blue = 0;
    _current_pattern->set_color(new_color);
}

PatternEngine::~PatternEngine() {
    this->_running = false;
}

void PatternEngine::main_loop(const std::shared_ptr<IOutputDevice> output_device) {

    // TODO Next Step redraw the screen on beats
    while (_running.load()) {
        if (this->_should_update()) {
            update_pattern();
            output_device->showPattern(_current_pattern);
            std::cout << "is_beat" << std::endl;
        } else {
            std::cout << "no_beat" << std::endl;
        }
    }

}

void PatternEngine::update_pattern() {
    if (_current_pattern->get_color().red == 255) {
        Color new_color;
        new_color.red = 0;
        new_color.green = 0;
        new_color.blue = 0;
        _current_pattern->set_color(new_color);
    } else {
        Color new_color;
        new_color.red = 255;
        new_color.green = 255;
        new_color.blue = 255;
        _current_pattern->set_color(new_color);
    }
}

int PatternEngine::run_on_output_device() {
    return _run_on_output_device(std::bind(&PatternEngine::main_loop, this, std::placeholders::_1));
}
