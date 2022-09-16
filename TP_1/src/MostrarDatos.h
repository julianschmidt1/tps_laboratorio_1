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

/// \brief Se muestra la interfaz del menu principal con las opciones disponibles
///
/// \param costoHospedaje Puntero a la variable de costo de hospedaje
/// \param costoComida Puntero a la variable de costo de comida
/// \param costoTransporte Puntero a la variable de costo de transporte
/// \param contadorArqueros Puntero a la variable contador de arqueros
/// \param contadorDefensores Puntero a la variable contador de defensores
/// \param contadorDelanteros Puntero a la variable contador de Delanteros
/// \param contadorMediocampistas Puntero a la variable contador de mediocampistas
void InterfazMenuPrincipal(float *costoHospedaje, float *costoComida,
		float *costoTransporte, int *contadorArqueros, int *contadorDefensores,
		int *contadorDelanteros, int *contadorMediocampistas);

/// \brief Se muestra la interfaz del ingreso de costos con las opciones disponibles
///
/// \param costoHospedaje Puntero a la variable de costoHospedaje
/// \param costoComida Puntero a la variable de costoComida
/// \param costoTransporte Puntero a la variable de costoTransporte
void InterfazSubmenuCostos(float *costoHospedaje, float *costoComida,
		float *costoTransporte);

/// \brief Se muestra la interfaz del ingreso de posiciones con las opciones disponibles
///
/// \param cantidadArqueros Puntero a la variable contadorArqueros
/// \param cantidadDefensores Puntero a la variable de contadorDefensores
/// \param cantidadMediocampistas Puntero a la variable de cantidadMediocampistas
/// \param cantidadDelanteros Puntero a la variable de cantidadDelanteros
void InterfazSubmenuPosiciones(int *cantidadArqueros, int *cantidadDefensores,
		int *cantidadMediocampistas, int *cantidadDelanteros);

/// \brief Se muestra menu con opciones de confederaciones
///
void InterfazSubmenuConfederaciones();

/// \brief Interfaz que muestra los resultados de los calculos
///
/// \param porcentajeUEFA Puntero a la variable porcentajeUEFA
/// \param porcentajeCONMEBOL Puntero a la variable porcentajeCONMEBOL
/// \param porcentajeCONCACAF Puntero a la variable porcentajeCONCACAF
/// \param porcentajeAFC Puntero a la variable porcentajeAFC
/// \param porcentajeOFC Puntero a la variable porcentajeOFC
/// \param porcentajeCAF Puntero a la variable porcentajeCAF
/// \param costoTotalMantenimiento Puntero a la variable costoTotalMantenimiento
/// \param valorAIncrementar Puntero a la variable valorAIncrementar
/// \param valorIncrementado Puntero a la variable valorIncrementado
void InterfazResultados(float *porcentajeUEFA, float *porcentajeCONMEBOL,
		float *porcentajeCONCACAF, float *porcentajeAFC, float *porcentajeOFC,
		float *porcentajeCAF, float *costoTotalMantenimiento,
		float *valorAIncrementar, float *valorIncrementado);

#endif /* MOSTRARDATOS_H_ */
