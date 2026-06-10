#include "event_handler.h"
#include "shapes.h"
#include "screen_init.h"

int clicked(const int shape, const int mouse_btn, const screen_conf conf, const void *data) {
    const Vector2 mouse_pos = GetMousePosition();
    const bool mouse_pressed = IsMouseButtonPressed(mouse_btn);
    switch (shape) {
        case rect2dS: {
            const rectangle r = *(const rectangle *) data;
            const Rectangle rec = {
                .x = r.position.row * (conf.scale.x / conf.placement.row),
                .y = r.position.column * (conf.scale.x / conf.placement.column),
                .width = r.scale.x,
                .height = r.scale.y,
            };


            if (mouse_pressed && CheckCollisionPointRec(mouse_pos, rec))
                return 1;
            break;
        }

        case circle2dS: {
            const circle c = *(const circle *) data;
            const Vector2 circle_pos = {
                .x = c.position.row * (conf.scale.x / conf.placement.row),
                .y = c.position.column * (conf.scale.x / conf.placement.column),
            };

            if (mouse_pressed && CheckCollisionPointCircle(circle_pos, circle_pos, c.radius))
                return 1;
            break;
        }

        case text2dS: {
            const text t = *(const text *) data;

            const int horizontal_size = MeasureText(t.content, t.font_size);
            const int vertical_size = t.font_size;

            const Rectangle rec = {
                .x = t.position.row * (conf.scale.x / conf.placement.row),
                .y = t.position.column * (conf.scale.x / conf.placement.column),
                .width = horizontal_size,
                .height = vertical_size,
            };
            if (mouse_pressed && CheckCollisionPointRec(mouse_pos, rec))
                return 1;
            break;
        }
        default:
            return 0;
    }
    /*
     * looks like unreachable code right?
     * I put this here 'cause if not mouse pressed it came here
     * instead of writing "return 0;" I write it here
     * so the code is more tidy
     */
    return 0;
}