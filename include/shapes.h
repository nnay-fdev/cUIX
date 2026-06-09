#pragma once

#pragma region INCLUDE

#include "raylib.h"
#include "math.h"
#include "UIXcalc.h"

#pragma endregion //INCLUDE


#pragma region SHAPES

typedef struct rectangle {
    grid2d placement;
    vector2d scale;

    Color color;
    Color border_color;

    int border_size;
} rectangle;

typedef struct circle {
    grid2d placement;

    Color color;
    Color border_color;

    int radius;
    int border_size;
} circle;

typedef struct button {
    grid2d placement;
    vector2d scale;

    Color color;
    Color border_color;
    Color text_color;

    int font_size;
    int border_size;
    int clicked;

    const char *content;
} button;

typedef struct textbox {
    grid2d placement;

    Color color;

    int font_size;
    const char *content;
} textbox;

#pragma endregion //SHAPES


#pragma region SHAPE_ENUM

typedef enum shapes {
    rect2dS,
    circle2dS,
    button2dS,
    textbox2dS
} shapes;

#pragma endregion //SHAPE_ENUM


#pragma region FUNCTIONS

int drew_rect(const rectangle *rect);
int drew_circle(const circle *circ);
int drew_button(const button *btn);
int drew_textbox(const textbox *tbox);

int drew(const int shape, const void *data);

#pragma endregion //FUNCTIONS