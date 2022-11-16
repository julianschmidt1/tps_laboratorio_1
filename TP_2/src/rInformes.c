/*
 * rInformes.c
 *
 *  Created on: 18 Oct 2022
 *      Author: Julian
 */

#include "rInformes.h"
#include "eConfederacion.h"
#include "Operaciones.h"

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

int inicializarIntArray(int *array, int tam, int valor) {
	int rtn = 0;
	if (array != NULL && tam > 0) {
		for (int i = 0; i < tam; i++) {
			array[i] = valor;
		}
		rtn = 1;
	}
	return rtn;
}

int informe_mostrarRegionConMasJugadores(eConfederacion *confederaciones,
		int tamConfederaciones, eJugador *jugadores, int tamJugadores) {
	int rtn = 0;
	int indiceConfederacionMasJugadores = -1;
	int indiceConfederacion;
	int contadoresJugadoresDeConfederaciones[tamConfederaciones];

	inicializarIntArray(contadoresJugadoresDeConfederaciones,
			tamConfederaciones, 0);
	if (confederaciones != NULL && jugadores != NULL && tamConfederaciones > 0
			&& tamJugadores > 0) {
		for (int i = 0; i < tamJugadores; i++) {
			if (jugadores[i].isEmpty == OCUPADO) {
				indiceConfederacion = abm_encontrarConfederacionPorId(
						confederaciones, tamConfederaciones,
						jugadores[i].idConfederacion);
				contadoresJugadoresDeConfederaciones[indiceConfederacion]++;
			}
		}

		for (int i = 0; i < tamConfederaciones; i++) {
			// Uso el indice como flag, si es el primer indice guardo el valor. Se espera que este ordenado
			if (i == 0
					|| contadoresJugadoresDeConfederaciones[i]
							> contadoresJugadoresDeConfederaciones[indiceConfederacionMasJugadores]) {
				indiceConfederacionMasJugadores = i;
			}
		}
		printf("\nRegion con mas jugadores: %s: ",
				confederaciones[indiceConfederacionMasJugadores].region);
		for (int i = 0; i < tamJugadores; i++) {
			if (jugadores[i].isEmpty == OCUPADO
					&& jugadores[i].idConfederacion
							== confederaciones[indiceConfederacionMasJugadores].id) {
				abm_mostrarUnJugador(jugadores[i], confederaciones,
						tamConfederaciones);
			}
		}
		rtn = 1;
	}

	return rtn;
}

int informe_mostrarPorcentajeJugadoresConfederacion(
		eConfederacion *confederaciones, int tamConfederaciones,
		eJugador *jugadores, int tamJugadores) {
	int rtn = 0;
	int totalJugadores = 0;
	int contadoresJugadoresDeConfederaciones[tamConfederaciones];
	int indiceConfederacion;

	inicializarIntArray(contadoresJugadoresDeConfederaciones,
			tamConfederaciones, 0);
	if (confederaciones != NULL && jugadores != NULL && tamConfederaciones > 0
			&& tamJugadores > 0) {

		for (int i = 0; i < tamJugadores; i++) {
			if (jugadores[i].isEmpty == OCUPADO) {
				totalJugadores++;
				indiceConfederacion = abm_encontrarConfederacionPorId(
						confederaciones, tamConfederaciones,
						jugadores[i].idConfederacion);
				contadoresJugadoresDeConfederaciones[indiceConfederacion]++;
			}
		}

		for (int i = 0; i < tamConfederaciones; i++) {
			printf("\nConfederacion: %s tiene un: %.2f%% de los jugadores.",
					confederaciones[i].nombre,
					op_calcularPorcentaje(
							(float) contadoresJugadoresDeConfederaciones[i],
							(float) totalJugadores));
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
	inicializarIntArray(acumuladoresAniosContrato, sizeAcumulador, 0);
	if (confederaciones != NULL && jugadores != NULL && tamConfederaciones > 0
			&& tamJugadores > 0) {
		for (int i = 0; i < tamJugadores; i++) {
			if (jugadores[i].isEmpty == OCUPADO) {
				indiceConfederacion = abm_encontrarConfederacionPorId(
						confederaciones, tamConfederaciones,
						jugadores[i].idConfederacion);
				// Los indices entre array de confederaciones y el array de acumuladores deben matchear
				acumuladoresAniosContrato[indiceConfederacion] +=
						jugadores[i].aniosContrato;
			}
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
			if (jugadores[i].isEmpty == OCUPADO) {
				totalSalarios = op_sumar(totalSalarios, jugadores[i].salario);
			}
		}
		promedioSalarios = op_dividir(totalSalarios, i);

		for (i = 0; i < tamJugadores; i++) {
			if (jugadores[i].salario
					> promedioSalarios&& jugadores[i].isEmpty == OCUPADO) {
				contadorMayoresPromedio++;
			}
		}

		printf("\n SALARIO TOTAL: %.2f", totalSalarios);
		printf("\n SALARIO PROMEDIO: %.2f", promedioSalarios);
		printf(
				"\n CANTIDAD DE JUGADORES QUE COBRAN MAS DEL SALARIO PROMEDIO: %d",
				contadorMayoresPromedio);

		rtn = 1;
	}
	return rtn;
}

