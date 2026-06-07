#include "raylib.h"
#include "cuix.h"

void drew_rect(const rectangle2d* rect) {
    //Rectangle Itself
    DrawRectangle(
        rect->position.x, rect->position.y,
        rect->scale.x, rect->scale.y,
        rect->color);

    //Rectangle Border
    const Rectangle r = {
        rect->position.x, rect->position.y,
        rect->scale.x, rect->scale.y,
    };
    DrawRectangleLinesEx(
        r,
        rect->border_size,
        rect->border_color);
}
void drew_circle(const circle2d* circle) {
    //Circle Border
    DrawCircle(
        circle->position.x, circle->position.y,
        circle->radius + circle->border_size,
        circle->border_color);

    //Circle Itself
    DrawCircle(
        circle->position.x, circle->position.y,
        circle->radius,
        circle->color);
}
void drew_text(const text2d* text) {
    DrawText(
        text->content,
        text->position.x, text->position.y,
        text->font_size,
        text->text_color);
}
void drew_button(const button2d* button) {
    const rectangle2d rect = {
        .position = button->position,
        .scale = button->scale,
        .color = button->background_color,
        .border_size = button->border_size,
        .border_color = button->border_color
    };
    drew_rect(&rect);

    const int text_len = MeasureText(button->content, button->font_size);
    const text2d text = {
        .position = {
            .x = button->position.x + ((button->scale.x - text_len) / 2),
            .y = button->position.y + ((button->scale.y - button->font_size) / 2),
        },
        .font_size = button->font_size,
        .text_color = button->foreground_color,
        .content = button->content
    };
    drew_text(&text);
}

void drew(const int shape, void* data) {
    if (shape == rectangle) {
        const rectangle2d* rect = (rectangle2d*) data;
        drew_rect(rect);
    }
    else if (shape == circle) {
        const circle2d* circle = (circle2d*) data;
        drew_circle(circle);
    }
    else if (shape == text) {
        const text2d* text = (text2d*) data;
        drew_text(text);
    }
    else if (shape == button) {
        const button2d* button = (button2d*) data;
    }
}