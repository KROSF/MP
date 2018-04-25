/**
* @file utilidades.h
* @author Carlos Rodrigo Sanabria Flores
* @date 25 Apr 2018
* @copyright 2018 Carlos Rodrigo Sanabria Flores
* @brief <brief>
*/
#ifndef  UTILIDADES_H
#define UTILIDADES_H
#ifdef _WIN32
#define CLEAN system("cls")
#elif defined __unix__
#define CLEAN system("clear")
#elif defined __APPLE__
#define CLEAN system("clear")
#endif
/**
* @brief <brief>
* @param [in] <name> <parameter_description>
* @return <return_description>
* @details <details>
*/
void flush_in();
/**
* @brief <brief>
* @param [in] <name> <parameter_description>
* @return <return_description>
* @details <details>
*/
void system_pause();
/**
* @brief <brief>
* @param [in] <name> <parameter_description>
* @return <return_description>
* @details <details>
*/
int validarFecha(char* cadena);
/**
* @brief <brief>
* @param [in] <name> <parameter_description>
* @return <return_description>
* @details <details>
*/
int validarHora(char* cadena,int hoy);
/**
* @brief <brief>
* @param [in] <name> <parameter_description>
* @return <return_description>
* @details <details>
*/
int fechaMenor(int d, int m, int a);
#endif
