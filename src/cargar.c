#include <stdlib.h>
#include "cargar.h"

/**
 * inicializa vector usuarios
 * @param v referencia al vector user
 */
static void initvUsuarios(vUsuarios* v)
{
   v->user = initUsuarios(&v->tam);
}

/**
 * guarda datos de usuarios en fichero y libera memoria
 * @param v referencia al vector user
 */
static void savevUsuarios(vUsuarios* v)
{
  saveUsuarios(v->tam,v->user);
  v->tam = 0;
  free(v->user);
}

/**
 * inicializa vector incidencias
 * @param i referencia al vector inci
 */
static void initvIncidencias(vIncidencias* i)
{
    i->inci = initIncidencias(&i->tam);
}

/**
 * guarda datos de incidencias en fichero y libera memoria
 * @param i referencia al vector inci
 */
static void savevIncidencias(vIncidencias* i)
{
    saveIncidencias(i->tam,i->inci);
    i->tam = 0;
    free(i->inci);
}

/**
 * inicializa vector viajes
 * @param v referencia al vector viajes
 */
static void initvViajes(vViajes* v)
{
    v->viajes = initViajes(&v->tam_v);
    v->pasos = initPasos(&v->tam_p);
    v->pasaj = initPasajeros(&v->tam_pj);
}

/**
 * guarda datos de viajes en fichero y libera memoria
 * @param v referencia al vector viajes
 */
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

/**
 * inicializa vector vehiculos
 * @param v referencia al vector vehi
 */
static void initvVehiculos(vVehiculos* v)
{
    v->vehi = initVehiculos(&v->tam);
}

/**
 * guarda datos de vehiculos en fichero y libera memoria
 * @param v referencia al vector vehi
 */
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
