//
// Created by Miguel on 14/3/18.
//

#include <stdio.h>
#include <w32api/adoctint.h>
#include "usuarios.h"

void users( ){

    int i=0;


    switch(){

        case 1:             //Añadir nuevo usuario
            puts("Añadir nuevo usuario");
            break;
        case 2:             //Borrar usuario
            puts("Eliminar un usuario");
            break;
        case 3:             //Modificar usuario
            puts("Modificar usuario");
            break;
        case 4:             //Listar usuarios
            puts("Listar usuarios");
            op4_usuarios();
            break;
    }
}

op1_usuarios(Usuarios *usuarios, int i ){

    puts("Id del nuevo usuario: ");
    puts("Nombre del nuevo usuario: ");
    puts("Localidad: ")
    puts("Tipo de usuario(Administrador o usuario): ");
    puts("User de inicio de sesión: ");
    puts("Contrasña: ");
    puts("Estado: ");
}

op4_usuarios(Usuarios *usuarios, int i){

    for(i=0;i<num_usuarios;i++){
        printf("%d-%s-%s-%d-%s-%s-%d \n\n", usuarios[i].Id_usuarios, usuarios[i].Nomb_usuario, usuarios[i].Localidad, usuarios[i].Perfil_usuarios, usuarios[i].User, usuarios[i].Login, usuarios[i].Estado);
    }
}