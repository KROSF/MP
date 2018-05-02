/**
 * @file utilidades.h
 * @author Carlos Rodrigo Sanabria Flores
 * @date 25 Apr 2018
 * @copyright 2018 Carlos Rodrigo Sanabria Flores
 */
#ifndef UTILIDADES_H
#define UTILIDADES_H
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"
#ifdef _WIN32
#define CLEAN system("cls")
#elif defined __unix__
#define CLEAN system("clear")
#elif defined __APPLE__
#define CLEAN system("clear")
#endif
#ifdef utilidades_IMPORT
#define EXTERN
#else
#define EXTERN extern
#endif
#include <wchar.h>
/**
 * Limpia el flujo de la entra estandar.
 */
EXTERN void flush_in(void);
/**
 * Agrega un pausa en la ejecucion.
 */
EXTERN void system_pause(void);
/**
 * valida cadena con el formato dd/mm/aaaa
 * @param cadena Contiene una fecha
 * @return -1 Si el formato es incorrecto.
 * @return 0 Si el formato es correcto.
 * @return 1 Si el formato es correcto y la fecha es igual a la de hoy
 */
EXTERN int validarFecha(char *cadena);
/**
 * valida una cadena con el formato hh:mm
 * @param cadena contine una hora
 * @param hoy entero que indica si el dia hoy.
 * @return 0 si el formato de la hora no es valido.
 * @return 1 si el formato de la hora es valido.
 */
EXTERN int validarHora(char *cadena, int hoy);
/**
 * Comprueba si una fecha es menor que la de hoy.
 * @param d dia.
 * @param m mes.
 * @param a año.
 * @return 1 si la fecha es menor.
 * @return 0 si la fecha es mayor o igual.
 */
EXTERN int fechaMenor(int d, int m, int a);
#undef EXTERN
#endif
