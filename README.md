[![Build Status](https://travis-ci.org/KROSF/MP.svg?branch=master)](https://travis-ci.org/KROSF/MP)
<h2 id="Estructuras">Estructuras</h2>
<ul>
  <li><a
  href="#Inicidencias">Inicidencias</a></li>
  <li><a href="#Pasos">Pasos</a></li>
  <li><a href="#Usuarios">Usuarios</a></li>
  <li><a href="#Vehiculos">Vehiculos</a></li>
  <li><a href="#Viajes">Viajes</a></li>
</ul>

<table>
<tr> <th colspan="2">Estructuras</th></tr>
<tr><td>

<h3 id="Inicidencias">Inicidencias</h3>

| TIPO | NOMBRE  |
|--:|---|
|`int` |**Id_viaje**|
|`int` |**Id_us_registra**|
|`int` |**Id_us_incidencia**|
|`char*`|**Desc_indicencia**|
|`int` |**Est_incidencia**|

<h3 id="Pasos">Pasos</h3>

| TIPO | NOMBRE  |
|--:|---|
|`int` |**Id_viaje**|
|`char *` |**Poblacion**|


<h3 id="Usuarios">Usuarios</h3>

| TIPO | NOMBRE  |
|--:|---|
|`int` |**Id_usuario**|
|`char *` |**Nomb_usuario**|
|`char *`| **Localidad**|
|`int`| **Perfil_usuario**|
|`char *` |**User**|
|`char *`| **Login**|
|`int` |**Estado**|

</td><td>

<h3 id="Vehiculos">Vehiculos</h3>

| TIPO | NOMBRE  |
|--:|---|
|`char *`| **Id_mat**|
|`int` |**Id_usuario**|
|`int` |**Num_plazas**|
|`char *` |**Desc_veh**|


<h3 id="Viajes">Viajes</h3>

| TIPO | NOMBRE  |
|--:|---|
| `int`   | **Id_viaje**  |
|`char *`| **Id_mat**|
|`char *`| **F_inic**|
|`char *`| **H_inic**|
|`char *`| **H_fin**|
|`int` |**Plazas_libre**|
|`int` |**Viaje**|
|`float`| **Importe**|
|`int` |**Estado**|

</td></tr> </table>
