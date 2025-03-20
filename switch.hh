#pragma once

#include <print>

#include <raylib.h>
#include <raymath.h>

#include "ui.hh"

class Switch : public Element {
    bool m_state;
public:
    Switch(int x, int y, int width, int height);
    Switch &update();
private:
    void set_state();
};
