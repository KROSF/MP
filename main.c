#include <stdio.h>
#include "carga.h"
#include "guardar.h"
#include "acceso.h"
#include "menu.h"
#include "utilidades.h"
int main(){

    Usuarios* usuarios;
    Vehiculos* vehiculos;
    Viajes* viajes;
    Pasos* pasos;
    Incidencias* incidencias;

    int vector[5];//Vector que contiene los contadores de las estructuras
    int* accs;

    cargar(&usuarios,&vehiculos,&viajes,&pasos,&incidencias,vector);
    //eliminarUsuario(&usuarios,&vector[0],1);
    accs = acceder(usuarios,vector[0]);
    if(accs[1] > -1 )
    {
        if(accs[1] == 0) menuAdmin(&usuarios,vector,accs[0]);
        else menuUser(&usuarios,vector,accs[0]);
    }
    else printf("No se puede determinar el tipo de usuario\n");

    guardar(&usuarios,&vehiculos,&viajes,&pasos,&incidencias,vector);

    return 0;
}
