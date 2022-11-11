#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "menu.h"

int main() {
	setbuf(stdout, NULL);
	int menuPrincipal;
	int menuListados;
	int menuConvocatoria;
	LinkedList *listaJugadores = ll_newLinkedList();
	LinkedList *listaSelecciones = ll_newLinkedList();
	int validaciones = 0;
	int auxIdJugador;
	Jugador *pAuxJugador;
	int auxIdSeleccion;

	do {

		menuPrincipal = menu_opciones(
				"\n\n ------- TRABAJO PRACTICO 3  ------- \n",
				"\n1. CARGA DE ARCHIVOS"
						"\n2. ALTA DE JUGADOR"
						"\n3. MODIFICACION DE JUGADOR"
						"\n4. BAJA DE JUGADOR"
						"\n5. LISTADOS"
						"\n6. CONVOCAR JUGADORES"
						"\n7. ORDENAR Y LISTAR"
						"\n8. GENERAR ARCHIVO BINARIO"
						"\n9. CARGAR ARCHIVO BINARIO"
						"\n10. GUARDAR ARCHIVOS .CSV"
						"\n11. SALIR", "\nOpcion invalida. Ingrese la opcion: ",
				1, 11);
		switch (menuPrincipal) {
		case 1:
			controller_cargarJugadoresDesdeTexto("jugadores.csv",
					listaJugadores);
			controller_cargarSeleccionesDesdeTexto("selecciones.csv",
					listaSelecciones);
			validaciones = 1;
			break;
		case 2:
			if (!validaciones) {
				puts("\nEs necesario cargar la opc 1 antes");
			} else {
				controller_agregarJugador(listaJugadores);
			}
			break;
		case 3:
			controller_editarJugador(listaJugadores);
			break;
		case 4:
			controller_removerJugador(listaJugadores, listaSelecciones);
			break;
		case 5:
			do {
				menuListados = menu_opciones("\n\n\n ---- LISTADOS ----- \n",
						"\n1. TODOS LOS JUGADORES"
								"\n2. TODAS LAS SELECCIONES"
								"\n3. JUGADORES CONVOCADOS"
								"\n4. VOLVER AL MENU PRINCIPAL",
						"\nOpcion invalida. Ingrese la opcion", 1, 4);

				switch (menuListados) {
				case 1:
					controller_listarJugadores(listaJugadores);
					break;
				case 2:
					controller_listarSelecciones(listaSelecciones);
					break;
				case 3:
					break;
				}
			} while (menuListados != 4);
			break;
		case 6:
			do {
				menuConvocatoria = menu_opciones(
						"\n --------- CONVOCAR JUGADORES --------- \n",
						"\n1. CONVOCAR"
								"\n2. QUITAR DE LA SELECCION"
								"\n3. VOLVER AL MENU PRINCIPAL",
						"\nOpcion invalida. Ingrese la opcion: ", 1, 3);
				if (menuConvocatoria == 3) {
					break;
				}

				controller_listarJugadores(listaJugadores);
				utn_getNumero(&auxIdJugador, "\nIngrese el id de jugador: ",
						"\nId invalido. Ingrese el id de jugador: ", 1, 99999,
						9999);

				if (controller_buscarJugadorPorId(listaJugadores,
						auxIdJugador) == NULL) {
					puts(
							"\n  -------- ERROR. EL JUGADOR NO EXISTE. ------------ \n");
					break;
				}

				switch (menuConvocatoria) {
				case 1:
					pAuxJugador = controller_buscarJugadorPorId(listaJugadores,
							auxIdJugador);
					if (pAuxJugador->idSeleccion != 0) {
						puts(
								"\n  -------- ERROR. EL JUGADOR YA ESTA CONVOCADO EN UNA SELECCION. ------------ \n");
						break;
					}
					auxIdSeleccion = controller_editarSeleccion(
							listaSelecciones);
					if (auxIdSeleccion) {
						jug_setIdSeleccion(pAuxJugador, auxIdSeleccion);
					} else {
						puts("\n -------- OCURRIO UN ERROR -------- ");
					}
					break;
				case 2:

					if (controller_buscarSeleccionPorId(listaSelecciones,
							pAuxJugador->idSeleccion) == NULL) {
						puts(
								"\nEL JUGADOR NO FUE CONVOCADO POR NINGUNA SELECCION.");
						break;
					} else {
						selec_eliminarUnConvocado(listaSelecciones,
								pAuxJugador->idSeleccion);
						jug_setIdSeleccion(pAuxJugador, 0);
						printf(
								"\n ---------- El jugador %s ya no forma parte de la seleccion \n",
								pAuxJugador->nombreCompleto);
					}

					break;
				}

			} while (menuConvocatoria != 3);
			break;
		case 7:
			break;
		case 8:
			break;
		case 9:
			break;
		case 10:
			break;
		case 11:
			break;
		}
	} while (menuPrincipal != 11);

	return 0;
}

