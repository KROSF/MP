#include <cstdio>
#include <cstdlib>
#include "carga.h"

static void cargarUsuario(int *,Usuarios *);
static void cargaVehiculos(int *,Usuarios *,Vehiculos *);

void cargarUsuario(int * n,Usuarios * users)
{
    char *id,*nomb,*locld,*usr,*log;
    int *perfil,*estado;

    FILE *file;
    file = fopen("usuarios.txt", "r");

    while(!feof(file))
    {
        id=(char *) malloc()



    }
}