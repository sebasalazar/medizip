/* 
 * File:   tareas.h
 * Author: seba
 *
 * Created on 11 de noviembre de 2013, 11:20 PM
 */

#ifndef SERVICIO_H
#define	SERVICIO_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "archivo.h"
#include "utils.h"
#include "lista.h"
#include "db.h"

    typedef struct {
        long id;
        long pacienteId;
        char *archivo;
        int cantidad_examenes;
        double tiempo_procesamiento;
        int codigo_salida;
    } compresion;


    lista* consultar_examenes(long id, char* nombre);
    int insertar_compresion(compresion* zip);

#ifdef	__cplusplus
}
#endif

#endif	/* SERVICIO_H */

