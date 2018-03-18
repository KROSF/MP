#include <stdio.h>
#include "carga.h"
int main(){

    Usuarios *usuarios;
    Vehiculos *vehiculos;
    Viajes *viajes;
    Pasos *pasos;
    Incidencias *incidencias;

    int vector[5];

    cargar(&usuarios,&vehiculos,&viajes,&pasos,&incidencias,vector);


    for (int i = 0; i < vector[3] ; ++i) {
        printf("%d ",incidencias[i].Id_viaje          );
        printf("%d ",incidencias[i].Id_us_registra    );
        printf("%d ",incidencias[i].Id_us_incidencia  );
        printf("%s ",incidencias[i].Desc_indicencia);
        printf("%d\n",incidencias[i].Est_incidencia    );
    }
    return 0;
}

