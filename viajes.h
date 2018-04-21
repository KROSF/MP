#ifndef VIAJES_H
#define VIAJES_H
#define ID_VIAJE 7
#define ID_MAT 8
#define FECHA 11
#define HORA 6
#define NPLAZS 2
#define IMPORTE 5
#define ESTADO_V 11
#define LOCAL 21

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
    char * Poblacion;/**< Poblacion en la que se recoge o deja a un usuario */
    /*@}*/
}Pasos;
typedef struct{
    Pasos* pasos;
    Viajes* viajes;
    int tam_p;
    int tam_v;
}vViajes;

Viajes* initViajes(int* n);
void saveViajes(int n,Viajes* viajes);
Pasos* initPasos(int* n);
void savePasos(int n,Pasos* pasos);
int generarIdViaje(vViajes* v);
void publicar(vViajes* v);
int* pasosViajes(vViajes* v,int id_viaje,int* j);
void eliminarViaje(vViajes* v,int id_viaje);
void eliminarViajes(vViajes* v,int id_viaje);
#endif
