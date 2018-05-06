/**
 * @file viajes.c
 * @author Carlos Rodrigo Sanabria Flores
 * @date 25 Apr 2018
 * @copyright 2018 Carlos Rodrigo Sanabria Flores
 * @brief Definicion de las funciones publicas y privadas del modulo viajes.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define utilidades_IMPORT
#include "utilidades.h"
#undef utilidades_IMPORT
#define viajes_IMPORT
#include "viajes.h"
#undef viajes_IMPORT
static const char*Matriculas[]={"1037MMX","0193QAZ","3975GLM","2279KHW","4531PMR",
"5282KJH","0484NKV","0620YOV","3421NYJ","6893VYT","1843CTH","4461OEV"};
static const char *Viaje[] = {"vuelta", "ida"};
static const char *Estado_Vi[] = {"cerrado", "abierto", "iniciado",
                                  "finalizado", "anulado"};
/**
 * Convierte los estados de viajes a enteros.
 * @param  c cadena con el estado.
 * @return   representacion numerica del estado.
 */
static int estadoViaje(char *c) {
    if (strcmp(c, "cerrado") == 0)
        return 0;
    if (strcmp(c, "abierto") == 0)
        return 1;
    if (strcmp(c, "iniciado") == 0)
        return 2;
    if (strcmp(c, "finalizado") == 0)
        return 3;
    return 4;
}

/**
 * Convierte el tipo de viaje a entero.
 * @param  c Cadena con el tipo de viaje
 * @return   1 si el tipo es ida.
 * @return   0 si el tipo es vuelta.
 */
static int idaVuelta(char *c) { return (strcmp(c, "ida") == 0) ? 1 : 0; }

void generarFicheros(char* file_name,int tam, int n)
{
    FILE* file=fopen(file_name,"w+");
    if (file == NULL) exit(EXIT_FAILURE);
    time_t t;
    srand((unsigned) time(&t));
    for(int i = 0 ; i < tam ; ++i)
    {
        struct tm hoy = *localtime(&t);
        char f_inic[FECHA],h_inic[HORA],h_fin[HORA];
        hoy.tm_hour+=rand()%23;
        hoy.tm_min+=rand()%59;
        hoy.tm_mday+=n;
        mktime(&hoy);
        strftime(f_inic,FECHA,"%d/%m/%Y",&hoy);
        strftime(h_inic,HORA,"%H:%M",&hoy);
        hoy.tm_hour+=rand()%4;
        hoy.tm_min+=rand()%29;
        strftime(h_fin,HORA,"%H:%M",&hoy);
        fprintf(file, "%06d-%s-%s-%s-%s-%d-%s-%.2f€-%s\n",i+1,
                Matriculas[rand()%11],
                f_inic,
                h_inic,
                h_fin,
                (rand()%5)+2,
                Viaje[i%2],
                rand()%50+1.0,
                Estado_Vi[rand()%4]);
    }
    fclose(file);
}

Viajes *initViajes(int *n) {
    FILE *file = fopen("ficheros/Viajes.txt", "r");
    if (file == NULL) exit(EXIT_FAILURE);
    (*n) = 0;
    Viajes *tmp = NULL;
    char *id_mat, *f_inic, *h_inic, *h_fin,
        *id_viaje = (char*)malloc(ID_VIAJE * sizeof(char)),
        *p_libres = (char*)malloc(NPLAZS   * sizeof(char)),
        *viaje    = (char*)malloc(ID_VIAJE * sizeof(char)),
        *importe  = (char*)malloc(IMPORTE  * sizeof(char)),
        *estado   = (char*)malloc(ESTADO_V * sizeof(char));

     if (id_viaje == NULL || p_libres == NULL || viaje == NULL ||
            importe == NULL || estado == NULL)  exit(1);

    while (!feof(file)) {
        id_mat = (char *)malloc(ID_MAT * sizeof(char));
        f_inic = (char *)malloc(FECHA * sizeof(char));
        h_inic = (char *)malloc(HORA * sizeof(char));
        h_fin = (char *)malloc(HORA * sizeof(char));

        if(id_mat == NULL || f_inic == NULL || h_inic == NULL || h_fin == NULL )
            exit(1);

        fscanf(file, "%[^-]-%[^-]-%[^-]-%[^-]-%[^-]-%[^-]-%[^-]-%[^€]€-%[^\n]\n",
            id_viaje, id_mat, f_inic, h_inic, h_fin, p_libres, viaje, importe,
            estado);

        tmp = (Viajes *)realloc(tmp, (*n + 1) * sizeof(Viajes));

        tmp[*n].Id_viaje = atoi(id_viaje);
        tmp[*n].Id_mat = id_mat;
        tmp[*n].F_inic = f_inic;
        tmp[*n].H_inic = h_inic;
        tmp[*n].H_fin = h_fin;
        tmp[*n].Plazas_libre = atoi(p_libres);
        tmp[*n].Viaje = idaVuelta(viaje);
        tmp[*n].Estado = estadoViaje(estado);
        sscanf(importe, "%f", &tmp[*n].Importe);
        ++(*n);
    }
    free(id_viaje);
    free(p_libres);
    free(viaje);
    free(estado);
    free(importe);
    fclose(file);
    return tmp;
}

void saveViajes(int n, Viajes *viajes) {
    FILE *file = fopen("ficheros/Viajes.txt", "w+");
    if (file == NULL)   exit(EXIT_FAILURE);
    for (int i = 0; i < n; ++i) {
        fprintf(file, "%06d-%s-%s-%s-%s-%d-%s-%.2f€-%s\n", viajes[i].Id_viaje,
                viajes[i].Id_mat, viajes[i].F_inic, viajes[i].H_inic,
                viajes[i].H_fin, viajes[i].Plazas_libre, Viaje[viajes[i].Viaje],
                viajes[i].Importe, Estado_Vi[viajes[i].Estado]);
        free(viajes[i].Id_mat);
        free(viajes[i].F_inic);
        free(viajes[i].H_inic);
        free(viajes[i].H_fin);
    }
    fclose(file);
    puts("Viajes Guardados");
}

void actualizarViajes(vViajes *v) {
    struct tm h_fin, f_inic,h_inic;
    //Incializa h_fin, f_inic, h_inic a 0.
    memset(&h_fin , 0, sizeof(struct tm));
    memset(&h_inic, 0, sizeof(struct tm));
    memset(&f_inic, 0, sizeof(struct tm));
    for (int i = 0; i < v->tam_v; ++i) {
        if (v->viajes[i].Estado == 1 || v->viajes[i].Estado == 0 )
        {   //convesion de fecha y hora a formato mas manejable
            sscanf(v->viajes[i].H_inic,"%d:%d",&h_inic.tm_hour, &h_inic.tm_min);
            sscanf(v->viajes[i].H_fin, "%d:%d", &h_fin.tm_hour, &h_fin.tm_min);
            sscanf(v->viajes[i].F_inic, "%d/%d/%d",
                    &f_inic.tm_mday, &f_inic.tm_mon,&f_inic.tm_year);
            //se le suma una hora a la hora final.
            h_fin.tm_hour += 1;
            //se guarda el cambio.
            mktime(&h_fin);
            if (fechaMenor(&f_inic))
                v->viajes[i].Estado = 3;
            else if (fechaIgual(&f_inic))
            {
                if(horaMenor(&h_inic))
                    v->viajes[i].Estado = 2;
                else if (horaMenor(&h_fin))
                    v->viajes[i].Estado = 3;
            }
        }
    }
}
