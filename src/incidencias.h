#ifndef INCIDENCIAS_H
#define INCIDENCIAS_H
#define ID_VIAJE 7
#define DES_INCI 101
#define ESTADO_I 9
#define ID_USUARIO 5
#include "viajes.h"
/**
 * Estructura para representar en memoria el fichero Incidencias.txt
 */
typedef struct{
    /*@{*/
    int Id_viaje;/**< Identificador del viaje sobre el cual hay una incidendia*/
    int Id_us_registra;/**< Indetificador del usuario que ha registrado la incidencia*/
    int Id_us_incidencia;/**< Indentificador del usuario sobre el que recae la incidencia*/
    char * Desc_incidencia;/**< Descripcion de  la incidencia */
    int Est_incidencia;/**< Estado de la inicidencia pudiendo ser: cerrada = 0, abierta = 1, validada = 2 */
    /*@}*/
}Incidencias;
/**
 * Estructura para contener el tamaño y el vector inci.
 */
typedef struct{
    /*@{*/
    Incidencias* inci;/**< Vector dinamico con elementos del tipo Incidencias*/
    int tam;/**< Tamaño del vector inci.*/
    /*@}*/
}vIncidencias;
/**
 * [initIncidencias description]
 * @param  n [description]
 * @return   [description]
 */
Incidencias* initIncidencias(int *n);

/**
 * [saveIncidencias description]
 * @param n           [description]
 * @param incidencias [description]
 */
void saveIncidencias(int n,Incidencias* incidencias);

/**
 * [incidenciasUsuario description]
 * @param  v      [description]
 * @param  userId [description]
 * @return        [description]
 */
int incidenciasUsuario(vIncidencias* v,int userId);

/**
 * [listarIncidencias description]
 * @param v [description]
 */
void listarIncidencias(vIncidencias* v);

/**
 * [crearIncidenciasAdmin description]
 * @param v  [description]
 * @param vv [description]
 * @param ve [description]
 */
void crearIncidenciasAdmin(vIncidencias* v,vViajes* vv,vVehiculos* ve);

/**
 * [crearIncidenciasUser description]
 * @param v      [description]
 * @param vv     [description]
 * @param ve     [description]
 * @param userId [description]
 */
void crearIncidenciasUser(vIncidencias*v,vViajes* vv ,vVehiculos* ve,int userId );

/**
 * [eliminarIncidenciasAdmin description]
 * @param v  [description]
 * @param vv [description]
 */
void eliminarIncidenciasAdmin(vIncidencias* v,vViajes* vv);

/**
 * [modificarIncidenciasAdmin description]
 * @param v [description]
 */
void modificarIncidenciasAdmin(vIncidencias* v);
#endif
