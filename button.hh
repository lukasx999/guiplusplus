#pragma once

#include <string>
#include <unordered_map>

#include <raylib.h>

#include "ui.hh"

enum class ButtonState {
    Idle,
    Hover,
    Pressed,
};

struct ButtonStateAttribute {
    Color m_color_bg;
    Color m_color_text;
    ButtonStateAttribute(Color color_bg, Color color_text);
};

typedef std::unordered_map<ButtonState, ButtonStateAttribute> ButtonAttributes;

class Button : public Element {
    ButtonState      m_state;
    ButtonAttributes m_attrs;
    std::string      m_text;
    float            m_padding;
    int              m_text_width, m_text_height;

public:
    Button(
        int x,
        int y,
        int width,
        int height,
        ButtonAttributes attrs,
        std::string text,
        float padding
    );
    bool clicked();
    ButtonState state();
    Button &update();

private:
    std::pair<int, int> calculate_text_size();
    void set_state();
};
