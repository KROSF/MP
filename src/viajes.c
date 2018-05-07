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

/**
 * Genera un nuevo id a partir del ultimo id en el vector viajes.
 * @param  v Referencia al vector de viajes.
 * @return   Nuevo id no repetido en el vector de viajes.
 */
static int generarIdViaje(vViajes *v) {
    return v->viajes[v->tam_v - 1].Id_viaje + 1;
}

/**
 * Pregunta y recoge por la entrada estandar el tipo de un viaje.
 * @param v      Referencia al vector de viajes.
 * @param vIndex Indice en el vector donde se guardara el tipo.
 */
static void tipoViaje(vViajes *v, int vIndex) {
    int tmp = 0;
    do {
        printf("0) Vuelta\n1) Ida\n");
        printf("Seleccione tipo de viaje: ");
        scanf("%1d[^\n]", &tmp);
        flush_in();
    } while (tmp < 0 && tmp > 1);
    v->viajes[vIndex].Viaje = tmp;
}

/**
 * Pregunta y recoge por la entrada estandar una poblacion.
 * @param v      Referencia al vector de viajes.
 * @param vIndex Indice en el vector donde se guardara la poblacion.
 */
static void pedirPaso(vViajes *v, int vIndex) {
    printf("Ingrese Poblacion: ");
    scanf("%20[^\n]", v->pasos[vIndex].Poblacion);
    flush_in();
}

/**
 * Agrega un elemento al vector pasos.
 * @param v        Referencia al vector de viajes.
 * @param id_viaje Indentificador del viaje que pasa por la poblacion.
 */
static void addPaso(vViajes *v, int id_viaje) {
    //Reasignamos memoria para un elemeto mas.
    v->pasos = (Pasos *)realloc(v->pasos, (v->tam_p + 1) * sizeof(Pasos));
    if (v->pasos == NULL)
        exit(1);//Cierra el programa si existe algun error con la reasignacion.
    //Reservamos memoria para la poblacion.
    v->pasos[v->tam_p].Poblacion = (char *)malloc(LOCAL * sizeof(char));
    if (v->pasos[v->tam_p].Poblacion == NULL)
        exit(1);//Cierra el programa si existe algun error con la reserva.
    v->pasos[v->tam_p].Id_viaje = id_viaje;
    pedirPaso(v, v->tam_p);
    ++v->tam_p;
}

static void addPasajero(vViajes *v, int id_viaje,int id_viajero)
{
    //Reasignamos memoria para un elemeto mas.
    v->pasaj = (Pasajeros *)realloc(v->pasaj, (v->tam_pj + 1) * sizeof(Pasajeros));
    if (v->pasaj == NULL)
        exit(1);//Cierra el programa si existe algun error con la reasignacion.
    v->pasaj[v->tam_pj].Id_viaje = id_viaje;
    v->pasaj[v->tam_pj].Id_viajero = id_viajero;
    ++v->tam_pj;
}

/**
 * Pregunta y recoge por la entrada estandar el importe del viaje.
 * @param v      Referencia al vector de viajes.
 * @param vIndex Indice en el vector donde se guardara.
 */
static void preguntarImporte(vViajes *v, int vIndex) {
  printf("Ingrese Importe Total: ");
  scanf("%f[^\n]", &v->viajes[vIndex].Importe);
  flush_in();
}
/**
 * Pregunta y recoge por la entrada estandar la fecha y horas de inicio y fin.
 * @param v      Referencia al vector de viajes.
 * @param vIndex Indice en el vector donde se guardara.
 */
static void preguntarFechaHora(vViajes *v, int vIndex) {
    int fecha_igual_a_hoy = 0;
    do {
        printf("Fecha del viaje: ");
        scanf("%10[^\n]", v->viajes[vIndex].F_inic);
        flush_in();
        fecha_igual_a_hoy = validarFecha(v->viajes[vIndex].F_inic);
    } while (fecha_igual_a_hoy < 0);

    do {
        puts("Hora de incio: ");
        scanf("%5[^\n]", v->viajes[vIndex].H_inic);
        flush_in();
    } while (validarHora(v->viajes[vIndex].H_inic, fecha_igual_a_hoy) != 1);

    do {
        puts("Hora de fin: ");
        scanf("%5[^\n]", v->viajes[vIndex].H_fin);
        flush_in();
    } while (validarHora(v->viajes[vIndex].H_fin, 0) != 1);
}

/**
 * Funcion para publicar un viaje sea usuario o administrador.
 * @param v   Referencia a la estructura viajes.
 * @param vve Referencia a la estructura vehiculos.
 * @param mat Matricula del coche que hace el viaje.
 */
static void publicarViaje(vViajes *v, vVehiculos *vve, char *mat) {
    int flag = 0, index = buscarIndexVehiculo(vve, mat);
    char resp = 0;
    if (index > -1) {
        v->viajes = (Viajes *)realloc(v->viajes, (v->tam_v + 1) * sizeof(Viajes));
        if (v->viajes == NULL)
            exit(EXIT_FAILURE);//Cierra el programa si existe algun error con la reasignacion.
        v->viajes[v->tam_v].Id_mat = (char *)malloc(ID_MAT * sizeof(char));
        v->viajes[v->tam_v].F_inic = (char *)malloc(FECHA  * sizeof(char));
        v->viajes[v->tam_v].H_inic = (char *)malloc(HORA   * sizeof(char));
        v->viajes[v->tam_v].H_fin  = (char *)malloc(HORA   * sizeof(char));
        if (v->viajes[v->tam_v].Id_mat == NULL ||
            v->viajes[v->tam_v].F_inic == NULL ||
            v->viajes[v->tam_v].H_inic == NULL ||
            v->viajes[v->tam_v].H_fin  == NULL)
                exit(EXIT_FAILURE);
        //Nuevo id_viaje.
        v->viajes[v->tam_v].Id_viaje = generarIdViaje(v);
        //Coche que el viaje.
        strcpy(v->viajes[v->tam_v].Id_mat, mat);
        //Plazas libres por defecto.
        v->viajes[v->tam_v].Plazas_libre = vve->vehi[index].Num_plazas;
        //Estado de viaje por defecto.
        v->viajes[v->tam_v].Estado = 1;
        //Preguntar tipo del viaje.
        tipoViaje(v, v->tam_v);
        //Preguntar por los pasos del viaje.
        printf("Acontinuacion ingrese poblaciones por donde pasa (Max 10)\n");
        do {
            addPaso(v, v->viajes[v->tam_v].Id_viaje);
            printf("Desea agregar otra poblacion S/N\n");
            scanf("%1c[^\n]", &resp);
            flush_in();
        } while (flag++ < 10 && (resp == 's' || resp == 'S'));
        //Establecer las fechas y hora de viaje.
        preguntarFechaHora(v, v->tam_v);
        //Establecer el precio.
        preguntarImporte(v, v->tam_v);
        //Incrementar el tamaño de la estructura.
        ++v->tam_v;
    }
}

/**
 * Pregunta y recoge por la entrada estandar el numero de plazas.
 * @param v             Referencia al vector viajes.
 * @param vve           Referencia al vector vehiculos.
 * @param indexViaje    Indice del viaje a modificar.
 * @param indexVehiculo Indice del vehiculo que limita el numero de plazas.
 */
static void modificarPlazas(vViajes *v, vVehiculos *vve, int indexViaje, int indexVehiculo) {
    int tmp = 0;
    do {
        printf("Ingrese Plazas: ");
        scanf("%d[^\n]", &tmp);
        flush_in();
    } while (tmp > vve->vehi[indexVehiculo].Num_plazas && tmp < 0);
    v->viajes[indexViaje].Plazas_libre = tmp;
}

/**
 * Busca los pasos que hace un viaje.
 * @param  v                  Referencia al vector viajes.
 * @param  id_viaje           Viaje del cual se quiere conocer los pasos.
 * @param  viajes_encontrados Referencia en la que se devulve el numero de pasos enconstrados.
 * @return                    Un vector con los indices donde se encuetra un paso para el viaje.
 */
static int *pasosViajes(vViajes *v, int id_viaje, int * viajes_encontrados) {
    int *vector_tmp = NULL;
    *viajes_encontrados = 0;
    for (int i = 0; i < v->tam_p; ++i) {
        if (id_viaje == v->pasos[i].Id_viaje) {
            vector_tmp = (int *)realloc(vector_tmp, ((*viajes_encontrados) + 1) * sizeof(int));
            if (vector_tmp == NULL)
                exit(1);//Error con la reserva de memoria o reasignacion.
            vector_tmp[(*viajes_encontrados)++] = i;//Se guarda el indice.
        }
    }
    return vector_tmp;
}

/**
 * Lista los pasos y pregunta cual de ellos se desea editar.
 * @param v        Referencia al vector viajes.
 * @param id_viaje Indentificador del viaje del que se modifican los pasos.
 */
static void modificarPaso(vViajes *v, int id_viaje) {
    int size_p = 0, resp = 0;
    int *pasos = pasosViajes(v, id_viaje, &size_p);
    for (int i = 0; i < size_p; ++i)
        printf(" %d. %s\n", i + 1, v->pasos[pasos[i]].Poblacion);
    printf("Que paso desea modificar: \n");
    scanf("%d[^\n]", &resp);
    flush_in();
    --resp;
    if (resp >= 0 && resp < size_p) {
        pedirPaso(v, pasos[resp]);
    }
    free(pasos);
}

/**
 * Modificar uno o varios pasos
 * @param v        Referencia al vector de viajes.
 * @param id_viaje Indentificador del viaje del que se modifican los pasos.
 */
static void modificarPasos(vViajes *v, int id_viaje) {
    char resp = 's';
    modificarPaso(v, id_viaje);
    while (resp == 's' || resp == 'S') {
        printf("Desea modificar otro paso S/N\n");
        scanf("%c[^\n]", &resp);
        if(resp == 's' || resp == 'S')
            modificarPaso(v, id_viaje);
    }
}

/**
 * Modifica el estado de un viaje.
 * @param v     Referencia a la vector viajes.
 * @param index Indice del viaje a modificar.
 */
static void modificarEstadoViaje(vViajes *v, int index) {
    do {
        printf(" 0) cerrado\n 1) abierto\n 2) iniciado\n"
        " 3) finalizado\n 4) anulado\nIngrese Estado: ");
        scanf("%1d[^\n]", &v->viajes[index].Estado);
        flush_in();
    } while (v->viajes[index].Estado > 0 && v->viajes[index].Estado < 4);
}

/**
 * Modifica un viaje con las restriciones de usuario.
 * @param v        Referencia al vector de viajes.
 * @param ve       Referencia al vector de vehiculos.
 * @param id_viaje Indentificador del viaje a modificar.
 */
static void modificarViaje(vViajes *v, vVehiculos *ve, int id_viaje) {
    int tmp = 0, index = buscarIndexViajes(v, id_viaje);
    if (index > -1) {
        int indexv = buscarIndexVehiculo(ve, v->viajes[index].Id_mat);
        if (v->viajes[index].Estado == 1 &&
            v->viajes[index].Plazas_libre == ve->vehi[indexv].Num_plazas)
        {
            printf(" 1. Fecha y Hora\n 2. Plazas\n 3. Tipo Viaje\n"
            " 4. Importe\n 5. Estado\n 6. Pasos\nSeleccione una opcion: ");
            scanf("%1d[^\n]", &tmp);
            flush_in();
            switch (tmp) {
                case 1:
                    preguntarFechaHora(v, index);
                    break;
                case 2:
                    modificarPlazas(v, ve, index, indexv);
                    break;
                case 3:
                    tipoViaje(v, index);
                    break;
                case 4:
                    preguntarImporte(v, index);
                    break;
                case 5:
                    modificarEstadoViaje(v, index);
                    break;
                case 6:
                    modificarPasos(v, id_viaje);
                    break;
                default:
                    printf("Opcion no valida no se hace nada.\n");
                    break;
            }
        }
    }
}

/**
 * Crea una lista con los viajes en estado abierto.
 * @param  v                    Referencia al vector de viajes.
 * @param  num_viajes_abiertos  Variable en la que se devulve el numero de viajes enconstrados.
 * @return                      Vector con los indices de viajes enconstrados.
 */
static int *listaViajesAbiertos(vViajes *v, int *num_viajes_abiertos) {
    int *tmp = NULL;
    *num_viajes_abiertos = 0;
    for (int i = 0; i < v->tam_v; ++i) {
        if (v->viajes[i].Estado == 1) {
            tmp = (int *)realloc(tmp, ((*num_viajes_abiertos) + 1) * sizeof(int));
            if (tmp == NULL)
                exit(1);//Error con la reserva de memoria o reasignacion.
            tmp[(*num_viajes_abiertos)++] = i;
        }
    }
    return tmp;
}

/**
 * Elimina un viaje del vector de viajes.
 * @param v      Referencia al vector de viajes.
 * @param vIndex Indice del elemento a eliminar del vector.
 */
static void eliminarViaje(vViajes *v, int vIndex) {
    //Liberar la memoria de las varibles dinamicas en la estructura.
    free(v->viajes[vIndex].Id_mat);
    free(v->viajes[vIndex].F_inic);
    free(v->viajes[vIndex].H_inic);
    free(v->viajes[vIndex].H_fin);
    //Desplaza los elementos del vector un posicion  desde el indice indicado.
    memmove(&v->viajes[vIndex], &v->viajes[vIndex + 1],
            (v->tam_v - vIndex - 1) * sizeof(Viajes));
    //Resta un elemento al contador.
    --v->tam_v;
}

/**
 * Elimina un pasos del vector de viajes.
 * @param v      Referencia al vector de viajes.
 * @param vIndex Indice del elemeto a eliminar del vector.
 */
static void eliminarPaso(vViajes *v, int vIndex) {
    //Liberar la memoria de las varibles dinamicas en la estructura.
    free(v->pasos[vIndex].Poblacion);
    //Desplaza los elementos del vector un posicion  desde el indice indicado.
    memmove(&v->pasos[vIndex], &v->pasos[vIndex + 1],
            (v->tam_p - vIndex - 1) * sizeof(Pasos));
    //Resta un elemento al contador.
    --v->tam_p;
}

/**
 * Elimina un viaje y sus pasos.
 * @param v        Referencia al vector de viajes.
 * @param id_viaje Indentificador del viaje a eliminar.
 */
static void eliminarViajes(vViajes *v, int id_viaje) {
    int index = buscarIndexViajes(v, id_viaje);
    if (index > -1) {
        eliminarViaje(v, index);
        int size_p = 0;
        int *pasos = pasosViajes(v, id_viaje, &size_p);
        for (int i = 0; i < size_p; ++i)
            eliminarPaso(v, pasos[i] - i);
        free(pasos);
    } else
        printf("No existe el viaje: %d\n", id_viaje);
}

/**
 *
 *  FUNCIONES PUBLICAS
 *
 */

Viajes *initViajes(int *n)
{
    FILE *file = fopen("ficheros/Viajes.txt", "r");
    if (file == NULL) exit(1);
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

Pasos *initPasos(int *n)
{
    FILE *file = fopen("ficheros/Pasos.txt", "r");
    if (file == NULL)   exit(1);
    (*n) = 0;
    Pasos *tmp = NULL;
    char *id_viaje= (char *)malloc(ID_VIAJE * sizeof(char)),*poblacion;
    while (!feof(file)) {

        poblacion = (char *)malloc(LOCAL * sizeof(char));

        if (id_viaje == NULL || poblacion == NULL)  exit(0);

        fscanf(file, "%[^-]-%[^\n]\n", id_viaje, poblacion);
        tmp = (Pasos *)realloc(tmp, ((*n) + 1) * sizeof(Pasos));
        tmp[*n].Id_viaje = atoi(id_viaje);
        tmp[*n].Poblacion = poblacion;
        (*n)++;
    }
    free(id_viaje);
    fclose(file);
    return tmp;
}

Pasajeros* initPasajeros(int* n)
{
    FILE *file = fopen("ficheros/Pasajeros.txt","r");
    if (file == NULL)   exit(1);
    (*n) = 0;
    Pasajeros* tmp =NULL;
    char id_viaje[ID_VIAJE],id_viajero[5];
    while(!feof(file))
    {
        fscanf(file, "%[^-]-%[^\n]\n", id_viaje, id_viajero);
        tmp = (Pasajeros *)realloc(tmp, ((*n) + 1) * sizeof(Pasajeros));
        tmp[*n].Id_viaje = atoi(id_viaje);
        tmp[*n].Id_viajero = atoi(id_viajero);
        (*n)++;
    }
    fclose(file);
    return tmp;
}

void publicarViajeUsuario(vViajes *v, vVehiculos *ve, int userId) {
    int l_vehi_size = 0, i = 0;
    int *l_vehi = listarVehiculosViajes(ve, userId, &l_vehi_size);
    if (l_vehi_size) {
        for (i = 0; i < l_vehi_size; ++i) {
            printf("%d) Matricula: %s Descripcion: %s ", i + 1,
            ve->vehi[l_vehi[i]].Id_mat, ve->vehi[l_vehi[i]].Desc_veh);
        }
        int opc = 0;
        do {
            printf("Con que vehiculo desea realizar el viaje: ");
            scanf("%d", &opc);
            --opc;
        } while (opc < 0 && opc > l_vehi_size - 1);
        publicarViaje(v, ve, ve->vehi[l_vehi[opc]].Id_mat);
    }
    free(l_vehi);
}

void editarViajesUsuario(vViajes *v, vVehiculos *ve, int userId) {
    char resp = 0;
    printf("Desea editar algun viaje: ");
    scanf("%c", &resp);
    flush_in();
    if (resp == 's' || resp == 'S') {
        int id_edit = 0;
        printf("Ingrese id_viaje a modificar: ");
        scanf("%d", &id_edit);
        flush_in();
        int iFindV = buscarIndexViajes(v, id_edit);
        if (iFindV > -1) {
            int l_size = 0;
            int *l_viajes = listarVehiculosViajes(ve, userId, &l_size);
            for (int k = 0; k < l_size; ++k)
            {
                if (strcmp(v->viajes[iFindV].Id_mat,
                    ve->vehi[l_viajes[k]].Id_mat) == 0)
                        modificarViaje(v, ve, id_edit);
            }
            free(l_viajes);
        }
    }
}

void incorporarseViaje(vViajes *v,int id_viajero){
    char tmp[LOCAL];
    printf("Introduzca una poblacion: ");
    scanf("%20[^\n]", tmp);
    flush_in();
    printf("Viajes que pasan por %s: \n",tmp);
    int l_size = 0,slct = 0,i,j;
    int *l_viajes = listaViajesAbiertos(v, &l_size);
    int *opciones = NULL;
    for (i = 0; i < l_size; ++i) {
        int size_p = 0;
        int *pasos = pasosViajes(v, v->viajes[i].Id_viaje, &size_p);
        for (j = 0; j < size_p; ++j) {
            if(strcmp(v->pasos[pasos[j]].Poblacion, tmp)==0)
            {
                opciones = (int*) realloc(opciones,(slct+1)*sizeof(int));
                opciones[slct] = i;
                printf("%d) Id viaje: %d Plazas: %d\n",++slct,v->viajes[i].Id_viaje,
                v->viajes[i].Plazas_libre);
            }
        }
        free(pasos);
    }
    free(l_viajes);
    if(slct > 0){
        int opc = 0;
        do {
            printf("A que viaje desea incorporarse: ");
            scanf("%d", &opc);
            --opc;
        } while (opc < 0 && opc > slct - 1);
        --v->viajes[opciones[opc]].Plazas_libre;//Resta una plaza libre
        addPasajero(v,v->viajes[opciones[opc]].Id_viaje,id_viajero);
        if(v->viajes[opciones[opc]].Plazas_libre == 0) v->viajes[opciones[opc]].Estado = 0;
        //Si es la ultima plaza se cambia el estado a cerrado.
        free(opciones);
    }
    else printf("no hay viajes con destino a esa poblacion.\n");
}

void detalleViaje(vViajes* v){
    int tmp;
    printf("Introduzca el id del viaje a detallar: ");
    scanf("%d", &tmp);
    flush_in();
    int vIndex = buscarIndexViajes(v, tmp);
    if (vIndex > -1){
        int size_p = 0;
        int *pasos = pasosViajes(v, v->viajes[vIndex].Id_viaje, &size_p);
        if (size_p)
            printf("Este viaje pasa por: \n");
        for (int j = 0; j < size_p; ++j)
            printf(" * %s.\n", v->pasos[pasos[j]].Poblacion);
        free(pasos);
    }
    else printf("No existe el viaje: %d\n",tmp);
}

void publicarViajeAdmin(vViajes *v, vVehiculos *ve){
    char tmp[ID_MAT];
    printf("Introduzca matricula del coche: ");
    scanf("%7[^\n]", tmp);
    flush_in();
    publicarViaje(v,ve,tmp);
}

void eliminarViajesAdmin(vViajes* v){
    int tmp;
    printf("Introduzca el id del viaje a eliminar: ");
    scanf("%d", &tmp);
    flush_in();
    eliminarViajes(v,tmp);
}

void modificarViajesAdmin(vViajes* v,vVehiculos *vve){
    int tmp;
    printf("Introduzca el id del viaje a modificar: ");
    scanf("%d", &tmp);
    flush_in();
    modificarViaje(v,vve,tmp);
}

void listarViajesAdmin(vViajes *v) {
    CLEAN;
    for (int i = 0; i < v->tam_v; ++i) {
        printf("%06d-%s-%s-%s-%s-%d-%s-%.2f€-%s\n", v->viajes[i].Id_viaje,
            v->viajes[i].Id_mat, v->viajes[i].F_inic, v->viajes[i].H_inic,
            v->viajes[i].H_fin, v->viajes[i].Plazas_libre,
            Viaje[v->viajes[i].Viaje], v->viajes[i].Importe,
            Estado_Vi[v->viajes[i].Estado]);
        int size_p = 0;
        int *pasos = pasosViajes(v, v->viajes[i].Id_viaje, &size_p);
        if (size_p)
            printf("Que pasa por:\n");
        for (int j = 0; j < size_p; ++j)
            printf(" * %s.\n", v->pasos[pasos[j]].Poblacion);
        free(pasos);
    }
    system_pause();
}

void saveViajes(int n, Viajes *viajes) {
    FILE *file = fopen("ficheros/Viajes.txt", "w+");
    if (file == NULL)   exit(1);
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

void savePasos(int n, Pasos *pasos)
{
    FILE *file = fopen("ficheros/Pasos.txt", "w+");
    if (file == NULL)
        exit(1);
    for (int i = 0; i < n; ++i) {
        fprintf(file, "%06d-%s\n", pasos[i].Id_viaje, pasos[i].Poblacion);
        free(pasos[i].Poblacion);
    }
    fclose(file);
    puts("Pasos Guardados");
}

void savePasajeros(int n,Pasajeros *pasaj)
{
    FILE *file = fopen("ficheros/Pasajeros.txt", "w+");
    if (file == NULL)
        exit(1);
    for (int i = 0; i < n; ++i)
        fprintf(file, "%06d-%04d\n", pasaj[i].Id_viaje, pasaj[i].Id_viajero);
    fclose(file);
    puts("Pasajeros Guardados");
}

int buscarIndexViajes(vViajes *v, int id_viaje) {
    for (int i = 0; i < v->tam_v; ++i) {
        if (id_viaje == v->viajes[i].Id_viaje)
            return i;
    }
    return -1;
}

void listarViajesAbiertos(vViajes *v) {
    printf("Viajes Abiertos: \n");
    int l_size = 0;
    int *l_viajes = listaViajesAbiertos(v, &l_size);
    for (int i = 0; i < l_size; ++i) {
        printf("%06d-%s-%s-%s-%s-%d-%s-%.2f€\n", v->viajes[l_viajes[i]].Id_viaje,
            v->viajes[l_viajes[i]].Id_mat, v->viajes[l_viajes[i]].F_inic,
            v->viajes[l_viajes[i]].H_inic, v->viajes[l_viajes[i]].H_fin,
            v->viajes[l_viajes[i]].Plazas_libre,
            Viaje[v->viajes[l_viajes[i]].Viaje], v->viajes[l_viajes[i]].Importe);
    }
    free(l_viajes);
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
