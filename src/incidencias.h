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
 * Estructura para contener el tamaño y el vector incidencias.
 */
typedef struct{
    /*@{*/
    Incidencias* inci;/**< Vector dinamico con elementos del tipo Incidencias*/
    int tam;/**< Tamaño del vector inci.*/
    /*@}*/
}vIncidencias;
/**
 * Inicializa las incidencias.
 * @param  n [description]
 * @return   [description]
 */
Incidencias* initIncidencias(int *n);

/**
 * Guarda las incidencias.
 * @param n           [description]
 * @param incidencias [description]
 */
void saveIncidencias(int n,Incidencias* incidencias);

/**
 * Devuelve un índice
 * @param  v      VECTOR INCIDENCIAS
 * @param  userId IDENTIFICADOR DEL USUARIO LOGUEADO
 * @return tmp
 */
int incidenciasUsuario(vIncidencias* v,int userId);

/**
 * Lista todas las incidencias
 * @param v VECTOR INCIDENCIAS
 */
void listarIncidencias(vIncidencias* v);

/**
 * Función exclusiva para administradores, en la que el administrador logueado puede crear una nueva incidencia.
 * @param v  VECTOR INCIDENCIAS
 * @param vv VECTOR VIAJES
 * @param ve VECTOR VEHICULOS
 */
void crearIncidenciasAdmin(vIncidencias* v,vViajes* vv,vVehiculos* ve);

/**
 * Función exclusiva para usuarios, en la que el usuario logueado puede crear una nueva incidencia.
 * @param v  VECTOR INCIDENCIAS
 * @param vv VECTOR VIAJES
 * @param ve VECTOR VEHICULOS
 * @param userId IDENTIFICADOR DEL USUARIO LOGUEADO
 */
void crearIncidenciasUser(vIncidencias*v,vViajes* vv ,vVehiculos* ve,int userId );

/**
 * Función para admins, el admin logueado puede eliminar una incidencia de la base de datos.
 * @param v  VECTOR INCIDENCIAS
 * @param vv VECTOR VIAJES
 */
void eliminarIncidenciasAdmin(vIncidencias* v,vViajes* vv);

/**
 * Función para administradores, modifica las incidencias de la base de datos.
 * @param v VECTOR INCIDENCIAS.
 */
void modificarIncidenciasAdmin(vIncidencias* v);
#endif
