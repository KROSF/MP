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
typedef struct{
  Usuarios* user;
  int tam;
}vUsuarios;
Usuarios* initUsuarios(int * n);
void listarUsuarios(vUsuarios* u,vIncidencias* i);
int generarIdUsuario(vUsuarios* v);
int buscarIndexUsuario(vUsuarios* v,int userId);
void altaUsuario(vUsuarios* v);
void bajaUsuario(vUsuarios* v,int uIndex);
void localidadUsuario(vUsuarios* v,int uIndex);
void loginUsuario(vUsuarios* v,int uIndex);
void nombreUsuario(vUsuarios* v,int uIndex);
void passUsuario(vUsuarios* v,int uIndex);
void perfilUsuario(vUsuarios* v,int userId);
void saveUsuarios(int n ,Usuarios* usuarios);
void modificarUsuario(vUsuarios* v,int userId);
void modificarPerfilUsuario(vUsuarios* v,int userId);
void modificarEstadoUsuario(vUsuarios* v,int userId);














#endif
