#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuarios.h"
#include "utilidades.h"
/**
 * Variable global para obtener el estado de un usuario.
 */
static const char *Estado_U[] = {"bloqueado", "activo"};

/**
 * Variable global para obtener el perfil de un usuario.
 */
static const char *Perfil[] = {"administrador", "usuario"};

/**
 * Estado Usuario a entero
 * @param recibe c referencia a la cadena
 * @return devuelve 1 si estado activo, 0 si estado bloqueado
 */
static int estadoUsuario(char *c) { return (strcmp(c, "activo") == 0) ? 1 : 0; }

/**
 * Perfil usuario a entero
 * @param recibe c referencia a la cadena
 * @return devuelve 1 si el perfil es usuario 0 administrador
 */
static int perfilUsuarioAint(char *c) { return (strcmp(c, "usuario") == 0) ? 1 : 0; }

/**
 * Modificación nombre usuario
 * @param recibe v referencia al vector de Usuarios
 * @param recibe uIndex con el indice del usuario seleccionado
 */
static void nombreUsuario(vUsuarios *v, int uIndex) {
  printf("Ingrese nombre: ");
  scanf("%20[^\n]", v->user[uIndex].Nomb_usuario);
  flush_in();
}

/**
 * Modificación localidad usuario
 * @param recibe v referencia al vector de Usuarios
 * @param recibe uIndex con el indice del usuario seleccionado
 */
static void localidadUsuario(vUsuarios *v, int uIndex) {
  printf("Ingrese localidad: ");
  scanf("%20[^\n]", v->user[uIndex].Localidad);
  flush_in();
}

/**
 * Modificación contraseña usuario
 * @param recibe v referencia al vector de Usuarios
 * @param recibe uIndex con el indice del usuario seleccionado
 */
static void passUsuario(vUsuarios *v, int uIndex) {
  printf("Ingrese contraseña: ");
  scanf("%8[^\n]", v->user[uIndex].Login);
  flush_in();
}

/**
 * Modificación user usuario
 * @param recibe v referencia al vector de Usuarios
 * @param recibe uIndex con el indice del usuario seleccionado
 */
static void loginUsuario(vUsuarios *v, int uIndex) {
  printf("Ingrese nombre de usuario: ");
  scanf("%5[^\n]", v->user[uIndex].User);
  flush_in();
}

/**
 * Genera Id Usuario
 * @param recibe v referencia al vector de Usuarios
 * @return devuelve nuevo usuario a partir del último en el vector
 */
static int generarIdUsuario(vUsuarios *v) {
  return v->user[v->tam - 1].Id_usuario + 1;
}

/**
 * modificar Tipo Perfil de un Usuario
 * @param recibe v referencia al vector de Usuarios
 * @param recibe userId con el id de usuario seleccionado
 */
static void modificarPerfilUsuario(vUsuarios *v, int userId) {
  int tmp = 0;
  do {
    puts("Seleccione el perfil: ");
    puts("0) Administrador");
    puts("1) Usuario");
    scanf("%1d[^\n]", &tmp);
    flush_in();
  } while (tmp < 0 || tmp > 1);
  v->user[userId].Perfil_usuario = tmp;
}

/**
 * Modificar el Estado de un Usuario
 * @param recibe v referencia al vector de Usuarios
 * @param recibe userId con el id de usuario seleccionado
 */
static void modificarEstadoUsuario(vUsuarios *v, int userId) {
  int tmp = 0;
  do {
    puts("Seleccione estado: ");
    puts("0) Bloqueado");
    puts("1) Activo");
    scanf("%1d[^\n]", &tmp);
    flush_in();
  } while (tmp < 0 || tmp > 1);
  v->user[userId].Perfil_usuario = tmp;
}

/**
 * Eliminar un usuario
 * @param recibe v referencia al vector de Usuarios
 * @param recibe uIndex con el indice del usuario seleccionado
 */
static void bajaUsuario(vUsuarios *v, int uIndex) {
  free(v->user[uIndex].Nomb_usuario);
  free(v->user[uIndex].Localidad);
  free(v->user[uIndex].User);
  free(v->user[uIndex].Login);
  memmove(&v->user[uIndex], &v->user[uIndex + 1],
          (v->tam - uIndex - 1) * sizeof(Usuarios));
  --v->tam;
}

/**
 * Busqueda del indice de un usuario
 * @param recibe v referencia al vector de Usuarios
 * @param recibe userId con el indice del  usuario seleccionado
 * @return devuelve i con un entero, si coincide con el id buscado; sino devuelve -1
 */
static int buscarIndexUsuario(vUsuarios *v, int userId) {
  for (int i = 0; i < v->tam; ++i) {
    if (userId == v->user[i].Id_usuario)
      return i;
  }
  return -1;
}

/***
*      ____ __ __ __  __   ___ __   ___   __  __  ____  __
*     ||    || || ||\ ||  //   ||  // \\  ||\ || ||    (( \
*     ||==  || || ||\\|| ((    || ((   )) ||\\|| ||==   \\
*     ||    \\_// || \||  \\__ ||  \\_//  || \|| ||___ \_))
*
*               ____  __ __ ____  __    __   ___  ___   __
*               || \\ || || || )) ||    ||  //   // \\ (( \
*               ||_// || || ||=)  ||    || ((    ||=||  \\
*               ||    \\_// ||_)) ||__| ||  \\__ || || \_))
*/

/* ficheros a estrucuturas */

Usuarios *initUsuarios(int * n){
    FILE *file = fopen("ficheros/Usuarios.txt", "r");
    if( file == NULL ) exit(1);
    Usuarios *tmp=NULL;
    (*n) = 0;
    char *nomb,*locld,*usr,*logg;
    char id[ID_USUARIO],perfil[PERFIL],estado[ESTADO_U];

    while(!feof(file))
    {
        nomb   = (char*) malloc(NOMB       * sizeof(char));
        locld  = (char*) malloc(LOCAL      * sizeof(char));
        usr    = (char*) malloc(USR        * sizeof(char));
        logg    = (char*) malloc(LOGINPASS  * sizeof(char));

        if( nomb == NULL || locld == NULL || usr == NULL ||logg == NULL)
            exit(1);

        fscanf(file, "%[^-]-%[^-]-%[^-]-%[^-]-%[^-]-%[^-]-%[^\n]\n",
                id, nomb, locld, perfil ,usr,logg,estado);
        tmp = (Usuarios*) realloc(tmp,(*n+1) * sizeof(Usuarios));

        tmp[*n].Id_usuario     = atoi(id);
        tmp[*n].Nomb_usuario   = nomb;
        tmp[*n].Localidad      = locld;
        tmp[*n].Perfil_usuario = perfilUsuarioAint(perfil);
        tmp[*n].User           = usr;
        tmp[*n].Login          = logg;
        tmp[*n].Estado         = estadoUsuario(estado);
        (*n)++;
    }
    fclose(file);
    return tmp;
}

void saveUsuarios(int n, Usuarios *usuarios) {
  FILE *file = fopen("ficheros/Usuarios.txt", "w+");

  if (file == NULL)
    exit(1);

  int i;
  for (i = 0; i < n; ++i) {
    fprintf(file, "%04d-%s-%s-%s-%s-%s-%s\n", usuarios[i].Id_usuario,
            usuarios[i].Nomb_usuario, usuarios[i].Localidad,
            Perfil[usuarios[i].Perfil_usuario], usuarios[i].User,
            usuarios[i].Login, Estado_U[usuarios[i].Estado]);
    free(usuarios[i].Nomb_usuario);
    free(usuarios[i].Login);
    free(usuarios[i].User);
    free(usuarios[i].Localidad);
  }
  fclose(file);
  puts("Usuarios Guardados");
}
void printPerfil(vUsuarios *v, int userIndex) {
  printf("  Id: %d\n  Nombre: %s\n  Localidad: %s\n  Perfil: %s\n  Usuario: %s\n  Contrase%ca: %s\n  Estado: %s\n",
         v->user[userIndex].Id_usuario,
         v->user[userIndex].Nomb_usuario, v->user[userIndex].Localidad,
         Perfil[v->user[userIndex].Perfil_usuario], v->user[userIndex].User,164,
         v->user[userIndex].Login, Estado_U[v->user[userIndex].Estado]);
}

void perfilUsuario(vUsuarios *v, int userIndex) {
  int tmp = 0;
  printf(" 1. Nombre\n 2. Localidad\n 3. Login\n 4. Contraseña\n");
  printf("seleccione una opcion: ");
  scanf("%1d[^\n]", &tmp);
  flush_in();
  switch (tmp) {
  case 1:
    nombreUsuario(v, userIndex);
    break;
  case 2:
    localidadUsuario(v, userIndex);
    break;
  case 3:
    loginUsuario(v, userIndex);
    break;
  case 4:
    passUsuario(v, userIndex);
    break;
  default:
    printf("Opcion no valida no se hace nada.\n");
    break;
  }
}

void altaUsuario(vUsuarios *v) {
  v->user = (Usuarios *)realloc(v->user, (v->tam + 1) * sizeof(Usuarios));
  v->user[v->tam].Nomb_usuario = (char *)malloc(NOMB * sizeof(char));
  v->user[v->tam].Localidad = (char *)malloc(LOCAL * sizeof(char));
  v->user[v->tam].User = (char *)malloc(USR * sizeof(char));
  v->user[v->tam].Login = (char *)malloc(LOGINPASS * sizeof(char));
  v->user[v->tam].Perfil_usuario = 1;
  v->user[v->tam].Estado = 1;
  v->user[v->tam].Id_usuario = generarIdUsuario(v);
  nombreUsuario(v, v->tam);
  localidadUsuario(v, v->tam);
  loginUsuario(v, v->tam);
  passUsuario(v, v->tam);
  ++v->tam;
}

void modificarUsuario(vUsuarios *v, int userId) {
  int tmp = 0, index = buscarIndexUsuario(v, userId);
  if (index > -1) {
    printf(" 1. Nombre\n 2. Localidad\n 3. Login\n 4. Contraseña\n");
    printf(" 5. Perfil\n 6. Estado\n");
    printf("Seleccione una opcion: ");
    scanf("%1d[^\n]", &tmp);
    flush_in();
    switch (tmp) {
    case 1:
      nombreUsuario(v, index);
      break;
    case 2:
      localidadUsuario(v, index);
      break;
    case 3:
      loginUsuario(v, index);
      break;
    case 4:
      passUsuario(v, index);
      break;
    case 5:
      modificarPerfilUsuario(v, index);
      break;
    case 6:
      modificarEstadoUsuario(v, index);
      break;
    default:
      printf("Opcion no valida no se hace nada.\n");
      break;
    }
  } else
    printf("El usuario buscado no existe");
}

void listarUsuarios(vUsuarios *u, vIncidencias *vi) {
    CLEAN;
  for (int i = 0; i < u->tam; ++i) {
    printf("\n%d - %s - %s - %s - %s - %s - %s ", u->user[i].Id_usuario,
           u->user[i].Nomb_usuario, u->user[i].Localidad,
           Perfil[u->user[i].Perfil_usuario], u->user[i].User, u->user[i].Login,
           Estado_U[u->user[i].Estado]);
    printf("- n%c incidencias: %d\n",167,
           incidenciasUsuario(vi, u->user[i].Id_usuario));
  }
  system_pause();
}

void preguntarIdBaja(vUsuarios *v) {
  int tmp, tmp2;
  printf("Introduzca el id del usuario a eliminar: ");
  scanf("%d", &tmp);
  flush_in();
  tmp2 = buscarIndexUsuario(v, tmp);
  if (tmp2 > -1)
    bajaUsuario(v, tmp2);
  else
    printf("No existe el usuario introducido\n");
}

int preguntarIdModificar(void) {
    int tmp;
    printf("Introduzca el id del usuario a modificar: ");
    scanf("%d", &tmp);
    flush_in();
    return tmp;
}
