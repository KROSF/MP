#ifndef ACCESO_H
#define ACCESO_H
#define ID_USUARIO 5
#define USR 6
#define LOGINPASS 9
#define ESTADO_U 10
#define PERFIL 14
#define NOMB 21
#define LOCAL 21

typedef struct{
   
    int Id_usuario; 
    char * Nomb_usuario; 
    char * Localidad;
    int Perfil_usuario; 
    char * User; 
    char * Login;
    int Estado; 
    
}Usuarios;

typedef struct{
  Usuarios* user;
  int tam;
}vUsuarios;

Usuarios *initUsuarios(int * n, char* fichero);
void saveUsuarios(int n, Usuarios *usuarios, char* fichero);
int check_user(vUsuarios *v, char* user, char* pass);


#endif


