#include <stdio.h>
#include <stdlib.h>
#include "carga.h"
#include "types.h"

int main(){
    Usuarios *usuarios1 = NULL;
    Vehiculos *vehiculos1 = NULL;
    int num_user;
    int num_vehiculos;
    cargarUsuario(&num_user, &usuarios1);
    cargaVehiculos(&num_user,&usuarios1,&vehiculos1,&num_vehiculos);
    printf("%d\n%d\n%d",*usuarios1[0].Id_usuario,*usuarios1[1].Id_usuario,*usuarios1[2].Id_usuario);
    return 0;
}

