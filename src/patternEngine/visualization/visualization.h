#pragma once

#include <memory>
#include <functional>
#include "IOutputDevice.h"

int _run_on_output_device(std::function<void(std::__1::shared_ptr<IOutputDevice>)> main_loop);