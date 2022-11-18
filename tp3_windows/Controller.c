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
 * \return int retorna 1 en caso de exito, 0 en caso de error y -1 en caso de que la lista tenga datos
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
				rtn = -1;
				puts("\nLa lista no esta vacia.");
			}
		}
	}

	fclose(pFile);
	return rtn;
}

/** \brief Carga los datos de los jugadores desde el archivo generado en modo binario.
 *
 * \param path char* ruta del archivo
 * \param pArrayListJugador LinkedList* del array a cargar
 * \return int retorna 1 en caso de exito, 0 en caso de error
 *
 */
int controller_cargarJugadoresDesdeBinario(char *path,
		LinkedList *pArrayListJugador) {
	int rtn = 0;
	FILE *pFile;

	if (path != NULL && pArrayListJugador != NULL) {
		pFile = fopen(path, "rb");
		if (ll_isEmpty(pArrayListJugador)) {
			if (parser_JugadorFromBinary(pFile, pArrayListJugador)) {
				puts("\n ---- Archivo cargado con exito ---- ");
				rtn = 1;
			} else {
				puts("\nERROR. Ocurrio un error al cargar el archivo");
			}
			fclose(pFile);
		}
	} else {
		puts("\n --- No es posible cargar jugadores ---- ");
	}
	return rtn;
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
					&& utn_getString("\nIngrese la nacionalidad: ",
							"\nnacionalidad invalida. Ingrese la nacionalidad: ",
							9999, NACIONALIDAD_CHARS,
							auxBufferJugador.nacionalidad) == 0) {
				menu_mostrarPosiciones();
				while (validarPosicionJugador(auxBufferJugador.posicion) == -1) {

					utn_getString("\nIngrese la posicion: ",
							"\nPosicion invalida. Ingrese la posicion: ", 9999,
							POSICION_CHARS, auxBufferJugador.posicion);
					if (validarPosicionJugador(auxBufferJugador.posicion)
							== -1) {
						puts("\nPosicion invalida");
					}
				}

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
					rtn = auxUltimoId;
					ll_add(pArrayListJugador, nuevoJugador);
				}
			}
		}

	}

	return rtn;
}

int controller_guardarUltimoId(char *path, int *pId) {
	int rtn = 0;
	FILE *pFile;

	pFile = fopen("ultimoId.bin", "wb");

	if (pFile != NULL) {
		if (fwrite(pId, sizeof(int), 1, pFile)) {
			puts("\nId actualizado correctamente.");
		} else {
			puts("\nOcurrio un error al actualizar el id");
		}
	}
	fclose(pFile);
	return rtn;
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
				rtn = -1;
				puts("\nLa lista no esta vacia.");
			}
		}
	}

	fclose(pFile);
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
	LinkedList *pAuxArrayListSelecciones = ll_newLinkedList();
	char auxPaisDeSeleccion[MAX_CHARS];

	// Levanto los datos de las selecciones desde el archivo y los almaceno en un auxiliar (Asi puedo hacer la relacion entre idSeleccion y el pais al que pertenece).
	// Me parece mucho mas barato hacer esto que modificar los prototipos y bajar parametros por todos lados
	controller_cargarSeleccionesDesdeTexto("selecciones.csv",
			pAuxArrayListSelecciones);

	if (pArrayListJugador != NULL && pAuxArrayListSelecciones != NULL) {
		arrayTam = ll_len(pArrayListJugador);
		if (arrayTam != -1) {
			puts(
					"\n==============================================================================================================");
			printf("| %-5s  | %-25s | %-15s | %-8s | %-25s | %-14s |\n", "ID",
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
					// Busco el idSeleccion vinculado al jugador. En este caso funciona porque solo me interesa guardar el nombre del país de tal seleccion
					// Si la informacion guardada de las selecciones esta actualizada o no es indiferente, solo necesito el nombre
					selec_encontrarPaisDeSeleccion(pAuxArrayListSelecciones,
							auxJugador.idSeleccion, auxPaisDeSeleccion);
					printf("\n| %-5d  | %-25s | %-15s | %-8d| %-25s | %-14s |",
							auxJugador.id, auxJugador.nombreCompleto,
							auxJugador.nacionalidad, auxJugador.edad,
							auxJugador.posicion, auxPaisDeSeleccion);
					rtn = 1;
				}
			}
		}
	}

	ll_deleteLinkedList(pAuxArrayListSelecciones);
	return rtn;
}

/// \brief Funcion que crea una nueva LinkedList en base a el criterio correspondiente para decir que un jugador fue convocado
///
/// \param pArrayListJugador Listado de jugadores
/// \param pArrayListSeleccion Listado de jugadores
/// \param pArrayListJugadorConvocado Listado a cargar
/// \return Retorna 1 en caso de exito y 0 en caso de error
int controller_crearListaJugadoresConvocados(LinkedList *pArrayListJugador,
		LinkedList *pArrayListSeleccion, LinkedList *pArrayListJugadorConvocado) {
	int rtn = 0;
	Jugador *pAuxJugador;
	Seleccion *pAuxSeleccion;
	int auxIdSeleccion;
	char auxConfederacion[MAX_CHARS];
	char bufferConfederacion[MAX_CHARS];
	Jugador *nuevoJugador;
	Jugador auxJugador;

	if (pArrayListJugador != NULL && pArrayListSeleccion != NULL
			&& pArrayListJugadorConvocado) {

		utn_getString("\nIngrese el nombre de la confederacion: ",
				"\nError. Ingrese la confederacion", 9999, MAX_CHARS,
				bufferConfederacion);

		for (int i = 0; i < ll_len(pArrayListJugador); i++) {
			pAuxJugador = ll_get(pArrayListJugador, i);
			jug_getSIdSeleccion(pAuxJugador, &auxIdSeleccion);
			if (auxIdSeleccion != 0) {
				pAuxSeleccion = selec_buscarSeleccionPorId(pArrayListSeleccion,
						auxIdSeleccion);
				if (pAuxSeleccion != NULL) {
					selec_getConfederacion(pAuxSeleccion, auxConfederacion);
					if (stricmp(auxConfederacion, bufferConfederacion) == 0) {
						nuevoJugador = jug_new();
						jug_getId(pAuxJugador, &auxJugador.id);
						jug_getEdad(pAuxJugador, &auxJugador.edad);
						jug_getNacionalidad(pAuxJugador,
								auxJugador.nacionalidad);
						jug_getNombreCompleto(pAuxJugador,
								auxJugador.nombreCompleto);
						jug_getPosicion(pAuxJugador, auxJugador.posicion);
						jug_getSIdSeleccion(pAuxJugador,
								&auxJugador.idSeleccion);

						jug_setId(nuevoJugador, auxJugador.id);
						jug_setEdad(nuevoJugador, auxJugador.edad);
						jug_setNacionalidad(nuevoJugador,
								auxJugador.nacionalidad);
						jug_setNombreCompleto(nuevoJugador,
								auxJugador.nombreCompleto);
						jug_setPosicion(nuevoJugador, auxJugador.posicion);
						jug_setIdSeleccion(nuevoJugador,
								auxJugador.idSeleccion);

						ll_add(pArrayListJugadorConvocado, nuevoJugador);
						rtn = 1;
					}
				}
			}

		}
	}
	if (rtn) {
		puts("\n ----- LISTA CREADA EXITOSAMENTE -----");
	} else {
		puts("\n ----- NO HAY JUGADORES EN LA CONFEDERACION INGRESADA ---- \n");
	}

	return rtn;
}

int controller_listarJugadoresConvocados(LinkedList *pArrayListJugador) {
	int rtn = 0;
	int arrayTam;
	Jugador *pJugador;
	Jugador auxJugador;
	int auxIdSeleccion;
	LinkedList *pAuxArrayListSelecciones = ll_newLinkedList();
	char auxPaisDeSeleccion[MAX_CHARS];

	controller_cargarSeleccionesDesdeTexto("selecciones.csv",
			pAuxArrayListSelecciones);

	if (pArrayListJugador != NULL) {
		arrayTam = ll_len(pArrayListJugador);

		if (arrayTam != -1) {
			puts(
					"\n==============================================================================================================");
			printf("| %-5s  | %-25s | %-15s | %-8s | %-25s | %-14s |\n", "ID",
					"NOMBRE COMPLETO", "NACIONALIDAD", "EDAD", "POSICION",
					"SELECCION");
			puts(
					"==============================================================================================================");
			for (int i = 0; i < arrayTam; i++) {
				pJugador = (Jugador*) ll_get(pArrayListJugador, i);
				jug_getSIdSeleccion(pJugador, &auxIdSeleccion);
				if (pJugador != NULL && auxIdSeleccion != 0) {
					jug_getId(pJugador, &auxJugador.id);
					jug_getNombreCompleto(pJugador, auxJugador.nombreCompleto);
					jug_getPosicion(pJugador, auxJugador.posicion);
					jug_getEdad(pJugador, &auxJugador.edad);
					jug_getNacionalidad(pJugador, auxJugador.nacionalidad);
					jug_getSIdSeleccion(pJugador, &auxJugador.idSeleccion);

					// Busco el idSeleccion vinculado al jugador. En este caso funciona porque solo me interesa guardar el nombre del país de tal seleccion
					// Si la informacion guardada de las selecciones esta actualizada o no es indiferente, solo necesito el nombre
					selec_encontrarPaisDeSeleccion(pAuxArrayListSelecciones,
							auxJugador.idSeleccion, auxPaisDeSeleccion);
					printf("\n| %-5d  | %-25s | %-15s | %-8d| %-25s | %-14s |",
							auxJugador.id, auxJugador.nombreCompleto,
							auxJugador.nacionalidad, auxJugador.edad,
							auxJugador.posicion, auxPaisDeSeleccion);
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
	int auxIdSeleccionado = -1;
	Jugador *pAuxJugador = NULL;
	int indiceJugador;
	int auxIdSeleccion;

	if (pArrayListJugador != NULL && pArrayListSeleccion) {
		controller_listarJugadores(pArrayListJugador);

		while (pAuxJugador == NULL) {
			utn_getNumero(&auxIdSeleccionado, "\nIngrese el id de jugador: ",
					"\nError. Ingrese el id de jugador: ", 1, 999, 9999);
			pAuxJugador = jug_buscarJugadorPorId(pArrayListJugador,
					auxIdSeleccionado);
			if (pAuxJugador == NULL) {
				puts("\nNo se encontro el id");
			}
		}

		jug_getSIdSeleccion(pAuxJugador, &auxIdSeleccion);

		if (menu_opciones("\n\nEsta seguro de que desea eliminar el jugador? ",
				"\n(1. SI | 2. NO)", "\nOpcion invalida.", 1, 2) == 1) {
			indiceJugador = ll_indexOf(pArrayListJugador, pAuxJugador);
			if (ll_remove(pArrayListJugador, indiceJugador) == 0) {
				selec_eliminarUnConvocado(pArrayListSeleccion, auxIdSeleccion);
				jug_delete(pAuxJugador);
				rtn = 1;
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
 * \return int retorna 1 en caso de exito y 0 en caso de error
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

		while (pAuxJugador == NULL) {
			utn_getNumero(&auxIdSeleccionado, "\nIngrese el id de jugador: ",
					"\nError. Ingrese el id de jugador: ", 1, 999, 9999);
			pAuxJugador = jug_buscarJugadorPorId(pArrayListJugador,
					auxIdSeleccionado);
			if (pAuxJugador == NULL) {
				puts("\nNo se encontro el id");
			}
		}

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
						rtn = 1;
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
						rtn = 1;
					} else {
						puts("\n ---- Modificacion cancelada ---- \n");
					}
					break;
				case 3:
					menu_mostrarPosiciones();
					utn_getString("\nIngrese la posicion: ",
							"\nError. Nombre invalido. ", 9999, POSICION_CHARS,
							auxJugador.posicion);
					if (validarPosicionJugador(auxJugador.posicion) != -1) {
						if (menu_opciones("\nEsta seguro que desea modificar?",
								"(1. SI | 2. NO )",
								"\nOpcion invalida. Ingrese la opcion: ", 1, 2)
								== 1) {
							jug_setPosicion(pAuxJugador, auxJugador.posicion);
							puts("\n ---- Modificacion exitosa ---- \n");
							rtn = 1;
						} else {
							puts("\n ---- Modificacion cancelada ---- \n");
						}
					} else {
						puts("\nPosicion invalida");
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
						rtn = 1;
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

/** \brief Guarda los datos de los jugadores en el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoBinario(char *path,
		LinkedList *pArrayListJugador) {
	int rtn = 0;
	Jugador *pJugador = NULL;
	FILE *pFile;
	int tamArray;

	if (path != NULL && pArrayListJugador != NULL) {
		pFile = fopen(path, "wb");

		if (pFile != NULL) {
			tamArray = ll_len(pArrayListJugador);

			for (int i = 0; i < tamArray; i++) {
				pJugador = (Jugador*) ll_get(pArrayListJugador, i);

				if (pJugador != NULL) {
					if (fwrite(pJugador, sizeof(Jugador), 1, pFile) != 1) {
						puts("\nError al guardar el archivo");
						jug_delete(pJugador);
						pJugador = NULL;
						break;
					}
				} else {
					rtn = 1;
				}
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
		if (selec_buscarSeleccionPorId(pArrayListSeleccion,
				auxIdSeleccion) == NULL) {
			puts("\n  -------- ERROR. LA SELECCION NO EXISTE. ------------ \n");
		} else {
			pAuxSeleccion = selec_buscarSeleccionPorId(pArrayListSeleccion,
					auxIdSeleccion);

			selec_getConvocados(pAuxSeleccion, &auxCantidadConvocados);
			selec_getId(pAuxSeleccion, &auxIdSeleccion);
			if (auxCantidadConvocados == MAX_JUGADORES) {
				puts(
						"\n  -------- ERROR. CANTIDAD DE CONVOCADOS ALCANZADA EN ESTA SELECCION. ------------ \n");
			} else {
				auxCantidadConvocados++;
				selec_setConvocados(pAuxSeleccion, auxCantidadConvocados);
				rtn = auxIdSeleccion;
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

/** \brief Guarda los datos de los jugadores en el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoTexto(char *path,
		LinkedList *pArrayListJugador) {
	int rtn = 0;
	FILE *pFile;
	int tamArray;
	int i;
	Jugador auxJugador;
	Jugador *pJugador = NULL;
	if (path != NULL && pArrayListJugador != NULL) {
		pFile = fopen(path, "w");
		if (pFile != NULL) {
			fprintf(pFile,
					"id,nombreCompleto,edad,posicion,nacionalidad,idSelecion\n");
			tamArray = ll_len(pArrayListJugador);
			for (i = 0; i < tamArray; i++) {
				pJugador = (Jugador*) ll_get(pArrayListJugador, i);
				if (pJugador != NULL) {
					if (!(jug_getId(pJugador, &auxJugador.id)
							&& jug_getNombreCompleto(pJugador,
									auxJugador.nombreCompleto)
							&& jug_getPosicion(pJugador, auxJugador.posicion)
							&& jug_getEdad(pJugador, &auxJugador.edad)
							&& jug_getNacionalidad(pJugador,
									auxJugador.nacionalidad)
							&& jug_getSIdSeleccion(pJugador,
									&auxJugador.idSeleccion))) {
						pJugador = NULL;
						jug_delete(pJugador);
						printf(
								"\nOcurrio un error el guardar daots en el archivo");
						break;
					} else {
						fprintf(pFile, "%d,%s,%d,%s,%s,%d\n", auxJugador.id,
								auxJugador.nombreCompleto, auxJugador.edad,
								auxJugador.posicion, auxJugador.nacionalidad,
								auxJugador.idSeleccion);
						rtn = 1;
					}
				}
			}
		}
	}
	fclose(pFile);
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
	int rtn = 0;
	FILE *pFile;
	int tamArray;
	int i;
	Seleccion auxSeleccion;
	Seleccion *pSeleccion = NULL;
	if (path != NULL && pArrayListSeleccion != NULL) {
		pFile = fopen(path, "w");
		if (pFile != NULL) {
			fprintf(pFile, "id,pais,confederacion,convocados\n");
			tamArray = ll_len(pArrayListSeleccion);
			for (i = 0; i < tamArray; i++) {
				pSeleccion = (Seleccion*) ll_get(pArrayListSeleccion, i);
				if (pSeleccion != NULL) {
					if (!(selec_getId(pSeleccion, &auxSeleccion.id)
							&& selec_getPais(pSeleccion, auxSeleccion.pais)
							&& selec_getConfederacion(pSeleccion,
									auxSeleccion.confederacion)
							&& selec_getConvocados(pSeleccion,
									&auxSeleccion.convocados))) {
						pSeleccion = NULL;
						selec_delete(pSeleccion);
						printf(
								"\nOcurrio un error el guardar daots en el archivo");
						break;
					} else {
						fprintf(pFile, "%d,%s,%s,%d\n", auxSeleccion.id,
								auxSeleccion.pais, auxSeleccion.confederacion,
								auxSeleccion.convocados);
						rtn = 1;
					}
				}
			}
		}
	}
	fclose(pFile);
	return rtn;
}
