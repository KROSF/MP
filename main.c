#include <stdio.h>
#include <stdlib.h>
#include "types.h"
int main(){
    Usuarios * usuarios;
    usuarios = (Usuarios * )malloc(2* sizeof(Usuarios));
    int *ip = malloc(sizeof(int)); /* declare and allocate a new int pointer */
    *ip =3;
    usuarios[0].Estado=ip;

    return 0;
}

