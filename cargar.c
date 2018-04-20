#include <stdlib.h>
#include "cargar.h"
void initvUsuarios(vUsuarios* v)
{
   v->user = initUsuarios(&v->tam);
}
void savevUsuarios(vUsuarios* v)
{
  saveUsuarios(v->tam,v->user);
  v->tam = 0;
  free(v->user);
}
