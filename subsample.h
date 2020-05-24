#ifndef _SUBSAMPLE_H
#define _SUBSAMPLE_H

#include "gfx.h"

// выделяет новое (меньшее) изображение, содержащее образцы
// с->xres должно быть кратно xres, и S->ряд шин должны быть 
// кратно yres
struct image *subsample(struct image *s, int xres, int yres);


#endif
