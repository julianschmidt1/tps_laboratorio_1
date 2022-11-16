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

/// \brief Funcion que retorna un identificar univoco autoincremental
///
/// \return Valor utilizado como identificador
int abm_obtenerIdConfederacion(void);

/// \brief Recorre un array de eConfederacion, inicializando su propiedad isEmpty
///
/// \param lista array de eConfederacion
/// \param tam tamaño del array de eConfederacion
/// \return retorna 1 en caso de exito y cero en caso de error
int abm_inicializarConfederacion(eConfederacion *lista, int tam);

/// \brief Funcion que itera un array de eConfederacion y busca un indice considero libre
///
/// \param lista array de eConfederacion
/// \param tam tamaño del array de eConfederacion
/// \return retorna el indice en caso de encontrarlo y -1 en caso de no encontrarlo o error
int abm_obtenerIndiceLibreConfederacion(eConfederacion *lista, int tam);

/// \brief Funcion que itera un array de eConfederacion, y busca el indice especificado
///
/// \param lista array de eConfederacion
/// \param tam tamaño del array de eConfederacion
/// \param id valor univoco que representa cada eConfederacion y permite la busqueda
/// \return Retorna el indice encontrado en caso de exito, o -1 en caso de error
int abm_encontrarConfederacionPorId(eConfederacion *lista, int tam, int id);

/// \brief Funcion que permite la adicion de una entidad de tipo eConfederacion a un array
///
/// \param lista array de eConfederacion
/// \param tam tamaño del array de eConfederacion
/// \param id identificar univoco que sera asignado al eConfederacion dado de alta
/// \param Notebook eConfederacion previamente cargado
/// \return retorna 1 en caso de exito y 0 en caso de error
int abm_altaConfederacion(eConfederacion *lista, int tam, int id,
		eConfederacion Confederacion);

/// \brief Funcion que muestra los campos de un eConfederacion
///
/// \param Notebook estructura a mostrar
void abm_mostrarUnConfederacion(eConfederacion Confederacion);

/// \brief Funcion que muestra un listado de eConfederacion
///
/// \param lista array de eConfederacion
/// \param tam tamaño del array de eConfederacion
/// \return Retorna 1 en caso de exito y 0 en caso de error
int abm_mostrarTodosConfederacion(eConfederacion *lista, int tam);

/// \brief Funcion que lista los usuarios y permite la seleccion de un indice para su baja
///
/// \param lista array de eConfederacion
/// \param tam tamaño del array de eConfederacion
/// \return Retorna 1 en caso de que las bajas sean aceptadas y 0 en caso de que se rechace o error
int abm_listadoBajaConfederacion(eConfederacion *lista, int tam);

/// \brief Funcion utilizada para aplicar una baja
///
/// \param lista array de eConfederacion
/// \param tam tamaño del array de eConfederacion
/// \param id de el eConfederacion a dar de baja
/// \return Retorna 1 en caso de que la baja sea exitosa y 0 en caso de error
int abm_bajaConfederacion(eConfederacion *lista, int tam, int id);

/// \brief Funcion utilizada como para mostrar el menu y realizar modificaciones
///
/// \param Notebook estructura sobre la cual aplicar modificaciones
/// \return Retorna estructura con modificaciones aplicadas
eConfederacion abm_modificacionConfederacion(eConfederacion Confederacion);

/// \brief Funcion que lista los usuarios y permite la seleccion de un indice para su modificacion
///
/// \param lista array de eConfederacion
/// \param tam tamaño del array de eConfederacion
/// \return Retorna 1 en caso de que las modificaciones sean aceptadas y 0 en caso de que se rechace o error
int abm_listadoModificacionConfederacion(eConfederacion lista[], int tam);

#endif /* ECONFEDERACION_H_ */
