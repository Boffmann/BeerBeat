#pragma once

#include "IOutputDevice.h"
#include <gtkmm.h>

class DebugGui;

class DebugApplication : public IOutputDevice, public Gtk::Application {
public:
    static Glib::RefPtr<DebugApplication> create();
    void showPattern(const std::shared_ptr<const Pattern> pattern) override;

protected:
    DebugApplication();
    void on_activate() override;

private:
    void create_debugwindow();
    void on_hide_window(Gtk::Window* window);

    DebugGui* _gui;
};