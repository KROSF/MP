#ifndef VEHICULOS_H
#define VEHICULOS_H
#define ID_MAT 8
#define ID_USUARIO 5
#define NPLAZS 2
#define DES_VEH 51
/**
 * Estructura para representar en memoria el fichero Vehiculos.txt
 */
typedef struct{
    /*@{*/
    char * Id_mat;/**< Matricula del vehiculo */
    int Id_usuario;/**< Identificador de usuario al que pertenece */
    int Num_plazas;/**< Numero de plazas del vehiculo sin tener en cuenta la del coductor */
    char * Desc_veh;/**< Breve descripcion del vehiculo */
    /*@}*/
}Vehiculos;
/**
 * Estructura para contener el tamaño y el vector vehi.
 */
typedef struct{
    /*@{*/
    Vehiculos* vehi;/**< Vector dinamico con elementos del tipo Vehiculos*/
    int tam;/**< Tamaño del vector vehi.*/
    /*@}*/
}vVehiculos;

/**
 * [initVehiculos description]
 * @param  n [description]
 * @return   [description]
 */
Vehiculos* initVehiculos(int* n);

/**
 * [saveVehiculos description]
 * @param n         [description]
 * @param vehiculos [description]
 */
void saveVehiculos(int n ,Vehiculos* vehiculos);

/**
 * [buscarIndexVehiculo description]
 * @param  v   [description]
 * @param  mat [description]
 * @return     [description]
 */
int buscarIndexVehiculo(vVehiculos* v,char* mat);

/**
 * [altaVehiculos description]
 * @param v      [description]
 * @param userId [description]
 */
void altaVehiculos(vVehiculos* v,int userId);

/**
 * [listarVehiculos description]
 * @param v [description]
 */
void listarVehiculos(vVehiculos* v);


/**
 * [listarVehiculosViajes description]
 * @param  v       [description]
 * @param  id_user [description]
 * @param  j       [description]
 * @return         [description]
 */
int* listarVehiculosViajes(vVehiculos* v,int id_user,int *j);

/**
 * [listarVehiculosUser description]
 * @param v      [description]
 * @param userId [description]
 */
void listarVehiculosUser(vVehiculos* v,int userId);

/**
 * [eliminarVehiculoUser description]
 * @param v      [description]
 * @param userId [description]
 */
void eliminarVehiculoUser(vVehiculos* v,int userId);

/**
 * [modificarVehiculoUser description]
 * @param v      [description]
 * @param userId [description]
 */
void modificarVehiculoUser(vVehiculos* v,int userId);

/**
 * [altaVehiculosAdmin description]
 * @param v [description]
 */
void altaVehiculosAdmin(vVehiculos* v);

/**
 * [bajaVehiculosAdmin description]
 * @param v [description]
 */
void bajaVehiculosAdmin(vVehiculos* v);

/**
 * [modificarVehiculosAdmin description]
 * @param v [description]
 */
void modificarVehiculosAdmin(vVehiculos* v);
#endif
