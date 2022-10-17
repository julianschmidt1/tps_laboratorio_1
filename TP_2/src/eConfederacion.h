/*
 * eConfederacion.h
 *
 *  Created on: 16 Oct 2022
 *      Author: Julian
 */

#ifndef ECONFEDERACION_H_
#define ECONFEDERACION_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Inputs.h"

#define MAX_CHARS 50
#define LIBRE 0
#define BAJA 1
#define OCUPADO -1
#define MAX_CONFEDERACIONES 6

typedef struct {
	int id;
	char nombre[MAX_CHARS];
	char region[MAX_CHARS];
	int anioCreacion;

	short isEmpty;
} eConfederacion;

int abm_obtenerIdConfederacion(void);
int abm_inicializarConfederacion(eConfederacion *lista, int tam);
int abm_obtenerIndiceLibreConfederacion(eConfederacion *lista, int tam);
int abm_encontrarConfederacionPorId(eConfederacion *lista, int tam, int id);

int abm_altaConfederacion(eConfederacion *lista, int tam, int id,
		eConfederacion Confederacion);

void abm_mostrarUnConfederacion(eConfederacion Confederacion);
int abm_mostrarTodosConfederacion(eConfederacion *lista, int tam);
int abm_listadoBajaConfederacion(eConfederacion *lista, int tam);
int abm_bajaConfederacion(eConfederacion *lista, int tam, int id);
eConfederacion abm_modificacionConfederacion(eConfederacion Confederacion);
int abm_listadoModificacionConfederacion(eConfederacion lista[], int tam);

#endif /* ECONFEDERACION_H_ */
