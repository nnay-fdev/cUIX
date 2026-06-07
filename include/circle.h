#pragma once

#include "raylib.h"
#include "vector.h"

typedef struct {
    vector2d position;

    Color color;
    Color border_color;

    int radius;
    int border_size;
} circle2d;