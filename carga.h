#ifndef CARGA_H
#define CARGA_H
#include "tipos.h"
/**
 *
 * @param pUsuarios
 * @param pVehiculos
 * @param pViajes
 * @param pPasos
 * @param pIncidencias
 * @param pInt
 */
void cargar(Usuarios ** pUsuarios,
            Vehiculos **pVehiculos,
            Viajes **pViajes,
            Pasos **pPasos,
            Incidencias**pIncidencias,
            int * pInt);
#endif
