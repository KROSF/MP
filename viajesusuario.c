//
// Created by Jesús de la Higuera on 11/4/18.
//
#include <stdio.h>
#include "viajesusuario.h"
#include "utilidades.h"


void viajeuser(Viajes* viajes, int* num_struct, int usuarioactual){
    int opc;
    printf(" /* LISTA DE VIAJES ABIERTOS */");

    for(int i=0; i< num_struct[2]; i++){
        if(viajes[i].Estado == 1){// 0 cerrado, 1 abierto
            printf(" %d-%s-%s-%s-%s-%d-%f\n",
                   viajes[i].Id_viaje,
                   viajes[i].Id_mat,
                   viajes[i].F_inic,
                   viajes[i].H_inic,
                   viajes[i].H_fin,
                   viajes[i].Plazas_libre,
                   viajes[i].Importe);
        }
    }
        printf("\n |______________________________|\n");
        printf(" |                              |\n");
        printf(" |    1. EDITAR VIAJE           |\n");
        printf(" |    2. PUBLICAR VIAJE         |\n");
        printf(" |    3. INCORPORARSE A VIAJE   |\n");
        printf(" |    4. LISTADO DE VIAJES      |\n");
        printf(" |______________________________|");

        do{
            printf("Seleccione una opcion: ");
            scanf("%d",&opc);
            switch(opc) {
                case 1:
                    editarviajeusuario(usuarioactual,usuarios,viajes,vehiculos);
                    break;
                case 2:
                    publicarviajeusuario();
                    break;
                case 3:
                    incorporarseaviajeusuario();
                    break;
                case 4:
                    listadoviajesusuario();
                    break;
                default:
                    printf("Opcion incorrecta.\n");
            }
        }while(opc<1 || opc>4);

    }

void editarviajeusuario(int actuser,Usuarios* usuarios,Viajes* viajes,Vehiculos* vehiculos,int* tam)
{
  int id_editar = 0;
  puts("Ingrese Id_viaje a editar");
  scanf("%d",&id_editar);
  flush_in();
  int ve_edit,edit = buscarViajesIndex(viajes,tam[2],id_editar);
  if (viajes[edit].Plazas_libre > 0){
    if(edit > 0) {
      ve_edit = buscarVehiculosIndex(vehiculos,tam[1],viajes[edit].Id_mat);
      if(ve_edit > 0){
        if( actuser == vehiculos[ve_edit].Id_usuario){
          int fechac = 0, horac = 0,tmp = 0;
          do{
            printf("Fecha del viaje: ");
            scanf("%10s", viajes[edit].F_inic);
            flush_in();                             //
            fechac = validarFecha(viajes[edit].F_inic);
          }while(fechac < 0);

          do {
            puts("Hora de incio: ");
            scanf("%5s", viajes[edit].H_inic);
            flush_in();
            horac = validarHora(viajes[edit].H_inic, fechac);
          }while(horac == 0);

          do {
            puts("Hora fin: ");
            scanf("%5s", viajes[edit].H_inic);
            flush_in();
            horac = validarHora(viajes[edit].H_inic,0);
          }while(horac == 0);

          do {
            puts("Precio: ");
            scanf("%f", &viajes[edit].Importe);
            flush_in();
          }while(viajes[edit].Importe < 0);

          do{
            puts("Seleccione el tipo de viaje:");
            puts("1) Ida");
            puts("2) Vuelta");
            scanf("%d",&tmp);
            flush_in();
          }while(tmp < 1 || tmp >2);
          viajes[edit].Viaje = (tmp == 1 )? 1 : 0 ;
          do{
            puts("Seleccione el tipo de viaje:");
            puts("0) Cerrado");
            puts("1) Abierto");
            puts("2) Iniciado");
            puts("3) Finalizado");
            puts("4) Anulado");
            scanf("%d",&tmp);
            flush_in();
          }while(tmp < 0 || tmp > 4);
          viajes[edit].Estado = tmp;
        }
      }
    }
  }else printf("No puede editar este viaje o no existe\n");
}



void publicarviajeusuario(Usuarios *usuarios, Viajes *viajes, Vehiculos *vehiculos int usuarioactual, int *tam_viajes){

    int sel;  //vehiculo seleccionado
    int *vehiculosusuario= todoVehiculosUser(vehiculos, tam_vehiculos, usuarioactual );

    if(vh[0]== 1){
        printf("No es posible publicar viaje ya que0));
    if(d < t2->tm_mday || d > (DiaMes[m]+bisiesto) ) return -1; no tienes vehiculo registrado.\n");
    }else{
        printf("Vehiculos disponibles\n");
        for(int i=1; i < vehiculosusuario[0] -1; i++){
            printf("%s-%d plazas-%s\n",vehiculos[vehiculosusuario[i]].Id_mat,
                                       vehiculos[vehiculosusuario[i]].Num_plazas,
                                       vehiculos[vehiculosusuario[i]].Desc_veh);
        }
        printf("Selecccione un vehiculo: ");
        scanf("%d",&sel);


        viajes=(Viajes*)realloc(usuarios,(*tam_viajes+1)*sizeof(Viajes);
        (*tam_viajes)++;

        viajes[*tam_viajes].Plazas_libre =

    }
}
