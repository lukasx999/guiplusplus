#include <print>
#include <string>
#include <unordered_map>

#include <raylib.h>
#include <raymath.h>

constexpr int width = 1600;
constexpr int height = 900;

enum class ButtonState {
    Idle,
    Hover,
    Pressed,
};

struct ButtonStateAttribute {
    Color m_color_bg;
    Color m_color_text;

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

public:
    Button(
        int x, int y,
        int width, int height,
        ButtonAttributes attrs,
        std::string text
    )
        : m_rect(x, y, width, height)
        , m_attrs(attrs)
        , m_text(text)
    {}

    void update() {
        set_state();

        ButtonStateAttribute &attr = m_attrs.at(m_state);

        float padding = 0.3;

        int text_height = m_rect.height;
        int text_width = 1e9;
        while (text_width > m_rect.width - padding*m_rect.width) {
            text_height--;
            text_width = MeasureText(m_text.c_str(), text_height);
        }

        DrawRectangleRec(m_rect, attr.m_color_bg);
        DrawText(
            m_text.c_str(),
            m_rect.x + m_rect.width  / 2 - text_width  / 2.0,
            m_rect.y + m_rect.height / 2 - text_height / 2.0,
            text_height,
            attr.m_color_text);

    }

private:
    void set_state() {
        Vector2 mpos = GetMousePosition();

        m_state = ButtonState::Idle;
        if (CheckCollisionPointRec(mpos, m_rect))
            m_state = IsMouseButtonDown(MOUSE_BUTTON_LEFT)
                ? ButtonState::Pressed
                : ButtonState::Hover;
    }

};

int main() {

    ButtonAttributes btn1_attrs = {
        { ButtonState::Idle,    ButtonStateAttribute(GRAY, WHITE) },
        { ButtonState::Hover,   ButtonStateAttribute(BLUE, BLACK) },
        { ButtonState::Pressed, ButtonStateAttribute(RED, WHITE) },
    };

    int btn_w = 500, btn_h = 200;
    Button btn1(
        width / 2 - btn_w / 2,
        height / 2 - btn_h / 2,
        btn_w,
        btn_h,
        btn1_attrs,
        "A button!"
    );

    InitWindow(width, height, "UI");

    while (!WindowShouldClose()) {
        BeginDrawing();
        {
            ClearBackground(BLACK);

            btn1.update();

        }
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
