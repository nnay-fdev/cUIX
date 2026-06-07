#pragma once

#include "vector.h"
#include "text.h"
#include "button.h"
#include "circle.h"
#include "rectangle.h"

typedef enum {
    rectangle,
    circle,
    text,
    button
} shapes;

void drew(const int shape, void* data);