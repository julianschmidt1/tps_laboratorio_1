/*
 * eJugador.h
 *
 *  Created on: 15 Oct 2022
 *      Author: Julian
 */

#ifndef EJUGADOR_H_
#define EJUGADOR_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Inputs.h"
#include "eConfederacion.h"
#include "Menu.h"

#define MAX_CHARS 50
#define LIBRE 0
#define BAJA 1
#define OCUPADO -1
#define MAX_JUGADORES 3000

typedef struct {
	int id; //PK
	char nombre[MAX_CHARS];
	char posicion[MAX_CHARS];
	short numeroCamiseta;
	int idConfederacion; //FK
	float salario;
	short aniosContrato;

	short isEmpty;
} eJugador;

/// \brief Funcion que retorna un identificar univoco autoincremental
///
/// \return Valor utilizado como identificador
int abm_obtenerIdJugador(void);

/// \brief Recorre un array de eJugador, inicializando su propiedad isEmpty
///
/// \param lista array de eJugador
/// \param tam tamaño del array de eJugador
/// \return retorna 1 en caso de exito y cero en caso de error
int abm_inicializarJugador(eJugador *lista, int tam);

/// \brief Funcion que itera un array de eJugador y busca un indice considero libre
///
/// \param lista array de eJugador
/// \param tam tamaño del array de eJugador
/// \return retorna el indice en caso de encontrarlo y -1 en caso de no encontrarlo o error
int abm_obtenerIndiceLibreJugador(eJugador *lista, int tam);

/// \brief Funcion que itera un array de eJugador, y busca el indice especificado
///
/// \param lista array de eJugador
/// \param tam tamaño del array de eJugador
/// \param id valor univoco que representa cada eJugador y permite la busqueda
/// \return Retorna el indice encontrado en caso de exito, o -1 en caso de error
int abm_encontrarJugadorPorId(eJugador *lista, int tam, int id);

/// \brief Funcion que permite la adicion de una entidad de tipo eJugador a un array
///
/// \param lista array de eJugador
/// \param tam tamaño del array de eJugador
/// \param id identificar univoco que sera asignado al eJugador dado de alta
/// \param Notebook eJugador previamente cargado
/// \return retorna 1 en caso de exito y 0 en caso de error
int abm_altaJugador(eJugador *lista, int tam, int id, eJugador jugador);

/// \brief Funcion que muestra los campos de un eJugador
///
/// \param Notebook estructura a mostrar
void abm_mostrarUnJugador(eJugador Jugador, eConfederacion *confederaciones,
		int tamConfederaciones);

/// \brief Funcion que muestra un listado de eJugador
///
/// \param lista array de eJugador
/// \param tam tamaño del array de eJugador
/// \return Retorna 1 en caso de exito y 0 en caso de error
int abm_mostrarTodosJugador(eJugador *lista, int tam,
		eConfederacion *confederaciones, int tamConfederaciones);

/// \brief Funcion que lista los usuarios y permite la seleccion de un indice para su baja
///
/// \param lista array de eJugador
/// \param tam tamaño del array de eJugador
/// \return Retorna 1 en caso de que las bajas sean aceptadas y 0 en caso de que se rechace o error
int abm_listadoBajaJugador(eJugador *lista, int tam,
		eConfederacion *confederaciones, int tamConfederaciones);

/// \brief Funcion utilizada para aplicar una baja
///
/// \param lista array de eJugador
/// \param tam tamaño del array de eJugador
/// \param id de el eJugador a dar de baja
/// \return Retorna 1 en caso de que la baja sea exitosa y 0 en caso de error
int abm_bajaJugador(eJugador *lista, int tam, int id);

/// \brief Funcion utilizada como para mostrar el menu y realizar modificaciones
///
/// \param Notebook estructura sobre la cual aplicar modificaciones
/// \return Retorna estructura con modificaciones aplicadas
eJugador abm_modificacionJugador(eJugador Jugador,
		eConfederacion *confederaciones, int tamConfederaciones);

/// \brief Funcion que lista los usuarios y permite la seleccion de un indice para su modificacion
///
/// \param lista array de eJugador
/// \param tam tamaño del array de eJugador
/// \return Retorna 1 en caso de que las modificaciones sean aceptadas y 0 en caso de que se rechace o error
int abm_listadoModificacionJugador(eJugador lista[], int tam,
		eConfederacion *confederaciones, int tamConfederaciones);

/// \brief Funcion que ordena eJugador por ID
///
/// \param lista array de eJugador
/// \param tam tamaño del array de eJugador
/// \return retorna 1 en caso de exito y 0 en caso de error
int ordenarJugadoresId(eJugador *jugadores, int tam);

/// \brief Funcion que valida que la posicion del jugador sea (delantero, mediocampista, defensor, arquero).
///
/// \param posicion cadena a validar
/// \return retorna 1 en caso de validacion exitosa, -1 en caso de que la cadena no se valide, y 0 en caso de puntero erroneo
int validarPosicionJugador(char *posicion);

#endif /* EJUGADOR_H_ */
