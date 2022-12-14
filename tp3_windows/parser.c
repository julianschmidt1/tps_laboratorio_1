#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Jugador.h"
#include "Seleccion.h"

/** \brief Parsea los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param pFile FILE* puntero al archivo abierto
 * \param pArrayListJugador LinkedList* array de jugadores a cargar
 * \return int retorna 1 en caso de exito y 0 en caso de error
 */
int parser_JugadorFromText(FILE *pFile, LinkedList *pArrayListJugador) {
	int rtn = 0;

	char buffer[6][150];
	Jugador *pJugador;

	if (pFile != NULL && pArrayListJugador != NULL) {
		// Cargamos cabecera
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0],
				buffer[1], buffer[2], buffer[3], buffer[4], buffer[5]);

		do {
			// Cargamos datos
			if (fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
					buffer[0], buffer[1], buffer[2], buffer[3], buffer[4],
					buffer[5]) < 6) {
				break;
			} else {
				pJugador = jug_newParametros(buffer[0], buffer[1], buffer[2],
						buffer[3], buffer[4], buffer[5]);
				if (pJugador == NULL) {
					break;
				} else {
					ll_add(pArrayListJugador, (Jugador*) pJugador);
					rtn = 1;
				}
			}
		} while (feof(pFile) == 0);
	}

	return rtn;
}

/// \brief Carga el ultimo id guardado
///
/// \param pFile puntero a archivo abierto
/// \param pId puntero a id a obtener
/// \return retorna 1 en caso de exito y 0 en caso de error
int parser_ObtenerUltimoId(FILE *pFile, int *pId) {
	int rtn = 0;

	if (pFile != NULL) {

		if (fread(pId, sizeof(int), 1, pFile) == 1) {
			puts("\nUltimo id cargado okamente!");
			rtn = 1;
		} else {
			puts("\nOcurrio un error :(.");
		}

	}

	return rtn;
}

/** \brief Parsea los datos de los jugadores desde el archivo binario.
 *
 * \param pFile puntero a archivo
 * \param pArrayListJugador array de jugadores
 * \return retorna 1 en caso de exito y 0 en caso de error
 */
int parser_JugadorFromBinary(FILE *pFile, LinkedList *pArrayListJugador) {
	int rtn = 0;

	if (pFile != NULL && pArrayListJugador != NULL) {
		do {
			Jugador *nuevoJugador = jug_new();
			if (nuevoJugador != NULL) {
				if (fread(nuevoJugador, sizeof(Jugador), 1, pFile) == 1) {
					if (ll_add(pArrayListJugador, nuevoJugador) == 0) {
						rtn = 1;
					}
				} else {
					puts("\n Cualquiereo");
					free(nuevoJugador);
					break;
				}
			}
		} while (!feof(pFile));
	}

	return rtn;
}

/** \brief Parsea los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param pFile FILE* puntero al archivo
 * \param pArrayListSeleccion LinkedList* array de selecciones
 * \return int retorna 1 en caso de exito y 0 en caso de error
 *
 */
int parser_SeleccionFromText(FILE *pFile, LinkedList *pArrayListSeleccion) {
	int rtn = 0;

	char buffer[4][150];
	Seleccion *pSeleccion;

	if (pFile != NULL && pArrayListSeleccion != NULL) {
		// Cargamos cabecera
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1],
				buffer[2], buffer[3]);

		do {
			// Cargamos datos
			if (fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0],
					buffer[1], buffer[2], buffer[3]) < 4) {
				break;
			} else {
				pSeleccion = selec_newParametros(buffer[0], buffer[1],
						buffer[2], buffer[3]);
				if (pSeleccion == NULL) {
					break;
				} else {
					ll_add(pArrayListSeleccion, (Seleccion*) pSeleccion);
					rtn = 1;
				}
			}
		} while (feof(pFile) == 0);
	}

	return rtn;
}

