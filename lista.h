/* 
 * File:   lista.h
 * Author: Sebastián Salazar Molina 
 *
 * Created on 29 de septiembre de 2015, 17:53
 */

#ifndef LISTA_H
#define	LISTA_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

    typedef struct nodo_ptr {
        char *dato;
        struct nodo_ptr *siguiente;
    } nodo;

    nodo *crear_nodo();
    void eliminar_nodo(nodo *nodo_actual);

    typedef struct lista_ptr {
        struct nodo_ptr *raiz;
    } lista;

    lista *crear_lista();
    void eliminar_lista(lista *listado);

    void agregar_en_lista(lista *listado, char *texto);
    void insertar_en_lista(lista *listado, int indice, char *texto);

    char *consultar_dato(lista *listado, int indice);
    int encontrar_indice(lista *listado, char *texto);

    void eliminar_dato(lista *listado, int indice);
    char *extraer_dato(lista *listado, int indice);

    int largo_lista(lista *listado);
    void imprimir_lista(lista *listado);

#ifdef	__cplusplus
}
#endif

#endif	/* LISTA_H */

