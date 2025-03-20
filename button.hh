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

class Button {
    Rectangle        m_rect;
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
    Button &operator()();

private:
    std::pair<int, int> calculate_text_size();
    void set_state();
};

class ButtonBuilder {
    Rectangle        m_rect;
    ButtonAttributes m_attrs;
    std::string      m_text;
    float            m_padding;
public:
    ButtonBuilder &set_x       (int x);
    ButtonBuilder &set_y       (int y);
    ButtonBuilder &set_width   (int width);
    ButtonBuilder &set_height  (int height);
    ButtonBuilder &set_text    (std::string text);
    ButtonBuilder &set_padding (float padding);
    Button build();
};
