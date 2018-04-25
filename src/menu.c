#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "menu.h"
#include "usuarios.h"
#include "viajes.h"

static void adminUsuarios(vUsuarios* v,vIncidencias* i);
static void adminVehiculos(vVehiculos* v);
static void adminViajes(vViajes* v, vVehiculos* vve);
static void adminIncidencias(vIncidencias* v,vViajes* vv,vVehiculos* ve);


void menuUser(vUsuarios* v,vIncidencias* vi,vViajes* vv,vVehiculos* vve,int id){
    CLEAN;
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
        case 2:break;
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
    CLEAN;
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
            case 1:adminUsuarios(v,vi);break;
            case 2:adminVehiculos(vve);break;
            case 3:adminViajes(vv,vve);break;
            case 4:adminIncidencias(vi,vv,vve);break;
            default:
                printf("Opcion incorrecta.\n");
        }
    }while(opc<1 || opc>4);
}


void adminUsuarios(vUsuarios* v,vIncidencias* i){

    int opc;

    printf("\n  ___________________________\n");
    printf(" |                           |\n");
    printf(" |    1. ALTA USUARIO        |\n");
    printf(" |    2. BAJA USUARIO        |\n");
    printf(" |    3. MODIFICAR USUARIO   |\n");
    printf(" |    4. LISTAR USUARIOS     |\n");
    printf(" |___________________________|");

     do{
        printf("\n\n  Seleccione una opción: ");
        scanf("%d",&opc);
        flush_in();
     switch(opc) {
        case 1:
            altaUsuario(v);
            break;
        case 2:
            //ppreguntar id a elimar a admin
            //aun falta enmascarar
            preguntarIdBaja(v);
            break;
        case 3:
        //ppreguntar id admin y pasar index
            modificarUsuario(v,preguntarIdModificar());
            break;
        case 4:
            listarUsuarios(v,i);//funciona perfe
            break;
        default:
            printf("Opcion incorrecta.");
     }
    }while(opc<1 || opc>4);

}


void adminVehiculos(vVehiculos* v){

    int opc;

    printf("\n  ____________________________\n");
    printf(" |                            |\n");
    printf(" |    1. ALTA VEHICULO        |\n");
    printf(" |    2. BAJA VEHICULO        |\n");
    printf(" |    3. MODIFICAR VEHICULO   |\n");
    printf(" |    4. LISTAR VEHICULOS     |\n");
    printf(" |____________________________|");

    do{
        printf("\n\n  Seleccione una opción: ");
        scanf("%d",&opc);
        flush_in();
        switch(opc) {
            case 1:
                //preguntar id al que pertenecera el vehiculo
                altaVehiculos(v,100);//perfe
                break;
            case 2:
            //preguntar matricula
                bajaVehiculos(v,"1234ABC");//perfe
                break;
            case 3:
            //preguntar matricula
                modificarVehiculo(v,"7886JJP");
                break;
            case 4:
                listarVehiculos(v);//perfe
                break;
            default:
                printf("Opcion incorrecta.");
        }
    }while(opc<1 || opc>4);

}

void adminViajes(vViajes* v, vVehiculos* vve){

    int opc;

    printf("\n  __________________________\n");
    printf(" |                          |\n");
    printf(" |    1. PUBLICAR VIAJE     |\n");
    printf(" |    2. ELIMINAR VIAJE     |\n");
    printf(" |    3. MODIFICAR VIAJE    |\n");
    printf(" |    4. LISTAR VIAJES      |\n");
    printf(" |__________________________|");

    do{
        printf("\n\n  Seleccione una opción: ");
        scanf("%d",&opc);
        flush_in();
        switch(opc) {
            case 1:
            //pedir matricula admin
                publicarViaje(v,vve,"7886JJP");
                break;
            case 2:
            //pedir id_viaje admin
                eliminarViajes(v,4);
                break;
            case 3:
            //pedir id viaje admin
                modificarViaje(v,vve,4);
                break;
            case 4:
                listarViajesAdmin(v);
                break;
            default:
                printf("Opcion incorrecta.");
        }
    }while(opc<1 || opc>4);

}
void adminIncidencias(vIncidencias* v,vViajes* vv,vVehiculos* ve){

    int opc;

    printf("\n  _______________________________\n");
    printf(" |                               |\n");
    printf(" |    1. CREAR INCIDENCIA        |\n");
    printf(" |    2. ELIMINAR INCIDENCIA     |\n");
    printf(" |    3. MODIFICAR INCIDENCIA    |\n");
    printf(" |    4. LISTAR INCIDENCIAS      |\n");
    printf(" |_______________________________|");

    do{
        printf("\n\n  Seleccione una opción: ");
        scanf("%d",&opc);
        flush_in();
        switch(opc) {
            case 1:
            //preguntar id_viaje al que quiere agregar la incidencia
                crearIncidencias(v,vv,ve,2232);
                break;
            case 2:
            //preguntar id_viaje del que se quiere elimiar la incidencia
                eliminarIncidencias(v,vv,2232);
                break;
            case 3:
            //preguntar id_viaje del que se quiere modificar la incidencia
                modificarIncidencias(v,2232);
                break;
            case 4:
                listarIncidencias(v);
                break;
            default:
                printf("Opcion incorrecta.");
        }
    }while(opc<1 || opc>4);
}
