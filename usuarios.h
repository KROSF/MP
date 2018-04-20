#ifndef USUARIOS_H
#define USUARIOS_H

#define ID_USUARIO 5
#define USR 6
#define LOGINPASS 9
#define ESTADO_U 10
#define PERFIL 14
#define NOMB 21
#define LOCAL 21
static const char* Estado_U[] = {"bloqueado","activo"};
/**
 * Varible global para obtener el perfil de un usuario
 */
static const char * Perfil[] = {"administrador","usuario"};
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
void saveUsuarios(int n ,Usuarios* usuarios);
void perfilUsuario(vUsuarios* v,int userId);
void editarNombreUsuario(vUsuarios* v,int uIndex);
void editarLocalidadUsuario(vUsuarios* v,int uIndex);
void editarLoginUsuario(vUsuarios* v,int uIndex);
void editarPassUsuario(vUsuarios* v,int uIndex);
void eliminarUsuario(vUsuarios* v,int uIndex);













#endif
