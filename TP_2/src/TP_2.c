/*
 ============================================================================
 Name        : TP_2.c
 Author      : Julián Schmidt
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Inputs.h"
#include "eJugador.h"
#include "Menu.h"
#include "eConfederacion.h"
#include "rInformes.h"

int main(void) {
	setbuf(stdout, NULL);
	eJugador jugadores[MAX_JUGADORES];
	eConfederacion confederaciones[MAX_CONFEDERACIONES] = { { 100, "CONMEBOL",
			"SUDAMERICA", 1916, -1 }, { 101, "UEFA", "EUROPA", 1954, -1 }, {
			102, "AFC", "ASIA", 1954, -1 }, { 103, "CAF", "AFRICA", 1957, -1 },
			{ 104, "CONCACAF", "NORTE Y CENTRO AMERICA", 1961, -1 }, { 105,
					"OFC", "OCEANIA", 1966, -1 } };
	int opcionSeleccionada;
	int idJugador;
	int auxIdConfederacion;
	eJugador nuevoJugador;
	int confirmarSalida;
	int contadorAltas = 0;
	int opcionInformes;

	if (!abm_inicializarJugador(jugadores, MAX_JUGADORES)) {
		puts(
				" ----------- OCURRIO UN ERROR AL INICIALIZAR JUGADORES ------------");
	}

//	int OK = -1;
//	eJugador jugadores[15] = { { 1, "Emiliano Martinez", "ARQUERO", 1, 100,
//			100000, 4, OK },
//			{ 2, "Juan Musso", "ARQUERO", 12, 100, 80000, 2, OK }, { 3,
//					"Leo Messi", "DELANTERO", 10, 100, 80000, 4, OK }, { 4,
//					"Almirez Ali", "DELANTERO", 9, 100, 55000, 1, OK }, { 5,
//					"Harry Maguire", "DEFENSOR", 2, 101, 70000, 4, OK }, { 6,
//					"Eric Dier", "DEFENSOR", 3, 101, 60000, 2, OK }, { 7,
//					"Harry Kane", "DELANTERO", 10, 101, 3000, 2, OK }, { 8,
//					"Alfred Gomis", "ARQUERO", 1, 101, 9000, 1, OK },
//			{ 9, "Abdelkarim Hassan", "MEDIOCAMPISTA", 8, 101, 48000, 1, OK }, {
//					10, "Guillermo Ochoa", "ARQUERO", 1, 104, 90000, 4, OK }, {
//					11, "Tecatito", "DELANTERO", 11, 104, 100000, 3, OK }, { 12,
//					"Luis Romo", "MEDIOCAMPISTA", 7, 104, 100000, 2, OK }, { 13,
//					"Bamba Dieng ", "DELANTERO", 9, 103, 100000, 2, OK }, { 14,
//					"Demba Seck", "DELANTERO", 11, 103, 6000, 2, OK }, { 15,
//					"Tarek Salman", "DEFENSOR", 6, 102, 78000, 5, OK } };

	do {
		opcionSeleccionada = menu_opciones(
				"\n\n ----------- TRABAJO PRACTICO 2 --------------",
				"\n 1. ALTA DE JUGADOR"
						"\n 2. BAJA DE JUGADOR"
						"\n 3. MODIFICACION DE JUGADOR"
						"\n 4. INFORMES"
						"\n 5. SALIR", "\nError, opcion invalida.", 1, 5);

		for (int i = 0; i < MAX_JUGADORES; i++) {
			if (jugadores[i].isEmpty == OCUPADO) {
				contadorAltas++;
				break;
			}
		}

		switch (opcionSeleccionada) {
		case 1:

			utn_getString("\nIngrese el nombre del jugador: ",
					"\nError. Nombre invalido. Ingrese el nombre del jugador",
					9999,
					MAX_CHARS, nuevoJugador.nombre);

			while (validarPosicionJugador(nuevoJugador.posicion) != 1) {
				utn_getString("\nIngrese la posicion del jugador: ",
						"\nError. Posicion invalida. Ingrese el nombre del jugador",
						1,
						MAX_CHARS, nuevoJugador.posicion);
			}

			utn_getNumeroShort(&nuevoJugador.numeroCamiseta,
					"\nIngrese el numero de camiseta: ",
					"Error. Ingrese el numero de camiseta: ", 1, 11, 9999);

			abm_mostrarTodosConfederacion(confederaciones, MAX_CONFEDERACIONES);
			utn_getNumero(&auxIdConfederacion,
					"\nIngrese el id de la confederacion: ",
					"\nError. El id seleccionado excede el limite.", 100, 9999,
					9999);
			while (abm_encontrarConfederacionPorId(confederaciones,
			MAX_CONFEDERACIONES, auxIdConfederacion) == -1) {
				puts("\nEl id ingresado no existe.");
				utn_getNumero(&auxIdConfederacion,
						"\nIngrese el id de la confederacion: ",
						"\nError. El id seleccionado no es valido.", 100, 9999,
						9999);
			}
			nuevoJugador.idConfederacion = auxIdConfederacion;

			utn_getNumeroDecimal(&nuevoJugador.salario,
					"\nIngrese el salario del jugador: ",
					"\nError. Salario invalido, ingrese el salario del jugador: ",
					1, 99999999, 9999);

			utn_getNumeroShort(&nuevoJugador.aniosContrato,
					"\nIngrese los anios de contrato: ",
					"Error. Ingrese los anios de contrato", 1, 99, 9999);

			idJugador = abm_obtenerIdJugador();
			if (abm_altaJugador(jugadores, MAX_JUGADORES, idJugador,
					nuevoJugador)) {
				puts("\n\n ---- JUGADOR DADO DE ALTA EXITOSAMENTE ------");
			} else {
				puts(
						"\n\n ---- OCURRIO UN ERROR EN EL ALTA DEL JUGADOR  ---- ");
			}

			break;
		case 2:
			if (contadorAltas > 0) {
				if (abm_listadoBajaJugador(jugadores, MAX_JUGADORES,
						confederaciones,
						MAX_CONFEDERACIONES)) {
					puts("\n\n ---- JUGADOR DADO DE BAJA EXITOSAMENTE ------");
				} else {
					puts("\n\n ---- BAJA CANCELADA ------");
				}
			} else {
				puts(
						"\n---NO ES POSIBLE LISTAR USUARIOS SI NO FUERON PREVIAMENTE CARGADOS -----");
			}
			break;
		case 3:
			if (contadorAltas > 0) {
				if (abm_listadoModificacionJugador(jugadores, MAX_JUGADORES,
						confederaciones,
						MAX_CONFEDERACIONES)) {
					puts("\n\n ---- JUGADOR MODIFICADO EXITOSAMENTE ------");
				} else {
					puts("\n\n ---- MODIFICACION CANCELADA ------");
				}
			} else {
				puts(
						"\n---NO ES POSIBLE LISTAR USUARIOS SI NO FUERON PREVIAMENTE CARGADOS -----");
			}
			break;
		case 4:
			if (contadorAltas > 0) {
				do {

					opcionInformes =
							menu_opciones(
									"\n ---------- INFORMES ----------- \n",
									"\n1. Listado de jugadores ordenados alfabeticamente por nombre de confederacion y nombre de jugador."
											"\n2. Listado de confederaciones con sus jugadores."
											"\n3. Total y promedio de todos los salarios y cuantos jugadores cobran mas del salario promedio."
											"\n4. Informar la confederacion con mayor cantidad de años de contratos total."
											"\n5. Informar porcentaje de jugadores por cada confederacion."
											"\n6. Informar cual es la region con mas jugadores y el listado de los mismos"
											"\n7. Volver al menu principal",
									"\nError. Ingrese la opcion: ", 1, 7);

					switch (opcionInformes) {
					case 1:
						informe_ordenarNombreConfederacionJugador(jugadores,
						MAX_JUGADORES, confederaciones,
						MAX_CONFEDERACIONES);
						abm_mostrarTodosJugador(jugadores, MAX_JUGADORES,
								confederaciones, MAX_CONFEDERACIONES);
						break;
					case 2:
						informe_mostrarJugadoresDeConfederacion(confederaciones,
						MAX_CONFEDERACIONES, jugadores,
						MAX_JUGADORES);
						break;
					case 3:
						informe_mostrarTotalPromedioJugadores(jugadores,
						MAX_JUGADORES);
						break;
					case 4:
						informe_mostrarConfederacionMasAniosContrato(
								confederaciones, MAX_CONFEDERACIONES, jugadores,
								MAX_JUGADORES);
						break;
					case 5:
						informe_mostrarPorcentajeJugadoresConfederacion(
								confederaciones, MAX_CONFEDERACIONES, jugadores,
								MAX_JUGADORES);
						break;
					case 6:
						informe_mostrarRegionConMasJugadores(confederaciones,
						MAX_CONFEDERACIONES, jugadores, MAX_JUGADORES);
						break;
					case 7:
						puts("\nVolviendo al menu principal");
						break;
					}
				} while (opcionInformes != 7);

			} else {
				puts(
						"\n---NO ES POSIBLE LISTAR USUARIOS SI NO FUERON PREVIAMENTE CARGADOS -----");
			}
			break;
		case 5:
			if (menu_salir(
					"\nEsta seguro que desea salir del programa? (1. SI | 0. NO) \nIngrese la opcion: ",
					"\nError. Opcion ingresada invalida.", &confirmarSalida)
					== 1) {
				if (confirmarSalida == 1) {
					puts("\n GRACIAS POR USAR EL SISTEMA.");
				} else {
					puts("\n Volviendo al menu principal ...");
				}
			}

			break;
		}

	} while (opcionSeleccionada != 5 || !confirmarSalida);

	return EXIT_SUCCESS;
}
