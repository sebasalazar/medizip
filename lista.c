#include "lista.h"

nodo *crear_nodo() {
    nodo *nodo_actual = malloc(sizeof (nodo));
    if (nodo_actual != NULL) {
        nodo_actual->dato = (char *) calloc(1, sizeof (char));
        nodo_actual->siguiente = NULL;
    }
    return nodo_actual;
}

void eliminar_nodo(nodo *nodo_actual) {
    if (nodo_actual != NULL) {
        free(nodo_actual);
    }
}

lista *crear_lista() {
    lista *listado = malloc(sizeof (lista));
    if (listado != NULL) {
        nodo *nodo_actual = crear_nodo();
        listado->raiz = nodo_actual;
    }
    return listado;
}

void eliminar_lista(lista *listado) {
    if (listado != NULL) {
        nodo *nodo_actual = listado->raiz;
        nodo *siguiente;
        while (nodo_actual != NULL) {
            siguiente = nodo_actual->siguiente;
            free(nodo_actual);
            nodo_actual = siguiente;
        }

        free(listado);
    }
}

void agregar_en_lista(lista *listado, char *texto) {
    if (listado != NULL && strlen(texto) > 0) {
        nodo *nodo_actual = listado->raiz;
        while (nodo_actual->siguiente != NULL) {
            nodo_actual = nodo_actual->siguiente;
        }

        nodo_actual->dato = (char *) calloc(strlen(texto) + 1, sizeof (char));
        sprintf(nodo_actual->dato, "%s", texto);
        nodo_actual->siguiente = crear_nodo();
    }
}

void insertar_en_lista(lista *listado, int indice, char *texto) {
    if (listado != NULL && indice >= 0 && strlen(texto) > 0) {
        if (indice == 0) {
            nodo *after = listado->raiz;
            listado->raiz = crear_nodo();
            listado->raiz->dato = (char *) calloc(strlen(texto) + 1, sizeof (char));
            sprintf(listado->raiz->dato, "%s", texto);
            listado->raiz->siguiente = after;
        } else if (indice == largo_lista(listado)) {
            agregar_en_lista(listado, texto);
        } else {
            nodo *anterior = listado->raiz;
            nodo *posterior = listado->raiz->siguiente;
            while (indice > 1) {
                indice--;
                anterior = anterior->siguiente;
                posterior = posterior->siguiente;
            }
            anterior->siguiente = crear_nodo();
            anterior->siguiente->dato = (char *) calloc(strlen(texto) + 1, sizeof (char));
            sprintf(anterior->siguiente->dato, "%s", texto);
            anterior->siguiente->siguiente = posterior;
        }
    }
}

char *consultar_dato(lista *listado, int indice) {
    char* dato = NULL;
    if (indice <= largo_lista(listado) && indice >= 0) {
        nodo *nodo_actual = listado->raiz;
        while (indice > 0) {
            nodo_actual = nodo_actual->siguiente;
            indice--;
        }
        dato = (char *) calloc(strlen(nodo_actual->dato) + 1, sizeof (char));
        sprintf(dato, "%s", nodo_actual->dato);
    }
    return dato;
}

int encontrar_indice(lista *listado, char *texto) {
    int indice = -1;
    if (largo_lista(listado) > 0 && strlen(texto) > 0) {
        nodo *nodo = listado->raiz;
        while (nodo->siguiente != NULL) {
            if (strlen(texto) == strlen(nodo->dato)) {
                int cmp = strcmp(texto, nodo->dato);
                if (cmp == 0) {
                    break;
                }
            }
            nodo = nodo->siguiente;
            indice++;
        }
    }
    return indice;
}

void eliminar_dato(lista *listado, int indice) {
    if (indice <= largo_lista(listado) && indice >= 0) {
        if (indice == 0) {
            nodo *nodo_actual = listado->raiz;
            listado->raiz = listado->raiz->siguiente;
            eliminar_nodo(nodo_actual);
        } else {
            nodo *anterior = listado->raiz;
            while (indice > 1) {
                anterior = anterior->siguiente;
                indice--;
            }
            nodo *posterior = anterior->siguiente;
            anterior->siguiente = anterior->siguiente->siguiente;
            eliminar_nodo(posterior);
        }
    }
}

char *extraer_dato(lista *listado, int indice) {
    char* dato = NULL;
    if (indice <= largo_lista(listado) && indice >= 0) {
        if (indice == 0) {
            nodo *nodo_actual = listado->raiz;
            listado->raiz = listado->raiz->siguiente;
            dato = (char *) calloc(strlen(nodo_actual->dato) + 1, sizeof (char));
            sprintf(dato, "%s", nodo_actual->dato);
            eliminar_nodo(nodo_actual);
        } else {
            nodo *anterior = listado->raiz;
            while (indice > 1) {
                anterior = anterior->siguiente;
                indice--;
            }
            nodo *posterior = anterior->siguiente;
            anterior->siguiente = anterior->siguiente->siguiente;
            dato = (char *) calloc(strlen(posterior->dato) + 1, sizeof (char));
            sprintf(dato, "%s", posterior->dato);
            eliminar_nodo(posterior);
        }
    }
    return dato;
}

int largo_lista(lista *listado) {
    int largo = 0;
    if (listado != NULL) {
        nodo *nodo = listado->raiz;
        while (nodo->siguiente != NULL) {
            largo++;
            nodo = nodo->siguiente;
        }
    }
    return largo;
}

void imprimir_lista(lista *listado) {
    if (listado != NULL) {
        printf("[");
        nodo *nodo = listado->raiz;
        while (nodo->siguiente != NULL) {
            printf("'%s'", nodo->dato);
            nodo = nodo->siguiente;
            if (nodo->siguiente != NULL) {
                printf(", ");
            }
        }
        printf("]\n");
    }
}
