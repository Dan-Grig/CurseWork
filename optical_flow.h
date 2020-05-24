#ifndef _OPTICAL_FLOW_H
#define _OPTICAL_FLOW_H

struct vector_field *compute_optical_flow(struct image *e,
                                          struct vector_field *d,
                                          float lambda, int nsteps);

// входные данные: изображение, векторное поле a, содержащее производные (ex, ey, et),
// a параметр лямбда, а также предыдущие настройки u и v (в векторе
// полевая структура " uvprev")
struct vector_field * optical_flow_step(struct image *e, struct vector_field *d, 
                                        float lambda, struct vector_field *uvprev);
 

// локальное среднее значение u и v в точке i и j. 
void local_average(struct vector_field *uv, int i, int j,
                   float *uavg, float *vavg);


#endif
