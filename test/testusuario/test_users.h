//
// Created by Miguel on 02/05/2018.
//

#ifndef PRUEBAS_MUSUARIOS_TEST_USERS_H
#define PRUEBAS_MUSUARIOS_TEST_USERS_H

#define ID_USUARIO 5
#define USR 6
#define LOGINPASS 9
#define ESTADO_U 10
#define PERFIL 14
#define NOMB 21
#define LOCAL 21
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

Usuarios *initUsuarios(int *n, char *fichero);
void saveUsuarios(int n, Usuarios *usuarios, char *fichero);
int buscarIndexUsuario(vUsuarios *v, int userId);

#endif //PRUEBAS_MUSUARIOS_TEST_USERS_H
