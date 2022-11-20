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

/// \brief Funcion que pide memoria suficiente para almacenar un tipo de dato Jugador
///
/// \return retorna puntero a Jugador
Jugador* jug_new();

/// \brief Funcion que pide memoria suficiente para almacenar un tipo de dato Jugador y carga el puntero de informacion
///
/// \param idStr idStr id de jugador en forma de string
/// \param nombreCompletoStr nombre completo de jugador
/// \param edadStr edad de jugador en forma de string
/// \param posicionStr posicion de jugador
/// \param nacionalidadStr nacionalidad de jugador
/// \param idSelccionStr id de seleccion en forma de string
/// \return Retorna un puntero a Jugador en caso de exito y 0 en caso de error
Jugador* jug_newParametros(char *idStr, char *nombreCompletoStr, char *edadStr,
		char *posicionStr, char *nacionalidadStr, char *idSelccionStr);

/// \brief Libera el puntero en memoria consumido por un Jugador
///
void jug_delete(Jugador *this);

/// \brief Funcion que guarda en un puntero a Jugador el valor de id recibido por parametros
///
/// \param this puntero a jugador
/// \param id valor de variable id
/// \return retorna 1 en caso de exito y 0 en caso de error
int jug_setId(Jugador *this, int id);

/// \brief Funcion que obtiene el id de jugador y lo almacena en un puntero recibido por params
///
/// \param this Puntero a jugador
/// \param id puntero a variable id
/// \return retorna 1 en caso de exito y 0 en caso de error
int jug_getId(Jugador *this, int *id);

/// \brief funcion que guarda en un puntero a jugador el nombre completo
///
/// \param this puntero a jugador
/// \param nombreCompleto puntero a string de nombre completo
/// \return retorna 1 en caso de exito y 0 en caso de error
int jug_setNombreCompleto(Jugador *this, char *nombreCompleto);

/// \brief funcion que obtiene el nombre completo y lo almacena en una variable nombre completo
///
/// \param this puntero a jugador
/// \param nombreCompleto puntero a string de nombre completo
/// \return retorna 1 en caso de exito y 0 en caso de error
int jug_getNombreCompleto(Jugador *this, char *nombreCompleto);

/// \brief funcion que guarda en un puntero a jugador la posicion
///
/// \param this puntero a jugador
/// \param nombreCompleto puntero a posicion
/// \return retorna 1 en caso de exito y 0 en caso de error
int jug_setPosicion(Jugador *this, char *posicion);

/// \brief funcion que obtiene la posicion y la almacena en un puntero
///
/// \param this Puntero a seleccion
/// \param id puntero a variable posicion
/// \return retorna 1 en caso de exito y 0 en caso de error
int jug_getPosicion(Jugador *this, char *posicion);

/// \brief funcion que guarda en un puntero a jugador la nacionalidad
///
/// \param this puntero a jugador
/// \param nombreCompleto puntero a string de nacionalidad
/// \return retorna 1 en caso de exito y 0 en caso de error
int jug_setNacionalidad(Jugador *this, char *nacionalidad);

/// \brief funcion que obtiene la nacionalidad y lo almacena en una variable nacionalidad
///
/// \param this puntero a jugador
/// \param nombreCompleto puntero a string de nacionalidad
/// \return retorna 1 en caso de exito y 0 en caso de error
int jug_getNacionalidad(Jugador *this, char *nacionalidad);

/// \brief funcion que guarda en un puntero a jugador la edad
///
/// \param this puntero a jugador
/// \param nombreCompleto puntero a variable edad
/// \return retorna 1 en caso de exito y 0 en caso de error
int jug_setEdad(Jugador *this, int edad);

/// \brief funcion que obtiene la edad y la almacena en una variable
///
/// \param this puntero a jugador
/// \param nombreCompleto puntero a variable edad
/// \return retorna 1 en caso de exito y 0 en caso de error
int jug_getEdad(Jugador *this, int *edad);

/// \brief funcion que guarda en un puntero a jugador el id de seleccion
///
/// \param this puntero a jugador
/// \param nombreCompleto puntero a variable idSeleccion
/// \return retorna 1 en caso de exito y 0 en caso de error
int jug_setIdSeleccion(Jugador *this, int idSeleccion);

/// \brief funcion que obtiene la edad y la almacena en una variable
///
/// \param this puntero a jugador
/// \param nombreCompleto puntero a variable idSeleccion
/// \return retorna 1 en caso de exito y 0 en caso de error
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
