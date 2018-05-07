#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "utilidades.h"

/**
 * muestra menú del perfil para usuarios
 * @param v         referencia al vector user
 * @param userIndex id del usuario
 */
static void userPerfil(vUsuarios *v, int userIndex) {

  int opc, bucle = 1;

  while (bucle == 1) {
    CLEAN;
    printf("Datos: ");
    printPerfil(v, userIndex);
    printf("\n  ___________________________\n");
    printf(" |                           |\n");
    printf(" |    1. MODIFICAR PERFIL    |\n");
    printf(" |    2. VOLVER              |\n");
    printf(" |___________________________|\n");
    do {
      printf("\n\n  Seleccione una opción: ");
      scanf("%d", &opc);
      flush_in();
      switch (opc) {
      case 1:
        perfilUsuario(v, userIndex);
        break;
      case 2:
        bucle = 0;
        break;
      default:
        printf("  Opci%cn incorrecta.", 162);
        break;
      }
    } while (opc < 1 || opc > 2);
  }
}

/**
 * muestra menú de vehiculos para usuarios
 * @param v         referencia al vector vehi
 * @param userId id del usuario
 */
static void userVehiculos(vVehiculos *v, int userId) {

  int opc, bucle = 1;
  while (bucle == 1) {
    CLEAN;
    printf("\n  ____________________________\n");
    printf(" |                            |\n");
    printf(" |    1. LISTA VEHICULOS      |\n");
    printf(" |    2. ALTA VEHICULO        |\n");
    printf(" |    3. ELIMINAR VEHICULO    |\n");
    printf(" |    4. MODIFICAR VEHICULO   |\n");
    printf(" |    5. VOLVER               |\n");
    printf(" |____________________________|\n");
    do {
      printf("\n\n  Seleccione una opci%cn: ", 162);
      scanf("%d", &opc);
      flush_in();
      switch (opc) {
      case 1:
        listarVehiculosUser(v, userId);
        system_pause();
        break;
      case 2:
        altaVehiculos(v, userId);
        break;
      case 3:
        eliminarVehiculoUser(v, userId);
        break;
      case 4:
        modificarVehiculoUser(v, userId);
        break;
      case 5:
        bucle = 0;
        break;
      default:
        printf("  Opci%cn incorrecta.", 162);
        break;
      }
    } while (opc < 1 || opc > 5);
  }
}

/**
 * muestar menú de viajes para usuarios
 * @param v      referencia al vector viajes
 * @param ve     referencia al vector vehi
 * @param userId id del usuario
 */
void userViajes(vViajes *v, vVehiculos *ve, int userId) {

  int opc, bucle = 1;v->last = -1;
  while (bucle == 1) {
    CLEAN;
    listarViajesAbiertos(v);
    printf("\n  _______________________________\n");
    printf(" |                               |\n");
    printf(" |    1. PUBLICAR VIAJE          |\n");
    printf(" |    2. MODIFICAR VIAJE         |\n");
    printf(" |    3. INCORPORARSE A VIAJE    |\n");
    printf(" |    4. DETALLES VIAJE          |\n");
    printf(" |    5. CANCELAR VIAJE          |\n");
    printf(" |    6. VOLVER                  |\n");
    printf(" |_______________________________|\n");
    do {
      printf("\n\n  Seleccione una opci%cn: ", 162);
      scanf("%d", &opc);
      flush_in();
      switch (opc) {
      case 1:
        publicarViajeUsuario(v, ve, userId);
        break;
      case 2:
        editarViajesUsuario(v, ve, userId);
        break;
      case 3:
        incorporarseViaje(v,userId,&v->last);
        break;
      case 4:
        detalleViaje(v);
        break;
      case 5:
        cancelarViaje(v,userId);
        break;
      case 6:
        bucle = 0;
        break;
      default:
        printf("  Opci%cn incorrecta.", 162);
        break;
      }
  } while (opc < 1 || opc > 6);
  }
}

/**
 * muestra menú de incidencias para usuarios
 * @param v      referencia al vector inci
 * @param userId id del usuario
 */
void userIncidencias(vIncidencias *v,int userId) {

  int opc, bucle;
  bucle = 1;
  while (bucle == 1) {
    CLEAN;
    printf("\n  ______________________________\n");
    printf(" |                              |\n");
    printf(" |    1. CREAR INCIDENCIA       |\n");
    printf(" |    2. LISTAR INCIDENCIAS     |\n");
    printf(" |    3. VOLVER                 |\n");
    printf(" |______________________________|");
    do {
      printf("\n\n  Seleccione una opci%cn: ", 162);
      scanf("%d", &opc);
      flush_in();
      switch (opc) {
      case 1:
        // c();
        break;
      case 2:
        listarIncidencias(v);
        break;
      case 3:
        bucle = 0;
        break;
      default:
        printf("  Opci%cn incorrecta.", 162);
        break;
      }
    } while (opc < 1 || opc > 3);
  }
}

void menuUser(vUsuarios *v, vIncidencias *vi, vViajes *vv, vVehiculos *vve,
              int indexusuario) {

  int i = strlen(v->user[indexusuario].Nomb_usuario), j, espacio, opc, bucle;
  bucle = 1;
  while (bucle == 1) {
    CLEAN;
    if (i % 2 == 0) {
      printf("  ______________________\n");
      printf(" |                      |\n |");
      espacio = (23 - i) / 2; // 24 asteriscos (nombre par)
    } else {
      printf("  _______________________\n");
      printf(" |                       |\n |");
      espacio = (24 - i) / 2; // 25 asteriscos (nombre impar)
    }

    for (j = 0; j < espacio; j++) {
      printf(" ");
    }
    printf("%s", v->user[indexusuario].Nomb_usuario);
    for (j = 0; j < espacio; j++) {
      printf(" ");
    }

    if (i % 2 == 0) {

      printf("|\n |______________________|\n");
      printf(" |                      |\n");
      printf(" |    1. PERFIL         |\n");
      printf(" |    2. VEHICULOS      |\n");
      printf(" |    3. VIAJES         |\n");
      printf(" |    4. INCIDENCIAS    |\n");
      printf(" |    5. SALIR          |\n");
      printf(" |______________________|");
    } else {

      printf("|\n |_______________________|\n");
      printf(" |                       |\n");
      printf(" |     1. PERFIL         |\n");
      printf(" |     2. VEHICULOS      |\n");
      printf(" |     3. VIAJES         |\n");
      printf(" |     4. INCIDENCIAS    |\n");
      printf(" |     5. SALIR          |\n");
      printf(" |_______________________|");
    }
    do {
      printf("\n\n  Seleccione una opci%cn: ", 162);
      scanf("%d", &opc);
      flush_in();
      switch (opc) {
      case 1:
        userPerfil(v, indexusuario);
        break;
      case 2:
        userVehiculos(vve,v->user[indexusuario].Id_usuario);
        break;
      case 3:
        userViajes(vv,vve,v->user[indexusuario].Id_usuario);
        break;
      case 4:
        userIncidencias(vi,v->user[indexusuario].Id_usuario);
        break;
      case 5:
        bucle = 0;
        break;
      default:
        printf("  Opci%cn incorrecta.", 162);
        break;
      }
    } while (opc < 1 || opc > 5);
  }
}

/**
 * muestra menú de usuarios para administradores
 * @param v referencia al vector user
 * @param i referencia al vector inci
 */
static void adminUsuarios(vUsuarios *v, vIncidencias *i) {

  int opc, bucle;
  bucle = 1;
  while (bucle == 1) {
    CLEAN;
    printf("\n  ___________________________\n");
    printf(" |                           |\n");
    printf(" |    1. ALTA USUARIO        |\n");
    printf(" |    2. BAJA USUARIO        |\n");
    printf(" |    3. MODIFICAR USUARIO   |\n");
    printf(" |    4. LISTAR USUARIOS     |\n");
    printf(" |    5. VOLVER              |\n");
    printf(" |___________________________|");

    do {
      printf("\n\n  Seleccione una opci%cn: ", 162);
      scanf("%d", &opc);
      flush_in();
      switch (opc) {
      case 1:
        altaUsuario(v);
        break;
      case 2:
        preguntarIdBaja(v);
        break;
      case 3:
        modificarUsuario(v, preguntarIdModificar());
        break;
      case 4:
        listarUsuarios(v, i);
        break;
      case 5:
        bucle = 0;
        break;
      default:
        printf("  Opci%cn incorrecta.", 162);
        break;
      }
    } while (opc < 1 || opc > 5);
  }
}
/**
 * muestra el menú de vehículos para administradores
 * @param v referencia al vector vehi
 */
static void adminVehiculos(vVehiculos *v) {

  int opc, bucle;
  bucle = 1;
  while (bucle == 1) {
    CLEAN;
    printf("\n  ____________________________\n");
    printf(" |                            |\n");
    printf(" |    1. ALTA VEHICULO        |\n");
    printf(" |    2. BAJA VEHICULO        |\n");
    printf(" |    3. MODIFICAR VEHICULO   |\n");
    printf(" |    4. LISTAR VEHICULOS     |\n");
    printf(" |    5. VOLVER               |\n");
    printf(" |____________________________|");

    do {
      printf("\n\n  Seleccione una opci%cn: ", 162);
      scanf("%d", &opc);
      flush_in();
      switch (opc) {
      case 1:
        altaVehiculosAdmin(v);
        break;
      case 2:
        bajaVehiculosAdmin(v);
        break;
      case 3:
        modificarVehiculosAdmin(v);
        break;
      case 4:
        listarVehiculos(v);
        break;
      case 5:
        bucle = 0;
        break;
      default:
        printf("  Opci%cn incorrecta.", 162);
        break;
      }
    } while (opc < 1 || opc > 5);
  }
}

/**
 * muestra el menú de viajes para administradores
 * @param v   referencia al vector viajes
 * @param vve referencia al vector vehi
 */
static void adminViajes(vViajes *v, vVehiculos *vve) {

  int opc, bucle;
  bucle = 1;
  while (bucle == 1) {
    CLEAN;

    printf("\n  __________________________\n");
    printf(" |                          |\n");
    printf(" |    1. PUBLICAR VIAJE     |\n");
    printf(" |    2. ELIMINAR VIAJE     |\n");
    printf(" |    3. MODIFICAR VIAJE    |\n");
    printf(" |    4. LISTAR VIAJES      |\n");
    printf(" |    5. VOLVER             |\n");
    printf(" |__________________________|");

    do {
      printf("\n\n  Seleccione una opci%cn: ", 162);
      scanf("%d", &opc);
      flush_in();
      switch (opc) {
      case 1:
        publicarViajeAdmin(v, vve);
        break;
      case 2:
        eliminarViajesAdmin(v);
        break;
      case 3:
        modificarViajesAdmin(v, vve);
        break;
      case 4:
        listarViajesAdmin(v);
        break;
      case 5:
        bucle = 0;
        break;
      default:
        printf("  Opci%cn incorrecta.", 162);
        break;
      }
    } while (opc < 1 || opc > 5);
  }
}

/**
 * muestra el menú de incidencias para administradores
 * @param v  referencia al vector inci
 * @param vv referencia al vector viajes
 * @param ve referencia al vector vehi
 */
static void adminIncidencias(vIncidencias *v, vViajes *vv, vVehiculos *ve) {

  int opc, bucle;
  bucle = 1;

  while (bucle == 1) {
    CLEAN;

    printf("\n  _______________________________\n");
    printf(" |                               |\n");
    printf(" |    1. CREAR INCIDENCIA        |\n");
    printf(" |    2. ELIMINAR INCIDENCIA     |\n");
    printf(" |    3. MODIFICAR INCIDENCIA    |\n");
    printf(" |    4. LISTAR INCIDENCIAS      |\n");
    printf(" |    5. VOLVER                  |\n");
    printf(" |_______________________________|");

    do {
      printf("\n\n  Seleccione una opci%cn: ", 162);
      scanf("%d", &opc);
      flush_in();
      switch (opc) {
      case 1:
        crearIncidenciasAdmin(v, vv, ve);
        break;
      case 2:
        eliminarIncidenciasAdmin(v, vv);
        break;
      case 3:
        modificarIncidenciasAdmin(v);
        break;
      case 4:
        listarIncidencias(v);
        break;
      case 5:
        bucle = 0;
        break;
      default:
        printf("  Opci%cn incorrecta.", 162);
        break;
      }
    } while (opc < 1 || opc > 5);
  }
}

void menuAdmin(vUsuarios *v, vIncidencias *vi, vViajes *vv, vVehiculos *vve,
               int indexadmin) {
  CLEAN;
  int i = strlen(v->user[indexadmin].Nomb_usuario), j, espacio, opc,
      bucle; // TAMAÑO TEXTO
  bucle = 1;
  while (bucle == 1) {
    CLEAN;
    if (i % 2 == 0) {
      printf("  ______________________\n");
      printf(" |                      |\n |");
      espacio = (23 - i) / 2; // 24 asteriscos (nombre par)
    } else {
      printf("  _______________________\n");
      printf(" |                       |\n |");
      espacio = (24 - i) / 2; // 25 asteriscos (nombre impar)
    }

    for (j = 0; j < espacio; j++) {
      printf(" ");
    }
    printf("%s", v->user[indexadmin].Nomb_usuario);
    for (j = 0; j < espacio; j++) {
      printf(" ");
    }

    if (i % 2 == 0) {

      printf("| \n |______________________|\n");
      printf(" |                      |\n");
      printf(" |    1. USUARIOS       |\n");
      printf(" |    2. VEHICULOS      |\n");
      printf(" |    3. VIAJES         |\n");
      printf(" |    4. INCIDENCIAS    |\n");
      printf(" |    5. SALIR          |\n");
      printf(" |______________________|");

    } else {

      printf("| \n |_______________________|\n");
      printf(" |                       |\n");
      printf(" |     1. USUARIOS       |\n");
      printf(" |     2. VEHICULOS      |\n");
      printf(" |     3. VIAJES         |\n");
      printf(" |     4. INCIDENCIAS    |\n");
      printf(" |     5. SALIR          |\n");
      printf(" |_______________________|\n\n");
    }

    do {
      printf("  \n\n  Seleccione una opci%cn: ", 162);
      scanf("%d", &opc);
      flush_in();
      switch (opc) {
      case 1:
        adminUsuarios(v, vi);
        break;
      case 2:
        adminVehiculos(vve);
        break;
      case 3:
        adminViajes(vv, vve);
        break;
      case 4:
        adminIncidencias(vi, vv, vve);
        break;
      case 5:
        bucle = 0;
        break;
      default:
        printf("  Opci%cn incorrecta.\n\n", 162);
        break;
      }
    } while (opc < 1 || opc > 5);
  }
}
