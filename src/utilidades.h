#ifndef  UTILIDADES_H
#define UTILIDADES_H
#ifdef _WIN32
#define CLEAN system("cls")
#elif defined __unix__
#define CLEAN system("clear")
#elif defined __APPLE__
#define CLEAN system("clear")
#endif
void flush_in();
int validarFecha(char* cadena);
int validarHora(char* cadena,int hoy);
int fechaMenor(int d, int m, int a);
#endif
