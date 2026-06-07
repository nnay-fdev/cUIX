#pragma once

#include "vector.h"
#include "raylib.h"

typedef struct {
    vector2d position;
    vector2d scale;

    Color background_color;
    Color foreground_color;
    Color border_color;

    int font_size;
    int border_size;

    char* content;

    bool clicked;
} button2d;