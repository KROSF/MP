/**
* @file viajes.h
* @author Carlos Rodrigo Sanabria Flores
* @date 25 Apr 2018
* @copyright 2018 Carlos Rodrigo Sanabria Flores
* @brief Funciones publicas del modulo viajes.
*/
#ifndef VIAJES_H
#define VIAJES_H
#define ID_VIAJE 7
#define ID_MAT 8
#define FECHA 11
#define HORA 6
#define NPLAZS 2
#define IMPORTE 11
#define ESTADO_V 11
#define LOCAL 21
#ifdef viajes_IMPORT
    #define EXTERN
#else
    #define EXTERN extern
#endif

#include "vehiculos.h"
/**
 * Estructura para representar en memoria el fichero Viajes.txt
 */
typedef struct{
    /*@{*/
    int Id_viaje;/**< Identificador unico de viaje */
    char * Id_mat;/**< Matricula del vehiculo que hace el viaje */
    char * F_inic;/**< Fecha del viaje en formato dd/mm/aaa */
    char * H_inic;/**< Hora de inicio con foramto hh:mm expresado en 24h */
    char * H_fin;/**< Hora de llegada con foramto hh:mm expresado en 24h */
    int Plazas_libre;/**< Numero de plazas que aun quedan sin ocupar */
    int Viaje;/**< Podra ser ida = 1 , vuelta = 0 */
    float Importe;/**< Importe total del viaje */
    int Estado;/** Estado del viaje pudiendo ser: cerrado = 0, abierto = 1, iniciado = 2, finalizado = 3, anulado = 4 */
    /*@}*/
}Viajes;
/**
 * Estructura para representar en memoria el fichero Pasos.txt
 */
typedef struct{
    /*@{*/
    int Id_viaje;/**< Indentificador del viaje que hace esta ruta */
    char* Poblacion;/**< Poblacion en la que se recoge o deja a un usuario */
    /*@}*/
}Pasos;
/**
 * Estructura para contener el tamaño y el vector de pasos y viajes.
 */
typedef struct{
    /*@{*/
    Pasos* pasos;/**< Vector dinamico con elementos del tipo Pasos.*/
    Viajes* viajes;/**< Vector dinamico con elementos del tipo Pasos.*/
    int tam_p;/**< Tamaño del vector pasos.*/
    int tam_v;/**< Tamaño del vector viajes.*/
    /*@}*/
}vViajes;

/**
 * Inicializa una estructura del tipo Viajes.
 * @param  n Referencia al tamaño de la estructura.
 * @return   Un vector con los datos del fichero Viajes.txt
 */
EXTERN Viajes* initViajes(int* n);

/**
* Inicializa una estructura del tipo Pasos.
* @param  n Referencia al tamaño de la estructura.
* @return   Un vector con los datos del fichero Pasos.txt
 */
EXTERN Pasos* initPasos(int* n);

/**
 * [publicarViajeUsuario description]
 * @param v      [description]
 * @param ve     [description]
 * @param userId [description]
 */
EXTERN void publicarViajeUsuario(vViajes* v,vVehiculos* ve,int userId);

/**
 * [editarViajesUsuario description]
 * @param v      [description]
 * @param ve     [description]
 * @param userId [description]
 */
EXTERN void editarViajesUsuario(vViajes* v,vVehiculos* ve,int userId);

/**
 * [incorporarseViaje description]
 * @param v [description]
 */
EXTERN void incorporarseViaje(vViajes *v);

/**
 * [detalleViaje description]
 * @param v [description]
 */
EXTERN void detalleViaje(vViajes* v);

/**
 * [publicarViajeAdmin description]
 * @param v  [description]
 * @param ve [description]
 */
EXTERN void publicarViajeAdmin(vViajes *v, vVehiculos *ve);

/**
 * [eliminarViajesAdmin description]
 * @param v [description]
 */
EXTERN void eliminarViajesAdmin(vViajes* v);

/**
 * [modificarViajesAdmin description]
 * @param v   [description]
 * @param vve [description]
 */
EXTERN void modificarViajesAdmin(vViajes* v,vVehiculos *vve);

/**
 * [listarViajesAdmin description]
 * @param v [description]
 */
EXTERN void listarViajesAdmin(vViajes* v);

/**
* Se guarda en fichero la estructura Viajes.
* @param n tamaño del vector usuarios.
* @param viajes puntero al vector del tipo Viajes
* @details Guarda los datos en el fichero y libera la memoria.
*/
EXTERN void saveViajes(int n,Viajes* viajes);

/**
* Se guarda en fichero la estructura Pasos.
* @param n tamaño del vector pasos.
* @details Guarda los datos en el fichero y libera la memoria.
*/
EXTERN void savePasos(int n,Pasos* pasos);

/**
 * [buscarIndexViajes description]
 * @param  v        [description]
 * @param  id_viaje [description]
 * @return          [description]
 */
EXTERN int buscarIndexViajes(vViajes* v,int id_viaje);

/**
 * [listarViajesAbiertos description]
 * @param v [description]
 */
EXTERN void listarViajesAbiertos(vViajes *v);

/**
 * [actualizarViajes description]
 * @param v [description]
 */
EXTERN void actualizarViajes(vViajes* v);
#undef EXTERN
#endif
