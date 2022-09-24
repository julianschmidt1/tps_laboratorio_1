/*
 ============================================================================
 Name        : TP_1.c
 Author      : Julián Schmidt
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Inputs.h"
#include "MostrarDatos.h"
#include "Menu.h"
#include "Operaciones.h"

int main(void) {
	setbuf(stdout, NULL);
	float costoHospedaje = 0;
	float costoComida = 0;
	float costoTransporte = 0;
	float costoTotalMantenimiento = 0;
	float valorAIncrementar = 0;
	float valorIncrementado = 0;

	int contadorArqueros = 1;
	int contadorDefensores = 0;
	int contadorMediocampistas = 0;
	int contadorDelanteros = 0;

	int contadorAFC = 2;
	int contadorCAF = 2;
	int contadorCONCACAF = 2;
	int contadorCONMEBOL = 2;
	int contadorOFC = 2;
	int contadorUEFA = 12;

	float porcentajeAFC = 0;
	float porcentajeCAF = 0;
	float porcentajeCONCACAF = 0;
	float porcentajeCONMEBOL = 0;
	float porcentajeUEFA = 0;
	float porcentajeOFC = 0;

	int totalJugadores = 0;

	int numeroCamiseta = 0;

	int opcionNumericaSeleccionada;

	int flagCalculoRealizado = 0;

	do {
		InterfazMenuPrincipal(&costoHospedaje, &costoComida, &costoTransporte,
				&contadorArqueros, &contadorDefensores, &contadorDelanteros,
				&contadorMediocampistas);
		getInt("\nIngrese la opcion: ",
				"\n -- El numero ingresado no es valido -- \n",
				&opcionNumericaSeleccionada, 5, 1);

		switch (opcionNumericaSeleccionada) {
		case 1:
			MenuCostos(&costoHospedaje, &costoComida, &costoTransporte);
			break;
		case 2:
			getIntReintentos("\nIngrese el numero de camiseta: ", 9999, 1, 11,
					"\nNumero de camiseta invalido. \nIngrese el numero de camiseta: ",
					&numeroCamiseta);

			if (MenuSeleccionPosicion(&contadorArqueros, &contadorDefensores,
					&contadorDelanteros, &contadorMediocampistas)) {
				MenuSeleccionConfederacion(&contadorAFC, &contadorCAF,
						&contadorCONCACAF, &contadorCONMEBOL, &contadorUEFA,
						&contadorOFC);
			} else {
				puts(
						"\n\n *-**-**-* LA POSICION SELECCIONADA ALCANZO LA MAXIMA CANTIDAD DE JUGADORES. *-**-*\n"
								"Retornando al menú principal...");
				break;
			}
			break;
		case 3:
			if (costoHospedaje && costoComida && costoTransporte
					&& numeroCamiseta) {
				flagCalculoRealizado = 1;
				totalJugadores = contadorAFC + contadorCAF + contadorCONCACAF
						+ contadorCONMEBOL + contadorOFC + contadorUEFA;
				porcentajeAFC = CalcularPorcentaje(contadorAFC, totalJugadores);
				porcentajeCAF = CalcularPorcentaje(contadorCAF, totalJugadores);
				porcentajeCONCACAF = CalcularPorcentaje(contadorCONCACAF,
						totalJugadores);
				porcentajeCONMEBOL = CalcularPorcentaje(contadorCONMEBOL,
						totalJugadores);
				porcentajeOFC = CalcularPorcentaje(contadorOFC, totalJugadores);
				porcentajeUEFA = CalcularPorcentaje(contadorUEFA,
						totalJugadores);
				;

				costoTotalMantenimiento = Sumar(costoComida,
						Sumar(costoHospedaje, costoTransporte));

				if (porcentajeUEFA > 50) {
					valorAIncrementar = AplicarPorcentaje(
							costoTotalMantenimiento, 35);
					valorIncrementado = Sumar(costoTotalMantenimiento,
							valorAIncrementar);
				}
				puts("\n\n *-**-**-* CALCULOS REALIZADOS EXITOSAMENTE. *-**-*");
			} else {
				puts(
						"\n\n *-**-**-* ES NECESARIO INGRESAR TODOS LOS VALORES ANTES DE CALCULARLOS. *-**-*");
			}
			break;
		case 4:
			if (flagCalculoRealizado) {

				InterfazResultados(&porcentajeUEFA, &porcentajeCONMEBOL,
						&porcentajeCONCACAF, &porcentajeAFC, &porcentajeOFC,
						&porcentajeCAF, &costoTotalMantenimiento,
						&valorAIncrementar, &valorIncrementado);
			} else {
				puts(
						"\n\n *-**-**-* ES NECESARIO CALCULAR LOS RESULTADOS ANTES DE MOSTRARLOS. *-**-*");
			}
			break;
		case 5:
			puts("Cerrando sesión");
			break;
		}
	} while (opcionNumericaSeleccionada != 5);

	return EXIT_SUCCESS;
}
