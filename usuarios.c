//
// Created by Miguel Cabral on 14/3/18.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuarios.h"
#include "utilidades.h"

void op1_usuarios(Usuarios *usuarios,int* i){

    int n;
    char *nombf, *locldf, *usrf, *login;

    nombf = (char *) malloc(21 * sizeof(char));
    locldf = (char *)malloc(21 * sizeof(char));
    usrf = (char *)malloc(6 * sizeof(char));
    login = (char *) malloc(9 * sizeof(char));

    usuarios = (Usuarios*)realloc(usuarios,(*i+1)*sizeof(Usuarios));
    (*i)++;

    puts("Id del nuevo usuario: ");
    scanf("%d", &usuarios[*i].Id_usuario);
    flush_in();

    puts("Nombre del nuevo usuario: ");
    scanf("%20s", nombf);
    flush_in();
    usuarios[*i].Nomb_usuario = nombf;

    puts("Localidad: ");
    scanf("%20s", locldf);
    flush_in();
    usuarios[*i].Localidad=locldf;

    do{
        puts("Seleccione el perfil del usuario:");
        puts("1) Administrador");
        puts("2) Usuario");
        scanf("%d",&n);
        flush_in();
    }while(n<1 || n>2);

    switch(n){

        case 1:
            usuarios[*i].Perfil_usuario = 0;
            break;

        case 2:
            usuarios[*i].Perfil_usuario = 1;
            break;
        default:
            puts("ERROR: La opcion introducida no es valida");
    }

    puts("User de inicio de sesión: ");
    scanf("%15s", usrf);
    flush_in();
    usuarios[*i].User = usrf;

    puts("Contrasña: ");
    scanf("%8s", login);
    flush_in();
    usuarios[*i].Login = login;

    do{
        puts("Seleccione el estado del usuario:");
        puts("1) Bloqueado");
        puts("2) Activo");
        scanf("%d",&n);
        flush_in();
    }while(n<1 || n>2);

    switch(n){

        case 1:
            usuarios[*i].Estado=0;
            break;

        case 2:
            usuarios[*i].Estado=1;
            break;

        default:
            puts("ERROR: La opcion introducida no es valida");
    }

    puts("***REALIZADO CON EXITO***");
}

void op2_usuarios(Usuarios *usuarios, int *j){

    int index=0, id_user = 0, i;
    char resp;

    do{
        if(index<0) puts("Id incorrecto, vuelva a intentarlo");
        else puts("Qué usuario desea eliminar? Introduce su User de sistema: ");
        scanf("%d", &id_user);
        flush_in();

        index = buscarUsuarioIndex(usuarios, *j, id_user);
    }while(index<0);

    printf("Se va a eliminar el user %d. %cEstá seguro%c(s/n)", id_user, 168, 160);
    scanf("%c", &resp);
    flush_in();

    if(resp == 's'){
        eliminarUsuario(usuarios, j, index);
        printf("\nSe ha eliminado el user correctamente\n");
    }else{
        printf("\nSe ha cancelado la eliminaci%cn del user\n", 162);
        exit(1);
    }
}

void op3_usuarios(Usuarios *usuarios, int num_usuarios){

    int id_user, index=0, n=0;

    do{
        if(index<0) puts("Id incorrecto, vuelva a intentarlo");
        else puts("Qué usuario desea eliminar? Introduce su User de sistema: ");
        scanf("%d", &id_user);
        flush_in();

        index = buscarUsuarioIndex(usuarios, num_usuarios, id_user);
    }while(index<0);

    printf("Se va a modificar el id %d...", index);

    puts("Id del nuevo usuario: ");
    scanf("%d", &usuarios[index].Id_usuario);
    flush_in();

    puts("Nombre del nuevo usuario: ");
    scanf("%20s", usuarios[index].Nomb_usuario);
    flush_in();

    puts("Localidad: ");
    scanf("%20s", usuarios[index].Localidad);
    flush_in();

    do{
        puts("Seleccione el perfil del usuario:");
        puts("1) Administrador");
        puts("2) Usuario");
        scanf("%d",&n);
        flush_in();
    }while(n<1 || n>2);

    switch(n){

        case 1:
            usuarios[index].Perfil_usuario = 0;
            break;

        case 2:
            usuarios[index].Perfil_usuario = 1;
            break;

        default:
            puts("ERROR: La opcion introducida no es valida");
    }

    puts("User de inicio de sesión: ");
    scanf("%15s", usuarios[index].User);
    flush_in();

    puts("Contrasña: ");
    scanf("%8s", usuarios[index].Login);
    flush_in();

    do{
        puts("Seleccione el estado del usuario:");
        puts("1) Bloqueado");
        puts("2) Activo");
        scanf("%d",&n);
        flush_in();
    }while(n<1 || n>2);

    switch(n){

        case 1:
            usuarios[index].Estado=0;
            break;

        case 2:
            usuarios[index].Estado=1;
            break;

        default:
            puts("ERROR: La opcion introducida no es valida");
    }
}

void op4_usuarios(Usuarios *usuarios, int num_usuarios){

    for( int i = 0; i < num_usuarios; i++ ){
        printf("%d-%s-%s-%s-%s-%s-%s\n",
               usuarios[i].Id_usuario,
               usuarios[i].Nomb_usuario,
               usuarios[i].Localidad,
               Perfil[usuarios[i].Perfil_usuario],
               usuarios[i].User,
               usuarios[i].Login,
               Estado_U[usuarios[i].Estado]);
    }
}
