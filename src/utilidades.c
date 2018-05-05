#include <stdio.h>
#define utilidades_IMPORT
#include "utilidades.h"
#undef utilidades_IMPORT

void flush_in(void) {
  int ch;
  while ((ch = getchar()) != '\n' && ch != EOF)
    ;
}

void system_pause(void) {
  printf("\n\nPresione " ANSI_COLOR_RED "'Enter'" ANSI_COLOR_RESET
         " para continuar: ... ");
  while (getchar() != '\n')
    ;
}

int validarFecha(char *cadena) {
  static const int DiaMes[] = {0,  31, 28, 31, 30, 31, 30,
                               31, 31, 30, 31, 30, 31};
  time_t t1 = {time(NULL)};
  struct tm *t2 = {localtime(&t1)};
  int d = 0, m = 0, a = 0;
  if (sscanf(cadena, "%d/%d/%4d", &d, &m, &a) != 3)
    return -1;
  if (a < t2->tm_year + 1900 || a > 2030)
    return -1;
  if (m < t2->tm_mon + 1 || m > 12)
    return -1;
  int bisiesto = (a % 4 == 0 && (a % 400 == 0 || a % 100 != 0));
  if (d < t2->tm_mday || d > (DiaMes[m] + bisiesto))
    return -1;
  if (d == t2->tm_mday && m == t2->tm_mon + 1 && a == t2->tm_year + 1900)
    return 1;
  return 0;
}

int validarHora(char *cadena, int hoy) {
  time_t t1 = {time(NULL)};
  struct tm *t2 = {localtime(&t1)};
  int h = 0, m = 0;
  if (sscanf(cadena, "%2d:%2d", &h, &m) != 2)
    return 0;
  if (h >= 0 && h < 24 && m >= 0 && m < 60) {
    if (hoy == 1 && (h > t2->tm_hour || (h == t2->tm_hour && m > t2->tm_min)))
      return 1;
    if (hoy == 0)
      return 1;
  }
  return 0;
}

/*int fechaMenor(int d, int m, int a) {
    time_t sys = time(NULL);
    struct tm hoy = *localtime(&sys);
    if (a < hoy.tm_year + 1900)
        return 1;
    else if (a > hoy.tm_year + 1900)
        return 0;
    if (m < hoy.tm_mon + 1)
        return 1;
    else if (m > hoy.tm_mon + 1)
        return 0;
    return d < hoy.tm_mday;
}*/
int fechaMenor(struct tm* fecha)
{
    time_t sys = time(NULL);
    struct tm hoy = *localtime(&sys);
    if (fecha->tm_year < hoy.tm_year + 1900)
        return 1;
    else if (fecha->tm_year > hoy.tm_year + 1900)
        return 0;
    if (fecha->tm_mon < hoy.tm_mon + 1)
        return 1;
    else if (fecha->tm_mon > hoy.tm_mon + 1)
        return 0;
    return fecha->tm_mday < hoy.tm_mday;
}

int fechaIgual(struct tm* fecha){
    time_t sys = time(NULL);
    struct tm hoy = *localtime(&sys);
    return fecha->tm_mday == hoy.tm_mday &&
           fecha->tm_mon  == hoy.tm_mon+1  &&
           fecha->tm_year == hoy.tm_year+1900;
}

int horaMenor(struct tm* hora)
{
    time_t sys = time(NULL);
    struct tm hoy = *localtime(&sys);
    return ((hora->tm_hour*60)+hora->tm_min) < ((hoy.tm_hour*60)+hoy.tm_min);
}
