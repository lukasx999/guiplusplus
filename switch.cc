#include "switch.hh"

Switch::Switch(int x, int y, int width, int height)
: Element(x, y, width, height)
{}

Switch &Switch::update() {
    int switch_center_y   = m_rect.y + m_rect.height / 2.0;
    int circle_left_x     = m_rect.x + m_rect.width * 0.25;
    int circle_right_x    = m_rect.x + m_rect.width * 0.75;
    Color switch_color_bg = BLUE;

    DrawCircle(
        circle_left_x,
        switch_center_y,
        m_rect.height / 2.0,
        switch_color_bg
    );

    DrawCircle(
        circle_right_x,
        switch_center_y,
        m_rect.height / 2.0,
        switch_color_bg
    );

    DrawRectangle(
        circle_left_x,
        m_rect.y,
        circle_right_x - circle_left_x,
        m_rect.height,
        switch_color_bg
    );



    DrawCircle(
        circle_left_x,
        switch_center_y,
        50.0,
        RED
    );

    DrawCircle(
        circle_right_x,
        switch_center_y,
        50.0,
        RED
    );

    return *this;
}

void Switch::set_state() {
}
