//Required Libraries
#include "screen_init.h"
#include "shapes.h"
#include "UIXcalc.h"
#include "raylib.h"

//Debug Libraries
#include "stdio.h"

#define GRID_SIZE_X conf.scale.x / conf.placement.row
#define GRID_SIZE_Y conf.scale.y / conf.placement.column


int drew_rect(const rectangle *rect, const screen_conf conf) {
    const double x_pos = rect->position.row * GRID_SIZE_X;
    const double y_pos = rect->position.column * GRID_SIZE_Y;

    //Rectangle
    DrawRectangle(
        x_pos,
        y_pos,
        rect->scale.x, rect->scale.y,
        rect->background_color);

    //Border
    const Rectangle r = {
        x_pos,
        y_pos,
        rect->scale.x, rect->scale.y,
    };
    DrawRectangleLinesEx(r, rect->border_size, rect->border_color);

    return rect2dS;
}

int drew_circle(const circle *circ, const screen_conf conf) {
    const double x_pos = circ->position.row * GRID_SIZE_X;
    const double y_pos = circ->position.column * GRID_SIZE_Y;

    //Border
    DrawCircle(
        x_pos,
        y_pos,
        circ->radius + circ->border_size,
        circ->border_color);

    //Circle
    DrawCircle(
        x_pos,
        y_pos,
        circ->radius,
        circ->background_color);

    return circle2dS;
}

int drew_text(const text *textbox, const screen_conf conf) {
    const double x_pos = textbox->position.row * GRID_SIZE_X;
    const double y_pos = textbox->position.column * GRID_SIZE_Y;

    //Text
    DrawText(
        textbox->content,
        x_pos,
        y_pos,
        textbox->font_size,
        textbox->text_color);

    return text2dS;
}

int drew_button(const button *btn, const screen_conf conf) {
    const double x_pos = btn->position.row * GRID_SIZE_X;
    const double y_pos = btn->position.column * GRID_SIZE_Y;

    //Background
    DrawRectangle(
        x_pos,
        y_pos,
        btn->scale.x, btn->scale.y,
        btn->background_color);

    //Border
    const Rectangle r = {
        x_pos,
        y_pos,
        btn->scale.x, btn->scale.y,
    };
    DrawRectangleLinesEx(r, btn->border_size, btn->border_color);

    //Text
    const int text_len = MeasureText(btn->content, btn->font_size);
    DrawText(
        btn->content,
        x_pos + ((btn->scale.x - text_len) / 2),
        y_pos + ((btn->scale.y - btn->font_size) / 2),
        btn->font_size,
        btn->foreground_color);

    return button2dS;
}

