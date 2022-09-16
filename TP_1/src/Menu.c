/*
 * Menu.c
 *
 *  Created on: 16 Sept 2022
 *      Author: Julian
 */

#include "Menu.h"

void MenuCostos(float *costoHospedaje, float *costoComida,
		float *costoTransporte) {
	char opcionSeleccionada;

	do {
		InterfazSubmenuCostos(&*costoHospedaje, &*costoComida,
				&*costoTransporte);
		opcionSeleccionada = getChar("\n Ingrese la opción: ");
		switch (opcionSeleccionada) {
		case 'a':
			getFloat("Ingrese el costo de hospedaje: ",
					"\n Costo ingresado invalido \n\n", &*costoHospedaje,
					1000000, 1);
			break;
		case 'b':
			getFloat("Ingrese el costo de comida: ",
					"\n Costo ingresado invalido \n\n", &*costoComida, 1000000,
					1);
			break;
		case 'c':
			getFloat("Ingrese el costo de transporte: ",
					"\n Costo ingresado invalido \n\n", &*costoTransporte,
					1000000, 1);
			break;
		}
	} while (opcionSeleccionada != 's');
}

int MenuSeleccionPosicion(int *contadorArqueros, int *contadorDefensores,
		int *contadorDelanteros, int *contadorMediocampistas) {
	int opcionSeleccionada;

	int retorno = 0;

	InterfazSubmenuPosiciones(&*contadorArqueros, &*contadorDefensores,
			&*contadorDelanteros, &*contadorMediocampistas);

	getIntReintentos("\nIngrese la posicion: ", 9999, 1, 4,
			"Posicion Invalida. Ingrese la posicion nuevamente: ",
			&opcionSeleccionada);

	switch (opcionSeleccionada) {
	case 1:
		if (CANTIDAD_MAX_ARQUEROS > *contadorArqueros) {
			*contadorArqueros = *contadorArqueros + 1;
			retorno = 1;
		}
		break;
	case 2:
		if (CANTIDAD_MAX_DEFENSORES_MEDIOCAMPISTAS > *contadorDefensores) {
			*contadorDefensores = *contadorDefensores + 1;
			retorno = 1;
		}
		break;
	case 3:
		if (CANTIDAD_MAX_DEFENSORES_MEDIOCAMPISTAS > *contadorMediocampistas) {
			*contadorMediocampistas = *contadorMediocampistas + 1;
			retorno = 1;
		}
		break;
	case 4:
		if (CANTIDAD_MAX_DELANTEROS > *contadorDelanteros) {
			*contadorDelanteros = *contadorDelanteros + 1;
			retorno = 1;
		}
		break;
	}
	return retorno;
}

void MenuSeleccionConfederacion(int *contadorAFC, int *contadorCAF,
		int *contadorCONCACAF, int *contadorCONMEBOL, int *contadorUEFA,
		int *contadorOFC) {
	int opcionSeleccionada;
	InterfazSubmenuConfederaciones();
	getIntReintentos("\nIngrese la confederacion: ", 9999, 1, 6,
			"\nConfederacion Invalida. Ingrese la confederacion nuevamente: ",
			&opcionSeleccionada);

	switch (opcionSeleccionada) {
	case 1:
		*contadorAFC = *contadorAFC + 1;
		break;
	case 2:
		*contadorCAF = *contadorCAF + 1;
		break;
	case 3:
		*contadorCONCACAF = *contadorCONCACAF + 1;
		break;
	case 4:
		*contadorCONMEBOL = *contadorCONMEBOL + 1;
		break;
	case 5:
		*contadorUEFA = *contadorUEFA + 1;
		break;
	case 6:
		*contadorOFC = *contadorOFC + 1;
		break;
	}
}

