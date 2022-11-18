#ifndef jug_H_INCLUDED
#define jug_H_INCLUDED

#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "menu.h"

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

void jug_delete(Jugador *this);

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

/// \brief Ordena jugadores por nacionalidad
///
/// \param pPrimerJugador puntero a jugador
/// \param pSegundoJugador puntero a jugador
/// \return retorna 1 si esta ordenado, -1 si no lo esta, y 0 si son iguales
int jug_ordenarPorNacionalidad(void *pPrimerJugador, void *pSegundoJugador);

/// \brief Ordena jugadores por edad
///
/// \param pPrimerJugador puntero a jugador
/// \param pSegundoJugador puntero a jugador
/// \return retorna 1 si esta ordenado, -1 si no lo esta, y 0 si son iguales
int jug_ordenarPorEdad(void *pPrimerJugador, void *pSegundoJugador);

/// \brief Ordena jugadores por nombre completo
///
/// \param pPrimerJugador puntero a jugador
/// \param pSegundoJugador puntero a jugador
/// \return retorna 1 si esta ordenado, -1 si no lo esta, y 0 si son iguales
int jug_ordenarPorNombreCompleto(void *pPrimerJugador, void *pSegundoJugador);

/// \brief Valida la posicion ingresada por el usuario
///
/// \param posicion cadena de caracteres de la posicion
/// \return Retorna 1 en caso de validacion exitosa, -1 en caso de validacion erronea, 0 en caso de puntero invalido (ERROR)
int validarPosicionJugador(char *posicion);

/// \brief Funcion que busca un jugador por id
///
/// \param pArrayListJugador array sobre el cual buscar
/// \param idBusqueda id a encontrar
/// \return retorna el puntero al jugador, si es que se encuentra, o NULL en caso de error o jugador no encontrado
Jugador* jug_buscarJugadorPorId(LinkedList *pArrayListJugador, int idBusqueda);

#endif // jug_H_INCLUDED
