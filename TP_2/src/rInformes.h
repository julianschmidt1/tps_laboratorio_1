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

int informe_ordenarNombreConfederacionJugador(eJugador *jugadores,
		int tamJugadores, eConfederacion *confederaciones,
		int tamConfederaciones);

int informe_mostrarJugadoresDeConfederacion(eConfederacion *confederaciones,
		int tamConfederaciones, eJugador *jugadores, int tamJugadores);

int informe_mostrarTotalPromedioJugadores(eJugador *jugadores, int tamJugadores);

int informe_mostrarConfederacionMasAniosContrato(
		eConfederacion *confederaciones, int tamConfederaciones,
		eJugador *jugadores, int tamJugadores);

int inicializarIntArray(int *array, int tam, int valor);

int informe_mostrarPorcentajeJugadoresConfederacion(
		eConfederacion *confederaciones, int tamConfederaciones,
		eJugador *jugadores, int tamJugadores);

int informe_mostrarRegionConMasJugadores(eConfederacion *confederaciones,
		int tamConfederaciones, eJugador *jugadores, int tamJugadores);

#endif /* RINFORMES_H_ */
