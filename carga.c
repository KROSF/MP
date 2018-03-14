#include <cstdio>
#include <cstdlib>
#include "carga.h"

static void cargarUsuario(int *,Usuarios *);
static void cargaVehiculos(int *,Usuarios *,Vehiculos *);

void cargarUsuario(int * n,Usuarios * users)
{
    char *id,*nomb,*locld,*usr,*log,*perfil,*estado;

    FILE *file;
    file = fopen("usuarios.txt", "r");
    if (file == nullptr ) exit(1);

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

        if (! * n ) users = (Usuarios *) malloc( (*n+1) * sizeof(Usuarios));
        else users = (Usuarios *) realloc(users,(*n+1) * sizeof(Usuarios));
    }
}