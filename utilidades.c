#include <stdio.h>
#include "utilidades.h"
void flush_in() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}
int esMinuscula(char c) { return (c >= 'a' && c <= 'z') ? 1 : 0 ;}

int aMayuscula(char c) { return c - 32;}

void stringAmayuscula(char* cad)
{
    for(int index = 0; cad[index] != '\0'; ++index){
        if(esMinuscula(cad[index]))
            cad[index] = aMayuscula(cad[index]);
    }
}

/*void eliminarUsuario(Usuarios* usuarios,int* n,int index)
{
  memmove(&usuarios[index], &usuarios[index+1], (*n-index-1)*sizeof(Usuarios));
  (*n)--;
}
void eliminarVehiculos(Vehiculos* vehiculos,int* n,int index)
{
    memmove(&vehiculos[index], &vehiculos[index+1], (*n-index-1)*sizeof(Vehiculos));
    (*n)--;
}
void eliminarViajes(Viajes* viajes,int* n,int index)
{
    memmove(&viajes[index], &viajes[index+1], (*n-index-1)*sizeof(Viajes));
    (*n)--;
}
void eliminarPasos(Pasos* pasos,int* n,int index)
{
    memmove(&pasos[index], &pasos[index+1], (*n-index-1)*sizeof(Pasos));
    (*n)--;
}
void eliminarIncidencias(Incidencias* incidencias,int* n,int index)
{
    memmove(&incidencias[index], &incidencias[index+1], (*n-index-1)*sizeof(Incidencias));
    (*n)--;
}
int buscarUsuarioIndex(Usuarios* usuarios,int n,int id_usuario)
{
  int i;
  for(i = 0; i < n; ++i)
  {
    if(id_usuario == usuarios[i].Id_usuario) return i;
  }
  return -1;
}

int buscarVehiculosIndex(Vehiculos* vehiculos,int n,char* id_mat)
{
  int i;
  for(i = 0; i < n; ++i)
  {
    if(strcmp(id_mat,vehiculos[i].Id_mat)==0) return i;
  }
  return -1;
}

int* todoVehiculosUser(Vehiculos* vehiculos,int n,int id_usuario,int* tam)
{
  int* vh;
  for(int i = 0;i < n;++i)
  {
    if(id_usuario == vehiculos[i].Id_usuario)
    {
        if(! *tam )vh  = (int *) malloc((*tam+1)*sizeof(int));
        else vh = (int *) realloc(vh,(*tam +1) * sizeof(int));
        vh[(*tam)++] = i;
    }
  }
  return vh;
}

int buscarViajesIndex(Viajes* viajes,int n,int id_viaje)
{
  int i;
  for(i = 0; i < n; ++i)
  {
    if(id_viaje == viajes[i].Id_viaje) return i;
  }
  return -1;
}

int buscarPasosIndex(Pasos* pasos,int n, int id_viaje)
{
  int i;
  for(i = 0; i < n; ++i)
  {
    if(id_viaje == pasos[i].Id_viaje) return i;
  }
  return -1;
}
int buscarIncidenciasIndex(Incidencias* incidencias,int n, int id_viaje)
{
  int i;
  for(i = 0; i < n; ++i)
  {
    if(id_viaje == incidencias[i].Id_viaje) return i;
  }
  return -1;
}

int validarFecha(char* cadena)
{
    static const int DiaMes[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    time_t t1 = {time(NULL)};
    struct tm *t2 = {localtime(&t1)};
    int d=0,m=0,a=0;
    if(sscanf(cadena,"%d/%d/%4d",&d,&m,&a) != 3) return -1;
    if( a < t2->tm_year+1900 || a > 2030 ) return -1;
    if( m < t2->tm_mon+1 || m > 12 ) return -1;
    int bisiesto = (a % 4 == 0 && ( a % 400 == 0 || a % 100 != 0));
    if(d < t2->tm_mday || d > (DiaMes[m]+bisiesto) ) return -1;
    if(d == t2->tm_mday && m == t2->tm_mon+1 && a == t2->tm_year+1900) return 1;
    return 0;
}

int validarHora(char* cadena,int hoy)
{
  time_t t1 = {time(NULL)};
  struct tm* t2 = {localtime(&t1)};
  int h = 0, m = 0;
  if(sscanf(cadena,"%2d:%2d",&h,&m)!=2) return 0;
  if(h >= 0 && h < 24 && m >= 0 && m < 60){
	if(hoy == 1 && (h > t2->tm_hour || (h == t2->tm_hour && m > t2->tm_min))) return 1;
	else return 1;
  }

  return 0;
}

int generarIdViaje(Viajes* viajes,int n)
{ return viajes[n].Id_viaje + 1; }*/
