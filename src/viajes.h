/**
* @file viajes.h
* @author Carlos Rodrigo Sanabria Flores
* @date 25 Apr 2018
* @copyright 2018 Carlos Rodrigo Sanabria Flores
* @brief <brief>
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
 * Estructura para cargar en memoria el fichero Pasos.txt
 */
typedef struct{
    /*@{*/
    int Id_viaje;/**< Indentificador del viaje que hace esta ruta */
    char* Poblacion;/**< Poblacion en la que se recoge o deja a un usuario */
    /*@}*/
}Pasos;
typedef struct{
    Pasos* pasos;
    Viajes* viajes;
    int tam_p;
    int tam_v;
}vViajes;
/**
* @brief <brief>
* @param [in] <name> <parameter_description>
* @return <return_description>
* @details <details>
*/
EXTERN Viajes* initViajes(int* n);//non-static modulo cargar
/**
* @brief <brief>
* @param [in] <name> <parameter_description>
* @return <return_description>
* @details <details>
*/
EXTERN void saveViajes(int n,Viajes* viajes);//non-static cargar
/**
* @brief <brief>
* @param [in] <name> <parameter_description>
* @return <return_description>
* @details <details>
*/
EXTERN Pasos* initPasos(int* n);//non-static cargar
/**
* @brief <brief>
* @param [in] <name> <parameter_description>
* @return <return_description>
* @details <details>
*/
EXTERN void savePasos(int n,Pasos* pasos);//non-static cargar
/**
* @brief <brief>
* @param [in] <name> <parameter_description>
* @return <return_description>
* @details <details>
*/
EXTERN int buscarIndexViajes(vViajes* v,int id_viaje);//non-static public
/**
* @brief <brief>
* @param [in] <name> <parameter_description>
* @return <return_description>
* @details <details>
*/
EXTERN void publicarViaje(vViajes* v,vVehiculos* vve,char* mat);//non-static admin
/**
* @brief <brief>
* @param [in] <name> <parameter_description>
* @return <return_description>
* @details <details>
*/
EXTERN void modificarViaje(vViajes* v, vVehiculos* ve,int id_viaje);//non-static admin
/**
* @brief <brief>
* @param [in] <name> <parameter_description>
* @return <return_description>
* @details <details>
*/
EXTERN void eliminarViajes(vViajes* v,int id_viaje);//non-static admin
/**
* @brief <brief>
* @param [in] <name> <parameter_description>
* @return <return_description>
* @details <details>
*/
EXTERN void listarViajesAdmin(vViajes* v);//non-static admin
/**
* @brief <brief>
* @param [in] <name> <parameter_description>
* @return <return_description>
* @details <details>
*/
EXTERN int* listaViajesAbiertos(vViajes* v,int* t);//static
/**
* @brief <brief>
* @param [in] <name> <parameter_description>
* @return <return_description>
* @details <details>
*/
EXTERN void actualizarViajes(vViajes* v);
/**
* @brief <brief>
* @param [in] <name> <parameter_description>
* @return <return_description>
* @details <details>
*/
EXTERN void editarViajesUsuario(vViajes* v,vVehiculos* ve,int userId);
/**
* @brief <brief>
* @param [in] <name> <parameter_description>
* @return <return_description>
* @details <details>
*/
EXTERN void publicarViajeUsuario(vViajes* v,vVehiculos* ve,int userId);
EXTERN void publicarViajeAdmin(vViajes *v, vVehiculos *ve);
EXTERN void eliminarViajesAdmin(vViajes* v);
EXTERN void modificarViajesAdmin(vViajes* v,vVehiculos *vve);
EXTERN void detalleViaje(vViajes* v);
EXTERN void listarViajesAbiertos(vViajes *v);
EXTERN void incorporarseViaje(vViajes *v);
#undef EXTERN
#endif
