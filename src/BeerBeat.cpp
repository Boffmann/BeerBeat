#include <memory>
#include "patternEngine/PatternEngine.h"

#include <iostream>
#include <chrono>

bool beat = true;

bool is_beat() {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    beat = !beat;
    return beat;
}

int main(int argc, char** argv) {
    PatternEngine patternEngine(&is_beat);
    patternEngine.run_on_output_device();
}
