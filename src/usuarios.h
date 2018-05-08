#ifndef USUARIOS_H
#define USUARIOS_H
#define ID_USUARIO 5
#define USR 6
#define LOGINPASS 9
#define ESTADO_U 10
#define PERFIL 14
#define NOMB 21
#define LOCAL 21
#include "incidencias.h"
/**
 * Estructura para representar en memoria el fichero Usuarios.txt
 */
typedef struct{
    /*@{*/
    int Id_usuario; /**< Identificador unico de usuario */
    char * Nomb_usuario; /**< Nombre real de usuario*/
    char * Localidad; /**< Localidad del usuario */
    int Perfil_usuario; /**< Podra ser administrador = 0 , usuario = 1 */
    char * User; /**< Nombre de usuario */
    char * Login;/**< Contraseña */
    int Estado; /**< Podra ser activo = 1, bloqueado = 0 */
    /*@}*/
}Usuarios;
/**
 * Estructura para contener el tamaño y el vector user.
 */
typedef struct{
  Usuarios* user;/**< Vector dinamico con elementos del tipo Usuarios*/
  int tam;/**< Tamaño del vector user.*/
}vUsuarios;
/**
 * Inicializador de la estructura USUARIOS
 * @param recibe n como referencia al nº de elemento a cargar de los ficheros
 * @return devuelve la estructura Usuarios cargada
 */
Usuarios* initUsuarios(int * n);

/**
 * Salvaguardar los datos de la estructura USUARIOS en ficheros
 * @param recibe n como nº de elementos a guardar de la estructura
 * @param recibe usuarios como referencia al vector Usuarios
 */
void saveUsuarios(int n, Usuarios *usuarios);

/**
 * listar todos los Usuarios
 * @param reecibe u referencia al vector de Usuarios
 * @param recibe vi referencia al vector de Incidencias
 */
void listarUsuarios(vUsuarios* u,vIncidencias* vi);

/**
 * Dar de Alta a un nuevo Usuario
 * @param recibe v referencia al vecctor de Usuarios
 */
void altaUsuario(vUsuarios* v);

/**
 * Modificar los campos de un Usuario
 * @param recibe v referencia al vector de Usuarios
 * @param recibe userId con el indice del usuario seleccionado
 */
void modificarUsuario(vUsuarios* v,int userId);

/**
 * Slección opciones de modificación del perfil Usuario
 * @param recibe v referencia al vector de Usuarios
 * @param recibe userIndex con el indice del usuario seleccionado
 */
void perfilUsuario(vUsuarios* v,int userId);

/**
 * pregunta y busca el Id para Dar de Baja en otra función
 * @param recibe v referencia al vector de Usuarios
 */
void preguntarIdBaja(vUsuarios* v);

/**
 * pregunta y busca el Id para Modificar en otra función
 * @return devuelve tmp con un entero con el id seleccionado
 */
int preguntarIdModificar(void);

/**
 * Print del Perfil de usuario
 * @param recibe v referencia al vector de Usuarios
 * @param recibe userIndex con el indice del usuario seleccionado
 */
void printPerfil(vUsuarios* v,int userIndex);

#endif
