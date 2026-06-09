//main UI library
#include "raylib.h"

//util libraries
#include "UIXcalc.h"
#include "shapes.h"

#include <stdio.h>


int drew_rect(const rectangle *rect) {
    //Rectangle Itself
    DrawRectangle(
        rect->placement.grid_placement.x, rect->placement.grid_placement.y,
        rect->scale.x, rect->scale.y,
        rect->color);

    //Rectangle Border
    const Rectangle ang = {
        .x = rect->placement.grid_placement.x,
        .y = rect->placement.grid_placement.y,
        .width = rect->scale.x,
        .height = rect->scale.y
    };
    DrawRectangleLinesEx(
        ang,
        rect->border_size,
        rect->border_color);

    return rect2dS;
}

int drew_circle(const circle *circ) {
    //Circle Border
    DrawCircle(
        circ->placement.grid_placement.x, circ->placement.grid_placement.y,
        circ->radius + circ->border_size,
        circ->border_color);

    //Circle Itself
    DrawCircle(
        circ->placement.grid_placement.x, circ->placement.grid_placement.y,
        circ->radius,
        circ->color);

    return circle2dS;
}

//hope it works
int drew_button(const button *btn) {
    //Button Background
    DrawRectangle(
        btn->placement.grid_placement.x, btn->placement.grid_placement.y,
        btn->scale.x, btn->scale.y,
        btn->color);

    //Button Text (I hate this)
    const int text_size = MeasureText(btn->content, btn->font_size);
    const textbox tbox = {
        .placement = {
            .grid_placement = {
                .x = btn->placement.grid_placement.x + ((btn->scale.x - text_size) / 2),
                .y = btn->placement.grid_placement.y + ((btn->scale.y - btn->font_size) / 2),
            },
            .grid_size = btn->placement.grid_size
        },
        .font_size = btn->font_size,
        .color = btn->text_color,
        .content = btn->content,
    };
    drew_textbox(&tbox);

    //Button Border
    const Rectangle ang = {
        .x = btn->placement.grid_placement.x,
        .y = btn->placement.grid_placement.y,
        .width = btn->scale.x,
        .height = btn->scale.y
    };
    DrawRectangleLinesEx(
        ang,
        btn->border_size,
        btn->border_color);

    return button2dS;
}

int drew_textbox(const textbox *tbox) {
    DrawText(
        tbox->content,
        tbox->placement.grid_placement.x, tbox->placement.grid_placement.y,
        tbox->font_size,
        tbox->color);

    return textbox2dS;
}

int drew(const int shape, const void *data) {
    switch (shape) {
        case rect2dS:
            return drew_rect((rectangle *)data);

        case circle2dS:
            return drew_circle((circle *)data);

        case button2dS:
            return drew_button((button *)data);

        case textbox2dS:
            return drew_textbox((textbox *)data);

        default:
            return -1;
    }
}

int main() {
    InitWindow(1000, 1000, "content");
    SetTargetFPS(60);

    const button btn = {
        .placement = {
            .grid_placement = {450, 450},
            .grid_size = {0, 0}
        },
        .font_size = 36,
        .color = GRAY,
        .border_color = WHITE,
        .content = "Press Me",
        .border_size = 5,
        .scale = {200, 200},
        .text_color = BLACK,
        .clicked = false
    };

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        drew(button2dS, &btn);

        EndDrawing();
    }
    CloseWindow();
    return 0;
}