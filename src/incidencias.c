#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "incidencias.h"
#include "utilidades.h"
/**
 * Constante para obtener el estado de una incidencia.
 */
static const char * Estado_I[] = {"cerrada","abierta","validada"};

/**
 * Devuelve el estado de la incidencia en cuestión a la función que la llama.
 * @param  c [description]
 * @return   [description]
 */
static int estadoIncidencia(char **c)
{
    if(strcmp(*c,"cerrada") == 0) return 0;
    if(strcmp(*c,"abierta")== 0) return 1;
    return 2;
}

/**
 * Recoge el ID del usuario denunciante.
 * @param v      [description]
 * @param iIndex [description]
 */
static void idRegistar(vIncidencias* v,int iIndex)
{
    printf("Ingrese id_usuario que registra la incidencia: ");
    scanf("%4d[^\n]",&v->inci[iIndex].Id_us_registra);
    flush_in();
}

/**
 * Lista todas las incidencias de la base de datos.
 * @param  v
 * @param  id_viaje
 * @param  j
 */
static int* listaIncidencias(vIncidencias* v,int id_viaje,int* j)
{
    int* tmp = NULL;
    *j = 0;
    for(int i = 0; i < v->tam;++i){
        if(id_viaje == v->inci[i].Id_viaje)
        {
            tmp = (int *) realloc(tmp,(*j+1) * sizeof(int));
            tmp[(*j)++] = i;
        }
    }
    return tmp;
}

/**
 * Aquí se introduce una breve descripción de la incidencia en cuestión.
 * @param v      [description]
 * @param iIndex [description]
 */
static void descripcionIncidencia(vIncidencias* v,int iIndex)
{
    printf("Ingrese id_usuario que registra la incidencia: ");
    scanf("%100[^\n]",v->inci[iIndex].Desc_incidencia);
    flush_in();
}

/**
 * Esta función crea desde cero una incidencia que no existe.
 * @param v VECTOR INCIDENCIAS
 * @param vv VECTOR VIAJES
 * @param ve VECTOR VEHICULOS
 * @param index IDENTIFICADOR (INDICE) DE LA INCIDENCIA EN EL VECTOR INCIDENCIAS.
 * @param usuario IDENTIFICADOR DEL USUARIO LOGUEADO O DENUNCIANTE
 */
static void crearIncidencias(vIncidencias* v,vViajes* vv,vVehiculos* ve,int index,int usuario)
{
    v->inci = (Incidencias*)realloc(v->inci,(v->tam+1) * sizeof(Incidencias));
    v->inci[v->tam].Desc_incidencia = (char *)malloc(DES_INCI * sizeof(char));
    v->inci[v->tam].Est_incidencia = 1;
    v->inci[v->tam].Id_viaje = vv->viajes[index].Id_viaje;
    v->inci[v->tam].Id_us_incidencia = ve->vehi[buscarIndexVehiculo(ve,vv->viajes[index].Id_mat)].Id_usuario;
    if(usuario != 0) idRegistar(v,v->tam);
    else v->inci[v->tam].Id_us_registra = usuario;
    descripcionIncidencia(v,v->tam);
    ++v->tam;
}

/**
 * Esta función libera la memoria ocupada por la incidencia eliminada en cuestión.
 * @param v      VECTOR INCIDENCIAS]
 * @param iIndex [description]
 */
static void eliminarIncidencia(vIncidencias* v, int iIndex)
{
    free(v->inci[iIndex].Desc_incidencia);
    memmove(&v->inci[iIndex],&v->inci[iIndex+1],(v->tam-iIndex-1)*sizeof(Pasos));
    --v->tam;
}

/**
 * Esta función lista las incidencias y da la opción de eliminar la incidencia desada.
 * @param v VECTOR INCIDENCIAS
 * @param vi
 * @param id_viaje
 */
static void eliminarIncidencias(vIncidencias* v,vViajes* vi,int id_viaje)
{
    int resp = 0,index = buscarIndexViajes(vi,id_viaje);
    if(index > -1)
    {
        int size_l = 0,i;
        int* l_inci = listaIncidencias(v,id_viaje,&size_l);
        for(i = 0;i < size_l;++i)
        {
            printf(" %d. denunciante: %d * denunciado: %d\n",i+1,
            v->inci[l_inci[i]].Id_us_registra,v->inci[l_inci[i]].Id_us_incidencia);
        }
        printf(" %d. Todas\n",i+1);
        printf("Que incidencia desea eliminar: \n");
        scanf("%d[^\n]",&resp);
        flush_in();
        --resp;
        if(resp >= 0 && resp < size_l)
        {
            eliminarIncidencia(v,l_inci[resp]);
        }
        if(resp == size_l)
        {
            for(i = 0;i < size_l;++i) eliminarIncidencia(v,l_inci[i]);
        }
        free(l_inci);
    }
}

/**
 * Modifica el estado de una incidencia que se pasa como parámetro.
 * @param v      VECTOR INCIDENCIAS
 * @param iIndex [description]
 */
static void modificarEstadoIncidencia(vIncidencias* v, int iIndex)
{
    int tmp = 0;
    do{
        puts("0) Cerrada");
        puts("1) Abierta");
        puts("2) Validada");
        printf("Seleccione estado: ");
        scanf("%1d[^\n]",&tmp);
        flush_in();
    }while(tmp < 0 && tmp > 2);
    v->inci[iIndex].Est_incidencia = tmp;
}

/**
 * En esta función se muestra un menú que permite editar cómodamente el contenido informativo de las incidencias.
 * @param v        VECTOR INCIDENCIAS
 * @param id_viaje [description]
 */
static void modificarIncidencias(vIncidencias* v,int id_viaje)
{
        int size_l = 0, i, resp = 0;
        int* l_inci = listaIncidencias(v,id_viaje,&size_l);
        for(i = 0;i < size_l;++i)
        {
            printf(" %d. denunciante: %d * denunciado: %d\n",i+1,
            v->inci[l_inci[i]].Id_us_registra,v->inci[l_inci[i]].Id_us_incidencia);
        }
        printf("Que incidencia desea modificar: \n");
        scanf("%d[^\n]",&resp);
        flush_in();
        --resp;
        if(resp >= 0 && resp < size_l)
        {
            descripcionIncidencia(v,l_inci[resp]);
            modificarEstadoIncidencia(v,l_inci[resp]);
        }
        free(l_inci);
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

Incidencias* initIncidencias(int* n)
{
    FILE* file = fopen("ficheros/Incidencias.txt", "r");
    if (file == NULL ) exit(1);
    (*n)=0;
    Incidencias *tmp = NULL;
    char *id_viaje,*id_us_registra,*id_us_incidencia,*desc_inicidencia,*estado;
    while(!feof(file))
    {
        id_viaje         = (char *)malloc( ID_VIAJE   * sizeof(char));
        id_us_registra   = (char *)malloc( ID_USUARIO * sizeof(char));
        id_us_incidencia = (char *)malloc( ID_USUARIO * sizeof(char));
        desc_inicidencia = (char *)malloc( DES_INCI   * sizeof(char));
        estado           = (char *)malloc( ESTADO_I   * sizeof(char));

        if( id_viaje == NULL || id_us_incidencia == NULL ||
            id_us_registra == NULL || desc_inicidencia == NULL ||
            estado == NULL) exit(1);

        fscanf(file,"%[^-]-%[^-]-%[^-]-%[^-]-%[^\n]\n",
        id_viaje,id_us_registra,id_us_incidencia,desc_inicidencia,estado);

        tmp = (Incidencias *) realloc(tmp,(*n+1) * sizeof(Incidencias));

        tmp[*n].Id_viaje         = atoi(id_viaje);
        tmp[*n].Id_us_registra   = atoi(id_us_registra);
        tmp[*n].Id_us_incidencia = atoi(id_us_incidencia);
        tmp[*n].Desc_incidencia  = desc_inicidencia;
        tmp[*n].Est_incidencia   = estadoIncidencia(&estado);
        free(id_viaje);
        free(id_us_incidencia);
        free(id_us_registra);
        free(estado);
        (*n)++;
    }
    fclose(file);
    return tmp;
}

void saveIncidencias(int n,Incidencias* incidencias)
{
    FILE* file = fopen("ficheros/Incidencias.txt","w+");
    if (file==NULL) exit(1);
    int i;
    for ( i = 0 ; i < n; ++i ){
        fprintf(file,"%06d-%04d-%04d-%s-%s\n",
        incidencias[i].Id_viaje,
        incidencias[i].Id_us_registra,
        incidencias[i].Id_us_incidencia,
        incidencias[i].Desc_incidencia,
        Estado_I[incidencias[i].Est_incidencia]);
        free(incidencias[i].Desc_incidencia);
    }
    fclose(file);
    puts("Incidencias Guardadas");
}
/*
 * Lista las incidencias del usuario logueado.
 * @param v VECTOR INCIDENCIAS.
 * @param userId IDENTIFICADOR USUARIO LOGUEADO.
 */
int incidenciasUsuario(vIncidencias* v,int userId)
{
    int tmp = 0;
    for(int i = 0;i < v->tam; ++i)
    {
        if(userId == v->inci[i].Id_us_incidencia && v->inci[i].Est_incidencia != 0)
            ++tmp;
    }
    return tmp;
}
/*
 * Lista todas las incidencias de la base de datos.
 * @param v VECTOR INCIDENCIAS
 */
void listarIncidencias(vIncidencias* v)
{
    CLEAN;
    for(int i = 0;i<v->tam;++i)
    {
        printf("%d-%d-%d-%s-%d\n",
        v->inci[i].Id_viaje,
        v->inci[i].Id_us_registra,
        v->inci[i].Id_us_incidencia,
        v->inci[i].Desc_incidencia,
        v->inci[i].Est_incidencia);
    }
    system_pause();
}
/*
 * Función exclusiva de administrador, que le permite añadir una incidencia a la base de datos.
 * @param v VECTOR INCIDENCIAS
 * @param vv VECTOR VIAJES
 * @param ve VECTOR VEHÍUCULOS
 */
void crearIncidenciasAdmin(vIncidencias* v,vViajes* vv,vVehiculos* ve)
{
    int tmp;
    printf("Introduzca el id del viaje: ");
    scanf("%d", &tmp);
    flush_in();
    int indexViaje = buscarIndexViajes(vv,tmp);
    if(indexViaje > -1)
    {
        crearIncidencias(v,vv,ve,indexViaje,0);
    }
    else printf("No existe el viaje\n");
}
/*
 * El usuario puede crear una incidencia, para ello, el viaje debe estar activo.
 * @param v VECTOR INCIDENCIAS
 * @param ve VECTOR VEHÍUCULOS
 * @param vv VECTOR VIAJES
 */
void crearIncidenciasUser(vIncidencias*v,vViajes* vv ,vVehiculos* ve,int userId )
{
    int tmp;
    printf("Introduzca el id del viaje: ");
    scanf("%d", &tmp);
    flush_in();
    int indexPasajero = buscarIndexPasejeros(vv,tmp,userId);
    int indexViaje = buscarIndexViajes(vv,tmp);
    if(indexPasajero > -1 && indexViaje > -1)
    {
        crearIncidencias(v,vv,ve,indexViaje,userId);
    }
    else printf("No existe el viaje o no ha viajado en dicho viaje\n");
}
/*
 * Función exclusiva de administrador para elminar la incidencia deseada.
 * @param
 */
void eliminarIncidenciasAdmin(vIncidencias* v,vViajes* vv)
{
  int tmp;
  printf("Introduzca el id del viaje: ");
  scanf("%d", &tmp);
  flush_in();
  eliminarIncidencias(v,vv,tmp);
}
/*
 * Permite al administrador modificar la incidencia deseada.
 * @param VECTOR INCIDENCIAS
 */
void modificarIncidenciasAdmin(vIncidencias* v)
{
  int tmp;
  printf("Introduzca el id del viaje: ");
  scanf("%d", &tmp);
  flush_in();
  modificarIncidencias(v,tmp);
}
