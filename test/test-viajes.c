#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "viajes.h"
#include "utilidades.h"
#include "fct.h"
FCT_BGN()
{
    FCT_SUITE_BGN(Buscador del ID en los Usuarios)
    {
        FCT_TEST_BGN(Test_Estructura_Vacia: no se cumpla la condicion del bucle)
        {
            generarFicheros("ficheros/prueba.txt",22,-2);
            fct_chk(1==1);
        }
        FCT_TEST_END();
    }
    FCT_SUITE_END();
}
FCT_END();
