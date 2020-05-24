#include <stdlib.h>
#include "gfx.h"



struct image *new_image(int xres, int yres)
{
   int i;
   struct image *new = (struct image *)malloc(sizeof(struct image));
   new->xres = xres;
   new->yres = yres;
   new->s = (int **)malloc(new->xres*sizeof(int *));
   for(i=0; i < new->xres; i++)
   {
      new->s[i] = (int *)calloc((new->yres), sizeof(int));
//      for(j=0; j < new->yres; j++)
//      {
//         new->s[i][j] = 0;
//      }
      
   }
   return new;
}


void free_image(struct image *s)
{
   int i;

   for(i=0; i < s->xres; i++)
   {
      free(s->s[i]);
   }

   free(s->s);
   free(s);
}
