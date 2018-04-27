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
      time_t sys;
      struct tm hoy;
      char buffer [11];
      FCT_FIXTURE_SUITE_BGN(Actualizar Vehiculos)
      {
            FCT_SETUP_BGN()
            {

               test.viajes = initViajes(&test.tam_v);
               test.pasos  = initPasos(&test.tam_p);
               sys = time(NULL);
               hoy=*localtime(&sys);

            }
            FCT_SETUP_END();

            FCT_TEARDOWN_BGN()
            {
               saveViajes(test.tam_v,test.viajes);
               savePasos (test.tam_p,test.pasos);
               free(test.viajes);
               free(test.pasos);
            }
            FCT_TEARDOWN_END();

            FCT_TEST_BGN(Estructura_Viajes)
            {
               fct_chk( test.viajes != NULL );
               fct_chk_eq_int(test.tam_v,5);
            }
            FCT_TEST_END();
            FCT_TEST_BGN(Estructura_Pasos)
            {
               fct_chk( test.pasos != NULL );
               fct_chk_eq_int(test.tam_p,5);

            }
            FCT_TEST_END();

            FCT_TEST_BGN(Fecha_Menor)
            {
               fct_chk_eq_int(fechaMenor(hoy.tm_mday-1,hoy.tm_mon+1,hoy.tm_year+1900),1);
            }
            FCT_TEST_END();

            FCT_TEST_BGN(Fecha_Igual)
            {

               fct_chk_eq_int(fechaMenor(hoy.tm_mday,hoy.tm_mon+1,hoy.tm_year+1900), 0);
            }
            FCT_TEST_END();

            FCT_TEST_BGN(Fecha_Mayor)
            {
               fct_chk_eq_int(fechaMenor(hoy.tm_mday+1,hoy.tm_mon+1,hoy.tm_year+1900),0);
            }
            FCT_TEST_END();
            FCT_TEST_BGN(Validar_Fecha_Ayer)
            {
               hoy.tm_mday--;
               mktime(&hoy);
               strftime(buffer,11,"%d/%m/%Y",&hoy);
               fct_chk_eq_int(validarFecha(buffer),-1);
            }
            FCT_TEST_END();
            FCT_TEST_BGN(Validar_Fecha_Hoy)
            {
               strftime(buffer,11,"%d/%m/%Y",&hoy);
               fct_chk_eq_int(validarFecha(buffer),1);
            }
            FCT_TEST_END();
            FCT_TEST_BGN(Validar_Fecha_Mañana)
            {
               hoy.tm_mday++;
               mktime(&hoy);
               strftime(buffer,11,"%d/%m/%Y",&hoy);
               fct_chk_eq_int(validarFecha(buffer),0);
            }
            FCT_TEST_END();


      }
      FCT_FIXTURE_SUITE_END();
   }
}
FCT_END();
