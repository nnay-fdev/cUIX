#include "screen_init.h"

void init_screen(const screen_conf *sc) {
    InitWindow(sc->scale.x, sc->scale.y, sc->title);
}
screen_conf init_screen_ex(const double size_x, const double size_y, const int rows, const int columns, const char *title) {
    const screen_conf sc = {
        .scale = {size_x, size_y},
        .placement = {rows, columns},
        .title = title
    };
    init_screen(&sc);
    return sc;
}
void close_screen() {
    CloseWindow();
}