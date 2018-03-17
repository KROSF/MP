//
// Created by Miguel Cabral on 14/03/2018.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "viajes.h"

void flush_in() { // Función que sistituye el "fflush(stdin)"
    int ch;

    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){}
}

void TRIPS_admin(Viajes **viajes, int num_viajes){

    int i=0;

    switch ( ){

        case 1:             //Añadir nuevo viaje
            puts("Publicar nuevo viaje:");
            op1_viajes(&viajes, i);
            break;
        case 2:             //Borrar viaje
            puts("Eliminar un viaje:");
            op2_viajes(&viajes, i);
            break;
        case 3:             //Modificar viaje
            puts("Modificar viaje:");
            op3_viajes(&viajes, i);
            break;
        case 4:             //Listar viajes
            puts("Listar todos los viajes:");
            op4_viajes(&viajes, i);
            break;
    }
}

void op1_viajes(Viajes **Viajes, int num_viajes){

    int n;

    puts("Identificador del viaje: ");
    flush_in();
    scanf("%7s", viajes[i].Id_viaje);

    puts("Matrícula: ");
    flush_in();
    scanf("%8s", viajes[i].Id_mat);

    puts("Fecha del viaje: ");
    flush_in();
    scanf("")


}






