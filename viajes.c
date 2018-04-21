#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "viajes.h"
static const char * Viaje[] = {"vuelta","ida"};
static const char * Estado_Vi[] = {"cerrado","abierto","iniciado","finalizado","anulado"};
static int estadoViaje(char** c);
int estadoViaje(char** c)
{
    if(strcmp(*c,"cerrado")    == 0) return 0;
    if(strcmp(*c,"abierto")    == 0) return 1;
    if(strcmp(*c,"iniciado")   == 0) return 2;
    if(strcmp(*c,"finalizado") == 0) return 3;
    return 4;
}

static int idaVuelta (char** c);
int idaVuelta (char** c)
{ return (strcmp(*c,"ida")== 0) ? 1 : 0;}

Viajes* initViajes(int * n)
{
    FILE* file = fopen("ficheros/Viajes.txt", "r");
    if (file == NULL ) exit(1);
    (*n)=0;
    Viajes* tmp = NULL;
    char *id_viaje,*id_mat,*f_inic,*h_inic,*h_fin,*p_libres,*viaje,*importe,*estado;

    while (!feof(file))
    {
        id_viaje = (char*) malloc(ID_VIAJE * sizeof(char));
        id_mat   = (char*) malloc(ID_MAT   * sizeof(char));
        f_inic   = (char*) malloc(FECHA    * sizeof(char));
        h_inic   = (char*) malloc(HORA     * sizeof(char));
        h_fin    = (char*) malloc(HORA     * sizeof(char));
        p_libres = (char*) malloc(NPLAZS   * sizeof(char));
        viaje    = (char*) malloc(ID_VIAJE * sizeof(char));
        importe  = (char*) malloc(IMPORTE  * sizeof(char));
        estado   = (char*) malloc(ESTADO_V * sizeof(char));
        if(id_viaje == NULL || id_mat == NULL || f_inic == NULL || h_inic == NULL ||
              h_fin == NULL || p_libres == NULL || viaje == NULL ||
            importe == NULL || estado == NULL) exit(1);

        fscanf(file,"%[^-]-%[^-]-%[^-]-%[^-]-%[^-]-%[^-]-%[^-]-%[^€]€-%[^\n]\n",
               id_viaje,id_mat,f_inic,h_inic,h_fin,p_libres,viaje,importe,estado);

        if (! *n ) tmp = (Viajes *) malloc( (*n+1) * sizeof(Viajes));
        else tmp = (Viajes *) realloc(tmp,(*n+1) * sizeof(Viajes));

        tmp[*n].Id_viaje     = atoi(id_viaje);
        tmp[*n].Id_mat       = id_mat;
        tmp[*n].F_inic       = f_inic;
        tmp[*n].H_inic       = h_inic;
        tmp[*n].H_fin        = h_fin;
        tmp[*n].Plazas_libre = atoi(p_libres);
        tmp[*n].Viaje        = idaVuelta(&viaje);
        tmp[*n].Estado       = estadoViaje(&estado);
        sscanf(importe, "%f", &tmp[*n].Importe);
        (*n)++;
        free(id_viaje);
        free(p_libres);
        free(viaje);
        free(importe);
        free(estado);
    }
    fclose(file);
    return tmp;
}

Pasos* initPasos(int * n)
{
    FILE* file = fopen("ficheros/Pasos.txt", "r");
    if (file == NULL ) exit(1);
    (*n)=0;
    Pasos *tmp = NULL;
    char *id_viaje,*poblacion;

    while(!feof(file))
    {
        id_viaje  = (char*) malloc(ID_VIAJE * sizeof(char));
        poblacion = (char*) malloc(LOCAL    * sizeof(char));

        if( id_viaje == NULL || poblacion == NULL ) exit(0);

        fscanf(file,"%[^-]-%[^\n]\n",id_viaje,poblacion);

        if (! *n ) tmp = (Pasos *) malloc( (*n+1) * sizeof(Pasos));
        else tmp = (Pasos *) realloc(tmp,(*n+1) * sizeof(Pasos));

        tmp[*n].Id_viaje  = atoi(id_viaje);
        tmp[*n].Poblacion = poblacion;
        (*n)++;
        free(id_viaje);
    }
    fclose(file);
    return tmp;
}

void saveViajes(int n,Viajes* viajes)
{
    FILE* file=fopen("ficheros/Viajes.txt","w+");
    if (file==NULL) exit(1);
    for (int i = 0 ; i < n; ++i ){
        fprintf(file,"%06d-%s-%s-%s-%s-%d-%s-%.2f€-%s\n",
        viajes[i].Id_viaje,
        viajes[i].Id_mat,
        viajes[i].F_inic,
        viajes[i].H_inic,
        viajes[i].H_fin,
        viajes[i].Plazas_libre,
        Viaje[viajes[i].Viaje],
        viajes[i].Importe,
        Estado_Vi[viajes[i].Estado]);
        free(viajes[i].Id_mat);
        free(viajes[i].F_inic);
        free(viajes[i].H_inic);
        free(viajes[i].H_fin);
    }
    fclose(file);
    puts("Viajes Guardados");
}

void savePasos(int n,Pasos* pasos)
{
    FILE* file = fopen("ficheros/Pasos.txt","w+");
    if (file==NULL) exit(1);

    for (int i = 0 ; i < n; ++i ){
        fprintf(file,"%06d-%s\n",
        pasos[i].Id_viaje,
        pasos[i].Poblacion);
        free(pasos[i].Poblacion);
    }
    fclose(file);
    puts("Pasos Guardados");
}
