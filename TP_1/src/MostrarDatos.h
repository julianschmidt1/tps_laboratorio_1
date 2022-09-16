/*
 * MostrarDatos.h
 *
 *  Created on: 16 Sept 2022
 *      Author: Julian
 */

#ifndef MOSTRARDATOS_H_
#define MOSTRARDATOS_H_

#include <stdio.h>
#include <stdlib.h>

void InterfazMenuPrincipal(float *costoHospedaje, float *costoComida,
		float *costoTransporte, int *contadorArqueros, int *contadorDefensores,
		int *contadorDelanteros, int *contadorMediocampistas);

void InterfazSubmenuCostos(float *costoHospedaje, float *costoComida,
		float *costoTransporte);

void InterfazSubmenuPosiciones(int *cantidadArqueros, int *cantidadDefensores,
		int *cantidadMediocampistas, int *cantidadDelanteros);

void InterfazSubmenuConfederaciones();

void InterfazResultados(float *porcentajeUEFA, float *porcentajeCONMEBOL,
		float *porcentajeCONCACAF, float *porcentajeAFC, float *porcentajeOFC,
		float *porcentajeCAF, float *costoTotalMantenimiento,
		float *valorAIncrementar, float *valorIncrementado);

#endif /* MOSTRARDATOS_H_ */
