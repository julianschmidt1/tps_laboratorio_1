/*
 * Menu.h
 *
 *  Created on: 16 Sept 2022
 *      Author: Julian
 */

#ifndef MENU_H_
#define MENU_H_
#include <stdio.h>
#include <stdlib.h>
#include "MostrarDatos.h"
#include "Inputs.h"

#define CANTIDAD_MAX_ARQUEROS 2
#define CANTIDAD_MAX_DEFENSORES_MEDIOCAMPISTAS 8
#define CANTIDAD_MAX_DELANTEROS 4

void MenuCostos(float *costoHospedaje, float *costoComida,
		float *costoTransporte);

int MenuSeleccionPosicion(int *contadorArqueros, int *contadorDefensores,
		int *contadorDelanteros, int *contadorMediocampistas);

void MenuSeleccionConfederacion(int *contadorAFC, int *contadorCAF,
		int *contadorCONCACAF, int *contadorCONMEBOL, int *contadorUEFA,
		int *contadorOFC);

#endif /* MENU_H_ */
