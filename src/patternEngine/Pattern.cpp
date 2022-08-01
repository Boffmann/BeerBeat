#include "Pattern.h"

Pattern::Pattern(): _color{0.1, 0.2, 0.4} {}

const struct Color& Pattern::get_color() const {
    return this->_color;
}

void Pattern::set_color(const Color color) {
    this->_color.red = color.red;
    this->_color.green = color.green;
    this->_color.blue = color.blue;
}