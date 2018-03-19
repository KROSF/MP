#ifndef TIPOS_H
#define TIPOS_H
/**
 * Varible global para obtener el estado de un usuario
 */
static char * Estado_U[] = {"bloqueado","activo"};
/**
 * Varible global para obtener el perfil de un usuario
 */
static char * Perfil[] = {"administrador","usuario"};
/**
 * Variable global para saber el tipo de viaje
 */
static char * Viaje[] = {"vuelta","ida"};
/**
 * Varible global para obtener el estado del viaje
 */
static char * Estado_Vi[] = {"cerrado","abierto","iniciado","finalizado","anulado"};
/**
 * Varible global para obtener el estado de una incidencia
 */
static char * Estado_I[] = {"cerrada","abierta","validada"};
/**
 * Estructura para cargar en memoria el fichero Usuarios.txt
 */
typedef struct{
    /*@{*/
    int Id_usuario; /**< Identificador unico de usuario */
    char * Nomb_usario; /**< Nombre real de usuario*/
    char * Localidad; /**< Localidad del usuario */
    int Perfil_usuario; /**< Podra ser administrador = 0 , usuario = 1 */
    char * User; /**< Nombre de usuario */
    char * Login;/**< Contraseña */
    int Estado; /**< Podra ser activo = 1, bloqueado = 0 */
    /*@}*/
}Usuarios;
/**
 * Estructura para cargar en memoria el fichero Vehiculos.txt
 */
typedef struct{
    /*@{*/
    char * Id_mat;/**< Matricula del vehiculo */
    int Id_usuario;/**< Identificador de usuario al que pertenece */
    int Num_plazas;/**< Numero de plazas del vehiculo sin tener en cuenta la del coductor */
    char * Desc_veh;/**< Breve descripcion del vehiculo */
    /*@}*/
}Vehiculos;
/**
 * Estructura para cargar en memoria el fichero Viajes.txt
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
 * Estructura para cargar en memoria el fichero Pasos.txt
 */
typedef struct{
    /*@{*/
    int Id_viaje;/**< Indentificador del viaje que hace esta ruta */
    char * Poblacion;/**< Poblacion en la que se recoge o deja a un usuario */
    /*@}*/
}Pasos;
/**
 * Estructura para cargar en memoria el fichero Incidencias.txt
 */
typedef struct{
    /*@{*/
    int Id_viaje;/**< Identificador del viaje sobre el cual hay una incidendia*/
    int Id_us_registra;/**< Indetificador del usuario que ha registrado la incidencia*/
    int Id_us_incidencia;/**< Indentificador del usuario sobre el que recae la incidencia*/
    char * Desc_indicencia;/**< Descripcion de  la incidencia */
    int Est_incidencia;/**< Estado de la inicidencia pudiendo ser: cerrada = 0, abierta = 1, validada = 2 */
    /*@}*/
}Incidencias;

#endif
