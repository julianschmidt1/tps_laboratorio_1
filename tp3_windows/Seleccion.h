#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifndef selec_H_INCLUDED
#define selec_H_INCLUDED
#define MAX_CHARS 30
#define MAX_JUGADORES 22

typedef struct {
	int id;
	char pais[30];
	char confederacion[30];
	int convocados;
} Seleccion;

Seleccion* selec_new();
Seleccion* selec_newParametros(char *idStr, char *paisStr,
		char *confederacionStr, char *convocadosStr);
void selec_delete();

int selec_getId(Seleccion *this, int *id);
int selec_getPais(Seleccion *this, char *pais);
int selec_getConfederacion(Seleccion *this, char *confederacion);

int selec_setConvocados(Seleccion *this, int convocados);
int selec_getConvocados(Seleccion *this, int *convocados);

int selec_eliminarUnConvocado(LinkedList *pSeleccion, int idSeleccion);
int selec_ordenarPorConfederacion(void *pPrimerSeleccion,
		void *pSegundaSeleccion);
int selec_encontrarPaisDeSeleccion(LinkedList *pArrayListSeleccion,
		int idBusqueda, char *paisBuscado);
Seleccion* selec_buscarSeleccionPorId(LinkedList *pArrayListSeleccion,
		int idBusqueda);

#endif // selec_H_INCLUDED
