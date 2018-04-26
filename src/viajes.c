/**
* @file viajes.c
* @author Carlos Rodrigo Sanabria Flores
* @date 25 Apr 2018
* @copyright 2018 Carlos Rodrigo Sanabria Flores
* @brief <brief>
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "viajes.h"
#include "utilidades.h"
static const char * Viaje[] = {"vuelta","ida"};
static const char * Estado_Vi[] = {"cerrado","abierto","iniciado","finalizado","anulado"};
static int estadoViaje(char** c);
static void modificarPasos(vViajes* v,int index);
static int* pasosViajes(vViajes* v,int id_viaje,int* j);
static void eliminarViaje(vViajes* v,int id_viaje);
static void tipoViaje(vViajes* v, int vIndex);
static void addPaso(vViajes* v,int id_viaje);
static void pedirPaso(vViajes* v,int vIndex);
static void preguntarImporte(vViajes* v,int vIndex);
static void preguntarFechaHora(vViajes* v,int vIndex);
static int generarIdViaje(vViajes* v);
int estadoViaje(char** c)
{
    if(strcmp(*c,"cerrado")    == 0) return 0;
    if(strcmp(*c,"abierto")    == 0) return 1;
    if(strcmp(*c,"iniciado")   == 0) return 2;
    if(strcmp(*c,"finalizado") == 0) return 3;
    return 4;
}

static int idaVuelta (char** c);
int idaVuelta (char** c)
{ return (strcmp(*c,"ida")== 0) ? 1 : 0;}

Viajes* initViajes(int * n)
{
    FILE* file = fopen("ficheros/Viajes.txt", "r");
    if (file == NULL ) exit(1);
    (*n)=0;
    Viajes* tmp = NULL;
    char *id_viaje,*id_mat,*f_inic,*h_inic,*h_fin,*p_libres,*viaje,*importe,*estado;

    while (!feof(file))
    {
        id_viaje = (char*) malloc(ID_VIAJE * sizeof(char));
        id_mat   = (char*) malloc(ID_MAT   * sizeof(char));
        f_inic   = (char*) malloc(FECHA    * sizeof(char));
        h_inic   = (char*) malloc(HORA     * sizeof(char));
        h_fin    = (char*) malloc(HORA     * sizeof(char));
        p_libres = (char*) malloc(NPLAZS   * sizeof(char));
        viaje    = (char*) malloc(ID_VIAJE * sizeof(char));
        importe  = (char*) malloc(IMPORTE  * sizeof(char));
        estado   = (char*) malloc(ESTADO_V * sizeof(char));
        if(id_viaje == NULL || id_mat == NULL || f_inic == NULL || h_inic == NULL ||
              h_fin == NULL || p_libres == NULL || viaje == NULL ||
            importe == NULL || estado == NULL) exit(1);

        fscanf(file,"%[^-]-%[^-]-%[^-]-%[^-]-%[^-]-%[^-]-%[^-]-%[^€]€-%[^\n]\n",
               id_viaje,id_mat,f_inic,h_inic,h_fin,p_libres,viaje,importe,estado);

        tmp = (Viajes *) realloc(tmp,(*n+1) * sizeof(Viajes));
        tmp[*n].Id_viaje     = atoi(id_viaje);
        tmp[*n].Id_mat       = id_mat;
        tmp[*n].F_inic       = f_inic;
        tmp[*n].H_inic       = h_inic;
        tmp[*n].H_fin        = h_fin;
        tmp[*n].Plazas_libre = atoi(p_libres);
        tmp[*n].Viaje        = idaVuelta(&viaje);
        tmp[*n].Estado       = estadoViaje(&estado);
        sscanf(importe, "%f", &tmp[*n].Importe);
        (*n)++;
        free(id_viaje);
        free(p_libres);
        free(viaje);
        free(estado);
        free(importe);
    }
    fclose(file);
    return tmp;
}

Pasos* initPasos(int * n)
{
    FILE* file = fopen("ficheros/Pasos.txt", "r");
    if (file == NULL ) exit(1);
    (*n)=0;
    Pasos *tmp = NULL;
    char *id_viaje,*poblacion;

    while(!feof(file))
    {
        id_viaje  = (char*) malloc(ID_VIAJE * sizeof(char));
        poblacion = (char*) malloc(LOCAL    * sizeof(char));

        if( id_viaje == NULL || poblacion == NULL ) exit(0);

        fscanf(file,"%[^-]-%[^\n]\n",id_viaje,poblacion);
        tmp = (Pasos*) realloc(tmp,((*n)+1) * sizeof(Pasos));
        tmp[*n].Id_viaje  = atoi(id_viaje);
        tmp[*n].Poblacion = poblacion;
        (*n)++;
        free(id_viaje);
    }
    fclose(file);
    return tmp;
}

void saveViajes(int n,Viajes* viajes)
{
    FILE* file=fopen("ficheros/Viajes.txt","w+");
    if (file==NULL) exit(1);
    for (int i = 0 ; i < n; ++i ){
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
    FILE* file = fopen("ficheros/Pasos.txt","w+");
    if (file==NULL) exit(1);

    for (int i = 0 ; i < n; ++i ){
        fprintf(file,"%06d-%s\n",
        pasos[i].Id_viaje,
        pasos[i].Poblacion);
        free(pasos[i].Poblacion);
    }
    fclose(file);
    puts("Pasos Guardados");
}

int generarIdViaje(vViajes* v)
{
    return v->viajes[v->tam_v-1].Id_viaje + 1;
}

int* pasosViajes(vViajes* v,int id_viaje,int* j)
{
    int* tmp = NULL;
    *j = 0;
    for(int i = 0; i < v->tam_p;++i){
        if(id_viaje == v->pasos[i].Id_viaje)
        {
            tmp = (int *) realloc(tmp,((*j)+1) * sizeof(int));
            tmp[(*j)] = i;
            (*j)++;
        }
    }
    return tmp;
}

int buscarIndexViajes(vViajes* v,int id_viaje)
{
    for(int i = 0; i < v->tam_v ; ++i)
    {
      if(id_viaje == v->viajes[i].Id_viaje) return i;
    }
    return -1;
}

void eliminarViaje(vViajes* v,int vIndex)
{
    free(v->viajes[vIndex].Id_mat);
    free(v->viajes[vIndex].F_inic);
    free(v->viajes[vIndex].H_inic);
    free(v->viajes[vIndex].H_fin);
    memmove(&v->viajes[vIndex],&v->viajes[vIndex+1],(v->tam_v-vIndex-1)*sizeof(Viajes));
    --v->tam_v;
}

void eliminarPaso(vViajes* v,int vIndex)
{
    free(v->pasos[vIndex].Poblacion);
    memmove(&v->pasos[vIndex],&v->pasos[vIndex+1],(v->tam_p-vIndex-1)*sizeof(Pasos));
    --v->tam_p;
}

void eliminarViajes(vViajes* v, int id_viaje)
{
    int index = buscarIndexViajes(v,id_viaje);
    if(index > -1)
    {
        eliminarViaje(v,index);
        int size_p = 0;
        int* pasos = pasosViajes(v,id_viaje,&size_p);
        for(int i = 0;i< size_p;++i)
        {
            eliminarPaso(v,pasos[i]-i);
        }
        free(pasos);
    }
    else printf("No existe el viaje: %d\n",id_viaje);
}

void tipoViaje(vViajes* v, int vIndex)
{
    int tmp = 0;
    do{
        puts("0) Vuelta");
        puts("1) Ida");
        puts("Seleccione tipo de viaje: ");
        scanf("%1d[^\n]",&tmp);
        flush_in();
    }while(tmp < 0 && tmp > 1);
    v->viajes[vIndex].Viaje = tmp;
}

void pedirPaso(vViajes* v,int vIndex)
{
    printf("Ingrese Poblacion: ");
    scanf("%20[^\n]",v->pasos[vIndex].Poblacion);
    flush_in();
}

void addPaso(vViajes* v,int id_viaje)
{
    v->pasos = (Pasos*) realloc(v->pasos,(v->tam_p+1)  * sizeof(Pasos));
    v->pasos[v->tam_p].Poblacion = (char*) malloc(LOCAL* sizeof(char));
    v->pasos[v->tam_p].Id_viaje = id_viaje;
    pedirPaso(v,v->tam_p);
    ++v->tam_p;
}

void preguntarImporte(vViajes* v,int vIndex)
{
    printf("Ingrese Importe Total: ");
    scanf("%f[^\n]",&v->viajes[vIndex].Importe);
    flush_in();
}

void preguntarFechaHora(vViajes* v,int vIndex)
{
    int fflag = 0, hflag = 0;
    do{
        printf("Fecha del viaje: ");
        scanf("%10[^\n]", v->viajes[vIndex].F_inic);
        flush_in();                             //
        fflag = validarFecha(v->viajes[vIndex].F_inic);
    }while(fflag < 0);

    do {
        puts("Hora de incio: ");
        scanf("%5[^\n]", v->viajes[vIndex].H_inic);
        flush_in();
        hflag = validarHora(v->viajes[vIndex].H_inic, fflag);
    }while(hflag == 0);

    do {
        puts("Hora de fin: ");
        scanf("%5[^\n]", v->viajes[vIndex].H_fin);
        flush_in();
        hflag = validarHora(v->viajes[vIndex].H_fin,0);
    }while(hflag == 0);
}

void publicarViaje(vViajes* v,vVehiculos* vve,char* mat)
{
    int flag = 0, index = buscarIndexVehiculo(vve,mat);
    char resp = 0;
    if(index > -1){
        v->viajes = (Viajes *) realloc(v->viajes,(v->tam_v+1) * sizeof(Viajes));
        v->viajes[v->tam_v].Id_mat = (char*) malloc(ID_MAT    * sizeof(char));
        v->viajes[v->tam_v].F_inic = (char*) malloc(FECHA     * sizeof(char));
        v->viajes[v->tam_v].H_inic = (char*) malloc(HORA      * sizeof(char));
        v->viajes[v->tam_v].H_fin  = (char*) malloc(HORA      * sizeof(char));
        v->viajes[v->tam_v].Id_viaje = generarIdViaje(v);
        strcpy(v->viajes[v->tam_v].Id_mat,mat);
        v->viajes[v->tam_v].Plazas_libre = vve->vehi[index].Num_plazas;
        v->viajes[v->tam_v].Estado = 1;
        tipoViaje(v,v->tam_v);
        printf("Acontinuacion ingrese poblaciones por donde pasa (Max 10)\n");
        do{
            addPaso(v,v->viajes[v->tam_v].Id_viaje);
            printf("Desea agregar otra poblacion S/N\n");
            scanf("%1c[^\n]",&resp);
            flush_in();
            ++flag;
        }while( flag < 10 && (resp == 's' || resp =='S'));
        preguntarImporte(v,v->tam_v);
        preguntarFechaHora(v,v->tam_v);
        ++v->tam_v;
    }
}

void modificarPlazas(vViajes* v,vVehiculos* vve,int index,int indexv)
{
    float tmp = 0;
    do{
        printf("Ingrese Plazas: ");
        scanf("%f[^\n]",&tmp);
        flush_in();
    }while(tmp > vve->vehi[indexv].Num_plazas && tmp < 0.0);
    v->viajes[index].Plazas_libre = tmp;
}

void modificarEstadoViaje(vViajes* v,int index)
{
    do{
        printf(" 0) cerrado\n 1) abierto\n 2) iniciado\n 3) finalizado\n 4) anulado");
        printf("Ingrese Estado: ");
        scanf("%1d[^\n]",&v->viajes[index].Estado);
        flush_in();
    }while(v->viajes[index].Estado > 0 && v->viajes[index].Estado < 4);
}

void modificarPaso(vViajes* v,int id_viaje)
{
    int size_p = 0,resp = 0;
    int* pasos = pasosViajes(v,id_viaje,&size_p);
    for(int i = 0;i < size_p;++i)
    {
        printf(" %d. %s\n",i+1,v->pasos[pasos[i]].Poblacion);
    }
    printf("Que paso desea modificar: \n");
    scanf("%d[^\n]",&resp);
    flush_in();
    --resp;
    if(resp >= 0 && resp < size_p)
    {
        pedirPaso(v,pasos[resp]);
    }
    free(pasos);
}

void modificarPasos(vViajes* v,int id_viaje)
{
    char resp = 0;
    modificarPaso(v,id_viaje);
    do{
        printf("Desea modificar otro paso S/N\n");
        scanf("%c[^\n]",&resp);
        if(resp == 's' || resp == 'S') modificarPaso(v,id_viaje);
    }while(resp == 's' || resp == 'S');
}

void modificarViaje(vViajes* v, vVehiculos* ve,int id_viaje)
{
    int tmp = 0, index = buscarIndexViajes(v,id_viaje);
    if(index > -1){
    int indexv = buscarIndexVehiculo(ve,v->viajes[index].Id_mat);
        if(v->viajes[index].Estado == 1 &&
            v->viajes[index].Plazas_libre == ve->vehi[indexv].Num_plazas )
            {
                printf(" 1. Fecha y Hora\n 2. Plazas\n 3. Tipo Viaje\n 4. Importe\n 5. Estado\n 6. Pasos\n");
                printf("Seleccione una opcion: ");
                scanf("%1d[^\n]",&tmp);
                flush_in();
                switch (tmp) {
                    case 1:preguntarFechaHora(v,index);break;
                    case 2:modificarPlazas(v,ve,index,indexv);break;
                    case 3:tipoViaje(v,index);break;
                    case 4:preguntarImporte(v,index);break;
                    case 5:modificarEstadoViaje(v,index);break;
                    case 6:modificarPasos(v,id_viaje);break;
                    default:printf("Opcion no valida no se hace nada.\n");break;
                }
            }
    }
}

void listarViajesAdmin(vViajes* v)
{
    CLEAN;
    for(int i = 0;i<v->tam_v;++i)
    {
        printf("%06d-%s-%s-%s-%s-%d-%s-%.2f€-%s\n",
        v->viajes[i].Id_viaje,
        v->viajes[i].Id_mat,
        v->viajes[i].F_inic,
        v->viajes[i].H_inic,
        v->viajes[i].H_fin,
        v->viajes[i].Plazas_libre,
        Viaje[v->viajes[i].Viaje],
        v->viajes[i].Importe,
        Estado_Vi[v->viajes[i].Estado]);
        int size_p = 0;
        int* pasos = pasosViajes(v,v->viajes[i].Id_viaje,&size_p);
        if(size_p) printf("Que pasa por:\n");
        for(int j = 0;j < size_p;++j)
        {
            printf(" * %s.\n",v->pasos[pasos[j]].Poblacion);
        }
        free(pasos);
    }
    system_pause();
}

void listarViajesAbiertos(vViajes* v)
{
  printf("Viajes Abiertos: \n");
  int l_size = 0;
  int* l_viajes = listaViajesAbiertos(v,&l_size);
  for(int i = 0; i < l_size; ++i)
  {
      printf("%06d-%s-%s-%s-%s-%d-%s-%.2f€\n",
        v->viajes[l_viajes[i]].Id_viaje,
        v->viajes[l_viajes[i]].Id_mat,
        v->viajes[l_viajes[i]].F_inic,
        v->viajes[l_viajes[i]].H_inic,
        v->viajes[l_viajes[i]].H_fin,
        v->viajes[l_viajes[i]].Plazas_libre,
        Viaje[v->viajes[l_viajes[i]].Viaje],
        v->viajes[l_viajes[i]].Importe);
  }
  free(l_viajes);
}

int* listaViajesAbiertos(vViajes* v,int* j)
{
  int* tmp = NULL;
  *j = 0;
  for(int i = 0; i < v->tam_v;++i){
      if(v->viajes[i].Estado == 1)
      {
          tmp = (int *) realloc(tmp,((*j)+1) * sizeof(int));
          tmp[(*j)] = i;
          (*j)++;
      }
  }
  return tmp;
}

void publicarViajeUsuario(vViajes* v,vVehiculos* ve,int userId)
{
  int l_vehi_size = 0,i = 0;
  int* l_vehi = listarVehiculosViajes(ve,userId,&l_vehi_size);
  if(l_vehi_size){
    for(i = 0;i< l_vehi_size;++i)
    {
      printf("%d) Matricula: %s Descripcion: %s ",i+1,
      ve->vehi[l_vehi[i]].Id_mat,
      ve->vehi[l_vehi[i]].Desc_veh);
    }
    int opc = 0;
    do{
    printf("Con que vehiculo desea realizar el viaje: ");
    scanf("%d",&opc);
    --opc;
    }while(opc < 0 && opc > l_vehi_size-1);
    publicarViaje(v,ve,ve->vehi[l_vehi[opc]].Id_mat);
  }
  free(l_vehi);
}

void incorporarseViaje()
{

}

void actualizarViajes(vViajes* v)
{
  time_t hoy = time(NULL);
  struct tm t1,t2,t3=*localtime(&hoy);
  memset(&t1, 0, sizeof(struct tm));
  memset(&t2, 0, sizeof(struct tm));
  for(int i = 0; i < v->tam_v;++i )
  {
    if(v->viajes[i].Estado == 1)
    { //1 = abierto
      sscanf(v->viajes[i].H_fin,"%d:%d",&t1.tm_hour,&t1.tm_min);
      sscanf(v->viajes[i].F_inic,"%d/%d/%d",&t2.tm_mday,&t2.tm_mon,&t2.tm_year);
      t1.tm_hour+=1;
      mktime(&t1);
      mktime(&t2);
      if(fechaMenor(t2.tm_mday,t2.tm_mon,t2.tm_year)) { v->viajes[i].Estado = 3; }
      else if((t2.tm_mday==t3.tm_mday)&&(t2.tm_mon == t3.tm_mon+1)&&(t2.tm_year == t3.tm_year+1900))
            { if(((t1.tm_hour*60) + t1.tm_min) < ((t3.tm_hour*60)+t3.tm_min))
                { v->viajes[i].Estado = 3;}
            }
    }
  }
}
