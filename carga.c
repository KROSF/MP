#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "carga.h"

/**
 * Estado Usuario a entero
 * @param c referencia a la cadena
 * @return 1 si el estado es activo 0 bloqueado
 */
int estadoUsuario(char ** c);
/**
 * Perfil usuario a entero
 * @param c referencia a la cadena
 * @return 1 si el perfil es usuario 0 administrador
 */
int perfilUsuario(char ** c);
//
//
int estadoUsuario(char** c){
    return (strcmp(*c,"activo")== 0) ? 1 : 0;
}

int perfilUsuario(char** c){
    return (strcmp(*c,"usuario")== 0) ? 1 : 0;
}

void cargarUsuario(int * n,Usuarios ** users)
{
    char *id,*nomb,*locld,*usr,*log,*perfil,*estado;

    FILE *file;
    file = fopen("Usuarios.txt", "r");
    if (file == NULL ) exit(1);

    while(!feof(file))
    {
        id = (char *) malloc( ( ID_USUARIO + 1 ) * sizeof(char));
        nomb = (char *) malloc((NOMB_USUARIO + 1)* sizeof(char));
        locld = (char *)malloc((LOCALIDAD +1) * sizeof(char));
        usr = (char *)malloc((USER + 1) * sizeof(char));
        log = (char *) malloc( (LOGIN + 1) * sizeof(char));
        perfil = (char *) malloc( 14 * sizeof(char));
        estado = (char *) malloc( 10 * sizeof(char));

        fscanf(file, "%[^-]-%[^-]-%[^-]-%[^-]-%[^-]-%[^-]-%[^\n]\n", id, nomb, locld, perfil ,usr,log,estado);

        if (! * n ) *users = (Usuarios *) malloc( (*n+1) * sizeof(Usuarios));
        else *users = (Usuarios *) realloc(*users,(*n+1) * sizeof(Usuarios));

        (*users)[*n].Id_usuario=atoi(id);
        (*users)[*n].Nomb_usario=nomb;
        (*users)[*n].Localidad=locld;
        (*users)[*n].Perfil_usuario=perfilUsuario(&perfil);
        (*users)[*n].User=usr;
        (*users)[*n].Login=log;
        (*users)[*n].Estado=estadoUsuario(&estado);
        (*n)++;
    }
    fclose(file);
}