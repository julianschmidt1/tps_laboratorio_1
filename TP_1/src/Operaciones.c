/*
 * Operaciones.c
 *
 *  Created on: 16 Sept 2022
 *      Author: Julian
 */

#include "Operaciones.h"

float Sumar(float primerNumero, float segundoNumero) {
	float resultado;
	resultado = primerNumero + segundoNumero;
	return resultado;
}

float Restar(float primerNumero, float segundoNumero) {
	float resultado;
	resultado = primerNumero - segundoNumero;
	return resultado;
}

float Multiplicar(float primerNumero, float segundoNumero) {
	float resultado;
	resultado = primerNumero * segundoNumero;
	return resultado;
}

float Dividir(float primerNumero, float segundoNumero) {
	float resultado;
	if (segundoNumero != 0) {
		resultado = primerNumero / segundoNumero;
		return resultado;
	} else {
		return 0;
	}
}

float AplicarPorcentaje(float valor, float porcentaje) {
	float resultado;
	resultado = (valor * porcentaje) / 100;
	return resultado;
}

float CalcularPorcentaje(float valor, float total) {
	float resultado;
	resultado = (float) (valor * 100) / total;

	return resultado;
}
