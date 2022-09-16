/*
 * MostrarDatos.c
 *
 *  Created on: 16 Sept 2022
 *      Author: Julian
 */

#include "MostrarDatos.h"

void InterfazMenuPrincipal(float *costoHospedaje, float *costoComida,
		float *costoTransporte, int *contadorArqueros, int *contadorDefensores,
		int *contadorDelanteros, int *contadorMediocampistas) {
	printf("\n\n               Menú principal  \n");
	printf("1. Ingreso de los costos de Mantenimiento"
			"\n   	Costo de hospedaje -> $%.2f"
			"\n   	Costo de Comida -> $%.2f"
			"\n   	Costo de Transporte -> $%.2f", *costoHospedaje, *costoComida,
			*costoTransporte);
	printf("\n2. Carga de jugadores"
			"\n   	Arqueros -> %d"
			"\n   	Defensores -> %d"
			"\n   	Mediocampistas -> %d"
			"\n   	Delanteros -> %d", *contadorArqueros, *contadorDefensores,
			*contadorDelanteros, *contadorMediocampistas);
	printf("\n3. Realizar todos los calculos");
	printf("\n4. Informar todos los resultados");
	printf("\n5. Salir");
}

void InterfazSubmenuCostos(float *costoHospedaje, float *costoComida,
		float *costoTransporte) {
	printf("\n             Costos de mantenimiento \n"
			"\n a. Costo de hospedaje -> %.2f"
			"\n b. Costo de Comida -> %.2f"
			"\n c. Costo de Transporte -> %.2f"
			"\n s. Volver al menú principal", *costoHospedaje, *costoComida,
			*costoTransporte);
}

void InterfazSubmenuPosiciones(int *cantidadArqueros, int *cantidadDefensores,
		int *cantidadMediocampistas, int *cantidadDelanteros) {
	printf("\n            Seleccion de jugador \n"
			"\n 1. Arqueros -> %d"
			"\n 2. Defensores -> %d"
			"\n 3. Mediocampistas -> %d"
			"\n 4. Delanteros -> %d", *cantidadArqueros, *cantidadDefensores,
			*cantidadMediocampistas, *cantidadDelanteros);
}

void InterfazSubmenuConfederaciones() {
	printf("\n            Seleccion de confederacion \n"
			"\n 1. AFC (Asia)"
			"\n 2. CAF (Africa)"
			"\n 3. CONCACAF (zona del Norte)"
			"\n 4. CONMEBOL (Sudamerica)"
			"\n 5. UEFA (Europa)"
			"\n 6. OFC (Oceania)");
}

void InterfazResultados(float *porcentajeUEFA, float *porcentajeCONMEBOL,
		float *porcentajeCONCACAF, float *porcentajeAFC, float *porcentajeOFC,
		float *porcentajeCAF, float *costoTotalMantenimiento,
		float *valorAIncrementar, float *valorIncrementado) {
	printf("\n            Informar todos los Resultados \n"
			"\nPorcentaje UEFA %.2f"
			"\nPorcentaje CONMEBOL %.2f"
			"\nPorcentaje CONCACAF %.2f"
			"\nPorcentaje AFC %.2f"
			"\nPorcentaje OFC %.2f"
			"\nPorcentaje CAF %.2f", *porcentajeUEFA, *porcentajeCONMEBOL,
			*porcentajeCONCACAF, *porcentajeAFC, *porcentajeOFC,
			*porcentajeCAF);
	if (valorIncrementado != 0) {
		printf(
				"\n El costo de mantenimiento era de %.2f y recibio un aumento de $%.2f, su nuevo valor es de: $%.2f",
				*costoTotalMantenimiento, *valorAIncrementar,
				*valorIncrementado);
	} else {
		printf("\n Costo de mantenimiento: %.2f", *costoTotalMantenimiento);
	}
}
