#ifndef MENU_H
#define MENU_H
#include "usuarios.h"

/**
 * muestra menú principal para usuarios
 * @param v              referencia al vector user
 * @param vi             referencia al vector inci
 * @param vv             referencia al vector viajes
 * @param vve            referencia al vector vehi
 * @param indexusuario   Index del usuario
 */
void menuUser(vUsuarios *vu, vIncidencias *vi, vViajes *vv, vVehiculos *vve,
              int indexusuario);

/**
 * muestra menú principal para administradores
 * @param vu          referencia al vector user
 * @param vi          referencia al vector inci
 * @param vv          referencia al vector viajes
 * @param vve         referencia al vector vehi
 * @param indexadmin  Index del admin
 */
void menuAdmin(vUsuarios *vu, vIncidencias *vi, vViajes *vv, vVehiculos *vve,
               int indexadmin);
#endif
