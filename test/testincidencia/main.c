#include<stdio.h>
#include "fct.h"
#include "incidencia.h"

FCT_BGN()
{
    printf("\n-------------------------- TEST INCIDENCIA --------------------------\n\n");
    FCT_SUITE_BGN(TestAcceso)
    {
        FCT_TEST_BGN(NoSeCumpleLaCondicionDelBucle)
        {
           vIncidencias test;
           test.inci = initIncidencias(&test.tam, "Incidencias.txt");
           int j;
           int * n = listaIncidencias(&test,22312,&j);
           fct_chk(n == NULL);
           saveIncidencias(test.tam,test.inci);
        }
        FCT_TEST_END();
        FCT_TEST_BGN(UnaUnicaIteracion)
        {
            vIncidencias test;
            test.inci = initIncidencias(&test.tam, "Incidencias1.txt");
            int j;
            int * n = listaIncidencias(&test,1,&j);
            fct_chk(n[0] == 0);
            fct_chk(j == 1);
            free(n);
            saveIncidencias(test.tam,test.inci);
        }
        FCT_TEST_END();
        FCT_TEST_BGN(DosIteraciones)
        {
            vIncidencias test;
            test.inci = initIncidencias(&test.tam, "Incidencias2.txt");
            int j;
            int * n = listaIncidencias(&test,223322,&j);
            fct_chk(n[0] == 0);
            fct_chk(n[1] == 1);
            fct_chk(j == 2);
            free(n);
            saveIncidencias(test.tam,test.inci);
        }
        FCT_TEST_END();
        FCT_TEST_BGN(m < niteraciones)
        {
            vIncidencias test;
            test.inci = initIncidencias(&test.tam, "Incidencias5.txt");
            int j;
            int * n = listaIncidencias(&test,789789,&j);
            fct_chk(j == test.tam-5);
            for(int i = 0; i < j-5 ;i++)
                fct_chk(n[i] == i);
            free(n);
            saveIncidencias(test.tam,test.inci);
        }
        FCT_TEST_END();
        FCT_TEST_BGN(n-1 iteraciones)
        {
            vIncidencias test;
            test.inci = initIncidencias(&test.tam, "Incidencias4.txt");
            int j;
            int * n = listaIncidencias(&test,456456,&j);
            fct_chk(j == test.tam-1);
            for(int i = 0; i < j-1 ;i++)
                fct_chk(n[i] == i);
            free(n);
            saveIncidencias(test.tam,test.inci);
        }
        FCT_TEST_END();
        FCT_TEST_BGN(n iteraciones)
        {
            vIncidencias test;
            test.inci = initIncidencias(&test.tam, "Incidencias3.txt");
            int j;
            int * n = listaIncidencias(&test,123123,&j);
            fct_chk(j == test.tam);
            for(int i = 0; i < j ;i++)
                fct_chk(n[i] == i);
            free(n);
            saveIncidencias(test.tam,test.inci);
        }
        FCT_TEST_END();
    }
    FCT_SUITE_END();
}
FCT_END();
