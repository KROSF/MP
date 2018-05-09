#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "incidencia.h"

static int estadoIncidencia(char **c)
{
    if(strcmp(*c,"cerrada") == 0) return 0;
    if(strcmp(*c,"abierta")== 0) return 1;
    return 2;
}

Incidencias* initIncidencias(int* n,char*  fichero)
{
    FILE* file = fopen(fichero, "r");
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
    for (int i = 0 ; i < n; ++i ){
        free(incidencias[i].Desc_incidencia);
    }
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
