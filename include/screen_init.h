#pragma once


#include "raylib.h"
#include "UIXcalc.h"


typedef struct {
    vector2d scale;
    grid placement;

    const char *title;
} screen_conf;

void init_screen(const screen_conf *sc);
screen_conf init_screen_ex(const double size_x, const double size_y, const int rows, const int columns, const char *title);
void close_screen();
