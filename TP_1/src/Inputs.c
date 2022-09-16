/*
 * Inputs.c
 *
 *  Created on: 16 Sept 2022
 *      Author: Julian
 */

#include "Inputs.h"

int getFloat(char mensaje[], char mensajeError[], float *pValor, float max,
		float min) {
	int funcReturn = 0;
	int bufferFloat;
	int scanfReturn;
	if (mensaje != NULL && min < max && mensajeError != NULL && pValor != NULL) {
		printf("%s", mensaje);
		scanfReturn = scanf("%d", &bufferFloat);
	}

	if (scanfReturn != 1 || bufferFloat > max || bufferFloat < min) {
		printf("%s", mensajeError);
	} else {
		*pValor = bufferFloat;
		funcReturn = 1;
	}

	return funcReturn;
}

int getInt(char mensaje[], char mensajeError[], int *pValor, int max, int min) {
	int funcReturn = 0;
	int bufferInt;
	int scanfReturn;
	if (mensaje != NULL && min < max && mensajeError != NULL && pValor != NULL) {
		printf("%s", mensaje);
		scanfReturn = scanf("%d", &bufferInt);
	}

	if (scanfReturn != 1 || bufferInt > max || bufferInt < min) {
		printf("%s", mensajeError);
		//scanfReturn = scanf("%d", &bufferInt);
	} else {
		*pValor = bufferInt;
		funcReturn = 1;
	}

	return funcReturn;
}

