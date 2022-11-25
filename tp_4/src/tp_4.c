/*
 ============================================================================
 Name        : tp_4.c
 Author      : Julián Schmidt
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "string.h"

typedef struct {
	char nombreCompleto[50];
	int edad;
} eUsuario;

eUsuario* us_new();
void mostrarUsuarios(LinkedList *lista);
int ordenarJugadorPorNombre(void *pPrimero, void *pSegundo);

eUsuario* us_new() {
	eUsuario *pUsuario = (eUsuario*) malloc(sizeof(eUsuario));

	return pUsuario;
}

void mostrarUsuarios(LinkedList *listadoUsuarios) {
	eUsuario *auxUsuario;
	// obtengo tamaño del listado para iterarlo
	int tam = ll_len(listadoUsuarios);
	if (tam > 0 && listadoUsuarios != NULL) {
		for (int i = 0; i < tam; i++) {
			// obtengo el puntero del indice para mostrarlo
			auxUsuario = ll_get(listadoUsuarios, i);
			printf("\n Nombre: %s Edad: %d", auxUsuario->nombreCompleto,
					auxUsuario->edad);
		}
	} else {
		puts("\nNo hay nada para mostrar");
	}
	puts("\n--------------------------");
}

int ordenarJugadorPorNombre(void *pPrimero, void *pSegundo) {
	int rtn = 0;
	eUsuario *auxPrimero;
	eUsuario *auxSegundo;
	char nombrePrimerUsuario[40];
	char nombreSegundoUsuario[40];
	int resultadoOrdenamiento;

	if (pPrimero != NULL && pSegundo != NULL) {
		auxPrimero = (eUsuario*) pPrimero;
		auxSegundo = (eUsuario*) pSegundo;
		strcpy(nombrePrimerUsuario, auxPrimero->nombreCompleto);
		strcpy(nombreSegundoUsuario, auxSegundo->nombreCompleto);

		resultadoOrdenamiento = stricmp(nombrePrimerUsuario,
				nombreSegundoUsuario);
		if (resultadoOrdenamiento > 0) {
			rtn = 1;
		} else {
			if (resultadoOrdenamiento < 0) {
				rtn = -1;
			}
		}

	}
	return rtn;
}

int filtroNombres(void *usuario);

int filtroNombres(void *usuario) {
	int rtn = 0;
	eUsuario *aux = NULL;

	if (usuario != NULL) {
		aux = (eUsuario*) usuario;
		if (aux->nombreCompleto[0] == 'j' || aux->nombreCompleto[0] == 'J') {
			rtn = 1;
		}
	}

	return rtn;
}

int main(void) {
	setbuf(stdout, NULL);
	LinkedList *listadoUsuarios = ll_newLinkedList();
	LinkedList *listaClonada = ll_newLinkedList();
	LinkedList *listaFiltrada = ll_newLinkedList();

	eUsuario *usuarioUno = us_new();
	eUsuario *usuarioDos = us_new();
	eUsuario *usuarioTres = us_new();
	eUsuario *usuarioCuatro = us_new();
	eUsuario *usuarioCinco = us_new();
	eUsuario *auxUsuario = us_new();

	int (*pFunc)(void*, void*);
	int (*pFuncFilter)(void*);

	strcpy(usuarioUno->nombreCompleto, "Julian Schmidt");
	usuarioUno->edad = 23;
	strcpy(usuarioDos->nombreCompleto, "Javier Schmidt");
	usuarioDos->edad = 25;
	strcpy(usuarioTres->nombreCompleto, "Guillermo Schmidt");
	usuarioTres->edad = 30;
	strcpy(usuarioCuatro->nombreCompleto, "Jorge Schmidt");
	usuarioCuatro->edad = 69;
	strcpy(usuarioCinco->nombreCompleto, "Marcos Schmidt");
	usuarioCinco->edad = 95;

	puts("\nAgrego usuarios a la lista (ll_add)");
	ll_add(listadoUsuarios, usuarioUno);
	ll_add(listadoUsuarios, usuarioDos);
	ll_add(listadoUsuarios, usuarioTres);
	ll_add(listadoUsuarios, usuarioCuatro);
	ll_add(listadoUsuarios, usuarioCinco);

	puts("\nObtengo el tamaño e itero la lista");
	mostrarUsuarios(listadoUsuarios);

	puts("\nModifico usuario en indice 0 y lo seteo (ll_set)");
	strcpy(auxUsuario->nombreCompleto, "Pablo Schmidt");
	auxUsuario->edad = 51;
	ll_set(listadoUsuarios, 0, auxUsuario);
	mostrarUsuarios(listadoUsuarios);

	puts("\nEliminamos usuario en indice 2 (ll_remove)");
	ll_remove(listadoUsuarios, 2);
	mostrarUsuarios(listadoUsuarios);

	puts("\nAgregamos nuevamente el usuario eliminado en indice 2 (ll_push)");
	ll_push(listadoUsuarios, 2, usuarioTres);
	mostrarUsuarios(listadoUsuarios);

	puts("\nBusco indice de usuario (ll_indexOf)");
	printf("Indice de el usuario %s: %d", usuarioDos->nombreCompleto,
			ll_indexOf(listadoUsuarios, usuarioDos));

	puts("\n\nRemuevo usuario de la lista y obtengo su puntero (ll_pop)");
	auxUsuario = (eUsuario*) ll_pop(listadoUsuarios, 2);
	mostrarUsuarios(listadoUsuarios);
	puts("Mostrando usuario desde puntero obtenido");
	printf("\nUSUARIO ELIMINADO Nombre: %s, edad: %d",
			auxUsuario->nombreCompleto, auxUsuario->edad);

	printf("\n\nComprobamos que el usuario %s exista en la lista (ll_contains)",
			auxUsuario->nombreCompleto);
	if (!ll_contains(listadoUsuarios, auxUsuario)) {
		puts("\nEl usuario no fue encontrado");
	}

	printf("\n\nClono el listado actual y lo muestro (ll_clone)");
	listaClonada = ll_clone(listadoUsuarios);
	mostrarUsuarios(listaClonada);

	printf(
			"\nComprobando si todos los elementos del listado original se encuentran en el clonado");
	if (ll_containsAll(listadoUsuarios, listaClonada)) {
		puts("\nSe contienen todos los elementos");
	} else {
		puts("\nNo se contienen todos los elementos");
	}

	puts("\nCompruebo si la lista clonada esta vacia (ll_isEmpty)");
	if (!ll_isEmpty(listaClonada)) {
		printf("\n\nLa lista tiene datos. Eliminando... \n");
	}

	puts("\nVaciando lista clonada... (ll_clear)");
	ll_clear(listaClonada);
	if (ll_isEmpty(listaClonada)) {
		puts("\nLa lista se vacio exitosamente");
		mostrarUsuarios(listaClonada);
	}

	puts(
			"\nCreando sublista desde indice 0 a indice 3 y la muestro (ll_subList)");
	listaClonada = ll_subList(listadoUsuarios, 0, 3);
	mostrarUsuarios(listaClonada);

	puts("\nOrdenando usuarios por nombre ASCENDENTE (ll_sort)");
	pFunc = ordenarJugadorPorNombre;
	ll_sort(listadoUsuarios, pFunc, 1);
	mostrarUsuarios(listadoUsuarios);

	puts("\nOrdenando usuarios por nombre DESCENDENTE (ll_sort)");
	ll_sort(listadoUsuarios, pFunc, 0);
	mostrarUsuarios(listadoUsuarios);

	puts("\nFiltrando usuarios que comiencen en J (ll_filter)");
	pFuncFilter = filtroNombres;
	listaFiltrada = ll_filter(listadoUsuarios, pFuncFilter);
	mostrarUsuarios(listaFiltrada);

	puts("\nEliminando lista");
	if (!ll_deleteLinkedList(listadoUsuarios)) {
		puts("\nLista eliminada correctamente");
	}

	return EXIT_SUCCESS;
}
