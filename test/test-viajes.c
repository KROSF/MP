#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "viajes.h"
#include "utilidades.h"
#include "fct.h"
FCT_BGN()
{
    printf("\n------------------------------ TEST VIAJE ------------------------------\n\n");
    FCT_SUITE_BGN(NoItera)
    {
        FCT_TEST_BGN(NoSeCumpleLaCondicionDelBucle)
        {
            vViajes viaje;
            viaje.pasos = NULL;
            viaje.viajes = NULL;
            viaje.tam_p = 0;
            viaje.tam_v = 0;
            actualizarViajes(&viaje);
            fct_chk(viaje.pasos == NULL);
            fct_chk(viaje.viajes == NULL);
            fct_chk_eq_int(viaje.tam_p,0);
            fct_chk_eq_int(viaje.tam_v,0);
        }
        FCT_TEST_END();
        FCT_TEST_BGN(NoSeCumpleLaCondicionDelIf)
        {
            vViajes viaje;
            viaje.pasos = NULL;
            viaje.tam_p = 0;
            char directorio[]="ficheros/anulado.txt";
            generarFicheros(directorio,100,0,4,-4,2);
            viaje.viajes=initViajes(&viaje.tam_v,directorio);
            fct_chk_eq_int(viaje.tam_v,100);
            actualizarViajes(&viaje);
            for(int i = 0; i <viaje.tam_v;++i)
            {
                fct_chk_eq_int(viaje.viajes[i].Estado,4);
            }
            saveViajes(viaje.tam_v,viaje.viajes,directorio);
            viaje.tam_v = 0;
            free(viaje.viajes);
            fct_chk_eq_int(viaje.tam_v,0);
        }
        FCT_TEST_END();
    }
    FCT_SUITE_END();
    printf("\n------------------------------ ESTADO = 0 ------------------------------\n\n");
    FCT_SUITE_BGN(ESTADO_0)
    {
        FCT_TEST_BGN(FechaIgualHoraInicioYHoraFinMenoresQueHoraActual)
        {
            vViajes viaje;
            viaje.pasos = NULL;
            viaje.tam_p = 0;
            char directorio[]="ficheros/estado_0.0.txt";
            generarFicheros(directorio,22,0,0,-4,2);
            viaje.viajes=initViajes(&viaje.tam_v,directorio);
            fct_chk_eq_int(viaje.tam_v,22);
            actualizarViajes(&viaje);
            for(int i = 0; i <viaje.tam_v;++i)
            {
                fct_chk_eq_int(viaje.viajes[i].Estado,3);
            }
            saveViajes(viaje.tam_v,viaje.viajes,directorio);
            viaje.tam_v = 0;
            free(viaje.viajes);
            fct_chk_eq_int(viaje.tam_v,0);
        }
        FCT_TEST_END();
        FCT_TEST_BGN(FechaMenorHoraInicioYHoraFinMenoresQueHoraActual)
        {
            vViajes viaje;
            viaje.pasos = NULL;
            viaje.tam_p = 0;
            char directorio[]="ficheros/estado_0.1.txt";
            generarFicheros(directorio,22,-1,0,-4,2);
            viaje.viajes=initViajes(&viaje.tam_v,directorio);
            fct_chk_eq_int(viaje.tam_v,22);
            actualizarViajes(&viaje);
            for(int i = 0; i <viaje.tam_v;++i)
            {
                fct_chk_eq_int(viaje.viajes[i].Estado,3);
            }
            saveViajes(viaje.tam_v,viaje.viajes,directorio);
            viaje.tam_v = 0;
            free(viaje.viajes);
            fct_chk_eq_int(viaje.tam_v,0);
        }
        FCT_TEST_END();
        FCT_TEST_BGN(FechaMayorHoraInicioYHoraFinMenoresQueHoraActual)
        {
            vViajes viaje;
            viaje.pasos = NULL;
            viaje.tam_p = 0;
            char directorio[]="ficheros/estado_0.2.txt";
            generarFicheros(directorio,22,1,0,-4,2);
            viaje.viajes=initViajes(&viaje.tam_v,directorio);
            fct_chk_eq_int(viaje.tam_v,22);
            actualizarViajes(&viaje);
            for(int i = 0; i <viaje.tam_v;++i)
            {
                fct_chk_eq_int(viaje.viajes[i].Estado,0);
            }
            saveViajes(viaje.tam_v,viaje.viajes,directorio);
            viaje.tam_v = 0;
            free(viaje.viajes);
            fct_chk_eq_int(viaje.tam_v,0);
        }
        FCT_TEST_END();

    }
    FCT_SUITE_END();
    printf("\n------------------------------ ESTADO = 1 ------------------------------\n\n");
    FCT_SUITE_BGN(ESTADO_1)
    {
        FCT_TEST_BGN(FechaIgualHoraInicioYHoraFinMenoresQueHoraActual)
        {
            vViajes viaje;
            viaje.pasos = NULL;
            viaje.tam_p = 0;
            char directorio[]="ficheros/estado_1.0.txt";
            generarFicheros(directorio,22,0,1,-4,2);
            viaje.viajes=initViajes(&viaje.tam_v,directorio);
            fct_chk_eq_int(viaje.tam_v,22);
            actualizarViajes(&viaje);
            for(int i = 0; i <viaje.tam_v;++i)
            {
                fct_chk_eq_int(viaje.viajes[i].Estado,3);
            }
            saveViajes(viaje.tam_v,viaje.viajes,directorio);
            viaje.tam_v = 0;
            free(viaje.viajes);
            fct_chk_eq_int(viaje.tam_v,0);
        }
        FCT_TEST_END();
        FCT_TEST_BGN(FechaMenorHoraInicioYHoraFinMenoresQueHoraActual)
        {
            vViajes viaje;
            viaje.pasos = NULL;
            viaje.tam_p = 0;
            char directorio[]="ficheros/estado_1.1.txt";
            generarFicheros(directorio,22,-1,1,-4,2);
            viaje.viajes=initViajes(&viaje.tam_v,directorio);
            fct_chk_eq_int(viaje.tam_v,22);
            actualizarViajes(&viaje);
            for(int i = 0; i <viaje.tam_v;++i)
            {
                fct_chk_eq_int(viaje.viajes[i].Estado,3);
            }
            saveViajes(viaje.tam_v,viaje.viajes,directorio);
            viaje.tam_v = 0;
            free(viaje.viajes);
            fct_chk_eq_int(viaje.tam_v,0);
        }
        FCT_TEST_END();
        FCT_TEST_BGN(FechaMayorHoraInicioYHoraFinMenoresQueHoraActual)
        {
            vViajes viaje;
            viaje.pasos = NULL;
            viaje.tam_p = 0;
            char directorio[]="ficheros/estado_1.2.txt";
            generarFicheros(directorio,22,1,1,-4,2);
            viaje.viajes=initViajes(&viaje.tam_v,directorio);
            fct_chk_eq_int(viaje.tam_v,22);
            actualizarViajes(&viaje);
            for(int i = 0; i <viaje.tam_v;++i)
            {
                fct_chk_eq_int(viaje.viajes[i].Estado,1);
            }
            saveViajes(viaje.tam_v,viaje.viajes,directorio);
            viaje.tam_v = 0;
            free(viaje.viajes);
            fct_chk_eq_int(viaje.tam_v,0);
        }
        FCT_TEST_END();

    }
    FCT_SUITE_END();
    printf("\n------------------------------ ESTADO = 2 ------------------------------\n\n");
    FCT_SUITE_BGN(ESTADO_1)
    {
        FCT_TEST_BGN(FechaIgualHoraInicioYHoraFinMenoresQueHoraActual)
        {
            vViajes viaje;
            viaje.pasos = NULL;
            viaje.tam_p = 0;
            char directorio[]="ficheros/estado_1.0.txt";
            generarFicheros(directorio,22,0,2,-4,2);
            viaje.viajes=initViajes(&viaje.tam_v,directorio);
            fct_chk_eq_int(viaje.tam_v,22);
            actualizarViajes(&viaje);
            for(int i = 0; i <viaje.tam_v;++i)
            {
                fct_chk_eq_int(viaje.viajes[i].Estado,3);
            }
            saveViajes(viaje.tam_v,viaje.viajes,directorio);
            viaje.tam_v = 0;
            free(viaje.viajes);
            fct_chk_eq_int(viaje.tam_v,0);
        }
        FCT_TEST_END();
        FCT_TEST_BGN(FechaMenorHoraInicioYHoraFinMenoresQueHoraActual)
        {
            vViajes viaje;
            viaje.pasos = NULL;
            viaje.tam_p = 0;
            char directorio[]="ficheros/estado_1.1.txt";
            generarFicheros(directorio,22,-1,2,-4,2);
            viaje.viajes=initViajes(&viaje.tam_v,directorio);
            fct_chk_eq_int(viaje.tam_v,22);
            actualizarViajes(&viaje);
            for(int i = 0; i <viaje.tam_v;++i)
            {
                fct_chk_eq_int(viaje.viajes[i].Estado,3);
            }
            saveViajes(viaje.tam_v,viaje.viajes,directorio);
            viaje.tam_v = 0;
            free(viaje.viajes);
            fct_chk_eq_int(viaje.tam_v,0);
        }
        FCT_TEST_END();
        FCT_TEST_BGN(FechaMayorHoraInicioYHoraFinMenoresQueHoraActual)
        {
            vViajes viaje;
            viaje.pasos = NULL;
            viaje.tam_p = 0;
            char directorio[]="ficheros/estado_1.2.txt";
            generarFicheros(directorio,22,1,2,-4,2);
            viaje.viajes=initViajes(&viaje.tam_v,directorio);
            fct_chk_eq_int(viaje.tam_v,22);
            actualizarViajes(&viaje);
            for(int i = 0; i <viaje.tam_v;++i)
            {
                fct_chk_eq_int(viaje.viajes[i].Estado,2);
            }
            saveViajes(viaje.tam_v,viaje.viajes,directorio);
            viaje.tam_v = 0;
            free(viaje.viajes);
            fct_chk_eq_int(viaje.tam_v,0);
        }
        FCT_TEST_END();

    }
    FCT_SUITE_END();
    printf("\n------------------------------ ESTADO = 3 ------------------------------\n\n");
    FCT_SUITE_BGN(ESTADO_1)
    {
        FCT_TEST_BGN(FechaIgualHoraInicioYHoraFinMenoresQueHoraActual)
        {
            vViajes viaje;
            viaje.pasos = NULL;
            viaje.tam_p = 0;
            char directorio[]="ficheros/estado_1.0.txt";
            generarFicheros(directorio,22,0,3,-4,2);
            viaje.viajes=initViajes(&viaje.tam_v,directorio);
            fct_chk_eq_int(viaje.tam_v,22);
            actualizarViajes(&viaje);
            for(int i = 0; i <viaje.tam_v;++i)
            {
                fct_chk_eq_int(viaje.viajes[i].Estado,3);
            }
            saveViajes(viaje.tam_v,viaje.viajes,directorio);
            viaje.tam_v = 0;
            free(viaje.viajes);
            fct_chk_eq_int(viaje.tam_v,0);
        }
        FCT_TEST_END();
        FCT_TEST_BGN(FechaMenorHoraInicioYHoraFinMenoresQueHoraActual)
        {
            vViajes viaje;
            viaje.pasos = NULL;
            viaje.tam_p = 0;
            char directorio[]="ficheros/estado_1.1.txt";
            generarFicheros(directorio,22,-1,3,-4,2);
            viaje.viajes=initViajes(&viaje.tam_v,directorio);
            fct_chk_eq_int(viaje.tam_v,22);
            actualizarViajes(&viaje);
            for(int i = 0; i <viaje.tam_v;++i)
            {
                fct_chk_eq_int(viaje.viajes[i].Estado,3);
            }
            saveViajes(viaje.tam_v,viaje.viajes,directorio);
            viaje.tam_v = 0;
            free(viaje.viajes);
            fct_chk_eq_int(viaje.tam_v,0);
        }
        FCT_TEST_END();
        FCT_TEST_BGN(FechaMayorHoraInicioYHoraFinMenoresQueHoraActual)
        {
            vViajes viaje;
            viaje.pasos = NULL;
            viaje.tam_p = 0;
            char directorio[]="ficheros/estado_1.2.txt";
            generarFicheros(directorio,22,1,3,-4,2);
            viaje.viajes=initViajes(&viaje.tam_v,directorio);
            fct_chk_eq_int(viaje.tam_v,22);
            actualizarViajes(&viaje);
            for(int i = 0; i <viaje.tam_v;++i)
            {
                fct_chk_eq_int(viaje.viajes[i].Estado,3);
            }
            saveViajes(viaje.tam_v,viaje.viajes,directorio);
            viaje.tam_v = 0;
            free(viaje.viajes);
            fct_chk_eq_int(viaje.tam_v,0);
        }
        FCT_TEST_END();

    }
    FCT_SUITE_END();
    printf("\n------------------------------ ESTADO = 4 ------------------------------\n\n");
    FCT_SUITE_BGN(ESTADO_1)
    {
        FCT_TEST_BGN(FechaIgualHoraInicioYHoraFinMenoresQueHoraActual)
        {
            vViajes viaje;
            viaje.pasos = NULL;
            viaje.tam_p = 0;
            char directorio[]="ficheros/estado_1.0.txt";
            generarFicheros(directorio,22,0,4,-4,2);
            viaje.viajes=initViajes(&viaje.tam_v,directorio);
            fct_chk_eq_int(viaje.tam_v,22);
            actualizarViajes(&viaje);
            for(int i = 0; i <viaje.tam_v;++i)
            {
                fct_chk_eq_int(viaje.viajes[i].Estado,4);
            }
            saveViajes(viaje.tam_v,viaje.viajes,directorio);
            viaje.tam_v = 0;
            free(viaje.viajes);
            fct_chk_eq_int(viaje.tam_v,0);
        }
        FCT_TEST_END();
        FCT_TEST_BGN(FechaMenorHoraInicioYHoraFinMenoresQueHoraActual)
        {
            vViajes viaje;
            viaje.pasos = NULL;
            viaje.tam_p = 0;
            char directorio[]="ficheros/estado_1.1.txt";
            generarFicheros(directorio,22,-1,4,-4,2);
            viaje.viajes=initViajes(&viaje.tam_v,directorio);
            fct_chk_eq_int(viaje.tam_v,22);
            actualizarViajes(&viaje);
            for(int i = 0; i <viaje.tam_v;++i)
            {
                fct_chk_eq_int(viaje.viajes[i].Estado,4);
            }
            saveViajes(viaje.tam_v,viaje.viajes,directorio);
            viaje.tam_v = 0;
            free(viaje.viajes);
            fct_chk_eq_int(viaje.tam_v,0);
        }
        FCT_TEST_END();
        FCT_TEST_BGN(FechaMayorHoraInicioYHoraFinMenoresQueHoraActual)
        {
            vViajes viaje;
            viaje.pasos = NULL;
            viaje.tam_p = 0;
            char directorio[]="ficheros/estado_1.2.txt";
            generarFicheros(directorio,22,1,4,-4,2);
            viaje.viajes=initViajes(&viaje.tam_v,directorio);
            fct_chk_eq_int(viaje.tam_v,22);
            actualizarViajes(&viaje);
            for(int i = 0; i <viaje.tam_v;++i)
            {
                fct_chk_eq_int(viaje.viajes[i].Estado,4);
            }
            saveViajes(viaje.tam_v,viaje.viajes,directorio);
            viaje.tam_v = 0;
            free(viaje.viajes);
            fct_chk_eq_int(viaje.tam_v,0);
        }
        FCT_TEST_END();

    }
    FCT_SUITE_END();

}
FCT_END();
