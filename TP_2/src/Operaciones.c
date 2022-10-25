/*
 * Operaciones.c
 *
 *  Created on: 25 Oct 2022
 *      Author: Julian
 */

#include "Operaciones.h"

float op_calcularPorcentaje(float valor, float total) {
	float resultado;
	resultado = (float) (valor * 100) / total;

	return resultado;
}
