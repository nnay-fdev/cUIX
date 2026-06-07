#pragma once

#include "vector.h"
#include "raylib.h"

typedef struct {
    vector2d position;

    Color text_color;

    char* content;
    int font_size;
} text2d;