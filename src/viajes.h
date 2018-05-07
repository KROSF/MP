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
    int Estado;/** Estado del viaje pudiendo ser:
                                        cerrado = 0, abierto = 1, iniciado = 2,
                                        finalizado = 3, anulado = 4 */
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
typedef struct{
    /*@{*/
    int Id_viaje;/**< Indentificador del viaje*/
    int Id_viajero;/**< Indentificador del pasajero que esta en el viaje*/
    /*@}*/
}Pasajeros;
/**
 * Estructura para contener el tamaño y el vector de pasos y viajes.
 */
typedef struct{
    /*@{*/
    Pasajeros* pasaj;/**< Vector dinamico con elementos del tipo Pasajeros*/
    Pasos* pasos;/**< Vector dinamico con elementos del tipo Pasos.*/
    Viajes* viajes;/**< Vector dinamico con elementos del tipo Pasos.*/
    int tam_pj;/**< Tamaño del vector pasaj.*/
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
 * Inicializa una estructura del tipo Pasejeros;
 * @param  n Referencia al tamaño de la estructura.
 * @return   Un vector con los datos del fichero Pasajeros.txt
 */
EXTERN Pasajeros* initPasajeros(int* n);

/**
 * Funcion para publicar un viaje en el sistema de esi-share.
 * @param v      Referencia al vector de viajes.
 * @param ve     Referencia al vector de vehiculos.
 * @param userId Identificador del usuario que publica el viaje.
 */
EXTERN void publicarViajeUsuario(vViajes* v,vVehiculos* ve,int userId);

/**
 * Permite la edicion de un viaje en estado abierto.
 * @param v      Referencia al vector de viajes.
 * @param ve     Referencia al vector de vehiculos.
 * @param userId Identificador del usuario que publico el viaje.
 */
EXTERN void editarViajesUsuario(vViajes* v,vVehiculos* ve,int userId);

/**
 * Permite a un usuario incorporarse a un viajes publicado en el sistema.
 * @param v Referencia al vector de viajes.
 * @param id_viajero Identificador del usuario que se une al viaje.
 */
EXTERN void incorporarseViaje(vViajes *v,int id_viajero);

/**
 * Permite a un usuario ver los datos de un viaje al detalle.
 * @param v Referencia al vector de viajes.
 */
EXTERN void detalleViaje(vViajes* v);

/**
 * Permite a un administrador publicar un viaje en nombre de un usuario.
 * @param v  Referencia al vector de viajes.
 * @param ve Referencia al vector de vehiculos.
 */
EXTERN void publicarViajeAdmin(vViajes *v, vVehiculos *ve);

/**
 * Permite a un administrador eliminar un viaje.
 * @param v Referencia al vector de viajes.
 */
EXTERN void eliminarViajesAdmin(vViajes* v);

/**
 * Permite a un administrador eliminar un viaje.
 * @param v   Referencia al vector de viajes.
 * @param vve Referencia al vector de vehiculos.
 */
EXTERN void modificarViajesAdmin(vViajes* v,vVehiculos *vve);

/**
 * Muestra los viajes al detalle.
 * @param v Referencia al vector de viajes.
 */
EXTERN void listarViajesAdmin(vViajes* v);

/**
* Se guarda en fichero la estructura Viajes.
* @param n tamaño del vector viajes.
* @param viajes puntero al vector del tipo Viajes.
* @details Guarda los datos en el fichero y libera la memoria.
*/
EXTERN void saveViajes(int n,Viajes* viajes);

/**
* Se guarda en fichero la estructura Pasos.
* @param n tamaño del vector pasos.
* @param viajes puntero al vector del tipo Pasos.
* @details Guarda los datos en el fichero y libera la memoria.
*/
EXTERN void savePasos(int n,Pasos* pasos);

/**
 * Se guarda en fichero la estructura Pasajeros.
 * @param n     Tamaño del vector pasaj.
 * @param pasaj puntero al vector de tipo Pasajeros.
 */
EXTERN void savePasajeros(int n,Pasajeros *pasaj);

/**
 * Busca si un viaje exite en el vector.
 * @param  v        Referencia al vector de viajes.
 * @param  id_viaje Identificador del viaje a buscar.
 * @return          -1 Si no se encuentra.
 * @return          iesima posicion del vector donde se encuentra el viaje.
 */
EXTERN int buscarIndexViajes(vViajes* v,int id_viaje);

/**
 * Muestra los viajes en estado abierto.
 * @param v Referencia al vector de viajes.
 */
EXTERN void listarViajesAbiertos(vViajes *v);

/**
 * Actualiza el estado de los viajes.
 * @param v Referencia al vector de viajes.
 */
EXTERN void actualizarViajes(vViajes* v);
#undef EXTERN
#endif
