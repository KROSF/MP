#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuarios.h"
/**
 * Estado Usuario a entero
 * @param c referencia a la cadena
 * @return 1 si el estado es activo 0 bloqueado
 */
static int estadoUsuario(char ** c);

int estadoUsuario(char** c)
{ return (strcmp(*c,"activo")== 0) ? 1 : 0; }

/**
 * Perfil usuario a entero
 * @param c referencia a la cadena
 * @return 1 si el perfil es usuario 0 administrador
 */
static int perfilUsuarioAint(char ** c);

int perfilUsuarioAint(char** c)
{ return (strcmp(*c,"usuario")== 0) ? 1 : 0; }

/* ficheros a estrucuturas */

Usuarios *initUsuarios(int * n){
  FILE *file = fopen("ficheros/Usuarios.txt", "r");
  if( file == NULL ) exit(1);
  Usuarios *tmp=NULL;
  (*n) = 0;
  char *id,*nomb,*locld,*usr,*log,*perfil,*estado;

  while(!feof(file))
  {
    id     = (char*) malloc(ID_USUARIO * sizeof(char));
    nomb   = (char*) malloc(NOMB       * sizeof(char));
    locld  = (char*) malloc(LOCAL      * sizeof(char));
    usr    = (char*) malloc(USR        * sizeof(char));
    log    = (char*) malloc(LOGINPASS  * sizeof(char));
    perfil = (char*) malloc(PERFIL     * sizeof(char));
    estado = (char*) malloc(ESTADO_U   * sizeof(char));

    if( id == NULL || nomb == NULL || locld == NULL || usr == NULL ||
            log == NULL || perfil == NULL || estado == NULL) exit(1);

    fscanf(file, "%[^-]-%[^-]-%[^-]-%[^-]-%[^-]-%[^-]-%[^\n]\n",
               id, nomb, locld, perfil ,usr,log,estado);
    if ( !*n ) tmp = (Usuarios*) malloc((*n + 1)    * sizeof(Usuarios));
    else       tmp = (Usuarios*) realloc(tmp,(*n+1) * sizeof(Usuarios));

    tmp[*n].Id_usuario     = atoi(id);
    tmp[*n].Nomb_usuario   = nomb;
    tmp[*n].Localidad      = locld;
    tmp[*n].Perfil_usuario = perfilUsuarioAint(&perfil);
    tmp[*n].User           = usr;
    tmp[*n].Login          = log;
    tmp[*n].Estado         = estadoUsuario(&estado);
    (*n)++;
    free(id);
    free(perfil);
    free(estado);
  }
  fclose(file);
  return tmp;
}

void saveUsuarios(int n ,Usuarios * usuarios)
{
    FILE* file = fopen("ficheros/Usuarios.txt","w+");

    if (file==NULL) exit(1);

    int i;
    for ( i = 0 ; i < n; ++i ){
        fprintf(file,"%04d-%s-%s-%s-%s-%s-%s\n",
                usuarios[i].Id_usuario,
                usuarios[i].Nomb_usuario,
                usuarios[i].Localidad,
                Perfil[usuarios[i].Perfil_usuario],
                usuarios[i].User,
                usuarios[i].Login,
                Estado_U[usuarios[i].Estado]);
        free(usuarios[i].Nomb_usuario);
        free(usuarios[i].Login);
        free(usuarios[i].User);
        free(usuarios[i].Localidad);
    }
    fclose(file);
    puts("Usuarios Guardados");
}

void perfilUsuario(vUsuarios* v,int userIndex)
{
    char resp = 0;
    printf("%d-%s-%s-%s-%s-%s-%s\n",
               v->user[userIndex].Id_usuario,
               v->user[userIndex].Nomb_usuario,
               v->user[userIndex].Localidad,
               Perfil[v->user[userIndex].Perfil_usuario],
               v->user[userIndex].User,
               v->user[userIndex].Login,
              Estado_U[v->user[userIndex].Estado]);
    printf("Desea modificar algun dato S/N\n");
    scanf("%c\n",&resp);
    if(resp == 's' || resp =='S')
    {
      puts(" 1. Nombre\n 2. Localidad\n 3. Login\n 4. Contraseña");
    }
}

void editarNombreUsuario(vUsuarios* v,int uIndex)
{

}

void editarLocalidadUsuario(vUsuarios* v,int uIndex)
{

}
void editarLoginUsuario(vUsuarios* v,int uIndex)
{

}
void editarPassUsuario(vUsuarios* v,int uIndex)
{

}
void eliminarUsuario(vUsuarios* v,int uIndex)
{
  Usuarios* tmp;
  tmp = (Usuarios *) malloc((v->tam-1)*sizeof(Usuarios));
  memcpy(tmp,v->user,(uIndex+1)*sizeof(Usuarios));
  memcpy(tmp + uIndex,(v->user)+(uIndex+1),(v->tam-uIndex)*sizeof(Usuarios));
  //memmove(&v->user[uIndex],&v->user[uIndex+1],(v->tam-uIndex-1)*sizeof(Usuarios));
  for (int i = 0 ; i < v->tam; ++i ){
    free(v->user[i].Nomb_usuario);
    free(v->user[i].Login);
    free(v->user[i].User);
    free(v->user[i].Localidad);
  }
  free(v->user);
  v->user=tmp;
  --v->tam;
}
