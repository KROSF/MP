/**
 * @file main.c
 * @author Carlos Rodrigo Sanabria Flores
 * @date 25 Apr 2018
 * @copyright 2018 Carlos Rodrigo Sanabria Flores
 * @brief <brief>
 */
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "acceso.h"
#include "cargar.h"
#include "menu.h"

int main() {
  setlocale(LC_ALL,"es_ES.UTF-8");
  vUsuarios user;
  vIncidencias inci;
  vViajes viaje;
  vVehiculos vehi;
  init(&user, &inci, &viaje, &vehi);
  actualizarViajes(&viaje);
  int *accs = acceder(&user);
  if (accs[1] > -1) {
    if (accs[1] == 0)
      menuAdmin(&user, &inci, &viaje, &vehi, accs[0]);
    else
      menuUser(&user, &inci, &viaje, &vehi, accs[0]);
  } else
    printf("No se puede determinar el tipo de usuario\n");
  CLEAN;
  save(&user, &inci, &viaje, &vehi);
  return 0;
}
