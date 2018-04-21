#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vehiculos.h"
Vehiculos* initVehiculos(int * n)
{
    FILE* file = fopen("ficheros/Vehiculos.txt", "r");
    if (file == NULL ) exit(1);
    char *mat,*idu,*nplzs,*des_veh;
    Vehiculos *tmp=NULL;
    (*n)=0;
    while(!feof(file))
    {
        mat     = (char*) malloc( ID_MAT     * sizeof(char));
        idu     = (char*) malloc( ID_USUARIO * sizeof(char));
        nplzs   = (char*) malloc( NPLAZS     * sizeof(char));
        des_veh = (char*) malloc( DES_VEH    * sizeof(char));

        if(mat == NULL || idu == NULL || nplzs == NULL || des_veh == NULL) exit(1);
        fscanf(file, "%[^-]-%[^-]-%[^-]-%[^\n]\n", mat, idu, nplzs,des_veh);

        if (! * n ) tmp = (Vehiculos *) malloc( (*n+1) * sizeof(Vehiculos));
        else tmp = (Vehiculos *) realloc(tmp,(*n+1) * sizeof(Vehiculos));

        tmp[*n].Id_usuario = atoi(idu);
        tmp[*n].Id_mat     = mat;
        tmp[*n].Desc_veh   = des_veh;
        tmp[*n].Num_plazas = atoi(nplzs);
        (*n)++;
        free(idu);
        free(nplzs);
    }
    fclose(file);
    return tmp;
}

void saveVehiculos(int n ,Vehiculos* vehiculos)
{
    FILE* file = fopen("ficheros/Vehiculos.txt","w+");
    if (file==NULL) exit(1);
    for (int i = 0 ; i < n; ++i ){
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
