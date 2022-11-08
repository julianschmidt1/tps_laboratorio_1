#ifndef jug_H_INCLUDED
#define jug_H_INCLUDED

#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NOMBRE_CHARS 100
#define POSICION_CHARS 30
#define NACIONALIDAD_CHARS 30
#define PRIMER_ID_MANUAL 371

typedef struct {
	int id;
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	int idSeleccion;
} Jugador;

Jugador* jug_new();
Jugador* jug_newParametros(char *idStr, char *nombreCompletoStr, char *edadStr,
		char *posicionStr, char *nacionalidadStr, char *idSelccionStr);

int jug_mostrarUno(Jugador *this);

void jug_delete();

int jug_setId(Jugador *this, int id);
int jug_getId(Jugador *this, int *id);

int jug_setNombreCompleto(Jugador *this, char *nombreCompleto);
int jug_getNombreCompleto(Jugador *this, char *nombreCompleto);

int jug_setPosicion(Jugador *this, char *posicion);
int jug_getPosicion(Jugador *this, char *posicion);

int jug_setNacionalidad(Jugador *this, char *nacionalidad);
int jug_getNacionalidad(Jugador *this, char *nacionalidad);

int jug_setEdad(Jugador *this, int edad);
int jug_getEdad(Jugador *this, int *edad);

int jug_setIdSeleccion(Jugador *this, int idSeleccion);
int jug_getSIdSeleccion(Jugador *this, int *idSeleccion);

#endif // jug_H_INCLUDED
