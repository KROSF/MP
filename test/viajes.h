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
EXTERN void generarFicheros(char* file_name,int tam, int n);
/**
 * Inicializa una estructura del tipo Viajes.
 * @param  n Referencia al tamaño de la estructura.
 * @return   Un vector con los datos del fichero Viajes.txt
 */
EXTERN Viajes* initViajes(int* n);

/**
* Se guarda en fichero la estructura Viajes.
* @param n tamaño del vector viajes.
* @param viajes puntero al vector del tipo Viajes
* @details Guarda los datos en el fichero y libera la memoria.
*/
EXTERN void saveViajes(int n,Viajes* viajes);

/**
 * Actualiza el estado de los viajes.
 * @param v Referencia al vector de viajes.
 */
EXTERN void actualizarViajes(vViajes* v);
#undef EXTERN
#endif
