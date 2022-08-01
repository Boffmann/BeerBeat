#pragma once

struct Color {
    float red;
    float green;
    float blue;
};

class Pattern {

public:
    Pattern();

    const struct Color& get_color() const;
    void set_color(const Color color);

private:
    struct Color _color;

};