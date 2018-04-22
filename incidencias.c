#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "incidencias.h"
#include "utilidades.h"
/**
 * Varible global para obtener el estado de una incidencia
 */
static const char * Estado_I[] = {"cerrada","abierta","validada"};
static int estadoIncidencia(char ** c);
static void idRegistar(vIncidencias* v,int iIndex);//static
static int* listaIncidencias(vIncidencias* v,int id_viaje,int* j);//static
int estadoIncidencia(char **c)
{
    if(strcmp(*c,"cerrada") == 0) return 0;
    if(strcmp(*c,"abierta")== 0) return 1;
    return 2;
}
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

        if (! * n ) tmp = (Incidencias *) malloc( (*n+1) * sizeof(Incidencias));
        else tmp = (Incidencias *) realloc(tmp,(*n+1) * sizeof(Incidencias));

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
    puts("Incidencias Guardadas");
}

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

void idRegistar(vIncidencias* v,int iIndex)
{
    printf("Ingrese id_usuario que registra la incidencia: ");
    scanf("%4d[^\n]",&v->inci[iIndex].Id_us_registra);
    flush_in();
}

void descripcionIncidencia(vIncidencias* v,int iIndex)
{
    printf("Ingrese id_usuario que registra la incidencia: ");
    scanf("%100[^\n]",v->inci[iIndex].Desc_incidencia);
    flush_in();
}

void crearIncidencias(vIncidencias* v,vViajes* vv,vVehiculos* ve,int id_viaje)
{
    int index = buscarIndexViajes(vv,id_viaje);
    if(index > -1)
    {
        v->inci = (Incidencias*)realloc(v->inci,(v->tam+1) * sizeof(Incidencias));
        v->inci[v->tam].Desc_incidencia = (char *)malloc(DES_INCI * sizeof(char));
        v->inci[v->tam].Est_incidencia = 1;
        v->inci[v->tam].Id_viaje = id_viaje;
        v->inci[v->tam].Id_us_incidencia = ve->vehi[buscarIndexVehiculo(ve,vv->viajes[index].Id_mat)].Id_usuario;
        idRegistar(v,v->tam);
        descripcionIncidencia(v,v->tam);
        ++v->tam;
    }
    else printf("No existe el viaje %d\n", id_viaje);
}

int* listaIncidencias(vIncidencias* v,int id_viaje,int* j)
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
static void eliminarIncidencia(vIncidencias* v, int iIndex);
void eliminarIncidencia(vIncidencias* v, int iIndex)
{
    free(v->inci[iIndex].Desc_incidencia);
    memmove(&v->inci[iIndex],&v->inci[iIndex+1],(v->tam-iIndex-1)*sizeof(Pasos));
    --v->tam;
}

void eliminarIncidencias(vIncidencias* v,vViajes* vi,int id_viaje)
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
        printf("Que incidencia desea modificar: \n");
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

void modificarIncidencias(vIncidencias* v,int id_viaje)
{

}
