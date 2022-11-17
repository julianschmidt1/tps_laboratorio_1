/*
 * Menu.c
 *
 *  Created on: 15 Oct 2022
 *      Author: Julian
 */

#include "Menu.h"

int menu_opciones(char *titulo, char *opciones, char *mensajeError, int min,
		int max) {
	int rtn = 0;
	int opcion;

	if (titulo != NULL && opciones != NULL && min > 0 && min < max) {
		printf("%s", titulo);
		printf("%s", opciones);

		if (utn_getNumero(&opcion, "\nIngrese la opcion: ", mensajeError, min,
				max, 1)) {
			rtn = opcion;
		}
	}

	return rtn;
}

int menu_salir(char *titulo, char *mensajeError, int *valorConfirmacion) {
	int rtn = 0;
	int auxConfirmacion;

	if (titulo != NULL && mensajeError != NULL) {
		utn_getNumero(&auxConfirmacion, titulo, mensajeError, 0, 1, 1);
		if (auxConfirmacion == 0 || auxConfirmacion == 1) {
			*valorConfirmacion = auxConfirmacion;
			rtn = 1;
		} else {
			rtn = -1;
		}

	}

	return rtn;
}

void menu_mostrarPosiciones(void) {
	puts(
			"\n POSICIONES:\n- ARQUERO\n- DEFENSOR\n- MEDIOCAMPISTA\n- DELANTERO\n\n");
}

