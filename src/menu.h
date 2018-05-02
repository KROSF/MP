#ifndef MENU_H
#define MENU_H
#include "usuarios.h"
#include "utilidades.h"
#include "viajes.h"
void menuUser(vUsuarios *vu, vIncidencias *vi, vViajes *vv, vVehiculos *vve,
              int id);
void menuAdmin(vUsuarios *vu, vIncidencias *vi, vViajes *vv, vVehiculos *vve,
               int id);
#endif
