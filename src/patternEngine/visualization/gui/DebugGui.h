#pragma once

#include <gtkmm.h>
#include "LEDArea.h"
#include "Pattern.h"

class DebugGui : public Gtk::ApplicationWindow  {
public:
    DebugGui();
    ~DebugGui();
    void draw_pattern(const std::shared_ptr<const Pattern> pattern);

private:
    void on_update_notification();

    LEDArea m_ledArea;
    std::shared_ptr<const Pattern> _pattern;
    Glib::Dispatcher _dispatcher;
};
