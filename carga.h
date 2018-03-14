#ifndef CARGA_H
#define CARGA_H
#include "types.h"
Usuarios *usuarios;
Vehiculos *vehiculos;
Viajes *viajes;
Pasos *pasos;
Incidencias *incidencias;

int num_usuarios;
int num_vehiulos;
int num_viajes;
int num_pasos;
int num_incidencias;

void cargarUsuario(int *,Usuarios **);
void cargaVehiculos(int *,Usuarios **,Vehiculos **);
#endif
