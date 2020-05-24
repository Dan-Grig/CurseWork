#ifndef _FOE_H
#define _FOE_H

#include "gfx.h"
#include "vector_field.h"

// выводит точку в точке min (uv) на "big". "маленький" - это подсвязанное изображение,
// big - это несвязанное изображение.
void render_foe(struct image *small, struct image *big, 
                struct vector_field *uv);

#endif
