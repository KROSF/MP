#include <stdlib.h>
#include "cargar.h"
static void initvUsuarios(vUsuarios* v)
{
   v->user = initUsuarios(&v->tam);
}
static void savevUsuarios(vUsuarios* v)
{
  saveUsuarios(v->tam,v->user);
  v->tam = 0;
  free(v->user);
}
static void initvIncidencias(vIncidencias* i)
{
    i->inci = initIncidencias(&i->tam);
}
static void savevIncidencias(vIncidencias* i)
{
    saveIncidencias(i->tam,i->inci);
    i->tam = 0;
    free(i->inci);
}
static void initvViajes(vViajes* v)
{
    v->viajes = initViajes(&v->tam_v);
    v->pasos = initPasos(&v->tam_p);
    v->pasaj = initPasajeros(&v->tam_pj);
}
static void savevViajes(vViajes* v)
{
    saveViajes(v->tam_v,v->viajes);
    v->tam_v = 0;
    free(v->viajes);
    savePasos(v->tam_p,v->pasos);
    v->tam_p = 0;
    free(v->pasos);
    savePasajeros(v->tam_pj,v->pasaj);
    v->tam_pj = 0;
    free(v->pasaj);
}
static void initvVehiculos(vVehiculos* v)
{
    v->vehi = initVehiculos(&v->tam);
}
static void savevVehiculos(vVehiculos* v)
{
    saveVehiculos(v->tam,v->vehi);
    v->tam = 0;
    free(v->vehi);
}

void init(vUsuarios* vu,vIncidencias* vi,vViajes* vv,vVehiculos* vve)
{
    initvUsuarios(vu);
    initvIncidencias(vi);
    initvViajes(vv);
    initvVehiculos(vve);
}
void save(vUsuarios* vu,vIncidencias* vi,vViajes* vv,vVehiculos* vve)
{
    savevUsuarios(vu);
    savevIncidencias(vi);
    savevViajes(vv);
    savevVehiculos(vve);
}
