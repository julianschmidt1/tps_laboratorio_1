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
	int menuOrdenamiento;
	LinkedList *listaJugadores = ll_newLinkedList();
	LinkedList *listaSelecciones = ll_newLinkedList();
	LinkedList *listaJugadoresConvocados = ll_newLinkedList();
	int auxIdJugador;
	Jugador *pAuxJugador;
	int auxIdSeleccion;
	int auxUltimoId = 0;
	char auxNombreCompleto[NOMBRE_CHARS];
	int flagCargaArchivos = 0;
	int flagGuardarArchivos = 1;
	int confirmarSalida;
	int confirmarSobreescritura = 0;

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
			if (flagCargaArchivos) {
				utn_getNumero(&confirmarSobreescritura,
						"\nYa existen datos cargados en las listas. Desea sobreescribirlos? (1. SI | 0. NO): ",
						"\nOpcion invalida. ", 0, 1, 1);
			}
			if (!flagCargaArchivos || confirmarSobreescritura) {
				ll_clear(listaJugadores);
				ll_clear(listaSelecciones);
				ll_clear(listaJugadoresConvocados);
				controller_cargarJugadoresDesdeTexto("jugadores.csv",
						listaJugadores);
				controller_cargarSeleccionesDesdeTexto("selecciones.csv",
						listaSelecciones);
			}
			flagCargaArchivos = 1;
			break;
		case 2:
			if (!flagCargaArchivos) {
				puts("\nEs necesario cargar la opc 1 antes");
			} else {
				auxUltimoId = controller_agregarJugador(listaJugadores);
				flagGuardarArchivos = 0;
			}
			break;
		case 3:
			if (!flagCargaArchivos) {
				puts("\nEs necesario cargar la opc 1 antes");
			} else {
				if (controller_editarJugador(listaJugadores)) {
					flagGuardarArchivos = 0;
				}
			}
			break;
		case 4:
			if (!flagCargaArchivos) {
				puts("\nEs necesario cargar la opc 1 antes");
			} else {
				auxIdSeleccion = controller_removerJugador(listaJugadores);
				if (auxIdSeleccion != 0) {
					selec_eliminarUnConvocado(listaSelecciones, auxIdSeleccion);
				}
				flagGuardarArchivos = 0;
			}
			break;
		case 5:
			if (!flagCargaArchivos) {
				puts("\nEs necesario cargar la opc 1 antes");
			} else {
				do {
					menuListados = menu_opciones(
							"\n\n\n ---- LISTADOS ----- \n",
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
						controller_listarJugadoresConvocados(listaJugadores);
						break;
					}
				} while (menuListados != 4);
			}
			break;
		case 6:
			if (!flagCargaArchivos) {
				puts("\nEs necesario cargar la opc 1 antes");
			} else {
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
							"\nId invalido. Ingrese el id de jugador: ", 1,
							99999, 9999);
					if (jug_buscarJugadorPorId(listaJugadores,
							auxIdJugador) == NULL) {
						puts(
								"\n  -------- ERROR. EL JUGADOR NO EXISTE. ------------ \n");
						break;
					}
					switch (menuConvocatoria) {
					case 1:
						pAuxJugador = jug_buscarJugadorPorId(listaJugadores,
								auxIdJugador);
						jug_getSIdSeleccion(pAuxJugador, &auxIdSeleccion);
						if (auxIdSeleccion != 0) {
							puts(
									"\n  -------- ERROR. EL JUGADOR YA ESTA CONVOCADO EN UNA SELECCION. ------------ \n");
							break;
						}
						auxIdSeleccion = controller_editarSeleccion(
								listaSelecciones);
						if (auxIdSeleccion) {
							jug_setIdSeleccion(pAuxJugador, auxIdSeleccion);
							flagGuardarArchivos = 0;
						} else {
							puts("\n -------- OCURRIO UN ERROR -------- ");
						}
						break;
					case 2:
						jug_getSIdSeleccion(pAuxJugador, &auxIdSeleccion);
						jug_getNombreCompleto(pAuxJugador, auxNombreCompleto);
						if (selec_buscarSeleccionPorId(listaSelecciones,
								auxIdSeleccion) == NULL) {
							puts(
									"\nEL JUGADOR NO FUE CONVOCADO POR NINGUNA SELECCION.");
							break;
						} else {
							selec_eliminarUnConvocado(listaSelecciones,
									auxIdSeleccion);
							jug_setIdSeleccion(pAuxJugador, 0);
							flagGuardarArchivos = 0;
							printf(
									"\n ---------- El jugador %s ya no forma parte de la seleccion \n",
									auxNombreCompleto);
						}
						break;
					}

				} while (menuConvocatoria != 3);
			}
			break;
		case 7:
			if (!flagCargaArchivos) {
				puts("\nEs necesario cargar la opc 1 antes");
			} else {
				menuOrdenamiento = menu_opciones(
						"\n ------- ORDENAR Y LISTAR -------- \n",
						"\n1. JUGADORES"
								"\n2. SELECCIONES POR CONFEDERACION",
						"\nOpcin invalida, ingrese la opcion: ", 1, 2);
				if (menuOrdenamiento == 1) {
					controller_ordenarJugadores(listaJugadores);
				} else if (menuOrdenamiento == 2) {
					controller_ordenarSelecciones(listaSelecciones);
				}
			}
			break;
		case 8:
			if (controller_crearListaJugadoresConvocados(listaJugadores,
					listaSelecciones, listaJugadoresConvocados)) {
				if (controller_guardarJugadoresModoBinario("convocados.bin",
						listaJugadoresConvocados)) {
					puts("\n Lista guardada OK ");
				}
			}
			break;
		case 9:
			if (controller_cargarJugadoresDesdeBinario("convocados.bin",
					listaJugadoresConvocados)) {
				controller_listarJugadores(listaJugadoresConvocados);
			}
			break;
		case 10:
			if (!flagGuardarArchivos) {
				controller_guardarJugadoresModoTexto("jugadores.csv",
						listaJugadores);
				controller_guardarSeleccionesModoTexto("selecciones.csv",
						listaSelecciones);
				if (auxUltimoId != 0) {
					auxUltimoId++;
					controller_guardarUltimoId("ultimoId.bin", &auxUltimoId);
				}
				puts("\nCambios guardados exitosamente!");
				flagGuardarArchivos = 1;
			} else {
				puts("\nNo hay cambios para guardar");
			}
			break;
		case 11:
			if (!flagGuardarArchivos) {
				puts(
						"\nHay cambios sin guardar. (1. SALIR IGUALMENTE | 0. VOLVER AL MENU): ");
				utn_getNumero(&confirmarSalida, "\nIngrese la opcion: ",
						"\nOpcion invalida. Ingrese la opcion: ", 0, 1, 999999);
			} else {
				ll_deleteLinkedList(listaJugadores);
				ll_deleteLinkedList(listaSelecciones);
				ll_deleteLinkedList(listaJugadoresConvocados);
				confirmarSalida = 1;
			}
			break;
		}
	} while (menuPrincipal != 11 || !confirmarSalida);

	return 0;
}

