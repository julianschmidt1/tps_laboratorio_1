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

int informe_mostrarJugadoresDeConfederacion(eConfederacion *confederaciones,
		int tamConfederaciones, eJugador *jugadores, int tamJugadores) {
	int rtn = 0;

	if (confederaciones != NULL && jugadores != NULL && tamConfederaciones > 0
			&& tamJugadores > 0) {

		for (int i = 0; i < tamConfederaciones; i++) {
			puts("\n=======================================================");
			printf("|        %-36s         |", confederaciones[i].nombre);
			puts("\n=======================================================");
			for (int j = 0; j < tamJugadores; j++) {
				if (jugadores[j].idConfederacion == confederaciones[i].id) {
					printf("| %-24s | %-24s |\n", jugadores[j].nombre,
							jugadores[j].posicion);
				}
			}
		}
		rtn = 1;
	}

	return rtn;
}

int informe_mostrarConfederacionMasAniosContrato(
		eConfederacion *confederaciones, int tamConfederaciones,
		eJugador *jugadores, int tamJugadores) {
	int rtn = 0;
	int sizeAcumulador = tamConfederaciones + sizeof(int);
	int acumuladoresAniosContrato[sizeAcumulador];
	int indiceConfederacion;

	// Inicializo array de acumuladores en 0, utilizo la ultima posicion del array para almacenar el maximo temporal;
	for (int i = 0; i < sizeAcumulador; i++) {
		acumuladoresAniosContrato[i] = 0;
	}

	if (confederaciones != NULL && jugadores != NULL && tamConfederaciones > 0
			&& tamJugadores > 0) {
		for (int i = 0; i < tamJugadores; i++) {
			indiceConfederacion = abm_encontrarConfederacionPorId(
					confederaciones, tamConfederaciones,
					jugadores[i].idConfederacion);
			// Los indices entre array de confederaciones y el array de acumuladores deben matchear
			acumuladoresAniosContrato[indiceConfederacion] +=
					jugadores[i].aniosContrato;
		}

		for (int i = 0; i < tamConfederaciones; i++) {
			if (acumuladoresAniosContrato[i]
					> acumuladoresAniosContrato[tamConfederaciones + 1]) {
				acumuladoresAniosContrato[tamConfederaciones + 1] =
						acumuladoresAniosContrato[i];
				indiceConfederacion = i;
			}
		}

		printf(
				"\n CONFEDERACION CON MAYOR CANTIDAD DE ANIOS DE CONTRATO: %s CON %d ANIOS \n\n",
				confederaciones[indiceConfederacion].nombre,
				acumuladoresAniosContrato[indiceConfederacion]);
		rtn = 1;
	}
	return rtn;
}

int informe_mostrarTotalPromedioJugadores(eJugador *jugadores, int tamJugadores) {
	int rtn = 0;
	float totalSalarios = 0;
	float promedioSalarios = 0;
	int contadorMayoresPromedio = 0;
	int i;

	if (jugadores != NULL && tamJugadores > 0) {
		for (i = 0; i < tamJugadores; i++) {
			totalSalarios += jugadores[i].salario;
		}
		promedioSalarios = (float) (totalSalarios / i);

		for (i = 0; i < tamJugadores; i++) {
			if (jugadores[i].salario > promedioSalarios) {
				contadorMayoresPromedio++;
			}
		}

		printf("\n SALARIO TOTAL: %f", totalSalarios);
		printf("\n SALARIO PROMEDIO: %f", promedioSalarios);
		printf(
				"\n CANTIDAD DE JUGADORES QUE COBRAN MAS DEL SALARIO PROMEDIO: %d",
				contadorMayoresPromedio);

		rtn = 1;
	}
	return rtn;
}

