#ifndef VEHICULOS_H
#define VEHICULOS_H
#define ID_MAT 8
#define ID_USUARIO 5
#define NPLAZS 2
#define DES_VEH 51
typedef struct{
    /*@{*/
    char * Id_mat;/**< Matricula del vehiculo */
    int Id_usuario;/**< Identificador de usuario al que pertenece */
    int Num_plazas;/**< Numero de plazas del vehiculo sin tener en cuenta la del coductor */
    char * Desc_veh;/**< Breve descripcion del vehiculo */
    /*@}*/
}Vehiculos;
typedef struct{
    Vehiculos* vehi;
    int tam;
}vVehiculos;
Vehiculos* initVehiculos(int* n);
void saveVehiculos(int n ,Vehiculos* vehiculos);
void altaVehiculos(vVehiculos* v,int id);
void bajaVehiculos(vVehiculos* v,char* mat);
int buscarIndexVehiculo(vVehiculos* v,char* mat);
void eliminarVehiculo(vVehiculos* v,int vIndex);
void modificarVehiculo(vVehiculos* v,char* mat);
void listarVehiculos(vVehiculos* v);
#endif
