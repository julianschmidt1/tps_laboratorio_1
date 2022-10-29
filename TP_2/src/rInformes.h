/*
 * rInformes.h
 *
 *  Created on: 18 Oct 2022
 *      Author: Julian
 */

#ifndef RINFORMES_H_
#define RINFORMES_H_

#include <stdio.h>
#include <stdlib.h>
#include "eJugador.h"
#include "eConfederacion.h"

/// \brief Funcion que muestra un listado de jugadores ordenados por nombre de confederacion y nombre de jugador
///
/// \param jugadores array de jugadores
/// \param tamJugadores tamaño de array de jugadores
/// \param confederaciones array de confederaciones
/// \param tamConfederaciones tamaño de array de confederaciones
/// \return retorna 0 en caso de error y 1 en caso de exito
int informe_ordenarNombreConfederacionJugador(eJugador *jugadores,
		int tamJugadores, eConfederacion *confederaciones,
		int tamConfederaciones);

/// \brief Funcion que muestra un listado de jugadores y sus confederaciones
///
/// \param jugadores array de jugadores
/// \param tamJugadores tamaño de array de jugadores
/// \param confederaciones array de confederaciones
/// \param tamConfederaciones tamaño de array de confederaciones
/// \return retorna 0 en caso de error y 1 en caso de exito
int informe_mostrarJugadoresDeConfederacion(eConfederacion *confederaciones,
		int tamConfederaciones, eJugador *jugadores, int tamJugadores);

/// \brief Funcion que muestra el promedio y total del salario de jugadores, tambien cuantos jugadores lo superan
///
/// \param jugadores array de jugadores
/// \param tamJugadores tamaño de array de jugadores
/// \return retorna 0 en caso de error y 1 en caso de exito
int informe_mostrarTotalPromedioJugadores(eJugador *jugadores, int tamJugadores);

/// \brief Funcion que muestra la confederacion con mas años de contrato de los jugadores
///
/// \param jugadores array de jugadores
/// \param tamJugadores tamaño de array de jugadores
/// \param confederaciones array de confederaciones
/// \param tamConfederaciones tamaño de array de confederaciones
/// \return retorna 0 en caso de error y 1 en caso de exito
int informe_mostrarConfederacionMasAniosContrato(
		eConfederacion *confederaciones, int tamConfederaciones,
		eJugador *jugadores, int tamJugadores);

/// \brief Funcion utilizada para inicializar un array de int en un valor determinado
///
/// \param array array a inicializar
/// \param tam tamaño de array a inicializar
/// \param valor valor a asignar
/// \return retorna 0 en caso de error y 1 en caso de exito
int inicializarIntArray(int *array, int tam, int valor);

/// \brief Funcion que muestra la confederacion junto con el porcentaje de jugadores que tiene
///
/// \param jugadores array de jugadores
/// \param tamJugadores tamaño de array de jugadores
/// \param confederaciones array de confederaciones
/// \param tamConfederaciones tamaño de array de confederaciones
/// \return retorna 0 en caso de error y 1 en caso de exito
int informe_mostrarPorcentajeJugadoresConfederacion(
		eConfederacion *confederaciones, int tamConfederaciones,
		eJugador *jugadores, int tamJugadores);

/// \brief Funcion que muestra la region de la confederacion con mas jugadores
///
/// \param jugadores array de jugadores
/// \param tamJugadores tamaño de array de jugadores
/// \param confederaciones array de confederaciones
/// \param tamConfederaciones tamaño de array de confederaciones
/// \return retorna 0 en caso de error y 1 en caso de exito
int informe_mostrarRegionConMasJugadores(eConfederacion *confederaciones,
		int tamConfederaciones, eJugador *jugadores, int tamJugadores);

#endif /* RINFORMES_H_ */
