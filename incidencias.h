#ifndef INCIDENCIAS_H
#define INCIDENCIAS_H
#define ID_VIAJE 7
#define DES_INCI 101
#define ESTADO_I 9
#define ID_USUARIO 5
typedef struct{
    /*@{*/
    int Id_viaje;/**< Identificador del viaje sobre el cual hay una incidendia*/
    int Id_us_registra;/**< Indetificador del usuario que ha registrado la incidencia*/
    int Id_us_incidencia;/**< Indentificador del usuario sobre el que recae la incidencia*/
    char * Desc_indicencia;/**< Descripcion de  la incidencia */
    int Est_incidencia;/**< Estado de la inicidencia pudiendo ser: cerrada = 0, abierta = 1, validada = 2 */
    /*@}*/
}Incidencias;
typedef struct{
    Incidencias* inci;
    int tam;
}vIncidencias;
int inicidenciasUsuario(vIncidencias* v,int userId);
Incidencias* initIncidencias(int *n);
void saveIncidencias(int n,Incidencias* incidencias);

#endif
