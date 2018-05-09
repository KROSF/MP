#ifndef INCIDENCIA_H
#define INCIDENCIA_H
#define ID_VIAJE 7
#define DES_INCI 101
#define ESTADO_I 9
#define ID_USUARIO 5
typedef struct{
    int Id_viaje;/**< Identificador del viaje sobre el cual hay una incidendia*/
    int Id_us_registra;/**< Indetificador del usuario que ha registrado la incidencia*/
    int Id_us_incidencia;/**< Indentificador del usuario sobre el que recae la incidencia*/
    char * Desc_incidencia;/**< Descripcion de  la incidencia */
    int Est_incidencia;/**< Estado de la inicidencia pudiendo ser: cerrada = 0, abierta = 1, validada = 2 */
}Incidencias;
typedef struct{
    /*@{*/
    Incidencias* inci;/**< Vector dinamico con elementos del tipo Incidencias*/
    int tam;/**< Tamaño del vector inci.*/
    /*@}*/
}vIncidencias;
int* listaIncidencias(vIncidencias* v,int id_viaje,int* j);
Incidencias* initIncidencias(int* n,char*  fichero);
void saveIncidencias(int n,Incidencias* incidencias);
#endif
