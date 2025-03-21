#pragma once

#include <string>
#include <unordered_map>

#include <raylib.h>

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
    float m_padding = 0.3;
    int m_x = 0;
    int m_y = 0;
    ButtonAttributes m_attrs = {
        { ButtonState::Idle,    ButtonStateAttribute(GRAY, WHITE)      },
        { ButtonState::Hover,   ButtonStateAttribute(LIGHTGRAY, BLACK) },
        { ButtonState::Pressed, ButtonStateAttribute(BLUE, WHITE)      },
    };
    std::string m_text = "button";
public:
    ButtonBuilder &set_pos      (int x, int y);
    ButtonBuilder &set_text     (std::string text);
    ButtonBuilder &set_attribute(ButtonState state, ButtonStateAttribute attr);
    ButtonBuilder &set_padding  (float padding);
    Button build();
};
