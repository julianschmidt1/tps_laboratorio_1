/*
 * MostrarDatos.c
 *
 *  Created on: 16 Sept 2022
 *      Author: Julian
 */

#include "MostrarDatos.h"

void InterfazMenuPrincipal(float *costoHospedaje, float *costoComida,
		float *costoTransporte) {
	printf("                Menú principal  \n");
	printf("\n 1. Ingreso de los costos de Mantenimiento"
			"\n Costo de hospedaje -> %.2f"
			"\n Costo de Comida -> %.2f"
			"\n Costo de Transporte -> %.2f", *costoHospedaje, *costoComida,
			*costoTransporte);
	/*printf("\n 2. Ingresar precio de Vuelos");
	 printf("\n - Precio vuelo Aerolíneas Argentinas: %f", aerolineasPrice);
	 printf("\n - Precio vuelo latam: %f", latamPrice);
	 printf("\n 3. Calcular todos los costos");
	 printf("\n 4. Informar resultados");
	 printf("\n 5. Carga forzada");*/
	printf("\n 5. Salir");
}

