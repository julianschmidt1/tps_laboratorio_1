/*
 ============================================================================
 Name        : TP_1.c
 Author      : Julián Schmidt
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Inputs.h"
#include "MostrarDatos.h"

int main(void) {
	setbuf(stdout, NULL);
	float costoHospedaje = 0;
	float costoComida = 0;
	float costoTransporte = 0;

	int opcionNumericaSeleccionada;

	do {
		InterfazMenuPrincipal(&costoHospedaje, &costoComida, &costoTransporte);
		getInt("\nIngrese la opcion: ",
				"\n -- El numero ingresado no es valido -- \n",
				&opcionNumericaSeleccionada, 5, 1);

		switch (opcionNumericaSeleccionada) {
		case 1:
			puts("opc 1 xd");
			break;
		case 5:
			puts("No re vimo");
			break;
		}
	} while (opcionNumericaSeleccionada != 5);

	return EXIT_SUCCESS;
}
