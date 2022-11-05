#include <stdio.h>
#include <stdlib.h>

#include "Jugador.h"
#include "Seleccion.h"
#include "LinkedList.h"
#include "parser.h"

/** \brief Carga los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeTexto(char *path,
		LinkedList *pArrayListJugador) {
	int rtn = 0;

	FILE *pFile = fopen(path, "r");

	if (path != NULL && pArrayListJugador != NULL) {
		if (pFile == NULL) {
			puts("\nERROR. No es posible abrir el archivo");
		} else {
			if (ll_isEmpty(pArrayListJugador)) {
				if (parser_JugadorFromText(pFile, pArrayListJugador)) {
					printf("\nArchivos cargados con exito");
					rtn = 1;
				} else {
					puts("\nERROR. Ocurrio un error al cargar el archivo");
				}
			} else {
				// TODO: hacer else
			}
		}
	}

	fclose(pFile);
	return rtn;
}

/** \brief Carga los datos de los jugadores desde el archivo generado en modo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeBinario(char *path,
		LinkedList *pArrayListJugador) {
	return 1;
}

/** \brief Alta de jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_agregarJugador(LinkedList *pArrayListJugador) {
	return 1;
}

/** \brief Modificar datos del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_editarJugador(LinkedList *pArrayListJugador) {
	return 1;
}

/** \brief Baja del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_removerJugador(LinkedList *pArrayListJugador) {
	return 1;
}

/** \brief Listar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_listarJugadores(LinkedList *pArrayListJugador) {
	int rtn = 0;
	int arrayTam;
	Jugador *pJugador;
	Jugador auxJugador;

	if (pArrayListJugador != NULL) {
		arrayTam = ll_len(pArrayListJugador);

		if (arrayTam != -1) {

			for (int i = 0; i < arrayTam; i++) {
				pJugador = (Jugador*) ll_get(pArrayListJugador, i);
				if (pJugador != NULL) {

					jug_getId(pJugador, &auxJugador.id);
					jug_getNombreCompleto(pJugador, auxJugador.nombreCompleto);
					jug_getPosicion(pJugador, auxJugador.posicion);
					jug_getEdad(pJugador, &auxJugador.edad);
					jug_getNacionalidad(pJugador, auxJugador.nacionalidad);
					jug_getSIdSeleccion(pJugador, &auxJugador.idSeleccion);
					jug_getIsEmpty(pJugador, &auxJugador.isEmpty);

					printf("\n A ver que onda: %d %s %s %d %s %d %d",
							auxJugador.id, auxJugador.nombreCompleto,
							auxJugador.nacionalidad, auxJugador.edad,
							auxJugador.posicion, auxJugador.idSeleccion,
							auxJugador.isEmpty);

					rtn = 1;
				}
			}
		}
	}

	return rtn;
}

/** \brief Ordenar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_ordenarJugadores(LinkedList *pArrayListJugador) {
	return 1;
}

/** \brief Guarda los datos de los jugadores en el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoTexto(char *path,
		LinkedList *pArrayListJugador) {
	return 1;
}

/** \brief Guarda los datos de los jugadores en el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoBinario(char *path,
		LinkedList *pArrayListJugador) {
	return 1;
}

/** \brief Carga los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_cargarSeleccionesDesdeTexto(char *path,
		LinkedList *pArrayListSeleccion) {
	return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_editarSeleccion(LinkedList *pArrayListSeleccion) {
	return 1;
}

/** \brief Listar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_listarSelecciones(LinkedList *pArrayListSeleccion) {
	return 1;
}

/** \brief Ordenar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_ordenarSelecciones(LinkedList *pArrayListSeleccion) {
	return 1;
}

/** \brief Guarda los datos de los selecciones en el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarSeleccionesModoTexto(char *path,
		LinkedList *pArrayListSeleccion) {
	return 1;
}

