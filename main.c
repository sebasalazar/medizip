/* 
 * File:   main.c
 * Author: seba
 *
 * Created on November 11, 2013, 6:52 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "db.h"
#include "utils.h"
#include "servicio.h"
#include "lista.h"

/*
 * 
 */
int main(int argc, char** argv) {
    int i = 0;
    char* dato;
    struct timeval inicio, fin;
    double tiempo_transcurrido = 0.0;
    
    if (argc > 2) {
        long id = getLong(argv[1]);
        char* nombre = getString(argv[2]);
        if (id > 0 && strlen(nombre) > 0) {
            inicio = ahora();
            
            
            
            fin = ahora();
            
            tiempo_transcurrido = (fin.tv_usec - inicio.tv_usec) / 1000.0;
                    
        } else {
            fprintf(stderr, "Argumentos inválidos");
        }
    } else {
        fprintf(stderr, "Argumentos inválidos");
    }

    return (EXIT_SUCCESS);
}
