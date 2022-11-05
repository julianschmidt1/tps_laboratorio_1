#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "menu.h"

int main() {
	setbuf(stdout, NULL);
	int opcion = 0;
	LinkedList *listaJugadores = ll_newLinkedList();

	do {

		opcion = menu_opciones("\n ------- TRABAJO PRACTICO 3  ------- \n",
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
		switch (opcion) {
		case 1:
			controller_cargarJugadoresDesdeTexto("jugadores.csv",
					listaJugadores);
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
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
	} while (opcion != 10);

	return 0;
}

