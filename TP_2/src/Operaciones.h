/*
 * Operaciones.h
 *
 *  Created on: 25 Oct 2022
 *      Author: Julian
 */

#ifndef OPERACIONES_H_
#define OPERACIONES_H_

/// \brief Funcion utilizada para calcular el porcentaje sobre un total
///
/// \param valor valor a calcular
/// \param total total sobre el calculo
/// \return retorna el resultado del calculo
float op_calcularPorcentaje(float valor, float total);

/// \brief Funcion utilizada para sumar dos valores
///
/// \param primerNumero primer valor de tipo flotante
/// \param segundoNumero primer valor de tipo flotante
/// \return retorna la suma de ambos valores
float op_sumar(float primerNumero, float segundoNumero);

/// \brief Funcion utilizada para multiplicar dos valores
///
/// \param primerNumero primerNumero primer valor de tipo flotante
/// \param segundoNumero segundoNumero primer valor de tipo flotante
/// \return retorna la multiplicacion de ambos valores
float op_multiplicar(float primerNumero, float segundoNumero);

/// \brief Function utilizada para dividir dos valores
///
/// \param primerNumero primerNumero primer valor de tipo flotante
/// \param segundoNumero segundoNumero primer valor de tipo flotante
/// \return retorna la multiplicacion de ambos valores en caso de exito, 0 en caso de error
float op_dividir(float primerNumero, float segundoNumero);

#endif /* OPERACIONES_H_ */
