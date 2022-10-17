/*
 ============================================================================
 Name        : TP_2.c
 Author      : Julián Schmidt
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Inputs.h"
#include "eJugador.h"
#include "Menu.h"
#include "eConfederacion.h"

int main(void) {
	setbuf(stdout, NULL);
	eJugador jugadores[MAX_JUGADORES];
	eConfederacion confederaciones[MAX_CONFEDERACIONES] = { { 100, "CONMEBOL",
			"SUDAMERICA", 1916, -1 }, { 101, "UEFA", "EUROPA", 1954, -1 }, {
			102, "AFC", "ASIA", 1954, -1 }, { 103, "CAF", "AFRICA", 1957, -1 },
			{ 104, "CONCACAF", "NORTE Y CENTRO AMERICA", 1961, -1 }, { 105,
					"OFC", "OCEANIA", 1966, -1 } };
	int opcionSeleccionada;
	int idJugador;
	int auxIdConfederacion;
	eJugador nuevoJugador;

	if (!abm_inicializarJugador(jugadores, MAX_JUGADORES)) {
		puts(
				" ----------- OCURRIO UN ERROR AL INICIALIZAR JUGADORES ------------");
	}

	do {
		opcionSeleccionada = menu_opciones(
				"\n\n ----------- TRABAJO PRACTICO 2 --------------",
				"\n 1. ALTA DE JUGADOR"
						"\n 2. BAJA DE JUGADOR"
						"\n 3. MODIFICACION DE JUGADOR"
						"\n 4. INFORMES"
						"\n 5. SALIR", "\nError, opcion invalida.", 1, 5);

		switch (opcionSeleccionada) {
		case 1:
			utn_getString("\nIngrese el nombre del jugador: ",
					"\nError. Nombre invalido. Ingrese el nombre del jugador",
					9999,
					MAX_CHARS, nuevoJugador.nombre);

			utn_getString("\nIngrese la posicion del jugador: ",
					"\nError. Posicion invalida. Ingrese el nombre del jugador",
					9999,
					MAX_CHARS, nuevoJugador.posicion);

			utn_getNumeroShort(&nuevoJugador.numeroCamiseta,
					"\nIngrese el numero de camiseta: ",
					"Error. Ingrese el numero de camiseta: ", 1, 11, 9999);

			abm_mostrarTodosConfederacion(confederaciones, MAX_CONFEDERACIONES);
			utn_getNumero(&auxIdConfederacion,
					"\nIngrese el id de la confederacion: ",
					"\nError. El id seleccionado excede el limite.", 100, 9999,
					9999);
			while (abm_encontrarConfederacionPorId(confederaciones,
			MAX_CONFEDERACIONES, auxIdConfederacion) == -1) {
				puts("\nEl id ingresado no existe.");
				utn_getNumero(&auxIdConfederacion,
						"\nIngrese el id de la confederacion: ",
						"\nError. El id seleccionado excede el limite.", 100,
						9999, 9999);
			}
			nuevoJugador.idConfederacion = auxIdConfederacion;

			utn_getNumeroDecimal(&nuevoJugador.salario,
					"\nIngrese el salario del jugador: ",
					"\nError. Salario invalido, ingrese el salario del jugador: ",
					1, 99999999, 9999);

			utn_getNumeroShort(&nuevoJugador.aniosContrato,
					"\nIngrese los anios de contrato: ",
					"Error. Ingrese los anios de contrato", 1, 99, 9999);

			idJugador = abm_obtenerIdJugador();
			abm_altaJugador(jugadores, MAX_CHARS, idJugador, nuevoJugador);
			break;
		case 2:
			abm_listadoBajaJugador(jugadores, MAX_JUGADORES, confederaciones,
			MAX_CONFEDERACIONES);
			break;
		case 3:
			break;
		case 4:
			abm_mostrarTodosJugador(jugadores, MAX_JUGADORES, confederaciones,
			MAX_CONFEDERACIONES);
			break;
		case 5:
			break;
		}

	} while (opcionSeleccionada != 5);

	return EXIT_SUCCESS;
}
