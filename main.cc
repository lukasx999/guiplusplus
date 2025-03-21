#include <print>
#include <string>

#include <raylib.h>
#include <raymath.h>

#include "button.hh"
#include "switch.hh"

constexpr int width  = 1600;
constexpr int height = 900;


int main() {

    SetTraceLogLevel(LOG_ERROR);
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(width, height, "UI");
    SetTargetFPS(60);

    Button a = ButtonBuilder()
        .set_pos(300, 100)
        .set_padding(0.1)
        .set_text("button a")
        .build();

    Button b = ButtonBuilder()
        .set_pos(300, 400)
        .set_padding(2)
        .set_text("button b")
        .build();

    Button c = ButtonBuilder()
        .set_pos(300, 700)
        .set_padding(0.5)
        .set_text("button c")
        .build();

    while (!WindowShouldClose()) {
        BeginDrawing();
        {
            ClearBackground(BLACK);

            if (a().clicked()) {
                std::println("a was clicked!");
            }

            if (b().clicked()) {
                std::println("b was clicked!");
            }

            c();

        }
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
