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

/// \brief Se muestra un menu que permite la seleccion del gasto en cuestion
///
/// \param costoHospedaje Puntero al valor almacenado
/// \param costoComida Puntero al valor almacenado
/// \param costoTransporte Puntero al valor almacenado
void MenuCostos(float *costoHospedaje, float *costoComida,
		float *costoTransporte);

/// \brief Se muestra un menu que permite la seleccion de posiciones a elegir
///
/// \param contadorArqueros puntero a contador de arqueros
/// \param contadorDefensores puntero a contador de defensores
/// \param contadorDelanteros puntero a contador de delanteros
/// \param contadorMediocampistas puntero a contador de mediocampistas
/// \return retorna 0 si no pudo agregar la posicion o 1 si pudo
int MenuSeleccionPosicion(int *contadorArqueros, int *contadorDefensores,
		int *contadorDelanteros, int *contadorMediocampistas);

/// \brief Se muestra un menu que permite la seleccion de confederaciones
///
/// \param contadorAFC puntero a contadorAFC
/// \param contadorCAF puntero a contadorCAF
/// \param contadorCONCACAF puntero a contadorCONCACAF
/// \param contadorCONMEBOL puntero a contadorCONMEBOL
/// \param contadorUEFA puntero a contadorUEFA
/// \param contadorOFC puntero a contadorOFC
void MenuSeleccionConfederacion(int *contadorAFC, int *contadorCAF,
		int *contadorCONCACAF, int *contadorCONMEBOL, int *contadorUEFA,
		int *contadorOFC);

#endif /* MENU_H_ */
