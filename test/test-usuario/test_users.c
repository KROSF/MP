//
// Created by Miguel on 02/05/2018.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "test_users.h"

static const char *Estado_U[] = {"bloqueado", "activo"};
static const char *Perfil[] = {"administrador", "usuario"};

static int estadoUsuario(char **c) { return (strcmp(*c, "activo") == 0) ? 1 : 0; }
static int perfilUsuarioAint(char **c) { return (strcmp(*c, "usuario") == 0) ? 1 : 0; }

Usuarios *initUsuarios(int *n, char *fichero) {
    FILE *file = fopen(fichero, "r");
    if (file == NULL)
        exit(1);
    Usuarios *tmp = NULL;
    (*n) = 0;
    char *id, *nomb, *locld, *usr, *log, *perfil, *estado;

    while (!feof(file)) {
        id = (char *)malloc(ID_USUARIO * sizeof(char));
        nomb = (char *)malloc(NOMB * sizeof(char));
        locld = (char *)malloc(LOCAL * sizeof(char));
        usr = (char *)malloc(USR * sizeof(char));
        log = (char *)malloc(LOGINPASS * sizeof(char));
        perfil = (char *)malloc(PERFIL * sizeof(char));
        estado = (char *)malloc(ESTADO_U * sizeof(char));

        if (id == NULL || nomb == NULL || locld == NULL || usr == NULL ||
            log == NULL || perfil == NULL || estado == NULL)
            exit(1);

        fscanf(file, "%[^-]-%[^-]-%[^-]-%[^-]-%[^-]-%[^-]-%[^\n]\n", id, nomb,
               locld, perfil, usr, log, estado);
        tmp = (Usuarios *)realloc(tmp, (*n + 1) * sizeof(Usuarios));

        tmp[*n].Id_usuario = atoi(id);
        tmp[*n].Nomb_usuario = nomb;
        tmp[*n].Localidad = locld;
        tmp[*n].Perfil_usuario = perfilUsuarioAint(&perfil);
        tmp[*n].User = usr;
        tmp[*n].Login = log;
        tmp[*n].Estado = estadoUsuario(&estado);
        (*n)++;
        free(id);
        free(perfil);
        free(estado);
    }
    fclose(file);
    return tmp;
}

void saveUsuarios(int n, Usuarios *usuarios, char *fichero) {
    FILE *file = fopen(fichero, "w+");

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
}

int buscarIndexUsuario(vUsuarios *v, int userId) {
    for (int i = 0; i < v->tam; ++i) {
        if (userId == v->user[i].Id_usuario)
            return i;
    }
    return -1;
}
