/*
 * Operaciones.h
 *
 *  Created on: 16 Sept 2022
 *      Author: Julian
 */

#ifndef OPERACIONES_H_
#define OPERACIONES_H_
#include <stdio.h>
#include <stdlib.h>

/// \brief Funcion que suma dos valores
///
/// \param primerNumero valor flotante
/// \param segundoNumero valor flotante
/// \return retorna resultado de suma de dos valores flotantes
float Sumar(float primerNumero, float segundoNumero);

/// \brief Funcion que resta dos valores
///
/// \param primerNumero valor flotante
/// \param segundoNumero valor flotante
/// \return retorna resultado de resta de dos valores flotantes
float Restar(float primerNumero, float segundoNumero);

/// \brief Funcion que multiplica dos valores
///
/// \param primerNumero valor flotante
/// \param segundoNumero valor flotante
/// \return retorna resultado de multiplicacion de dos valores flotantes
float Multiplicar(float primerNumero, float segundoNumero);

/// \brief Funcion que divide dos valores
///
/// \param primerNumero valor flotante
/// \param segundoNumero valor flotante
/// \return retorna resultado de division de dos valores flotantes
float Dividir(float primerNumero, float segundoNumero);

/// \brief Funcion que aplica un porcentaje sobre determinado valor
///
/// \param primerNumero valor flotante
/// \param segundoNumero porcentaje flotante
/// \return Retorna porcentaje aplicado sobre un numero flotante
float AplicarPorcentaje(float valor, float porcentaje);

/// \brief Funcion que calcula un porcentaje en base a un total
///
/// \param primerNumero valor flotante
/// \param segundoNumero valor total flotante
/// \return retorna porcentaje en base a total
float CalcularPorcentaje(float valor, float total);

#endif /* OPERACIONES_H_ */
