#ifndef CARGA_H
#define CARGA_H
#include "tipos.h"

int num_usuarios;
int num_vehiulos;
int num_viajes;
int num_pasos;
int num_incidencias;

Usuarios *usuarios;
Vehiculos *vehiculos;
Viajes *viajes;
Pasos *pasos;
Incidencias *incidencias;

void cargar();
#endif
