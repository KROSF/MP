#ifndef ACCESO_H
#define ACCESO_H
#include "usuarios.h"
/**
 * comprueba el tipo de usuario (usuario/administrador)
 * @param usuarios referencia al vector user
 * @return iésima posición del usuario / -1 si no lo ha encontrado posición 0
 * @return tipo usuario (0 (admin) / 1 (usuario)) en posicion 1
 */
int *acceder(vUsuarios *usuarios);
#endif
