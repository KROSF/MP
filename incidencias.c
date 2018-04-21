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

int inicidenciasUsuario(vIncidencias* v,int userId)
{
    int tmp = 0;
    for(int i = 0;i < v->tam; ++i)
    {
        if(userId == v->inci[i].Id_us_incidencia && v->inci[i].Est_incidencia != 0)
            ++tmp;
    }
    return tmp;
}

int idRegistar(vIncidencias* v,vViajes* vv,int id_viaje,int iIndex)
{
    int index = buscarIndexViajes(vv,id_viaje);
    if(index > -1)
    {
        printf("Ingrese id_usuario que registra la incidencia: ");
        scanf("%4d[^\n]",&v->inci[iIndex].Id_us_registra);
        flush_in();
        return 1;
    }
    else return 0;
}

void crearIncidencias(vIncidencias* v,vViajes vv, int id_viaje)
{
    v->inci = (Incidencias*)realloc(v->inci,(v->tam+1)       * sizeof(Incidencias));
    v->inci[v->tam].Desc_incidencia = (char *)malloc(DES_INCI * sizeof(char));
    v->inci[v->tam].Est_incidencia = 1;
    v->inci[v->tam].Id_viaje = id_viaje;
}
