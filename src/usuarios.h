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
Usuarios* initUsuarios(int * n);//non-static
void listarUsuarios(vUsuarios* u,vIncidencias* i);//non-static
int buscarIndexUsuario(vUsuarios* v,int userId);//non-static
void altaUsuario(vUsuarios* v);// non-static
void bajaUsuario(vUsuarios* v,int uIndex);// non-static
void saveUsuarios(int n ,Usuarios* usuarios);//non-static
void modificarUsuario(vUsuarios* v,int userId);// non-static
void perfilUsuario(vUsuarios* v,int userId);//non-static Usuarios no Admin
void listarVehiculosUser(vVehiculos* v,vUsuarios* u,int uIndex);

#endif
