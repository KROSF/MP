#include "carga.h"
#include "guardar.h"
int main(){

    Usuarios *usuarios;
    Vehiculos *vehiculos;
    Viajes *viajes;
    Pasos *pasos;
    Incidencias *incidencias;

    int vector[5];

    cargar(&usuarios,&vehiculos,&viajes,&pasos,&incidencias,vector);





    guardar(&usuarios,&vehiculos,&viajes,&pasos,&incidencias,vector);

    return 0;
}

