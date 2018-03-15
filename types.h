#ifndef TYPES_H
#define TYPES_H

#define TAM04 4
#define TAM05 5
#define TAM07 7
#define TAM08 8
#define TAM20 20
#define TAM50 50

static const char * const Estado_U[] = {"bloqueado","activo"};
static const char * const Perfil[] = {"administrador","usuario"};
static const char * const Viaje[] = {"Ida","Vuelta"};
static const char * const Estado_Vi[] = {"Cerrado","Abierto","Iniciado","Finalizado","Anulado"};
static const char * const Estado_I[] = {"Cerrada","Abierta","Valida"};

typedef struct{
    int * Id_usuario;
    char * Nomb_usario;
    char * Localidad;
    int Perfil_usuario;
    char * User;
    char * Login;
    int Estado;
}Usuarios;

typedef struct{
    char * Id_mat;
    int * Id_usuario;
    int Num_plazas;
    char * Desc_veh;
}Vehiculos;

typedef struct{
    int * Id_viaje;
    char * Id_mat;
    char * F_inic;
    char * H_inic;
    char * H_fin;
    int * Plazas_libre;
    int * Viaje;
    double * Importe;
    int * Estado;
}Viajes;

typedef struct{
    int * Id_viaje;
    char * Poblacion;
}Pasos;

typedef struct{
    int * Id_viaje;
    int * Id_us_registra;
    int * Id_us_incidencia;
    char * Desc_indicencia;
    int * Est_incidencia;
}Incidencias;

#endif
