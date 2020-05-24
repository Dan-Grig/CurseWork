#include <assert.h>
#include <stdlib.h>
#include "gfx.h"
#include "vector_field.h"
#include "optical_flow.h"

struct vector_field *compute_optical_flow(struct image *e,
                                          struct vector_field *d,
                                          float lambda, int nsteps)
{
   assert(e != NULL);
   assert(d != NULL);
   assert(d->xres == e->xres);
   assert(d->yres == e->yres);
   assert(nsteps > 1);

   struct vector_field *uv1 = new_vector_field(d->xres, d->yres);
   struct vector_field *uv2;

   uv2 = optical_flow_step(e, d, lambda, uv1);
   free_vector_field(uv1);
   nsteps--;

   if(nsteps % 2 != 0)
   {
      uv1 = optical_flow_step(e, d, lambda, uv2);
      free_vector_field(uv2);
      uv2 = uv1;
      nsteps--;
   }

   while(nsteps > 0)
   {
      uv1 = optical_flow_step(e, d, lambda, uv2);
      free_vector_field(uv2);
      uv2 = optical_flow_step(e, d, lambda, uv1);
      free_vector_field(uv1);
      nsteps -= 2;
   }
   return uv2;
}


struct vector_field *optical_flow_step(struct image *e, 
                                       struct vector_field *d, 
                                       float lambda, 
                                       struct vector_field *uvprev)
{
   assert(e != NULL);
   assert(d != NULL);
   assert(uvprev != NULL);
   assert(uvprev->xres == d->xres);
   assert(uvprev->yres == d->yres);
   assert(uvprev->xres == e->xres);
   assert(uvprev->yres == e->yres);

   struct vector_field *uvnext = new_vector_field(e->xres, e->yres);

   int k,l;
   for(k=0; k < uvprev->xres-1; k++)
   {
      for(l=0; l < uvprev->yres-1; l++)
      {
         float uavg, vavg;
         local_average(uvprev, k, l, &uavg, &vavg);
         float numerator = 
            (d->s[k][l].x * uavg) + 
            (d->s[k][l].y * vavg) + d->s[k][l].t;
         
         float denominator = 
            1 + lambda*(d->s[k][l].x*d->s[k][l].x + 
                        d->s[k][l].y*d->s[k][l].y);

         uvnext->s[k][l].x = uavg - (numerator/denominator)*d->s[k][l].x;
         uvnext->s[k][l].y = vavg - (numerator/denominator)*d->s[k][l].y;
      }
   }
   return uvnext;    
}

void local_average(struct vector_field *uv, int i, int j, 
                   float *uavg, float *vavg)
{
   
  
   assert(i < uv->xres-1);
   assert(j < uv->yres-1);

   
   if(i == 0)
   {

      
      if(j == 0)
      {
         *uavg = (1/2.0) * (uv->s[i][j+1].x + uv->s[i+1][j].x);
         *vavg = (1/2.0) * (uv->s[i][j+1].y + uv->s[i+1][j].y);
      }

      
      else if(j == uv->yres-2)
      {
         *uavg = (1/2.0) * (uv->s[i][j-1].x + uv->s[i+1][j].x);
         *vavg = (1/2.0) * (uv->s[i][j-1].y + uv->s[i+1][j].y);
      }

      
      else 
      {
         *uavg = (1/3.0)*(uv->s[i][j-1].x + uv->s[i][j+1].x + uv->s[i+1][j].x);
         *vavg = (1/3.0)*(uv->s[i][j-1].y + uv->s[i][j+1].y + uv->s[i+1][j].y);
      }
   }
   
   
   else if(i == uv->xres-2)
   {
      
      if(j == 0)
      {
         *uavg = (1/2.0) * (uv->s[i][j+1].x + uv->s[i-1][j].x);
         *vavg = (1/2.0) * (uv->s[i][j+1].y + uv->s[i-1][j].y);
      }

      
      else if(j == uv->yres-2)
      {
         *uavg = (1/2.0) * (uv->s[i][j-1].x + uv->s[i-1][j].x);
         *vavg = (1/2.0) * (uv->s[i][j-1].y + uv->s[i-1][j].y);
      }

      
      else 
      {
         *uavg = (1/3.0)*(uv->s[i][j-1].x + uv->s[i][j+1].x + uv->s[i-1][j].x);
         *vavg = (1/3.0)*(uv->s[i][j-1].y + uv->s[i][j+1].y + uv->s[i-1][j].y);
      }
   }

   
   else if(j == 0)
   {
      *uavg = (1/3.0)*(uv->s[i][j+1].x + uv->s[i+1][j].x + uv->s[i-1][j].x);
      *vavg = (1/3.0)*(uv->s[i][j+1].y + uv->s[i+1][j].y + uv->s[i-1][j].y);
   }

   
   else if(j == 0)
   {
      *uavg = (1/3.0)*(uv->s[i][j-1].x + uv->s[i+1][j].x + uv->s[i-1][j].x);
      *vavg = (1/3.0)*(uv->s[i][j-1].y + uv->s[i+1][j].y + uv->s[i-1][j].y);
   }

   else 
   {
      *uavg = (1/4.0)*(uv->s[i][j-1].x + uv->s[i+1][j].x + uv->s[i-1][j].x + uv->s[i][j+1].x);
      *vavg = (1/4.0)*(uv->s[i][j-1].y + uv->s[i+1][j].y + uv->s[i-1][j].y + uv->s[i][j+1].y);
   }
}
