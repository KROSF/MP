#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "carga.h"
#include "types.h"

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

int estadoUsuario(char** c){
    return (strcmp(*c,"activo")== 0) ? 1 : 0;
}

int perfilUsuario(char** c){
    return (strcmp(*c,"usuario")== 0) ? 1 : 0;
}

void cargarUsuario(int * n,Usuarios ** users)
{
    char *id,*nomb,*locld,*usr,*log,*perfil,*estado;
    int *sid;

    FILE *file;
    file = fopen("Usuarios.txt", "r");
    if (file == NULL ) exit(1);

    while(!feof(file))
    {
        sid = (int *) malloc(sizeof(int));
        id = (char *) malloc(TAM05  * sizeof(char));
        nomb = (char *) malloc((TAM20 + 1)* sizeof(char));
        locld = (char *)malloc((TAM20 +1) * sizeof(char));
        usr = (char *)malloc((TAM05 + 1) * sizeof(char));
        log = (char *) malloc( (TAM08 + 1) * sizeof(char));
        perfil = (char *) malloc( 14 * sizeof(char));
        estado = (char *) malloc( 10 * sizeof(char));

        fscanf(file, "%[^-]-%[^-]-%[^-]-%[^-]-%[^-]-%[^-]-%[^\n]\n", id, nomb, locld, perfil ,usr,log,estado);
        *sid = atoi(id);
        if (! * n ) *users = (Usuarios *) malloc( (*n+1) * sizeof(Usuarios));
        else *users = (Usuarios *) realloc(*users,(*n+1) * sizeof(Usuarios));

        (*users)[*n].Id_usuario=sid;
        (*users)[*n].Nomb_usuario=nomb;
        (*users)[*n].Localidad=locld;
        (*users)[*n].Perfil_usuario=perfilUsuario(&perfil);
        (*users)[*n].User=usr;
        (*users)[*n].Login=log;
        (*users)[*n].Estado=estadoUsuario(&estado);
        (*n)++;
        free(id);
        free(perfil);
        free(estado);
    }
    fclose(file);
}

void cargarVehiculos(int * u,Usuarios ** users,Vehiculos ** vls,int * v)
{
    FILE *file;
    char *mat,*idu,*nplzs,*des_veh;
    file = fopen("Vehiculos.txt", "r");
    if (file == NULL ) exit(1);
    while(!feof(file))
    {
        int i;
        mat = (char *) malloc( TAM08 * sizeof(char));
        idu = (char *) malloc( TAM05 * sizeof(char));
        nplzs = (char *) malloc(2 * sizeof(char));
        des_veh = (char *) malloc((TAM50 + 1) * sizeof(char));

        fscanf(file, "%[^-]-%[^-]-%[^-]-%[^\n]\n", mat, idu, nplzs,des_veh);
        for (i = 0; i <  *u ; ++i) {
            if((*(*users)[i].Id_usuario) == atoi(idu)) break;
        }
        if (! * v ) *vls = (Vehiculos *) malloc( (*v+1) * sizeof(Vehiculos));
        else *vls = (Vehiculos *) realloc(*vls,(*v+1) * sizeof(Vehiculos));

        (*vls)[*v].Id_usuario=(*users)[i].Id_usuario;
        (*vls)[*v].Id_mat=mat;
        (*vls)[*v].Desc_veh=des_veh;
        (*vls)[*v].Num_plazas=atoi(nplzs);
        (*v)++;
        free(idu);
        free(nplzs);
    }
    fclose(file);
}

void cargarViajes(int * vh,Usuarios ** veh,Viajes ** vjs,int * vi){

}