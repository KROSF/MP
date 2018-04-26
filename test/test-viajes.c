#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "viajes.h"
#include "utilidades.h"
#include "fct.h"
FCT_BGN()
{
   /* Optionally, define a scope for you data. */
   {
      vViajes test;
      time_t sys = time(NULL);
      struct tm hoy=*localtime(&sys);
      FCT_FIXTURE_SUITE_BGN(Actualizar Vehiculos)
      {
            FCT_SETUP_BGN()
            {
               /* Initialize your data before a test is executed. */

               test.viajes = initViajes(&test.tam_v);
               test.pasos  = initPasos(&test.tam_p);

            }
            FCT_SETUP_END();

            FCT_TEARDOWN_BGN()
            {
               /* Clean up your data after a test is executed. */
               //free(data);
               //data = NULL;
               saveViajes(test.tam_v,test.viajes);
               savePasos (test.tam_p,test.pasos);
               free(test.viajes);
               free(test.pasos);
            }
            FCT_TEARDOWN_END();

            FCT_TEST_BGN(Cargar_Viajes_Pasos)
            {
               fct_chk( test.viajes != NULL );
            }
            FCT_TEST_END();

            FCT_TEST_BGN(Funcion_Fecha_Menor_Y_Menor)
            {
               fct_chk(fechaMenor(hoy.tm_mday-1,hoy.tm_mon+1,hoy.tm_year+1900) == 1);
            }
            FCT_TEST_END();

            FCT_TEST_BGN(Funcion_Fecha_Menor_E_Igual)
            {

               fct_chk(fechaMenor(hoy.tm_mday,hoy.tm_mon+1,hoy.tm_year+1900) == 0);
            }
            FCT_TEST_END();

            FCT_TEST_BGN(Funcion_Fecha_Menor_Y_Mayor)
            {
               fct_chk(fechaMenor(hoy.tm_mday+1,hoy.tm_mon+1,hoy.tm_year+1900) == 0);
            }
            FCT_TEST_END();


      }
      FCT_FIXTURE_SUITE_END();
   }
}
FCT_END();
