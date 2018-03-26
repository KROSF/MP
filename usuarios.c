#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuarios.h"
#include "utilidades.h"
void USERS(Usuarios *usuarios, int *num_usuarios){
    int i = 0;
    scanf("%d",&i);
    switch ( i ){
        case 1:             //Añadir nuevo usuario
            puts("Añadir nuevo usuario:");
            op1_usuarios(usuarios, num_usuarios);
            break;
        case 2:             //Borrar usuario
            puts("Eliminar un usuario:");
            op2_usuarios(usuarios, num_usuarios);
            break;
        case 3:             //Modificar usuario
            puts("Modificar usuario:");
            op3_usuarios(usuarios, *num_usuarios);
            break;
        case 4:             //Listar usuarios
            puts("Listar usuarios:");
            op4_usuarios(usuarios, *num_usuarios);
            break;
    }
}

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
}

void op2_usuarios(Usuarios *usuarios, int *j){

    int id_user = 0, i;
    char resp;

    puts("Qué usuario desea eliminar? Introduce su User de sistema: ");
    scanf("%d", &id_user);
    flush_in();
    printf("Se va a eliminar el user %d. %cEstá seguro%c(s/n)", id_user, 168, 160);
    scanf("%c", &resp);
    flush_in();

    if(resp == 's'){
        for(i = 0 ; i < *j ;i++){
            if(usuarios[i].Id_usuario == id_user){
                usuarios[i].Id_usuario = usuarios[i+1].Id_usuario;
                strcpy(usuarios[i].Nomb_usuario, usuarios[i+1].Nomb_usuario);
                strcpy(usuarios[i].Localidad, usuarios[i+1].Localidad);
                usuarios[i].Perfil_usuario = usuarios[i+1].Perfil_usuario;
                strcpy(usuarios[i].User, usuarios[i+1].User);
                strcpy(usuarios[i].Login, usuarios[i+1].Login);
                usuarios[i].Estado = usuarios[i+1].Estado;
            }
        }
        (*j)--;
        usuarios = (Usuarios*)realloc(usuarios, ((*j+1)*sizeof(Usuarios)));
        printf("\nSe ha eliminado el user correctamente\n");
    }else{
        printf("\nSe ha cancelado la eliminaci%cn del user\n", 162);
        exit(1);
    }
}

void op3_usuarios(Usuarios *usuarios, int num_usuarios){

    int id_user, i, n=0;

    puts("Qué usuario desea modificar? Introduce su User de sistema: ");
    scanf("%d", &id_user);
    flush_in();

    for(i=0;i<num_usuarios;i++){
        if(usuarios[i].Id_usuario == id_user){
            puts("Id del nuevo usuario: ");
            scanf("%d", &usuarios[i].Id_usuario);
            flush_in();

            puts("Nombre del nuevo usuario: ");
            scanf("%20s", usuarios[i].Nomb_usuario);
            flush_in();

            puts("Localidad: ");
            scanf("%20s", usuarios[i].Localidad);
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
                    usuarios[i].Perfil_usuario = 0;
                    break;
                case 2:
                    usuarios[i].Perfil_usuario = 1;
                    break;
                default:
                    puts("ERROR: La opcion introducida no es valida");
            }

            puts("User de inicio de sesión: ");
            scanf("%15s", usuarios[i].User);
            flush_in();

            puts("Contrasña: ");
            scanf("%8s", usuarios[i].Login);
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
                    usuarios[i].Estado=0;
                    break;

                case 2:
                    usuarios[i].Estado=1;
                    break;
                default:
                    puts("ERROR: La opcion introducida no es valida");
            }
        }
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
