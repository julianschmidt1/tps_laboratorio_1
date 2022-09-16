/*
 * Inputs.h
 *
 *  Created on: 16 Sept 2022
 *      Author: Julian
 */

#ifndef INPUTS_H_
#define INPUTS_H_

#include <stdio.h>
#include <stdlib.h>

/// \brief Funcion validada utiliza para solicitar y almacenar un numero flotante
///
/// \param mensaje Texto a mostrar
/// \param mensajeError Texto a mostrar ante un error
/// \param pValor puntero sobre el cual se pretende almacenar un valor
/// \param max valor maximo permitido
/// \param min valor minimo permitido
/// \return Retorna 0 si algo salio mal, y 1 si guardo el valor correctamente
int getFloat(char mensaje[], char mensajeError[], float *pValor, float max,
		float min);

/// \brief Funcion validada utiliza para solicitar y almacenar un numero entero
///
/// \param mensaje Texto a mostrar
/// \param mensajeError Texto a mostrar ante un error
/// \param pValor puntero sobre el cual se pretende almacenar un valor
/// \param max valor maximo permitido
/// \param min valor minimo permitido
/// \return Retorna 0 si algo salio mal, y 1 si guardo el valor correctamente
int getInt(char mensaje[], char mensajeError[], int *pValor, int max, int min);

int getIntReintentos(char mensaje[], int reintentos, int minimo, int maximo,
		char mensajeError[], int *pNumeroIngresado);

char getChar(char *mensaje);

#endif /* INPUTS_H_ */
