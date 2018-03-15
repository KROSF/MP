//
// Created by Miguel Cabral on 14/3/18.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuarios.h"
#include "types.h"

void users(Usuarios **usuarios, int num_usuarios){

    int i=0;


    switch(){

        case 1:             //Añadir nuevo usuario
            puts("Añadir nuevo usuario");
            op1_usuarios(usuarios, i);
            break;
        case 2:             //Borrar usuario
            puts("Eliminar un usuario");
            op2_usuarios(usuarios, i);
            break;
        case 3:             //Modificar usuario
            puts("Modificar usuario");
            op3_usuarios(usuarios, i);
            break;
        case 4:             //Listar usuarios
            puts("Listar usuarios");
            op4_usuarios(usuarios, i);
            break;
    }
}

void op1_usuarios(Usuarios **usuarios, int i){

/*    char *id_usuf, *nombf, *locldf, *usrf, *logf, *perfilf,*estadof;

    id_usuf = (char *) malloc( ( ID_USUARIO + 1 ) * sizeof(char));
    nombf = (char *) malloc((NOMB_USUARIO + 1)* sizeof(char));
    locldf = (char *)malloc((LOCALIDAD +1) * sizeof(char));
    usrf = (char *)malloc((USER + 1) * sizeof(char));
    logf = (char *) malloc( (LOGIN + 1) * sizeof(char));
    perfilf = (char *) malloc( 14 * sizeof(char));
    estadof = (char *) malloc( 10 * sizeof(char));
    */

    puts("Id del nuevo usuario: ");
    fflush(stdin);
    scanf("%d", *usuarios[i].Id_usuario);
    puts("Nombre del nuevo usuario: ");
    fflush(stdin);
    fgets(usuarios[i].Nomb_usario, 21, stdin);
    puts("Localidad: ");
    fflush(stdin);
    fgets(usuarios[i].Localidad, 21, stdin);
    puts("Tipo de usuario(Administrador o usuario): ");
    fflush(stdin);
    scanf("%d", *usuarios[i].Perfil_usuario);
    puts("User de inicio de sesión: ");
    fflush(stdin);
    fgets(usuarios[i].User, 6, stdin);
    puts("Contrasña: ");
    fflush(stdin);
    fgets(usuarios[i].Login, 9, stdin);
    puts("Estado: ");
    fflush(stdin);
    scanf("%d", *usuarios[i].Estado);
}

void op2_usuarios(Usuarios **usuarios, int i){

    int id_user=0;
    char resp;

    puts("Qué usuario desea eliminar? Introduce su User de sistema: ");
    scanf("%d", &id_user);
    printf("Se va a eliminar el user %d. %cEstá seguro%c(s/n)", id_user, 168, 160);
    scanf("%c", &resp);
    fflush(stdin);

    if(resp == 's'){
        for(i=0;i<num_usuarios;i++){
            if(*usuarios[i].Id_usuario == id_user){
                usuarios[i].Id_usuario = usuarios[i+1].Id_usuario;
                strcpy(usuarios[i].Nomb_usario, usuarios[i+1].Nomb_usario);
                strcpy(usuarios[i].Localidad, usuarios[i+1].Localidad);
                usuarios[i].Perfil_usuario = usuarios[i+1].Perfil_usuario;
                strcpy(usuarios[i].User, usuarios[i+1].User);
                strcpy(usuarios[i].Login, usuarios[i+1].Login);
                usuarios[i].Estado = usuarios[i+1].Estado;
            }
        }
        num_usuarios--;
        usuarios = (Usuarios*)realloc(usuarios, (num_usuarios+1)* sizeof(Usuarios*));
        printf("\nSe ha eliminado el user correctamente\n");
    }else{
        printf("\nSe ha cancelado la eliminaci%cn del user\n", 162);
        exit(1);
    }
}

void op3_usuarios(Usuarios **usuarios, int i){

    int id_user;

    puts("Qué usuario desea modificar? Introduce su User de sistema: ");
    scanf("%d", &id_user);

    for(i=0;i<num_usuarios;i++){
        if(usuarios[i].Id_usuario == id_user){
            puts("Id del nuevo usuario: ");
            fflush(stdin);
            scanf("%d", *usuarios[i].Id_usuario);

            puts("Nombre del nuevo usuario: ");
            fflush(stdin);
            fgets(usuarios[i].Nomb_usario, 21, stdin);

            puts("Localidad: ");
            fflush(stdin);
            fgets(usuarios[i].Localidad, 21, stdin);

            puts("Tipo de usuario(Administrador o usuario): ");
            fflush(stdin);
            scanf("%d", *usuarios[i].Perfil_usuario);

            puts("User de inicio de sesión: ");
            fflush(stdin);
            fgets(usuarios[i].User, 6, stdin);

            puts("Contrasña: ");
            fflush(stdin);
            fgets(usuarios[i].Login, 9, stdin);

            puts("Estado: ");
            fflush(stdin);
            scanf("%d", *usuarios[i].Estado);
        }
    }
}

void op4_usuarios(Usuarios **usuarios, int i){

    for(i=0;i<num_usuarios;i++){
        printf("%d-%s-%s-%d-%s-%s-%d \n\n", *usuarios[i].Id_usuario, usuarios[i].Nomb_usario, usuarios[i].Localidad, usuarios[i].Perfil_usuario, usuarios[i].User, usuarios[i].Login, usuarios[i].Estado);
    }
}