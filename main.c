#include <stdio.h>
#include <stdlib.h>
#include "carga.h"
#include "types.h"

int main(){
    Usuarios *usuarios1 = NULL;
    int num_user;
    cargarUsuario(&num_user, &usuarios1);
    printf("%s\n%s\n%s",usuarios1[0].Nomb_usario,usuarios1[1].Nomb_usario,usuarios1[2].Nomb_usario);
    return 0;
}

