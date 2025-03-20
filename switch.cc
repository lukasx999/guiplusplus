#include "switch.hh"

Switch::Switch(int x, int y, int width, int height, float padding, Color color_bg, Color color_circle)
    : Element(x, y, width, height)
    , m_padding(std::clamp<float>(padding, 0.0, 0.9))
    , m_color_bg(color_bg)
    , m_color_circle(color_circle)
{}

Switch &Switch::update() {
    set_state();

    int switch_center_y   = m_rect.y + m_rect.height / 2.0;
    int circle_left_x     = m_rect.x + m_rect.width * 0.25;
    int circle_right_x    = m_rect.x + m_rect.width * 0.75;

    DrawCircle(
        circle_left_x,
        switch_center_y,
        m_rect.height / 2.0,
        m_color_bg
    );

    DrawCircle(
        circle_right_x,
        switch_center_y,
        m_rect.height / 2.0,
        m_color_bg
    );

    DrawRectangle(
        circle_left_x,
        m_rect.y,
        circle_right_x - circle_left_x,
        m_rect.height,
        m_color_bg
    );


    int radius = (m_rect.height / 2.0) * m_padding;

    static float x = 0.0;
    static float pos = circle_left_x;
    static int dir = 0; // 0 = left, 1 = right

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || x) {
        pos = dir
            ? Lerp(circle_right_x, circle_left_x, x)
            : Lerp(circle_left_x, circle_right_x, x);

        x += 0.05;
        if (x >= 1.0) {
            x = 0.0;
            dir = !dir;
        }
    }

    DrawCircle(
        pos,
        switch_center_y,
        radius,
        m_color_circle
    );


    return *this;
}

void Switch::set_state() {
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        m_state = !m_state;
}
