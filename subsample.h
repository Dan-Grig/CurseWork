#ifndef _SUBSAMPLE_H
#define _SUBSAMPLE_H

#include "gfx.h"

// �������� ����� (�������) �����������, ���������� �������
// �->xres ������ ���� ������ xres, � S->��� ��� ������ ���� 
// ������ yres
struct image *subsample(struct image *s, int xres, int yres);


#endif
