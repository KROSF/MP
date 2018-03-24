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
static void saveVehiculos(int n,Vehiculos*vehiculos);
/**
 *
 * @param n
 * @param viajes
 */
static void saveViajes(int n,Viajes *viajes);
/**
 *
 * @param n
 * @param pasos
 */
static void savePasos(int n ,Pasos* pasos);
/**
 *
 * @param n
 * @param incidencias
 */
static void saveIncidencias(int n,Incidencias* incidencias);


void saveUsuarios(int n ,Usuarios * usuarios)
{
    FILE *file;


    file=fopen("ficheros/Usuarios.txt","w+");

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

void saveVehiculos(int n ,Vehiculos* vehiculos)
{
    FILE *file;
    file=fopen("ficheros/Vehiculos.txt","w+");
    if (file==NULL) exit(1);

    int i;
    for ( i = 0 ; i < n; ++i ){
        fprintf(file,"%s-%04d-%d-%s\n",
        vehiculos[i].Id_mat,
        vehiculos[i].Id_usuario,
        vehiculos[i].Num_plazas,
        vehiculos[i].Desc_veh);

        free(vehiculos[i].Id_mat);
        free(vehiculos[i].Desc_veh);
    }
    fclose(file);
    puts("Vehiculos Guardados");
}

void saveViajes(int n,Viajes* viajes)
{
    FILE *file;
    file=fopen("ficheros/Viajes.txt","w+");
    if (file==NULL) exit(1);

    int i;
    for ( i = 0 ; i < n; ++i ){
        fprintf(file,"%06d-%s-%s-%s-%s-%d-%s-%.2f€-%s\n",
        viajes[i].Id_viaje,
        viajes[i].Id_mat,
        viajes[i].F_inic,
        viajes[i].H_inic,
        viajes[i].H_fin,
        viajes[i].Plazas_libre,
        Viaje[viajes[i].Viaje],
        viajes[i].Importe,
        Estado_Vi[viajes[i].Estado]);
        free(viajes[i].Id_mat);
        free(viajes[i].F_inic);
        free(viajes[i].H_inic);
        free(viajes[i].H_fin);
    }
    fclose(file);
    puts("Viajes Guardados");
}

void savePasos(int n,Pasos* pasos)
{
    FILE *file;
    file=fopen("ficheros/Pasos.txt","w+");
    if (file==NULL) exit(1);

    int i;
    for ( i = 0 ; i < n; ++i ){
        fprintf(file,"%06d-%s\n",
        pasos[i].Id_viaje,
        pasos[i].Poblacion);
        free(pasos[i].Poblacion);
    }
    fclose(file);
    puts("Pasos Guardados");
}

void saveIncidencias(int n,Incidencias* incidencias)
{
    FILE *file;
    file=fopen("ficheros/Incidencias.txt","w+");
    if (file==NULL) exit(1);

    int i;
    for ( i = 0 ; i < n; ++i ){
        fprintf(file,"%06d-%04d-%04d-%s-%s\n",
        incidencias[i].Id_viaje,
        incidencias[i].Id_us_registra,
        incidencias[i].Id_us_incidencia,
        incidencias[i].Desc_indicencia,
        Estado_I[incidencias[i].Est_incidencia]);
        free(incidencias[i].Desc_indicencia);
    }
    puts("Incidencias Guardadas");
}

void guardar(Usuarios** pUsuarios, Vehiculos** pVehiculos, Viajes** pViajes,
             Pasos** pPasos,Incidencias** pIncidencias,int* pInt)
{
    saveUsuarios(pInt[0],*pUsuarios);
    free(*pUsuarios);
    pInt[0] = 0;
    saveVehiculos(pInt[1],*pVehiculos);
    free(*pVehiculos);
    pInt[1] = 0;
    saveViajes(pInt[2],*pViajes);
    free(*pViajes);
    pInt[2] = 0;
    savePasos(pInt[3],*pPasos);
    free(*pPasos);
    pInt[3] = 0;
    saveIncidencias(pInt[4],*pIncidencias);
    free(*pIncidencias);
    pInt[4] = 0;
}
