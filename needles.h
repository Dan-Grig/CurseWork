#ifndef _NEEDLES_H
#define _NEEDLES_H

#include "gfx.h"
#include "vector_field.h"

// рендерит иглы из УФ-излучения на "большие". "маленький" - это подсвязанное изображение,
// big - это несвязанное изображение.
void render_needles(struct image *small, struct image *big, 
                    struct vector_field *uv);

void draw_needle(struct image *im, int xstart, int ystart, int xend, int yend);

#define DOT_COLOR 0
#endif
