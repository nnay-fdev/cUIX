#pragma once


#pragma region INCLUDE

#include "raylib.h"

#pragma endregion //INCLUDE


#pragma region GRID_DEPENDENCIES

typedef struct vector2d {
    double x;
    double y;
} vector2d;

typedef struct grid2d {
    vector2d grid_placement;
    vector2d grid_size;
} grid2d;

#pragma endregion //GRID_DEPENDENCIES

