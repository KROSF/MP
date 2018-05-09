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
 * Estructura para contener el tamaño y el vector vehiculos.
 */
typedef struct{
    /*@{*/
    Vehiculos* vehi;/**< Vector dinamico con elementos del tipo Vehiculos*/
    int tam;/**< Tamaño del vector vehi.*/
    /*@}*/
}vVehiculos;

/**
 * inicializa los vehículos.
 * @param  n ÍNDICE
 * @return   VEHICULOS INICIALIZADOS
 */
Vehiculos* initVehiculos(int* n);

/**
 * Guarda los vehículos.
 * @param n         ÍNDICE
 * @param vehiculos ESTRUCTURA
 */
void saveVehiculos(int n ,Vehiculos* vehiculos);

/**
 * Busca el índice o identificador del vehículo en cuestión en el vector vehículos.
 * @param  v   VECTOR VEHÍCULOS.
 * @param  mat MATRÍCULA DEL VEHÍCULO CON EL QUE SE ESTÁ TRABAJANDO.
 * @return     ÍNDICE EN EL VECTOR VEHÍCULOS DEL VEHÍCULO BUSCADO.
 */
int buscarIndexVehiculo(vVehiculos* v,char* mat);

/**
 * Da de alta el vehículo deseado
 * @param v      VECTOR VEHÍCULOS
 * @param userId IDENTIFICADOR DEL USUARIO LOGUEADO
 */
void altaVehiculos(vVehiculos* v,int userId);

/**
 * Lista los vehículos cuando se le llama.
 * @param v VECTOR VEHÍCULOS
 */
void listarVehiculos(vVehiculos* v);


/**
 * DEVUELVE LOS ÍNDICES DE LOS VEHÍCULOS QUE CUMPLEN LA CONDICIÓN
 * @param  v       VECTOR VEHÍCULOS
 * @param  id_user IDENTIFICADOR DEL USUARIO LOGUEADO
 * @param  j       ÍNDICE VIAJES
 * @return         ÍNDICE VEHÍCULO QUE CUMPLE LA CONDICIÓN.
 */
int* listarVehiculosViajes(vVehiculos* v,int id_user,int *j);

/**
 * Función de usuario para el listado de los vehiculos que posee.
 * @param v      VECTOR VEHÍCULOS
 * @param userId IDENTIFICADOR DEL USUARIO LOGUEADO
 */
void listarVehiculosUser(vVehiculos* v,int userId);

/**
 * Función de usuario para el borrado de los vehiculos que posee.
 * @param v      VECTOR VEHÍCULOS
 * @param userId IDENTIFICADOR DEL USUARIO LOGUEADO
 */
void eliminarVehiculoUser(vVehiculos* v,int userId);

/**
 * Función de usuario para la modificación de los vehículos que posee.
 * @param v      VECTOR VEHÍCULOS
 * @param userId IDENTIFICADOR DEL USUARIO LOGUEADO
 */
void modificarVehiculoUser(vVehiculos* v,int userId);

/**
 * Función de administrador para el alta de vehículos en la base de datos.
 * @param v VECTOR VEHÍCULOS
 */
void altaVehiculosAdmin(vVehiculos* v);

/**
 * Función de administrador para la eliminación de vehículos de la base de datos.
 * @param v VECTOR VEHÍCULOS
 */
void bajaVehiculosAdmin(vVehiculos* v);

/**
 * Función de administrador para la edición de los vehículos de la base de datos.
 * @param v VECTOR VEHÍCULOS
 */
void modificarVehiculosAdmin(vVehiculos* v);
#endif
