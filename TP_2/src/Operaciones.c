/*
 * Operaciones.c
 *
 *  Created on: 25 Oct 2022
 *      Author: Julian
 */

#include "Operaciones.h"

float op_calcularPorcentaje(float valor, float total) {
	float resultado;
	resultado = (valor * 100) / total;

	return resultado;
}

float op_sumar(float primerNumero, float segundoNumero) {
	float resultado;
	resultado = primerNumero + segundoNumero;
	return resultado;
}

float op_multiplicar(float primerNumero, float segundoNumero) {
	float resultado;
	resultado = primerNumero * segundoNumero;
	return resultado;
}

float op_dividir(float primerNumero, float segundoNumero) {
	float resultado;
	if (segundoNumero != 0) {
		resultado = primerNumero / segundoNumero;
	} else {
		resultado = 0;
	}
	return resultado;
}

