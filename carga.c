#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "carga.h"
#include "tipos.h"

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
static Usuarios *initUsuarios(int * );
static Vehiculos*initVehiculos(int *);

int estadoUsuario(char** c){
    return (strcmp(*c,"activo")== 0) ? 1 : 0;
}

int perfilUsuario(char** c){
    return (strcmp(*c,"usuario")== 0) ? 1 : 0;
}

void cargar(){
    usuarios=initUsuarios(&num_usuarios);
    vehiculos=initVehiculos(&num_vehiulos);
}

Usuarios *initUsuarios(int * n)
{
    Usuarios *tmp=NULL;
    (*n)=0;

    char *id,*nomb,*locld,*usr,*log,*perfil,*estado;

    FILE *file;
    file = fopen("Usuarios.txt", "r");
    if (file == NULL ) exit(1);

    while(!feof(file))
    {
        id = (char *) malloc(TAM05  * sizeof(char));
        nomb = (char *) malloc((TAM20 + 1)* sizeof(char));
        locld = (char *)malloc((TAM20 +1) * sizeof(char));
        usr = (char *)malloc((TAM05 + 1) * sizeof(char));
        log = (char *) malloc( (TAM08 + 1) * sizeof(char));
        perfil = (char *) malloc( 14 * sizeof(char));
        estado = (char *) malloc( 10 * sizeof(char));

        fscanf(file, "%[^-]-%[^-]-%[^-]-%[^-]-%[^-]-%[^-]-%[^\n]\n", id, nomb, locld, perfil ,usr,log,estado);
        if (! * n ) tmp = (Usuarios *) malloc( (*n+1) * sizeof(Usuarios));
        else tmp = (Usuarios *) realloc(tmp,(*n+1) * sizeof(Usuarios));

        tmp[*n].Id_usuario=atoi(id);
        tmp[*n].Nomb_usario=nomb;
        tmp[*n].Localidad=locld;
        tmp[*n].Perfil_usuario=perfilUsuario(&perfil);
        tmp[*n].User=usr;
        tmp[*n].Login=log;
        tmp[*n].Estado=estadoUsuario(&estado);
        (*n)++;
        free(id);
        free(perfil);
        free(estado);
    }
    fclose(file);
}

Vehiculos * initVehiculos(int * n)
{
    FILE *file;
    char *mat,*idu,*nplzs,*des_veh;

    Vehiculos *tmp=NULL;
    (*n)=0;
    file = fopen("Vehiculos.txt", "r");
    if (file == NULL ) exit(1);

    while(!feof(file))
    {
        mat = (char *) malloc( TAM08 * sizeof(char));
        idu = (char *) malloc( TAM05 * sizeof(char));
        nplzs = (char *) malloc(2 * sizeof(char));
        des_veh = (char *) malloc((TAM50 + 1) * sizeof(char));

        fscanf(file, "%[^-]-%[^-]-%[^-]-%[^\n]\n", mat, idu, nplzs,des_veh);

        if (! * n ) tmp = (Vehiculos *) malloc( (*n+1) * sizeof(Vehiculos));
        else tmp = (Vehiculos *) realloc(tmp,(*n+1) * sizeof(Vehiculos));

        tmp[*n].Id_usuario=atoi(idu);
        tmp[*n].Id_mat=mat;
        tmp[*n].Desc_veh=des_veh;
        tmp[*n].Num_plazas=atoi(nplzs);
        (*n)++;
        free(idu);
        free(nplzs);
    }
    fclose(file);
}
