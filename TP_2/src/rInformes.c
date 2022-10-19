/*
 * rInformes.c
 *
 *  Created on: 18 Oct 2022
 *      Author: Julian
 */

#include "rInformes.h"
#include "eConfederacion.h"

int informe_ordenarNombreConfederacionJugador(eJugador *jugadores,
		int tamJugadores, eConfederacion *confederaciones,
		int tamConfederaciones) {
	int rtn = 0;
	int indiceActual;
	int indiceSiguiente;
	eJugador auxJugador;

	if (jugadores != NULL && confederaciones != NULL && tamJugadores > 0
			&& tamConfederaciones > 0) {
		for (int i = 0; i < tamJugadores - 1; i++) {
			for (int j = i + 1; j < tamJugadores; j++) {
				indiceActual = abm_encontrarConfederacionPorId(confederaciones,
						tamConfederaciones, jugadores[i].idConfederacion);
				indiceSiguiente = abm_encontrarConfederacionPorId(
						confederaciones, tamConfederaciones,
						jugadores[j].idConfederacion);

				if ((strcmp(confederaciones[indiceActual].nombre,
						confederaciones[indiceSiguiente].nombre) > 0)
						|| ((strcmp(confederaciones[indiceActual].nombre,
								confederaciones[indiceSiguiente].nombre) == 0)
								&& (strcmp(jugadores[i].nombre,
										jugadores[j].nombre) > 0))) {
					auxJugador = jugadores[i];
					jugadores[i] = jugadores[j];
					jugadores[j] = auxJugador;
				}
			}
		}
	}

	return rtn;
}
