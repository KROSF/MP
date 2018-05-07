#ifndef CARGAR_H
#define CARGAR_H
#include "usuarios.h"

/**
 * inicializa los vectores de usuarios, incidencias, viajes y vehiculos
 * @param vu  referencia al vector user
 * @param vi  referencia al vector inci
 * @param vv  referencia al vector viajes
 * @param vve referencia al vector vehi
 */
void init(vUsuarios* vu,vIncidencias* vi,vViajes* vv,vVehiculos* vve);

/**
 * guarda datos de usuarios, incidencias, viajes y vehiculos en ficheros y libera memoria
 * @param vu  referencia al vector user
 * @param vi  referencia al vector inci
 * @param vv  referencia al vector viajes
 * @param vve referencia al vector vehi
 */
void save(vUsuarios* vu,vIncidencias* vi,vViajes* vv,vVehiculos* vve);
#endif
