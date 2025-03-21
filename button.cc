#include <string>
#include <print>

#include <raylib.h>
#include <raymath.h>

#include "button.hh"



Button::Button(
    int x,
    int y,
    int text_height,
    ButtonAttributes attrs,
    std::string text,
    float padding
)
    : m_attrs       (attrs)
    , m_text        (text)
    , m_state       (ButtonState::Idle)
    , m_padding     (std::clamp<float>(padding, 0.0, std::numeric_limits<float>::max()))
    , m_text_height (text_height)
    , m_text_width  (MeasureText(m_text.c_str(), m_text_height))
    , m_rect        (x, y, m_text_width * (1 + m_padding), m_text_height * (1 + m_padding))
{}

bool Button::clicked() {
    return m_state == ButtonState::Pressed
    && IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
}

ButtonState Button::state() {
    return m_state;
}

Button &Button::operator()() {
    set_state();

    ButtonStateAttribute &attr = m_attrs.at(m_state);

    DrawRectangleRec(m_rect, attr.m_color_bg);
    DrawText(
        m_text.c_str(),
        m_rect.x + m_rect.width  / 2 - m_text_width  / 2.0,
        m_rect.y + m_rect.height / 2 - m_text_height / 2.0,
        m_text_height,
        attr.m_color_text
    );

    return *this;
}

void Button::set_state() {
    Vector2 mpos = GetMousePosition();

    m_state = ButtonState::Idle;
    if (CheckCollisionPointRec(mpos, m_rect))
        m_state = IsMouseButtonDown(MOUSE_BUTTON_LEFT)
            ? ButtonState::Pressed
            : ButtonState::Hover;
}



ButtonBuilder &ButtonBuilder::set_pos(int x, int y) {
    m_x = x;
    m_y = y;
    return *this;
}

ButtonBuilder &ButtonBuilder::set_text_height(int text_height) {
    m_text_height = text_height;
    return *this;
}

ButtonBuilder &ButtonBuilder::set_attribute(
    ButtonState state,
    ButtonStateAttribute attr
) {
    m_attrs.insert_or_assign(state, attr);
    return *this;
}

ButtonBuilder &ButtonBuilder::set_text(std::string text) {
    m_text = text;
    return *this;
}

ButtonBuilder &ButtonBuilder::set_padding(float padding) {
    m_padding = padding;
    return *this;
}

Button ButtonBuilder::build() {
    return Button(m_x, m_y, m_text_height, m_attrs, m_text, m_padding);
}
