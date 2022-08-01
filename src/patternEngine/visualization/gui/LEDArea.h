#pragma once

#include <gtkmm/drawingarea.h>
#include <memory>
#include "Pattern.h"

class LEDArea : public Gtk::DrawingArea {

public:
    LEDArea();
    virtual ~LEDArea();
    void draw_pattern(const std::shared_ptr<const Pattern> pattern);


protected:
    void on_draw(const Cairo::RefPtr<Cairo::Context>& cr, int width, int height);

private:
    std::shared_ptr<const Pattern> _pattern;
};