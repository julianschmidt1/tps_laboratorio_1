/*
 * eJugador.c
 *
 *  Created on: 15 Oct 2022
 *      Author: Julian
 */

#include "eJugador.h"

int abm_obtenerIdJugador(void) {
	static int idIncrementalJugador = 0;
	return idIncrementalJugador++;
}

int abm_inicializarJugador(eJugador *lista, int tam) {
	int i;
	int rtn = 0;

	if (lista != NULL && tam > 0) {
		rtn = 1;
		for (i = 0; i < tam; i++) {
			lista[i].isEmpty = LIBRE;
		}
	}

	return rtn;
}

int abm_obtenerIndiceLibreJugador(eJugador *lista, int tam) {
	int rtn = -1;

	if (lista != NULL && tam > 0) {
		for (int i = 0; i < tam; i++) {
			if (lista[i].isEmpty == LIBRE) {
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

int abm_encontrarJugadorPorId(eJugador *lista, int tam, int id) {
	int rtn = -1;
	int i;

	if (lista != NULL && tam > 0) {
		for (i = 0; i < tam; i++) {
			if (lista[i].id == id && lista[i].isEmpty == OCUPADO) {
				// Retorno indice de Jugador ocupado
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

void abm_mostrarUnJugador(eJugador Jugador, eConfederacion *confederaciones,
		int tamConfederaciones) {
	// Modificar esto para que muestre data generica siempre
	char auxNombreConfederacion[20];

	for (int i = 0; i < tamConfederaciones; i++) {
		if (confederaciones[i].id == Jugador.idConfederacion) {
			strcpy(auxNombreConfederacion, confederaciones[i].nombre);
			break;
		}

	}

	printf(
			"\n|  %d  |  %-20s | %-17s |       %hi       | %-14.2f  | %-12s  |        %-5hi      |",
			Jugador.id, Jugador.nombre, Jugador.posicion,
			Jugador.numeroCamiseta, Jugador.salario, auxNombreConfederacion,
			Jugador.aniosContrato);
}

int abm_mostrarTodosJugador(eJugador *lista, int tam,
		eConfederacion *confederaciones, int tamConfederaciones) {
	int i;
	int rtn = 0;
	int cantidad = 0;

	if (lista != NULL && tam > 0) {
		puts(
				"\n========================================================================================================================");
		puts(
				"| ID  |     NOMBRE            | POSICION          |  N° CAMISETA  | SUELDO          | CONFEDERACION | ANIOS de CONTRATO |");
		puts(
				"-------------------------------------------------------------------------------------------------------------------------");
		for (i = 0; i < tam; i++) {
			if (lista[i].isEmpty == OCUPADO) {
				abm_mostrarUnJugador(lista[i], confederaciones,
						tamConfederaciones);
				cantidad++;
			}
		}
		puts(
				"\n========================================================================================================================");
	}

	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}

int abm_altaJugador(eJugador *lista, int tam, int id, eJugador jugador) {
	int rtn = 0;

	int index = abm_obtenerIndiceLibreJugador(lista, tam);
//SI INDEX == -1 ARRAY LLENO
//SI INDEX != -1 TENGO EN INDEX POSICION DE ARRAY LIBRE
	if (index != -1 && lista != NULL) {

		jugador.id = id;
		jugador.isEmpty = OCUPADO;
		lista[index] = jugador;

		rtn = 1;
	}
	return rtn;
}

int abm_listadoBajaJugador(eJugador *lista, int tam,
		eConfederacion *confederaciones, int tamConfederacion) {
	int rtn = -1;
	int idJugador;
	int flag = 0;
	int confirmar = 0;

	if (abm_mostrarTodosJugador(lista, tam, confederaciones,
			tamConfederacion)) {
		flag = 1;
	}

	if (flag) {
		utn_getNumero(&idJugador, "\nIngrese ID a dar de baja",
				"Valor incorrecto", 0, tam, 9999);

		while (abm_encontrarJugadorPorId(lista, tam, idJugador) == -1) {
			puts("\n --- ID INEXISTENTE ---");

			utn_getNumero(&idJugador, "\nIngrese ID a dar de baja: ",
					"Valor incorrecto", 0, tam, 99999);
		}

		printf("\nUsuario a dar de baja: ");
		abm_mostrarUnJugador(
				lista[abm_encontrarJugadorPorId(lista, tam, idJugador)],
				confederaciones, tamConfederacion);
		utn_getNumero(&confirmar,
				"\nEsta seguro que desea dar de baja? (1. SI - 0. NO)",
				"Opcion incorrecta", 0, 1, 9999);
		if (confirmar) {
			abm_bajaJugador(lista, tam, idJugador);
		}
	}

	return rtn;
}

int abm_bajaJugador(eJugador *lista, int tam, int id) {
	int rtn = 0;
	int index;

	index = abm_encontrarJugadorPorId(lista, tam, id);
	if (index != -1) {
		lista[index].isEmpty = BAJA;
		//printf("\n ---- Usuario: %s %s dado de baja exitosamente ---- \n",
		//	lista[index].name, lista[index].lastName);
		rtn = 1;
	}

	return rtn;
}

eJugador abm_modificacionJugador(eJugador Jugador) {
	eJugador auxiliar = Jugador;
	/*
	 utn_getString("Nuevo nombre: ", "Error, de nuevo", 9999, MAX_CHARS,
	 auxiliar.name);
	 utn_getString("Nuevo apellido: ", "Error, de nuevo", 9999, MAX_CHARS,
	 auxiliar.lastName);
	 */
	return auxiliar;
}

int abm_listadoModificacionJugador(eJugador *lista, int tam,
		eConfederacion *confederaciones, int tamConfederaciones) {
	int rtn = 0;
	int idJugador;
	int index;
	int flag = 0;
	eJugador auxiliar;
	int confirmar = 0;

	if (abm_mostrarTodosJugador(lista, tam, confederaciones,
			tamConfederaciones)) {
		flag = 1;
	}

	if (flag) {
		utn_getNumero(&idJugador, "\nIngrese ID a modificar: ",
				"Valor incorrecto", 0, tam, 99999);

		while (abm_encontrarJugadorPorId(lista, tam, idJugador) == -1) {
			puts("NO EXISTE ID.");

			utn_getNumero(&idJugador, "\nIngrese ID a modificar: ",
					"Valor incorrecto", 0, tam, 99999);
		}

		index = abm_encontrarJugadorPorId(lista, tam, idJugador);
		auxiliar = abm_modificacionJugador(lista[index]);

		printf("\nUsuario a modificar: ");
		abm_mostrarUnJugador(lista[index], confederaciones, tamConfederaciones);

		utn_getNumero(&confirmar,
				"\nEsta seguro que modificar el usuario? (1. SI - 0. NO)",
				"Opcion incorrecta", 0, 1, 9999);
		if (confirmar) {
			lista[index] = auxiliar;
			rtn = 1;
		}
	}

	return rtn;
}
