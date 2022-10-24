/*
 * eJugador.h
 *
 *  Created on: 15 Oct 2022
 *      Author: Julian
 */

#ifndef EJUGADOR_H_
#define EJUGADOR_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Inputs.h"
#include "eConfederacion.h"
#include "Menu.h"

#define MAX_CHARS 50
#define LIBRE 0
#define BAJA 1
#define OCUPADO -1
#define MAX_JUGADORES 6

typedef struct {
	char nombre[MAX_CHARS];
	char posicion[MAX_CHARS];
	short numeroCamiseta;
	int idConfederacion; //FK
	float salario;
	short aniosContrato;

	int id; //PK
	short isEmpty;
} eJugador;

int abm_obtenerIdJugador(void);
int abm_inicializarJugador(eJugador *lista, int tam);
int abm_obtenerIndiceLibreJugador(eJugador *lista, int tam);
int abm_encontrarJugadorPorId(eJugador *lista, int tam, int id);

int abm_altaJugador(eJugador *lista, int tam, int id, eJugador jugador);

void abm_mostrarUnJugador(eJugador Jugador, eConfederacion *confederaciones,
		int tamConfederaciones);
int abm_mostrarTodosJugador(eJugador *lista, int tam,
		eConfederacion *confederaciones, int tamConfederaciones);
int abm_listadoBajaJugador(eJugador *lista, int tam,
		eConfederacion *confederaciones, int tamConfederaciones);
int abm_bajaJugador(eJugador *lista, int tam, int id);
eJugador abm_modificacionJugador(eJugador Jugador,
		eConfederacion *confederaciones, int tamConfederaciones);
int abm_listadoModificacionJugador(eJugador lista[], int tam,
		eConfederacion *confederaciones, int tamConfederaciones);
int ordenarJugadoresId(eJugador *jugadores, int tam);

#endif /* EJUGADOR_H_ */
