#ifndef _FOE_H
#define _FOE_H

#include "gfx.h"
#include "vector_field.h"

// ������� ����� � ����� min (uv) �� "big". "���������" - ��� ������������ �����������,
// big - ��� ����������� �����������.
void render_foe(struct image *small, struct image *big, 
                struct vector_field *uv);

#endif
