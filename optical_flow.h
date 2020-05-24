#ifndef _OPTICAL_FLOW_H
#define _OPTICAL_FLOW_H

struct vector_field *compute_optical_flow(struct image *e,
                                          struct vector_field *d,
                                          float lambda, int nsteps);

// ������� ������: �����������, ��������� ���� a, ���������� ����������� (ex, ey, et),
// a �������� ������, � ����� ���������� ��������� u � v (� �������
// ������� ��������� " uvprev")
struct vector_field * optical_flow_step(struct image *e, struct vector_field *d, 
                                        float lambda, struct vector_field *uvprev);
 

// ��������� ������� �������� u � v � ����� i � j. 
void local_average(struct vector_field *uv, int i, int j,
                   float *uavg, float *vavg);


#endif
