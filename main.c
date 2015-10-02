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
    int i = 0, cantidad_examenes = 0;
    char* dato;
    struct timeval inicio, fin;
    double tiempo_transcurrido = 0.0;
    lista *examenes;
    char* argumentos_zip = NULL;
    char nombre_archivo[1024];
    char* cmd;
    int codigo_salida = -1;
    compresion zip;

    if (argc > 2) {
        long id = getLong(argv[1]);
        char* nombre = getString(argv[2]);
        if (id > 0 && strlen(nombre) > 0) {
            inicio = ahora();

            examenes = consultar_examenes(id, nombre);
            cantidad_examenes = largo_lista(examenes);
            if (cantidad_examenes > 0) {
                argumentos_zip = (char *) calloc(2, sizeof (char));
                sprintf(argumentos_zip, "");

                for (i = 0; i < cantidad_examenes; i++) {
                    dato = consultar_dato(examenes, i);
                    argumentos_zip = concatenar_con_espacio(argumentos_zip, dato);
                }
                eliminar_lista(examenes);
            }

            memset(nombre_archivo, 0, sizeof (nombre_archivo));
            sprintf(nombre_archivo, "/srv/web/medipacs.cl/www/htdocs/zip/%s%ld.zip", nombre, id);

            cmd = (char *) calloc(strlen(nombre_archivo) + strlen(argumentos_zip) + 25, sizeof (char));
            sprintf(cmd, "/usr/bin/zip -5 %s %s", nombre_archivo, argumentos_zip);
            fprintf(stderr, "%s", cmd);

            codigo_salida = system(cmd);

            fin = ahora();
            tiempo_transcurrido = (fin.tv_usec - inicio.tv_usec) / 1000.0;

            zip.pacienteId = id;
            zip.archivo = (char *) calloc(strlen(nombre_archivo) + 1, sizeof (char));
            sprintf(zip.archivo, "%s", nombre_archivo);
            zip.cantidad_examenes = cantidad_examenes;
            zip.tiempo_procesamiento = tiempo_transcurrido;
            zip.codigo_salida = codigo_salida;
            insertar_compresion(&zip);

            free(cmd);
            free(argumentos_zip);
        } else {
            fprintf(stderr, "Argumentos inválidos");
        }
    } else {
        fprintf(stderr, "Argumentos inválidos");
    }

    return (EXIT_SUCCESS);
}
