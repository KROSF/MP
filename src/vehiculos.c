#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vehiculos.h"
#include "utilidades.h"

/**
 * Se le llama desde bajaVehiculos, libera el espacio en memoria.
 * @param VECTOR VEHÍCULO
 * @param vIndex ÍNDICE EN EL VECTOR VEHÍCULOS
 */
static void eliminarVehiculo(vVehiculos* v,int vIndex)
{
    free(v->vehi[vIndex].Id_mat);
    free(v->vehi[vIndex].Desc_veh);
    memmove(&v->vehi[vIndex],&v->vehi[vIndex+1],(v->tam-vIndex-1)*sizeof(Vehiculos));
    --v->tam;
}

/**
 * Elimina el vehículo según sea la matrícula referenciada
 * @param VECTOR VEHÍCULO
 * @param mat MATRÍCULA DEL VEHÍCULO CON EL QUE SE ESTÁ TRABAJANDO.
 */
static void bajaVehiculos(vVehiculos* v, char* mat)
{
    int index = buscarIndexVehiculo(v,mat);
    if(index > -1)
    {
        eliminarVehiculo(v,index);
    }else printf("No existe un vehiculo con dicha matricula\n");
}

/**
 * Se introduce la matricula. Es una funcion a la que se le llama desde otra. (modificarVehiculo)
 * @param v      VECTOR VEHÍCULO
 * @param vIndex ÍNDICE EN EL VECTOR VEHÍCULOS
 */
static void matricula(vVehiculos* v,int vIndex)
{
    int tmp = 0;
    char tmpc[3];
    do{
        printf("Ingrese matricula: ");
        scanf("%7[^\n]",v->vehi[vIndex].Id_mat);
        flush_in();
    }while( sscanf(v->vehi[vIndex].Id_mat,"%4d%3s",&tmp,tmpc) != 2);
}

/**
 * Se introduce la descripción del vehículo. Es una función a la que se le llama desde otra. (modificarVehiculo)
 * @param v      VECTOR VEHÍCULO
 * @param vIndex ÍNDICE EN EL VECTOR VEHÍCULOS
 */
static void descripcion(vVehiculos* v,int vIndex)
{
    printf("Ingrese descripcion: ");
    scanf("%50[^\n]",v->vehi[vIndex].Desc_veh);
    flush_in();
}

/**
 * Se introduce el numero de plazas del vehículo. Es una función a la que se le llama desde otra. (modificarVehiculo)
 * @param v      VECTOR VEHÍCULO
 * @param vIndex ÍNDICE EN EL VECTOR VEHÍCULOS
 */
static void num_plazas(vVehiculos* v,int vIndex)
{
    printf("Ingrese numero de plazas: ");
    scanf("%1d[^\n]",&v->vehi[vIndex].Num_plazas);
    flush_in();
}

/**
 * Cambia el parámetro identificativo deseado del coche especificado. Llama a otras funciones.
 * @param v   VECTOR VEHÍCULO
 * @param mat MATRÍCULA DEL VEHÍCULO CON EL QUE SE ESTÁ TRABAJANDO.
 */
static void modificarVehiculo(vVehiculos* v,char* mat)
{
    int tmp = 0, index = buscarIndexVehiculo(v,mat);
    if(index > - 1)
    {
        printf(" 1. Matricula\n 2. Descripcion\n 3. Numero de Plazas\n");
        printf("Seleccione una opcion: ");
        scanf("%1d[^\n]",&tmp);
        flush_in();
        switch (tmp) {
            case 1:matricula(v,index);break;
            case 2:descripcion(v,index);break;
            case 3:num_plazas(v,index);break;
            default:printf("Opcion no valida no se hace nada.\n");break;
        }
    }
}



/***
*      ____ __ __ __  __   ___ __   ___   __  __  ____  __
*     ||    || || ||\ ||  //   ||  // \\  ||\ || ||    (( \
*     ||==  || || ||\\|| ((    || ((   )) ||\\|| ||==   \\
*     ||    \\_// || \||  \\__ ||  \\_//  || \|| ||___ \_))
*
*               ____  __ __ ____  __    __   ___  ___   __
*               || \\ || || || )) ||    ||  //   // \\ (( \
*               ||_// || || ||=)  ||    || ((    ||=||  \\
*               ||    \\_// ||_)) ||__| ||  \\__ || || \_))
*/

/*
 * Inicializa los vehículos.
 */
Vehiculos* initVehiculos(int * n)
{
    FILE* file = fopen("ficheros/Vehiculos.txt", "r");
    if (file == NULL ) exit(1);
    char *mat,*idu,*nplzs,*des_veh;
    Vehiculos *tmp=NULL;
    (*n)=0;
    while(!feof(file))
    {
        mat     = (char*) malloc( ID_MAT     * sizeof(char));
        idu     = (char*) malloc( ID_USUARIO * sizeof(char));
        nplzs   = (char*) malloc( NPLAZS     * sizeof(char));
        des_veh = (char*) malloc( DES_VEH    * sizeof(char));

        if(mat == NULL || idu == NULL || nplzs == NULL || des_veh == NULL) exit(1);
        fscanf(file, "%[^-]-%[^-]-%[^-]-%[^\n]\n", mat, idu, nplzs,des_veh);

        tmp = (Vehiculos *) realloc(tmp,(*n+1) * sizeof(Vehiculos));

        tmp[*n].Id_usuario = atoi(idu);
        tmp[*n].Id_mat     = mat;
        tmp[*n].Desc_veh   = des_veh;
        tmp[*n].Num_plazas = atoi(nplzs);
        (*n)++;
        free(idu);
        free(nplzs);
    }
    fclose(file);
    return tmp;
}
/*
 * Guarda los vehículos.
 */
void saveVehiculos(int n ,Vehiculos* vehiculos)
{
    FILE* file = fopen("ficheros/Vehiculos.txt","w+");
    if (file==NULL) exit(1);
    for (int i = 0 ; i < n; ++i ){
        fprintf(file,"%s-%04d-%d-%s\n",
        vehiculos[i].Id_mat,
        vehiculos[i].Id_usuario,
        vehiculos[i].Num_plazas,
        vehiculos[i].Desc_veh);
        free(vehiculos[i].Id_mat);
        free(vehiculos[i].Desc_veh);
    }
    fclose(file);
    puts("Vehiculos Guardados");
}
/*
 * Función de usuario para dar de alta un vehiculo que posee.
 * @param v VECTOR VEHÍCULO
 * @param userId IDENTIFICADOR DEL USUARIO LOGUEADO
 */
void altaVehiculos(vVehiculos* v,int userId)//opc2user
{
    v->vehi = (Vehiculos*) realloc(v->vehi,(v->tam+1)  * sizeof(Vehiculos));
    v->vehi[v->tam].Id_mat   = (char*) malloc( ID_MAT  * sizeof(char));
    v->vehi[v->tam].Desc_veh = (char*) malloc( DES_VEH * sizeof(char));
    v->vehi[v->tam].Id_usuario = userId;
    matricula(v,v->tam);
    descripcion(v,v->tam);
    num_plazas(v,v->tam);
    ++v->tam;
}
/*
 * Busca un vehículo por su matrícula y devuelve su posición en el vector vehículos.
 * @param v VECTOR VEHÍCULO
 * @param mat MATRÍCULA DEL VEHÍCULO CON EL QUE SE ESTÁ TRABAJANDO.
 */
int buscarIndexVehiculo(vVehiculos* v,char* mat)
{
    for(int i = 0; i < v->tam ; ++i)
    {
      if(strcmp(mat,v->vehi[i].Id_mat) == 0) return i;
    }
    return -1;
}
/*
 * Lista todos los vehículos de la base de datos, es una función exclusiva para el administrador.
 * @param v VECTOR VEHÍCULO
 */
void listarVehiculos(vVehiculos* v)
{
    CLEAN;
    for(int i = 0; i < v->tam;++i)
    {
        printf("%s-%d-%d-%s\n",
            v->vehi[i].Id_mat,
            v->vehi[i].Id_usuario,
            v->vehi[i].Num_plazas,
            v->vehi[i].Desc_veh);
    }
    system_pause();
}
/*
 *ESTA NO SE LO QUE HACE XD
 */
int* listarVehiculosViajes(vVehiculos* v,int id_user,int *j)
{
  int* tmp = NULL;
  *j = 0;
  for(int i = 0; i < v->tam;++i){
      if(id_user == v->vehi[i].Id_usuario)
      {
          tmp = (int *) realloc(tmp,((*j)+1) * sizeof(int));
          tmp[(*j)] = i;
          (*j)++;
      }
  }
  return tmp;
}
/*
 * Lista los vehículos que el usuario logueado posee.
 * @param v VECTOR VEHÍCULO
 * @param userId IDENTIFICADOR DEL USUARIO LOGUEADO
 */
void listarVehiculosUser(vVehiculos* v,int userId)//opc1 viajes user
{
    int taman = 0;
    int* i_veh = listarVehiculosViajes(v,userId, &taman);

    if(taman!=0){
        printf("Vehiculos disponibles: ");
        for(int i=0; i < taman; i++){
            printf("%s, %s\n", v->vehi[i_veh[i]].Id_mat, v->vehi[i_veh[i]].Desc_veh);
        }
    }else{
        printf("No se han encontrado vehiculos disponibles para el user: %d\n", userId);
    }
    free(i_veh);
}
/*
 * El usuario puede modificar cualidades del/los vehículo/s que posee.
 * @param v VECTOR VEHÍCULO
 * @param userId IDENTIFICADOR DEL USUARIO LOGUEADO
 */
void modificarVehiculoUser(vVehiculos* v,int userId)
{
  int veh_size = 0,resp = 0;
  int* i_veh = listarVehiculosViajes(v,userId, &veh_size);
  if(veh_size != 0)
  {
    for (int i = 0; i < veh_size; i++) {
      printf("%d %s, %s\n", i+1,v->vehi[i_veh[i]].Id_mat, v->vehi[i_veh[i]].Desc_veh);
    }
    printf("Que vehiculo desea modificar: \n");
    scanf("%d[^\n]",&resp);
    flush_in();
    --resp;
    if(resp >= 0 && resp < veh_size)
    {
        modificarVehiculo(v,v->vehi[i_veh[resp]].Id_mat);
    }
  }
  else printf("No tiene Vehiculos registrados\n");
  free(i_veh);
}
/*
 * El usuario puede eliminar uno de sus vehículos.
 * @param v VECTOR VEHÍCULO
 * @param userId IDENTIFICADOR DEL USUARIO LOGUEADO
 */
void eliminarVehiculoUser(vVehiculos* v,int userId)
{
  int veh_size = 0,resp = 0;
  int* i_veh = listarVehiculosViajes(v,userId, &veh_size);
  if(veh_size != 0)
  {
    for (int i = 0; i < veh_size; i++) {
      printf("%s, %s\n", v->vehi[i_veh[i]].Id_mat, v->vehi[i_veh[i]].Desc_veh);
    }
    printf("Que vehiculo desea eliminar: \n");
    scanf("%d[^\n]",&resp);
    flush_in();
    --resp;
    if(resp >= 0 && resp < veh_size)
    {
        eliminarVehiculo(v,buscarIndexVehiculo(v,v->vehi[i_veh[resp]].Id_mat));
    }
  }
  else printf("No tiene Vehiculos registrados\n");
  free(i_veh);
}
/*
 * El admin da de alta un vehículo en la base de datos.
 * @param v VECTOR VEHÍCULO
 */
void altaVehiculosAdmin(vVehiculos* v)
{
  int tmp;
  printf("Introduzca el id del usuario a que pertenece el vehiculo: ");
  scanf("%d", &tmp);
  flush_in();
  altaVehiculos(v,tmp);
}
/*
 * El admin elimina un vehículo de la base de datos.
 * @PARAM V VECTOR VEHÍCULO
 */
void bajaVehiculosAdmin(vVehiculos* v)
{
  char tmp[ID_MAT];
  printf("Introduzca matricula del coche: ");
  scanf("%7[^\n]", tmp);
  flush_in();
  bajaVehiculos(v,tmp);
}
/*
 * El admin modifica un vehíuculo de la base de datos.
 * @param v VECTOR VEHÍCULO
 */
void modificarVehiculosAdmin(vVehiculos* v)
{
  char tmp[ID_MAT];
  printf("Introduzca matricula del coche: ");
  scanf("%7[^\n]", tmp);
  flush_in();
  modificarVehiculo(v,tmp);
}
