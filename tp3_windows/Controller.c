#include <stdio.h>
#include <stdlib.h>
#include "Jugador.h"
#include "Seleccion.h"
#include "LinkedList.h"
#include "parser.h"
#include "inputs.h"
#include "menu.h"

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
					printf("\nJugadores cargados con exito");
					rtn = 1;
				} else {
					puts("\nERROR. Ocurrio un error al cargar el archivo");
				}
			} else {
				puts("\nLa lista no esta vacia.");
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

	if (pArrayListJugador != NULL) {
		nuevoJugador = jug_new();
		idFile = fopen("ultimoId.bin", "rb");

		if (idFile == NULL) {
			auxUltimoId = PRIMER_ID_MANUAL;
		} else {
			if (!parser_ObtenerUltimoId(idFile, &auxUltimoId)) {
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

			puts(
					"\n==============================================================================================================");
			printf("| %-5s  | %-25s | %-15s | %-8s | %-25s | %-8s |\n", "ID",
					"NOMBRE COMPLETO", "NACIONALIDAD", "EDAD", "POSICION",
					"SELECCION");
			puts(
					"==============================================================================================================");
			for (int i = 0; i < arrayTam; i++) {
				pJugador = (Jugador*) ll_get(pArrayListJugador, i);
				if (pJugador != NULL) {
					jug_getId(pJugador, &auxJugador.id);
					jug_getNombreCompleto(pJugador, auxJugador.nombreCompleto);
					jug_getPosicion(pJugador, auxJugador.posicion);
					jug_getEdad(pJugador, &auxJugador.edad);
					jug_getNacionalidad(pJugador, auxJugador.nacionalidad);
					jug_getSIdSeleccion(pJugador, &auxJugador.idSeleccion);
					printf("\n| %-5d  | %-25s | %-15s | %-8d| %-25s | %-8d |",
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

Seleccion* controller_buscarSeleccionPorId(LinkedList *pArrayListSeleccion,
		int idBusqueda) {
	Seleccion *rtn = NULL;
	int tamArray;
	int i;
	int auxIdSeleccion;
	Seleccion *pSeleccion;
	if (pArrayListSeleccion != NULL) {
		if (!ll_isEmpty(pArrayListSeleccion)) {
			tamArray = ll_len(pArrayListSeleccion);
			for (i = 0; i < tamArray; i++) {
				pSeleccion = (Seleccion*) ll_get(pArrayListSeleccion, i);
				selec_getId(pSeleccion, &auxIdSeleccion);
				if (auxIdSeleccion == idBusqueda) {
					rtn = pSeleccion;
					break;
				}
			}
			if (rtn != pSeleccion) {
				printf("\nNo se encontro el id");
			}
		}
	}

	return rtn;
}

int controller_listarJugadoresConvocados(LinkedList *pArrayListJugador) {
	int rtn = 0;
	int arrayTam;
	Jugador *pJugador;
	Jugador auxJugador;

	if (pArrayListJugador != NULL) {
		arrayTam = ll_len(pArrayListJugador);

		if (arrayTam != -1) {
			puts(
					"\n==============================================================================================================");
			printf("| %-5s  | %-25s | %-15s | %-8s | %-25s | %-8s |\n", "ID",
					"NOMBRE COMPLETO", "NACIONALIDAD", "EDAD", "POSICION",
					"SELECCION");
			puts(
					"==============================================================================================================");
			for (int i = 0; i < arrayTam; i++) {
				pJugador = (Jugador*) ll_get(pArrayListJugador, i);
				if (pJugador != NULL && pJugador->idSeleccion != 0) {
					jug_getId(pJugador, &auxJugador.id);
					jug_getNombreCompleto(pJugador, auxJugador.nombreCompleto);
					jug_getPosicion(pJugador, auxJugador.posicion);
					jug_getEdad(pJugador, &auxJugador.edad);
					jug_getNacionalidad(pJugador, auxJugador.nacionalidad);
					jug_getSIdSeleccion(pJugador, &auxJugador.idSeleccion);

					printf("\n| %-5d  | %-25s | %-15s | %-8d| %-25s | %-8d |",
							auxJugador.id, auxJugador.nombreCompleto,
							auxJugador.nacionalidad, auxJugador.edad,
							auxJugador.posicion, auxJugador.idSeleccion);
					rtn = 1;
				}
			}
			puts(
					"\n==============================================================================================================");
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
int controller_removerJugador(LinkedList *pArrayListJugador,
		LinkedList *pArrayListSeleccion) {
	int rtn = 0;
	int auxIdSeleccionado;
	Jugador *pAuxJugador;
	int indiceJugador;

	if (pArrayListJugador != NULL && pArrayListSeleccion) {
		controller_listarJugadores(pArrayListJugador);
		utn_getNumero(&auxIdSeleccionado, "\nIngrese el id de jugador: ",
				"\nError. Ingrese el id de jugador: ", 1, 999, 9999);
		while (controller_buscarJugadorPorId(pArrayListJugador,
				auxIdSeleccionado) == NULL) {
			utn_getNumero(&auxIdSeleccionado, "\nIngrese el id de jugador: ",
					"\nError. Ingrese el id de jugador: ", 1, 999, 9999);
		}

		pAuxJugador = controller_buscarJugadorPorId(pArrayListJugador,
				auxIdSeleccionado);

		if (menu_opciones("\n\nEsta seguro de que desea eliminar el jugador? ",
				"\n(1. SI | 2. NO)", "\nOpcion invalida. Ingrese la opcion: ",
				1, 2) == 1) {
			indiceJugador = ll_indexOf(pArrayListJugador, pAuxJugador);
			if (ll_remove(pArrayListJugador, indiceJugador) == 0) {
				selec_eliminarUnConvocado(pArrayListSeleccion,
						pAuxJugador->idSeleccion);
				jug_delete(pAuxJugador);
				puts("\nJugador dado de baja exitosamente");
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
	int opcion;
	Jugador *pAuxJugador = NULL;
	Jugador auxJugador;

	if (pArrayListJugador != NULL) {
		controller_listarJugadores(pArrayListJugador);

		utn_getNumero(&auxIdSeleccionado, "\nIngrese el id de jugador: ",
				"\nError. Ingrese el id de jugador: ", 1, 999, 9999);
		while (controller_buscarJugadorPorId(pArrayListJugador,
				auxIdSeleccionado) == NULL) {
			utn_getNumero(&auxIdSeleccionado, "\nIngrese el id de jugador: ",
					"\nError. Ingrese el id de jugador: ", 1, 999, 9999);
		}

		pAuxJugador = controller_buscarJugadorPorId(pArrayListJugador,
				auxIdSeleccionado);

		if (pAuxJugador != NULL) {

			do {

				opcion = menu_opciones(
						"\n ---------- Edicion de usuario ----------",
						"\n1. Editar nombre"
								"\n2. Editar edad"
								"\n3. Editar posicion"
								"\n4. Editar nacionalidad"
								"\n5. Volver al menu principal",
						"\nOpcion invalida. Ingrese la opcion", 1, 5);

				switch (opcion) {
				case 1:
					utn_getString("\nIngrese el nombre: ",
							"\nError. Nombre invalido. ", 9999, NOMBRE_CHARS,
							auxJugador.nombreCompleto);
					if (menu_opciones("\nEsta seguro que desea modificar?",
							"(1. SI | 2. NO )",
							"\nOpcion invalida. Ingrese la opcion: ", 1, 2)
							== 1) {
						jug_setNombreCompleto(pAuxJugador,
								auxJugador.nombreCompleto);
						puts("\n ---- Modificacion exitosa ---- \n");
					} else {
						puts("\n ---- Modificacion cancelada ---- \n");
					}

					break;
				case 2:
					utn_getNumero(&auxJugador.edad, "\nIngrese la edad: ",
							"\nEdad invalida, ingrese la edad: ", 18, 100,
							9999);
					if (menu_opciones("\nEsta seguro que desea modificar?",
							"(1. SI | 2. NO )",
							"\nOpcion invalida. Ingrese la opcion: ", 1, 2)
							== 1) {
						jug_setEdad(pAuxJugador, auxJugador.edad);
						puts("\n ---- Modificacion exitosa ---- \n");
					} else {
						puts("\n ---- Modificacion cancelada ---- \n");
					}
					break;
				case 3:
					utn_getString("\nIngrese la posicion: ",
							"\nError. Nombre invalido. ", 9999, POSICION_CHARS,
							auxJugador.posicion);
					if (menu_opciones("\nEsta seguro que desea modificar?",
							"(1. SI | 2. NO )",
							"\nOpcion invalida. Ingrese la opcion: ", 1, 2)
							== 1) {
						jug_setPosicion(pAuxJugador, auxJugador.posicion);
						puts("\n ---- Modificacion exitosa ---- \n");
					} else {
						puts("\n ---- Modificacion cancelada ---- \n");
					}
					break;
				case 4:
					utn_getString("\nIngrese la nacionalidad: ",
							"\nError. Nacionalidad invalida. ", 9999,
							NACIONALIDAD_CHARS, auxJugador.nacionalidad);
					if (menu_opciones("\nEsta seguro que desea modificar?",
							"(1. SI | 2. NO )",
							"\nOpcion invalida. Ingrese la opcion: ", 1, 2)
							== 1) {
						jug_setNacionalidad(pAuxJugador,
								auxJugador.nacionalidad);
						puts("\n ---- Modificacion exitosa ---- \n");
					} else {
						puts("\n ---- Modificacion cancelada ---- \n");
					}
					break;
				}

			} while (opcion != 5);

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
	int rtn = 0;
	int (*pOrdenamiento)(void*, void*);
	int menuOrdenamiento;
	int criterioOrdenamiento;

	if (pArrayListJugador != NULL) {

		do {

			menuOrdenamiento = menu_opciones(
					"\n ---- ORDENAR Y LISTAR JUGADORES ----- \n",
					"\n1. JUGADORES POR NACIONALIDAD"
							"\n2. JUGADORES POR EDAD"
							"\n3. JUGADORES POR NOMBRE"
							"\n4. SALIR",
					"\nOpcion invalida. Ingrese la opcion: ", 1, 4);

			switch (menuOrdenamiento) {
			case 1:
				pOrdenamiento = jug_ordenarPorNacionalidad;
				break;
			case 2:
				pOrdenamiento = jug_ordenarPorEdad;
				break;
			case 3:
				pOrdenamiento = jug_ordenarPorNombreCompleto;
				break;
			}

			if (menuOrdenamiento != 4) {
				if (utn_getNumero(&criterioOrdenamiento,
						"\nCRITERIO DE ORDENAMIENTO (0. ASC | 1. DESC): ",
						"\nError. Opcion invalida. Ingrese la opcion: ", 0, 1,
						9999)) {
					if (!ll_sort(pArrayListJugador, pOrdenamiento,
							criterioOrdenamiento)) {
						puts("\nJugadores ordenados exitosamente");
						controller_listarJugadores(pArrayListJugador);
					} else {
						puts("\nNo se pudieron ordenar los jugadores");
					}
				} else {
					puts("\nLimite de reintentos alcanzados.");
				}

			}
		} while (menuOrdenamiento != 4);
	}

	return rtn;
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
	int rtn = 0;

	FILE *pFile = fopen(path, "r");

	if (path != NULL && pArrayListSeleccion != NULL) {
		if (pFile == NULL) {
			puts("\nERROR. No es posible abrir el archivo");
		} else {
			if (ll_isEmpty(pArrayListSeleccion)) {
				if (parser_SeleccionFromText(pFile, pArrayListSeleccion)) {
					printf("\nSelecciones cargadas con exito");
					rtn = 1;
				} else {
					puts("\nERROR. Ocurrio un error al cargar el archivo");
				}
			} else {
				puts("\nLa lista no esta vacia.");
			}
		}
	}

	fclose(pFile);
	return rtn;
}

/** \brief Listar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_listarSelecciones(LinkedList *pArrayListSeleccion) {
	int rtn = 0;
	int arrayTam;
	Seleccion *pSeleccion;
	Seleccion auxSeleccion;

	if (pArrayListSeleccion != NULL) {
		arrayTam = ll_len(pArrayListSeleccion);

		if (arrayTam != -1) {

			puts(
					"\n=================================================================");
			printf("| %-5s  | %-20s | %-15s | %-8s |", "ID", "PAIS",
					"CONFEDERACION", "CONVOCADOS");
			puts(
					"\n=================================================================");
			for (int i = 0; i < arrayTam; i++) {
				pSeleccion = (Seleccion*) ll_get(pArrayListSeleccion, i);
				if (pSeleccion != NULL) {

					selec_getId(pSeleccion, &auxSeleccion.id);
					selec_getPais(pSeleccion, auxSeleccion.pais);
					selec_getConfederacion(pSeleccion,
							auxSeleccion.confederacion);
					selec_getConvocados(pSeleccion, &auxSeleccion.convocados);
					printf("\n| %-5d  | %-20s | %-15s | %-8d |",
							auxSeleccion.id, auxSeleccion.pais,
							auxSeleccion.confederacion,
							auxSeleccion.convocados);
					rtn = 1;
				}
			}
			puts(
					"\n=================================================================");
		}
	}

	return rtn;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_editarSeleccion(LinkedList *pArrayListSeleccion) {
	int rtn = 0;

	int auxIdSeleccion;
	Seleccion *pAuxSeleccion;
	int auxCantidadConvocados;

	if (pArrayListSeleccion != NULL) {
		controller_listarSelecciones(pArrayListSeleccion);
		utn_getNumero(&auxIdSeleccion, "\nIngrese el id de seleccion: ",
				"\nId invalido. Ingrese el id de seleccion: ", 1, 50, 9999);
		if (controller_buscarSeleccionPorId(pArrayListSeleccion,
				auxIdSeleccion) == NULL) {
			puts("\n  -------- ERROR. LA SELECCION NO EXISTE. ------------ \n");
		} else {
			pAuxSeleccion = controller_buscarSeleccionPorId(pArrayListSeleccion,
					auxIdSeleccion);
			if (pAuxSeleccion->convocados == MAX_JUGADORES) {
				puts(
						"\n  -------- ERROR. CANTIDAD DE CONVOCADOS ALCANZADA EN ESTA SELECCION. ------------ \n");
			} else {
				selec_getConvocados(pAuxSeleccion, &auxCantidadConvocados);
				auxCantidadConvocados++;
				selec_setConvocados(pAuxSeleccion, auxCantidadConvocados);
				rtn = pAuxSeleccion->id;
			}
		}

	}

	return rtn;
}

/** \brief Ordenar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_ordenarSelecciones(LinkedList *pArrayListSeleccion) {
	int rtn = 0;
	int criterioOrdenamiento;
	int (*pOrdenamiento)(void*, void*);

	if (pArrayListSeleccion != NULL) {
		pOrdenamiento = selec_ordenarPorConfederacion;

		if (utn_getNumero(&criterioOrdenamiento,
				"\nCRITERIO DE ORDENAMIENTO (0. ASC | 1. DESC): ",
				"\nError. Opcion invalida. Ingrese la opcion: ", 0, 1, 9999)) {
			if (!ll_sort(pArrayListSeleccion, pOrdenamiento,
					criterioOrdenamiento)) {
				puts("\nJugadores ordenados exitosamente");
				controller_listarSelecciones(pArrayListSeleccion);
			} else {
				puts("\nNo se pudieron ordenar los jugadores");
			}
		} else {
			puts("\nLimite de reintentos alcanzados.");
		}
	}

	return rtn;
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
