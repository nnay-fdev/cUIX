#pragma once

#include "screen_init.h"
#include "UIXcalc.h"
#include "raylib.h"


typedef struct {
    grid position;
    vector2d scale;

    Color background_color;
    Color border_color;

    int border_size;
} rectangle;

typedef struct {
    grid position;

    Color background_color;
    Color border_color;

    int radius;
    int border_size;
} circle;

typedef struct {
    grid position;

    Color text_color;

    int font_size;

    const char *content;
} text;

typedef struct {
    grid position;
    vector2d scale;

    Color background_color;
    Color foreground_color;
    Color border_color;

    int border_size;
    int font_size;

    const char *content;
} button;


typedef enum {
    rect2dS,
    circle2dS,
    text2dS,
    button2dS
} shapes;

int drew_rect(const rectangle *rect, const screen_conf conf);
int drew_circle(const circle *circ, const screen_conf conf);
int drew_text(const text *textbox, const screen_conf conf);
int drew_button(const button *btn, const screen_conf conf);

int drew(const int shape, const screen_conf conf, void *data);