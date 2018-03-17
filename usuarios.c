//
// Created by Miguel Cabral on 14/3/18.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuarios.h"

void flush_in() { // Función que sistituye el "fflush(stdin)"
    int ch;

    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){}
}

void USERS(Usuarios **usuarios, int num_usuarios){

    int i = 0;

    switch (  ){

        case 1:             //Añadir nuevo usuario
            puts("Añadir nuevo usuario:");
            op1_usuarios(&usuarios, i);
            break;
        case 2:             //Borrar usuario
            puts("Eliminar un usuario:");
            op2_usuarios(&usuarios, i);
            break;
        case 3:             //Modificar usuario
            puts("Modificar usuario:");
            op3_usuarios(&usuarios, i);
            break;
        case 4:             //Listar usuarios
            puts("Listar usuarios:");
            op4_usuarios(&usuarios, i);
            break;
    }
}

void op1_usuarios(Usuarios **usuarios, int i){

    int n;
/*    char *id_usuf, *nombf, *locldf, *usrf, *logf, *estadof;

    id_usuf = (char *) malloc((TAM04 + 1) * sizeof(char));
    nombf = (char *) malloc((TAM20 + 1)* sizeof(char));
    locldf = (char *)malloc((TAM20 +1) * sizeof(char));
    usrf = (char *)malloc((TAM05 + 1) * sizeof(char));
    logf = (char *) malloc((TAM08 + 1) * sizeof(char));
    estadof = (char *) malloc(10 * sizeof(char));*/


    puts("Id del nuevo usuario: ");
    flush_in();
    scanf("%d", usuarios[i]->Id_usuario);

    puts("Nombre del nuevo usuario: ");
    flush_in();
    scanf("%20s", usuarios[i]->Nomb_usuario);

    puts("Localidad: ");
    flush_in();
    scanf("%20s", usuarios[i]->Localidad);

    do{
        puts("Seleccione el perfil del usuario:");
        puts("1) Administrador");
        puts("2) Profesor");
        flush_in();
        scanf("%d",&n);
    }while(n<1 || n>2);

    switch(n){

        case 1:
            (*usuarios)[i].Perfil_usuario=0;
            break;

        case 2:
            (*usuarios)[i].Perfil_usuario=1;
            break;
        default:
            puts("ERROR: La opcion introducida no es valida");
    }

    puts("User de inicio de sesión: ");
    flush_in();
    scanf("%15s", usuarios[i]->User);

    puts("Contrasña: ");
    flush_in();
    scanf("%8s", usuarios[i]->Login);

    do{
        puts("Seleccione el estado del usuario:");
        puts("1) Activo");
        puts("2) Bloqueado");
        flush_in();
        scanf("%d",&n);
    }while(n<1 || n>2);

    switch(n){

        case 1:
            (*usuarios)[i].Estado=0;
            break;

        case 2:
            (*usuarios)[i].Estado=1;
            break;
        default:
            puts("ERROR: La opcion introducida no es valida");
    }
}

void op2_usuarios(Usuarios **usuarios, int i){

    int id_user=0;
    char resp;

    puts("Qué usuario desea eliminar? Introduce su User de sistema: ");
    scanf("%d", &id_user);
    printf("Se va a eliminar el user %d. %cEstá seguro%c(s/n)", id_user, 168, 160);
    scanf("%c", &resp);
    flush_in();

    if(resp == 's'){
        for(i=0;i<num_usuarios;i++){
            if(usuarios[i]->Id_usuario == id_user){
                usuarios[i]->Id_usuario = usuarios[i+1]->Id_usuario;
                strcmp(usuarios[i]->Nomb_usuario, usuarios[i+1]->Nomb_usuario);
                strcmp(usuarios[i]->Localidad, usuarios[i+1]->Localidad);
                usuarios[i]->Perfil_usuario = usuarios[i+1]->Perfil_usuario;
                strcmp(usuarios[i]->User, usuarios[i+1]->User);
                strcmp(usuarios[i]->Login, usuarios[i+1]->Login);
                usuarios[i]->Estado = usuarios[i+1]->Estado;
            }
        }
        num_usuarios--;
        *usuarios = (Usuarios*)realloc(usuarios, (num_usuarios+1)* sizeof(Usuarios*));
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
        if(*usuarios[i]->Id_usuario == id_user){
            puts("Id del nuevo usuario: ");
            flush_in();
            scanf("%d", usuarios[i]->Id_usuario);

            puts("Nombre del nuevo usuario: ");
            flush_in();
            scanf("%20s", usuarios[i]->Nomb_usuario);

            puts("Localidad: ");
            flush_in();
            scanf("%20s", usuarios[i]->Localidad);

            puts("Tipo de usuario(Administrador o usuario): ");
            flush_in();
            scanf("%d", usuarios[i]->Perfil_usuario);

            puts("User de inicio de sesión: ");
            flush_in();
            scanf("%15s", usuarios[i]->User);

            puts("Contrasña: ");
            flush_in();
            scanf("%8s", usuarios[i]->Login);

            puts("Estado: ");
            flush_in();
            scanf("%d", usuarios[i]->Estado);
        }
    }
}

void op4_usuarios(Usuarios **usuarios, int i){

    for(i=0;i<num_usuarios;i++){
        printf("%d-%s-%s-%d-%s-%s-%d \n\n", *usuarios[i]->Id_usuario, *usuarios[i]->Nomb_usuario, *usuarios[i]->Localidad, *usuarios[i]->Perfil_usuario, *usuarios[i]->User, *usuarios[i]->Login, *usuarios[i]->Estado);
    }
}