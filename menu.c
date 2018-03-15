//
// Created by theje on 15/03/2018.
//

#include "menu.h"
#include "usuarios.h"
#include "stdio.h"

void menuuser(){
    int i,j,espacio,opc; // TAMAÑO TEXTO
    char t[21];
    char caca[21]= "prueba"; // usuario  a escribir en pantalla
    for(i=0;caca[i]!='\0';i++);
    if(i%2==0){
        printf("  ______________________\n");
        printf(" |                      |\n |");
        espacio=(23-i)/2;  // 24 asteriscos (nombre par)
    }else{
        printf("  _______________________\n");
        printf(" |                       |\n |");
        espacio=(24-i)/2; // 25 asteriscos (nombre impar)
    }

    for(j=0;j<espacio;j++){
        printf(" ");
    }
    printf("%s",caca);
    for(j=0;j<espacio;j++){
        printf(" ");
    }

    if(i%2==0){

        printf("|\n |______________________|\n");
        printf(" |                      |\n");
        printf(" |    1. PERFIL         |\n");
        printf(" |    2. VEHICULOS      |\n");
        printf(" |    3. VIAJES         |\n");
        printf(" |    4. INCIDENCIAS    |\n");
        printf(" |______________________|");
    }else{

        printf("|\n |_______________________|\n");
        printf(" |                       |\n");
        printf(" |     1. PERFIL         |\n");
        printf(" |     2. VEHICULOS      |\n");
        printf(" |     3. VIAJES         |\n");
        printf(" |     4. INCIDENCIAS    |\n");
        printf(" |_______________________|");
    }
    do{
        printf("Seleccione una opcion: ");
        scanf("%d",&opc);
    switch(opc) {
        case 1:
            perfiluser();
            break;
        case 2:
            vehiculosuser();
            break;
        case 3:
            viajesuser();
            break;
        case 4:
            incidenciasuser();
            break;
        default:
            printf("Opcion incorrecta.\n");
    }
    }while(opc<1 || opc>4);



}


void menuadmin(){

    int i,j,espacio,opc; // TAMAÑO TEXTO
    char t[21];
    char caca[21]= "pene";
    for(i=0;caca[i]!='\0';i++);
    if(i%2==0){
        printf("  ______________________\n");
        printf(" |                      |\n |");
        espacio=(23-i)/2;  // 24 asteriscos (nombre par)
    }else{
        printf("  _______________________\n");
        printf(" |                       |\n |");
        espacio=(24-i)/2; // 25 asteriscos (nombre impar)
    }

    for(j=0;j<espacio;j++){
        printf(" ");
    }
    printf("%s",caca);
    for(j=0;j<espacio;j++){
        printf(" ");
    }

    if(i%2==0){

        printf("|\n |______________________|\n");
        printf(" |                      |\n");
        printf(" |    1. USUARIOS       |\n");
        printf(" |    2. VEHICULOS      |\n");
        printf(" |    3. VIAJES         |\n");
        printf(" |    4. INCIDENCIAS    |\n");
        printf(" |______________________|");
    }else{

        printf("|\n |_______________________|\n");
        printf(" |                       |\n");
        printf(" |     1. USUARIOS       |\n");
        printf(" |     2. VEHICULOS      |\n");
        printf(" |     3. VIAJES         |\n");
        printf(" |     4. INCIDENCIAS    |\n");
        printf(" |_______________________|");
    }

    do{
        printf("Seleccione una opcion: ");
        scanf("%d",&opc);
        switch(opc) {
            case 1:
                usuariosadmin();
                break;
            case 2:
                vehiculosadmin();
                break;
            case 3:
                viajesadmin();
                break;
            case 4:
                incidenciasadmin();
                break;
            default:
                printf("Opcion incorrecta.\n");
        }
    }while(opc<1 || opc>4);

}