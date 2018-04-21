#include <stdio.h>
#include <time.h>
#include "utilidades.h"
void flush_in() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}
int validarFecha(char* cadena)
{
    static const int DiaMes[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    time_t t1 = {time(NULL)};
    struct tm *t2 = {localtime(&t1)};
    int d=0,m=0,a=0;
    if(sscanf(cadena,"%d/%d/%4d",&d,&m,&a) != 3) return -1;
    if( a < t2->tm_year+1900 || a > 2030 ) return -1;
    if( m < t2->tm_mon+1 || m > 12 ) return -1;
    int bisiesto = (a % 4 == 0 && ( a % 400 == 0 || a % 100 != 0));
    if(d < t2->tm_mday || d > (DiaMes[m]+bisiesto) ) return -1;
    if(d == t2->tm_mday && m == t2->tm_mon+1 && a == t2->tm_year+1900) return 1;
    return 0;
}

int validarHora(char* cadena,int hoy)
{
  time_t t1 = {time(NULL)};
  struct tm* t2 = {localtime(&t1)};
  int h = 0, m = 0;
  if(sscanf(cadena,"%2d:%2d",&h,&m)!=2) return 0;
  if(h >= 0 && h < 24 && m >= 0 && m < 60){
	if(hoy == 1 && (h > t2->tm_hour || (h == t2->tm_hour && m > t2->tm_min))) return 1;
	if(hoy == 0) return 1;
}
  return 0;
}
