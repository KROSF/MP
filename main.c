#include "carga.h"
#include "guardar.h"
#include "acceso.h"
int main(){

    Usuarios *usuarios;
    Vehiculos *vehiculos;
    Viajes *viajes;
    Pasos *pasos;
    Incidencias *incidencias;

    int vector[5];

    cargar(&usuarios,&vehiculos,&viajes,&pasos,&incidencias,vector);

    acceder(usuarios,vector[0]);

    guardar(&usuarios,&vehiculos,&viajes,&pasos,&incidencias,vector);

    return 0;
}
