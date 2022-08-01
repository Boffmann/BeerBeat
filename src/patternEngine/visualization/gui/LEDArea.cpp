#include "LEDArea.h"
#include <cairomm/context.h>

#include <iostream>

LEDArea::LEDArea() {
    set_draw_func(sigc::mem_fun(*this, &LEDArea::on_draw));
}

void LEDArea::draw_pattern(const std::shared_ptr<const Pattern> pattern) {
    _pattern = pattern;

    std::cout << "Color: " << _pattern->get_color().red << ";" << _pattern->get_color().red << ";" << _pattern->get_color().red << std::endl;
    queue_draw();
}

LEDArea::~LEDArea() {}

void LEDArea::on_draw(const Cairo::RefPtr<Cairo::Context>& cr, int width, int height) {
    if (_pattern == nullptr) {
        return;
    }
    // coordinates for the center of the window
    int xc, yc;
    xc = width / 2;
    yc = height / 2;

    cr->set_line_width(10.0);

    // draw red lines out from the center of the window
    cr->set_source_rgb(_pattern->get_color().red, _pattern->get_color().green, _pattern->get_color().blue);
    //cr->set_source_rgb(128,128,0);
    cr->move_to(0, 0);
    cr->line_to(xc, yc);
    cr->line_to(0, height);
    cr->move_to(xc, yc);
    cr->line_to(width, yc);
    cr->stroke();
}