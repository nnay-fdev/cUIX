#pragma once

#include "raylib.h"
#include "vector.h"

typedef struct {
    vector2d position;
    vector2d scale;

    Color color;
    Color border_color;

    int border_size;
} rectangle2d;

