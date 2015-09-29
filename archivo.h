/* 
 * File:   archivo.h
 * Author: Sebastián Salazar Molina <sebasalazar@gmail.com>
 *
 * Created on 29 de septiembre de 2015, 16:47
 */

#ifndef ARCHIVO_H
#define	ARCHIVO_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

    int is_regular_file(const char *path);


#ifdef	__cplusplus
}
#endif

#endif	/* ARCHIVO_H */

