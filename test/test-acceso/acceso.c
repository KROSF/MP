#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include "acceso.h"

static int estadoUsuario(char *c) { return (strcmp(c, "activo") == 0) ? 1 : 0; }

static int perfilUsuarioAint(char *c) { return (strcmp(c, "usuario") == 0) ? 1 : 0; }


 Usuarios *initUsuarios(int * n, char* fichero){
    FILE *file = fopen(fichero, "r");
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

void saveUsuarios(int n, Usuarios *usuarios, char* fichero) {
  int i;
  for (i = 0; i < n; ++i) {

    free(usuarios[i].Nomb_usuario);
    free(usuarios[i].Login);
    free(usuarios[i].User);
    free(usuarios[i].Localidad);
  }
}


int check_user(vUsuarios *v, char* user, char* pass) {

  int logincount = 0, i;

  while (logincount < 3) {

    for (i = 0; i < v->tam; ++i) {
      if (strcmp(v->user[i].User, user) == 0 &&
          strcmp(v->user[i].Login, pass) == 0)
        return i;
    }

    logincount++;

  }
  return -1;
}
