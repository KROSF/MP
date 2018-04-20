#include <stdio.h>
#include "cargar.h"
int main(){

  vUsuarios user;
  initvUsuarios(&user);
  printf("%d\n", user.tam );

  for(int i = 0;i< user.tam;++i)
  {
    printf("%d-%s-%s-%s-%s-%s-%s\n",
               user.user[i].Id_usuario,
               user.user[i].Nomb_usuario,
               user.user[i].Localidad,
               Perfil[user.user[i].Perfil_usuario],
               user.user[i].User,
               user.user[i].Login,
              Estado_U[user.user[i].Estado]);
  }
  eliminarUsuario(&user,0);
  for(int i = 0;i< user.tam;++i)
  {
    printf("%d-%s-%s-%s-%s-%s-%s\n",
               user.user[i].Id_usuario,
               user.user[i].Nomb_usuario,
               user.user[i].Localidad,
               Perfil[user.user[i].Perfil_usuario],
               user.user[i].User,
               user.user[i].Login,
              Estado_U[user.user[i].Estado]);
  }
  savevUsuarios(&user);
  return 0;
}
