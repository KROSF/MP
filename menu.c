#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "menu.h"
#include "usuarios.h"
#include "viajes.h"

void menuUser(vUsuarios* v,vIncidencias* vi,vViajes* vv,vVehiculos* vve,int id){
    system("clear");
    int i=strlen(v->user[id].Nomb_usuario),j,espacio,opc;
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
    printf("%s",v->user[id].Nomb_usuario);
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
        printf("\nSeleccione una opcion: ");
        scanf("%d",&opc);
        flush_in();
        CLEAN;
    switch(opc) {
        case 1:
            perfilUsuario(v,id);
            break;
        case 2:
            //vehiculosuser();
            printf("Vehiculos");
            break;
        case 3:
            //viajesuser();
            printf("Viajes");
            break;
        case 4:
            //incidenciasuser();
            printf("Incidencias");
            break;
        default:
            printf("Opcion incorrecta.\n");
    }
    }while(opc<1 || opc>4);
}


void menuAdmin(vUsuarios* v,vIncidencias* vi,vViajes* vv,vVehiculos* vve,int id){
    system("clear");
    int i=strlen(v->user[id].Nomb_usuario),j,espacio,opc; // TAMAÑO TEXTO
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
    printf("%s",v->user[id].Nomb_usuario);
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
        printf("\nSeleccione una opcion: ");
        scanf("%d",&opc);
        flush_in();
        CLEAN;
        switch(opc) {
            case 1:
                //usuariosadmin();
                publicarViaje(vv,vve,"7886JJP");
                break;
            case 2:
                //vehiculosadmin();
                printf("vehiculosadmin");
                break;
            case 3:
                //viajesadmin();
                listarViajesAdmin(vv);
                break;
            case 4:
                //incidenciasadmin();
                printf("incidenciasadmin");
                break;
            default:
                printf("Opcion incorrecta.\n");
        }
    }while(opc<1 || opc>4);
}
