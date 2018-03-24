#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "carga.h"
/**
 * Estado Usuario a entero
 * @param c referencia a la cadena
 * @return 1 si el estado es activo 0 bloqueado
 */
static int estadoUsuario(char ** c);
/**
 * Perfil usuario a entero
 * @param c referencia a la cadena
 * @return 1 si el perfil es usuario 0 administrador
 */
static int perfilUsuario(char ** c);
/**
 *
 * @param n
 * @return
 */
static Usuarios *initUsuarios(int * n);
/**
 *
 * @param n
 * @return
 */
static Vehiculos*initVehiculos(int * n);
/**
 *
 * @param n
 * @return
 */
static Viajes * initViajes(int * n);
/**
 *
 * @param n
 * @return
 */
static Pasos * initPasos(int * n);
/**
 *
 * @param n
 * @return
 */
static Incidencias * initIncidencias(int * n);
/**
 *
 * @param c
 * @return
 */
static int idaVuelta(char ** c);
/**
 *
 * @param c
 * @return
 */
static int estadoViaje(char ** c);
/**
 *
 * @param c
 * @return
 */
static int estadoIncidencia(char ** c);

void cargar(Usuarios ** usuarios,Vehiculos ** vehiculos,Viajes ** viajes,Pasos** pasos,Incidencias** incidencias,int * tam){
    *usuarios=initUsuarios(&tam[0]);
    *vehiculos=initVehiculos(&tam[1]);
    *viajes=initViajes(&tam[2]);
    *pasos=initPasos(&tam[3]);
    *incidencias=initIncidencias(&tam[4]);
}

int estadoIncidencia(char **c)
{
    int a=0;
    if(strcmp(*c,"cerrada") == 0) a=0;
    if(strcmp(*c,"abierta")== 0) a=1;
    if(strcmp(*c,"validada")== 0) a=2;
    return a;
}

int estadoViaje(char **c)
{
    int a=0;
    if(strcmp(*c,"cerrado") == 0) a=0;
    if(strcmp(*c,"abierto")== 0) a=1;
    if(strcmp(*c,"iniciado")== 0) a=2;
    if(strcmp(*c,"finalizado")== 0) a=3;
    if(strcmp(*c,"anulado")== 0) a=4;
    return a;
}

int idaVuelta (char ** c)
{
    return (strcmp(*c,"ida")== 0) ? 1 : 0;
}

int estadoUsuario(char** c){
    return (strcmp(*c,"activo")== 0) ? 1 : 0;
}

int perfilUsuario(char** c){
    return (strcmp(*c,"usuario")== 0) ? 1 : 0;
}


Usuarios *initUsuarios(int * n)
{
    FILE *file;
    file = fopen("ficheros/Usuarios.txt", "r");
    if (file == NULL ) exit(1);

    Usuarios *tmp=NULL;
    (*n)=0;

    char *id,*nomb,*locld,*usr,*log,*perfil,*estado;

    while(!feof(file))
    {
        id = (char *) malloc(5* sizeof(char));
        nomb = (char *) malloc(21* sizeof(char));
        locld = (char *)malloc(21 * sizeof(char));
        usr = (char *)malloc(6 * sizeof(char));
        log = (char *) malloc( 9 * sizeof(char));
        perfil = (char *) malloc( 14 * sizeof(char));
        estado = (char *) malloc( 10 * sizeof(char));

        if( id == NULL || nomb == NULL || locld == NULL || usr == NULL ||
            log == NULL || perfil == NULL || estado == NULL) exit(1);

        fscanf(file, "%[^-]-%[^-]-%[^-]-%[^-]-%[^-]-%[^-]-%[^\n]\n", id, nomb, locld, perfil ,usr,log,estado);
        if (! * n ) tmp = (Usuarios *) malloc( (*n+1) * sizeof(Usuarios));
        else tmp = (Usuarios *) realloc(tmp,(*n+1) * sizeof(Usuarios));

        tmp[*n].Id_usuario=atoi(id);
        tmp[*n].Nomb_usuario=nomb;
        tmp[*n].Localidad=locld;
        tmp[*n].Perfil_usuario=perfilUsuario(&perfil);
        tmp[*n].User=usr;
        tmp[*n].Login=log;
        tmp[*n].Estado=estadoUsuario(&estado);
        (*n)++;
        free(id);
        free(perfil);
        free(estado);
    }
    fclose(file);
    return tmp;
}

Vehiculos * initVehiculos(int * n)
{
    FILE *file;
    file = fopen("ficheros/Vehiculos.txt", "r");
    if (file == NULL ) exit(1);

    char *mat,*idu,*nplzs,*des_veh;

    Vehiculos *tmp=NULL;
    (*n)=0;

    while(!feof(file))
    {
        mat = (char *) malloc( 8 * sizeof(char));
        idu = (char *) malloc( 5 * sizeof(char));
        nplzs = (char *) malloc(2 * sizeof(char));
        des_veh = (char *) malloc(51 * sizeof(char));

        if(mat == NULL || idu == NULL || nplzs == NULL || des_veh == NULL) exit(1);

        fscanf(file, "%[^-]-%[^-]-%[^-]-%[^\n]\n", mat, idu, nplzs,des_veh);

        if (! * n ) tmp = (Vehiculos *) malloc( (*n+1) * sizeof(Vehiculos));
        else tmp = (Vehiculos *) realloc(tmp,(*n+1) * sizeof(Vehiculos));

        tmp[*n].Id_usuario=atoi(idu);
        tmp[*n].Id_mat=mat;
        tmp[*n].Desc_veh=des_veh;
        tmp[*n].Num_plazas=atoi(nplzs);
        (*n)++;
        free(idu);
        free(nplzs);
    }
    fclose(file);
    return tmp;
}

Viajes * initViajes(int * n)
{
    FILE *file;
    file = fopen("ficheros/Viajes.txt", "r");
    if (file == NULL ) exit(1);

    (*n)=0;
    Viajes *tmp = NULL;
    char * id_viaje,*id_mat,*f_inic,*h_inic,*h_fin,*p_libres,*viaje,*importe,*estado;

    while (!feof(file))
    {
        id_viaje=(char *)malloc(7* sizeof(char));
        id_mat=(char *)malloc(8* sizeof(char));
        f_inic=(char *)malloc(11* sizeof(char));
        h_inic=(char *)malloc(6* sizeof(char));
        h_fin=(char *)malloc(6* sizeof(char));
        p_libres=(char *)malloc(2* sizeof(char));
        viaje=(char *)malloc(7* sizeof(char));
        importe=(char *)malloc(5* sizeof(char));
        estado=(char *)malloc(11* sizeof(char));
        if(id_viaje == NULL || id_mat == NULL || f_inic == NULL || h_inic == NULL ||
                h_fin == NULL || p_libres == NULL || viaje == NULL || importe == NULL || estado == NULL) exit(1);

        fscanf(file,"%[^-]-%[^-]-%[^-]-%[^-]-%[^-]-%[^-]-%[^-]-%[^€]€-%[^\n]\n",
               id_viaje,id_mat,f_inic,h_inic,h_fin,p_libres,viaje,importe,estado);

        if (! * n ) tmp = (Viajes *) malloc( (*n+1) * sizeof(Viajes));
        else tmp = (Viajes *) realloc(tmp,(*n+1) * sizeof(Viajes));

        tmp[*n].Id_viaje=atoi(id_viaje);
        tmp[*n].Id_mat=id_mat;
        tmp[*n].F_inic=f_inic;
        tmp[*n].H_inic=h_inic;
        tmp[*n].H_fin=h_fin;
        tmp[*n].Plazas_libre=atoi(p_libres);
        tmp[*n].Viaje=idaVuelta(&viaje);
        sscanf(importe, "%f", &tmp[*n].Importe);
        tmp[*n].Estado=estadoViaje(&estado);
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

Pasos * initPasos(int * n)
{
    FILE *file;
    file = fopen("ficheros/Pasos.txt", "r");
    if (file == NULL ) exit(1);

    (*n)=0;
    Pasos *tmp = NULL;

    char *id_viaje,*poblacion;

    while(!feof(file))
    {
        id_viaje = (char *)malloc(7 * sizeof(char));
        poblacion = (char *)malloc(21 * sizeof(char));

        if( id_viaje == NULL || poblacion == NULL ) exit(0);

        fscanf(file,"%[^-]-%[^\n]\n",id_viaje,poblacion);

        if (! * n ) tmp = (Pasos *) malloc( (*n+1) * sizeof(Pasos));
        else tmp = (Pasos *) realloc(tmp,(*n+1) * sizeof(Pasos));

        tmp[*n].Id_viaje=atoi(id_viaje);
        tmp[*n].Poblacion=poblacion;
        (*n)++;
        free(id_viaje);
    }
    fclose(file);
    return tmp;
}

Incidencias * initIncidencias(int *n)
{
    FILE *file;
    file = fopen("ficheros/Incidencias.txt", "r");
    if (file == NULL ) exit(1);

    (*n)=0;
    Incidencias *tmp = NULL;

    char *id_viaje,*id_us_registra,*id_us_incidencia,*desc_inicidencia,*estado;

    while(!feof(file))
    {
        id_viaje = (char *)malloc(7 * sizeof(char));
        id_us_registra = (char *)malloc(5 * sizeof(char));
        id_us_incidencia = (char *)malloc(5 * sizeof(char));
        desc_inicidencia = (char *)malloc(101* sizeof(char));
        estado = (char *)malloc(9* sizeof(char));

        if( id_viaje == NULL || id_us_incidencia == NULL ||
            id_us_registra == NULL || desc_inicidencia == NULL ||
            estado == NULL) exit(1);

        fscanf(file,"%[^-]-%[^-]-%[^-]-%[^-]-%[^\n]\n",id_viaje,id_us_registra,id_us_incidencia,desc_inicidencia,estado);

        if (! * n ) tmp = (Incidencias *) malloc( (*n+1) * sizeof(Incidencias));
        else tmp = (Incidencias *) realloc(tmp,(*n+1) * sizeof(Incidencias));

        tmp[*n].Id_viaje=atoi(id_viaje);
        tmp[*n].Id_us_registra=atoi(id_us_registra);
        tmp[*n].Id_us_incidencia=atoi(id_us_incidencia);
        tmp[*n].Desc_indicencia=desc_inicidencia;
        tmp[*n].Est_incidencia=estadoIncidencia(&estado);

        free(id_viaje);
        free(id_us_incidencia);
        free(id_us_registra);
        free(estado);

        (*n)++;
    }
    fclose(file);
    return tmp;
}
