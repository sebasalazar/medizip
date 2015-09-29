/* 
 * File:   db.h
 * Author: Sebastián Salazar Molina.
 *
 * Created on November 11, 2013, 6:54 PM
 */

#ifndef DB_H
#define	DB_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <postgresql/libpq-fe.h>
#include "utils.h"

#define SERVIDOR "127.0.0.1"
#define PUERTO 5432
#define NOMBREDB "pacsdb"
#define USUARIODB "pacs"
#define PASSDB "pacs"

    PGconn* dbconnect(char* nombredb, char* usuario, char* password);
    PGconn* dbHostconnect(char* servidor, int puerto, char* nombredb, char* usuario, char* password);
    void dbclose(PGconn* conexion);
    PGresult* dbquery(PGconn* conexion, char* sql);
    long dbnumrows(PGresult *res);
    char* dbresult(PGresult *res, int fila, int columna);
    void dbfree(PGresult *res);



#ifdef	__cplusplus
}
#endif

#endif	/* DB_H */

