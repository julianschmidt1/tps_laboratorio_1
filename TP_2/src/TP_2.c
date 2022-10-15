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

int main(void) {
	setbuf(stdout, NULL);
	eJugador jugadores[MAX_JUGADORES];
	int opcionSeleccionada;
	int idJugador;

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
			abm_cargaJugador(&nuevoJugador);
			idJugador = abm_obtenerIdJugador();
			abm_altaJugador(jugadores, MAX_CHARS, idJugador, nuevoJugador);
			break;
		case 2:
			abm_listadoBajaJugador(jugadores, MAX_JUGADORES);
			break;
		case 3:
			break;
		case 4:
			abm_mostrarTodosJugador(jugadores, MAX_JUGADORES);
			break;
		case 5:
			break;
		}

	} while (opcionSeleccionada != 5);

	return EXIT_SUCCESS;
}
