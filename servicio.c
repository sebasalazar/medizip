#include "servicio.h"

lista* consultar_examenes(long id, char* nombre) {
    char sql[512];
    char temporal[1024];
    int i = 0;
    int num = 0;
    PGconn *conexion = NULL;
    PGresult *resultado = NULL;
    lista* examenes = NULL;

    if (id > 0 && strlen(nombre) > 0) {
        examenes = crear_lista();
        memset(sql, 0, sizeof (sql));
        sprintf(sql, "SELECT patient.pat_name AS paciente, files.filepath AS archivo FROM patient INNER JOIN study ON (patient.pk = study.patient_fk) INNER JOIN series ON (study.pk = series.study_fk) INNER JOIN instance ON (series.pk = instance.series_fk ) INNER JOIN files ON (instance.pk = files.instance_fk) INNER JOIN filesystem ON (files.filesystem_fk = filesystem.pk) WHERE (study.pk = '%ld' )", id);
        conexion = dbconnect(NOMBREDB, USUARIODB, PASSDB);
        if (conexion != NULL) {
            resultado = dbquery(conexion, sql);
            num = dbnumrows(resultado);
            if (num > 0) {
                for (i = 0; i < num; i++) {
                    memset(temporal, 0, sizeof (temporal));
                    sprintf(temporal, "/opt/dcm4chee/server/default/archive/%s", getString(dbresult(resultado, i, 1)));
                    if (is_regular_file(temporal)) {
                        agregar_en_lista(examenes, temporal);
                    }
                }
                dbfree(resultado);
            }
            dbclose(conexion);
        }
    }

    return examenes;
}

int insertar_compresion(compresion* zip) {
    int ok = 0;
    char sql[2048];
    PGconn *conexion = NULL;
    PGresult *resultado = NULL;

    if (zip != NULL) {
        memset(sql, 0, sizeof (sql));
        sprintf(sql, "INSERT INTO compresiones (paciente_fk, archivo, cantidad_examenes, tiempo_procesamiento, codigo_salida) VALUES ('%ld','%s','%d','%lf','%d')", zip->pacienteId, zip->archivo, zip->cantidad_examenes, zip->tiempo_procesamiento, zip->codigo_salida);
        conexion = dbconnect(NOMBREDB, USUARIODB, PASSDB);
        if (conexion != NULL) {
            resultado = dbquery(conexion, sql);
            ok = dbnumrows(resultado);
            if (ok) {
                dbfree(resultado);
            }
            dbclose(conexion);
        }
    }
    return ok;
}

