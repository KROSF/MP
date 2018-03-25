#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "acceso.h"
static int check_user(Usuarios* usuarios, int n);
int check_user(Usuarios* usuarios,int n)
{
    int logincount = 0, i;
    char user[6];
    char pass[9];
    while (logincount < 3) {
        printf("Usuario: ");
        scanf("%5[^\n]",user);
        flush_in();

        printf("Contraseña: ");
        scanf("%8[^\n]",pass);
        flush_in();
        for( i = 0 ; i < n ; ++i )
        {
            if( strcmp(usuarios[i].User,user) == 0 &&
                strcmp(usuarios[i].Login,pass) == 0)
                return i;
        }
        system("clear");
        logincount++;
        printf("Usuario y/o Contraseña Incorrectos\n");
        printf("Vuelta a intentarlo \n\n");
    }
    return -1;
}
void flush_in() {
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){}
}
void acceder(Usuarios* usuarios,int n)
{
    int check = check_user(usuarios,n);
    if( check > -1 )
    {
        if(usuarios[check].Perfil_usuario == 0) printf("soy administrador\n");
        else printf("soy usuario\n");
    }
    else
    {
        printf("El numero de intentos ha sido superado\n");
        exit(1);

    }
}