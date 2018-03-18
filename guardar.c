//
// Created by krosf on 18/03/18.
//

#include <stdio.h>
#include <stdlib.h>
#include "guardar.h"

/**
 *
 * @param n
 * @param usuarios
 */
static void saveUsuarios(int n,Usuarios * usuarios);
/**
 *
 * @param n
 * @param vehiculos
 */
static void savaVehiculos(int n,Vehiculos vehiculos);
/**
 *
 * @param n
 * @param viajes
 */
static void saveViajes(int n,Viajes viajes);
/**
 *
 * @param n
 * @param pasos
 */
static void savePasos(int n ,Pasos pasos);
/**
 *
 * @param n
 * @param incidencias
 */
static void saveIncidencias(int n,Incidencias incidencias);


void saveUsuarios(int n ,Usuarios * usuarios)
{
    FILE *file;


    file=fopen("usuarios.txt","w+");

    if (file==NULL) exit(1);

    for (int i=0; i< n; i++){
        fprintf(file,"%04d-%s-%s-%s-%s-%s-%s\n",
                usuarios[i].Id_usuario,
                usuarios[i].Nomb_usario,
                usuarios[i].Localidad,
                Perfil[usuarios[i].Perfil_usuario],
                usuarios[i].User,
                usuarios[i].Login,
                Estado_U[usuarios[i].Estado]);
        free(usuarios[i].Nomb_usario);
        free(usuarios[i].Login);
        free(usuarios[i].User);
        free(usuarios[i].Localidad);
    }
    fclose(file);
    puts("Usuarios guardados correctamente");
}

void guardar(Usuarios** pUsuarios, Vehiculos** pVehiculos, Viajes** pViajes,
             Pasos** pPasos,Incidencias** pIncidencias,int* pInt)
{
    saveUsuarios(pInt[0],*pUsuarios);
    free(*pUsuarios);
    pInt[0] = 0;

}
