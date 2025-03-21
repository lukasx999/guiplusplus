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
public:
    ButtonStateAttribute(Color color_bg, Color color_text)
        : m_color_bg(color_bg)
        , m_color_text(color_text)
    {}
};

typedef std::unordered_map<ButtonState, ButtonStateAttribute> ButtonAttributes;

class Button : public UiElement {
    ButtonAttributes m_attrs;
    std::string      m_text;
    ButtonState      m_state;
    float            m_padding;
    int              m_text_height;
    int              m_text_width;
    Rectangle        m_rect;

public:
    Button(
        int x,
        int y,
        int text_height,
        ButtonAttributes attrs,
        std::string text,
        float padding
    );
    bool clicked();
    ButtonState state();
    Button &operator()();

private:
    void set_state();
};



class ButtonBuilder {
    float m_padding = 0.3;
    int m_x = 0;
    int m_y = 0;
    int m_text_height = 50;
    ButtonAttributes m_attrs = {
        { ButtonState::Idle,    ButtonStateAttribute(GRAY, WHITE)      },
        { ButtonState::Hover,   ButtonStateAttribute(LIGHTGRAY, BLACK) },
        { ButtonState::Pressed, ButtonStateAttribute(BLUE, WHITE)      },
    };
    std::string m_text = "button";

public:
    ButtonBuilder &set_pos        (int x, int y);
    ButtonBuilder &set_text_height(int text_height);
    ButtonBuilder &set_text       (std::string text);
    ButtonBuilder &set_attribute  (ButtonState state, ButtonStateAttribute attr);
    ButtonBuilder &set_padding    (float padding);
    Button build();
};
