#ifndef _DERIVATIVES_H
#define _DERIVATIVES_H


#include "vector_field.h"
#include "gfx.h"
// �������� ��� ����������� E1 � E2, ��� E2-���� ����� E1, �� ���������
// ��������� ���� Ex, Ey � Et, ������������ ��� � ��������� vector_field.

// ����������� ��������� ����������� � ������ ������� ����� E1 � E2, � ��������
// ����� �� ������� ����� ����, ��� ��������� � E1 � E2. ������� x � y
// �� ������������ ��������� ����� ����� ��, ��� E1 � E2, �� ��������� ������
// � ��������� ������� �������� ������������� ��������.

// �������� ����� ������ ��� ���������� ����. 
struct vector_field *compute_derivatives(struct image *e1, struct image *e2);

#endif
