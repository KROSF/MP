#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vehiculos.h"
#include "utilidades.h"
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

void matricula(vVehiculos* v,int vIndex)
{
    int tmp = 0;
    char tmpc[3];
    do{
        printf("Ingrese matricula: ");
        scanf("%7[^\n]",v->vehi[vIndex].Id_mat);
        flush_in();
    }while( sscanf(v->vehi[vIndex].Id_mat,"%4d%3s",&tmp,tmpc) != 2);
}

void descripcion(vVehiculos* v,int vIndex)
{
    printf("Ingrese descripcion: ");
    scanf("%50[^\n]",v->vehi[vIndex].Id_mat);
    flush_in();
}

void num_plazas(vVehiculos* v,int vIndex)
{
    printf("Ingrese numero de plazas: ");
    scanf("%1d[^\n]",&v->vehi[vIndex].Num_plazas);
    flush_in();
}

void altaVehiculos(vVehiculos* v,int id)
{
    v->vehi = (Vehiculos*) realloc(v->vehi,(v->tam+1)  * sizeof(Vehiculos));
    v->vehi[v->tam].Id_mat   = (char*) malloc( ID_MAT  * sizeof(char));
    v->vehi[v->tam].Desc_veh = (char*) malloc( DES_VEH * sizeof(char));
    v->vehi[v->tam].Id_usuario = id;
    matricula(v,v->tam);
    descripcion(v,v->tam);
    num_plazas(v,v->tam);
    ++v->tam;
}

int buscarIndexVehiculo(vVehiculos* v,char* mat)
{
    for(int i = 0; i < v->tam ; ++i)
    {
      if(strcmp(mat,v->vehi[i].Id_mat) == 0) return i;
    }
    return -1;
}

void bajaVehiculos(vVehiculos* v, char* mat)
{
    int index = buscarIndexVehiculo(v,mat);
    if(index > -1)
    {
        eliminarVehiculo(v,index);
    }else printf("No existe un vehiculo con dicha matricula\n");
}

void eliminarVehiculo(vVehiculos* v,int vIndex)
{
    free(v->vehi[vIndex].Id_mat);
    free(v->vehi[vIndex].Desc_veh);
    memmove(&v->vehi[vIndex],&v->vehi[vIndex+1],(v->tam-vIndex-1)*sizeof(Vehiculos));
    --v->tam;
}

void modificarVehiculo(vVehiculos* v,char* mat)
{
    int tmp = 0, index = buscarIndexVehiculo(v,mat);
    if(index > - 1)
    {
        printf(" 1. Matricula\n 2. Descripcion\n 3. Numero de Plazas\n");
        printf("Seleccione una opcion: ");
        scanf("%1d[^\n]",&tmp);
        flush_in();
        switch (tmp) {
            case 1:matricula(v,index);break;
            case 2:descripcion(v,index);break;
            case 3:num_plazas(v,index);break;
            default:printf("Opcion no valida no se hace nada.\n");break;
        }
    }
}

void listarVehiculos(vVehiculos* v)
{
    for(int i = 0; i < v->tam;++i)
    {
        printf("%s-%d-%d-%s",
            v->vehi[i].Id_mat,
            v->vehi[i].Id_usuario,
            v->vehi[i].Num_plazas,
            v->vehi[i].Desc_veh);
    }
}

void listarVehiculosViajes(char* mat)
{
    //listar viajes realizados por cada vehiculo
}