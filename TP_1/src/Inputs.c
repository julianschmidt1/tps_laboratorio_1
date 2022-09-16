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

int getIntReintentos(char mensaje[], int reintentos, int minimo, int maximo,
		char mensajeError[], int *pNumeroIngresado) {
	int retorno = -1;
	int auxInt;
	int retornoScanf;
	if (mensaje != NULL && minimo < maximo && mensajeError != NULL
			&& pNumeroIngresado != NULL && reintentos > 0) {
		printf("%s", mensaje);
		retornoScanf = scanf("%d", &auxInt);

		do {
			if (retornoScanf != 1 || auxInt > maximo || auxInt < minimo) {
				printf("%s", mensajeError);
				// Limpio buffer porque si el usuario es muy cómico y pone un char me chinga el while
				fflush(stdin);
				retornoScanf = scanf("%d", &auxInt);
				reintentos--;
			} else {
				reintentos = 0;
				*pNumeroIngresado = auxInt;
				retorno = 0;
			}
		} while (reintentos > 0);
	}
	return retorno;
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
	} else {
		*pValor = bufferInt;
		funcReturn = 1;
	}

	return funcReturn;
}

char getChar(char *mensaje) {
	char opcion;
	printf("%s", mensaje);
	fflush(stdin);
	scanf("%c", &opcion);
	fflush(stdin);
	return opcion;
}

