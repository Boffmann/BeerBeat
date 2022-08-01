#include "visualization.h"

#include "IOutputDevice.h"
#include "DebugApplication.h"

#include <gtkmm.h>
#include <thread>
#include <functional>

#include <iostream>

int _run_on_output_device(std::function<void(std::__1::shared_ptr<IOutputDevice>)> main_loop) {
    Glib::RefPtr<DebugApplication> application = DebugApplication::create();
    std::thread main_thread(std::bind(main_loop, application));
    main_thread.detach();
    return application->run();
}