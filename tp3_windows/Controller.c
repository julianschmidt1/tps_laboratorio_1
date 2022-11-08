#include <stdio.h>
#include <stdlib.h>

#include "Jugador.h"
#include "Seleccion.h"
#include "LinkedList.h"
#include "parser.h"
#include "inputs.h"

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
	int rtn = 0;
	Jugador *nuevoJugador = NULL;
	FILE *idFile = NULL;
	int auxUltimoId;
	Jugador auxBufferJugador;

	//FILE *idFile = fopen("ultimoId.bin", "");

	if (pArrayListJugador != NULL) {
		nuevoJugador = jug_new();
		idFile = fopen("ultimoId.bin", "rb");

		if (idFile == NULL) {
			auxUltimoId = PRIMER_ID_MANUAL;
		} else {
			if (!parser_ObtenerUltimoId(idFile, &auxUltimoId)) {
				printf("%d", auxUltimoId);
				puts("\nOcurrio un error");
			}
		}
		fclose(idFile);

		if (nuevoJugador != NULL) {
			if (utn_getString("\nIngrese el nombre completo: ",
					"\nNombre invalido. Ingrese el nombre: ", 9999,
					NOMBRE_CHARS, auxBufferJugador.nombreCompleto) == 0
					&& utn_getNumero(&auxBufferJugador.edad,
							"\nIngrese la edad: ",
							"\nEdad invalida. Ingrese la edad: ", 18, 100, 9999)
					&& utn_getString("\nIngrese la posicion: ",
							"\nPosicion invalida. Ingrese la posicion: ", 9999,
							POSICION_CHARS, auxBufferJugador.posicion) == 0
					&& utn_getString("\nIngrese la nacionalidad: ",
							"\nnacionalidad invalida. Ingrese la nacionalidad: ",
							9999, NACIONALIDAD_CHARS,
							auxBufferJugador.nacionalidad) == 0) {

				if (!(jug_setNombreCompleto(nuevoJugador,
						auxBufferJugador.nombreCompleto)
						&& jug_setEdad(nuevoJugador, auxBufferJugador.edad)
						&& jug_setPosicion(nuevoJugador,
								auxBufferJugador.posicion)
						&& jug_setNacionalidad(nuevoJugador,
								auxBufferJugador.nacionalidad)
						&& jug_setId(nuevoJugador, auxUltimoId)
						&& jug_setIdSeleccion(nuevoJugador, 0))) {
					free(nuevoJugador);
					nuevoJugador = NULL;
				} else {
					rtn = 1;
					ll_add(pArrayListJugador, nuevoJugador);
					idFile = fopen("ultimoId.bin", "wb");
					auxUltimoId++;
					parser_GuardarUltimoId(idFile, &auxUltimoId);
					fclose(idFile);
				}
			}
		}

	}

	return rtn;
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
					printf("\n A ver que onda: %d %s %s %d %s %d",
							auxJugador.id, auxJugador.nombreCompleto,
							auxJugador.nacionalidad, auxJugador.edad,
							auxJugador.posicion, auxJugador.idSeleccion);

					rtn = 1;
				}
			}
		}
	}

	return rtn;
}

Jugador* controller_buscarJugadorPorId(LinkedList *pArrayListJugador,
		int idBusqueda) {
	Jugador *rtn = NULL;
	int tamArray;
	int i;
	int auxIdJugador;
	Jugador *pJugador;
	if (pArrayListJugador != NULL) {
		if (!ll_isEmpty(pArrayListJugador)) {
			tamArray = ll_len(pArrayListJugador);
			for (i = 0; i < tamArray; i++) {
				pJugador = (Jugador*) ll_get(pArrayListJugador, i);
				jug_getId(pJugador, &auxIdJugador);
				if (auxIdJugador == idBusqueda) {
					rtn = pJugador;
					break;
				}
			}
			if (rtn != pJugador) {
				printf("\nNo se encontro el id");
			}
		}
	}

	return rtn;
}

/** \brief Modificar datos del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_editarJugador(LinkedList *pArrayListJugador) {
	int rtn = 0;
	int auxIdSeleccionado;

	if (pArrayListJugador != NULL) {
		controller_listarJugadores(pArrayListJugador);

		utn_getNumero(&auxIdSeleccionado, "\nIngrese el id de jugador: ",
				"\nError. Ingrese el id de jugador: ", 1, 999, 9999);
		while (controller_buscarJugadorPorId(pArrayListJugador,
				auxIdSeleccionado) == NULL) {
			utn_getNumero(&auxIdSeleccionado, "\nIngrese el id de jugador: ",
					"\nError. Ingrese el id de jugador: ", 1, 999, 9999);
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
