#ifndef INCIDENCIAS_H
#define INCIDENCIAS_H
#define ID_VIAJE 7
#define DES_INCI 101
#define ESTADO_I 9
#define ID_USUARIO 5
#include "viajes.h"
typedef struct{
    /*@{*/
    int Id_viaje;/**< Identificador del viaje sobre el cual hay una incidendia*/
    int Id_us_registra;/**< Indetificador del usuario que ha registrado la incidencia*/
    int Id_us_incidencia;/**< Indentificador del usuario sobre el que recae la incidencia*/
    char * Desc_incidencia;/**< Descripcion de  la incidencia */
    int Est_incidencia;/**< Estado de la inicidencia pudiendo ser: cerrada = 0, abierta = 1, validada = 2 */
    /*@}*/
}Incidencias;
typedef struct{
    Incidencias* inci;
    int tam;
}vIncidencias;
Incidencias* initIncidencias(int *n);//non-static
void saveIncidencias(int n,Incidencias* incidencias);//non-static
void crearIncidencias(vIncidencias* v,vViajes* vv,vVehiculos* ve,int id_viaje);//non-static admin
void eliminarIncidencias(vIncidencias* v,vViajes* vi,int id_viaje);//non-static admin
void modificarIncidencias(vIncidencias* v,int id_viaje);//non-static admin
int incidenciasUsuario(vIncidencias* v,int userId);//non-static

#endif
