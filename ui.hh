#pragma once

#include <print>

#include <raylib.h>
#include <raymath.h>

class Element {
protected:
    Rectangle m_rect;
public:
    Element(int x, int y, int width, int height)
    : m_rect(x, y, width, height)
    {}
};
