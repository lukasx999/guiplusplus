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
        .set_pos(50, 100)
        .set_text("button a")
        .build();

    Button b = ButtonBuilder()
        .set_pos(50, 400)
        .set_text("button b")
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

        }
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
