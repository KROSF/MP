#include <stdio.h>
#include <memory.h>
#include "utilidades.h"
void flush_in() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}
void eliminarUsuario(Usuarios** usuarios,int* n,int index)
{
    memmove(&(*usuarios)[index], &(*usuarios)[index+1], (*n-index-1)*sizeof(Usuarios));
    (*n)--;
}
void eliminarVehiculos(Vehiculos** vehiculos,int* n,int index)
{
    memmove(&(*vehiculos)[index], &(*vehiculos)[index+1], (*n-index-1)*sizeof(Vehiculos));
    (*n)--;
}
void eliminarViajes(Viajes** viajes,int* n,int index)
{
    memmove(&(*viajes)[index], &(*viajes)[index+1], (*n-index-1)*sizeof(Viajes));
    (*n)--;
}
void eliminarPasos(Pasos** pasos,int* n,int index)
{
    memmove(&(*pasos)[index], &(*pasos)[index+1], (*n-index-1)*sizeof(Pasos));
    (*n)--;
}
void eliminarIncidencias(Incidencias** incidencias,int* n,int index)
{
    memmove(&(*incidencias)[index], &(*incidencias)[index+1], (*n-index-1)*sizeof(Incidencias));
    (*n)--;
}
