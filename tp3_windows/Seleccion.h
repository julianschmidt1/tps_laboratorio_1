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

/// \brief Funcion que pide memoria suficiente para almacenar un tipo de dato Seleccion
///
/// \return retorna puntero a Seleccion
Seleccion* selec_new();

/// \brief Funcion que pide memoria suficiente para almacenar un tipo de dato Seleccion y carga el puntero de informacion
///
/// \param idStr id de seleccion en forma de string
/// \param paisStr pais de seleccion en forma de string
/// \param confederacionStr confederacion de seleccion en forma de string
/// \param convocadosStr convocados de seleccion en forma de string
/// \return Retorna puntero a Seleccion den caso de exito y null en caso de error
Seleccion* selec_newParametros(char *idStr, char *paisStr,
		char *confederacionStr, char *convocadosStr);

/// \brief Libera el puntero en memoria consumido por un Seleccion
///
void selec_delete(Seleccion *this);

/// \brief funcion que obtiene el id de seleccion y lo almacena en un puntero
///
/// \param this Puntero a seleccion
/// \param id puntero a variable id
/// \return retorna 1 en caso de exito y 0 en caso de error
int selec_getId(Seleccion *this, int *id);

/// \brief funcion que obtiene el pais de seleccion y lo almacena en un puntero
///
/// \param this Puntero a seleccion
/// \param id puntero a variable pais
/// \return retorna 1 en caso de exito y 0 en caso de error
int selec_getPais(Seleccion *this, char *pais);

/// \brief funcion que obtiene la confederacion de seleccion y la almacena en un puntero
///
/// \param this Puntero a seleccion
/// \param id puntero a variable confederacion
/// \return retorna 1 en caso de exito y 0 en caso de error
int selec_getConfederacion(Seleccion *this, char *confederacion);

/// \brief Funcion que asigna el campo convocados de una Seleccion
///
/// \param this Puntero a seleccion
/// \param convocados contador enteros
/// \return retorna 1 en caso de exito y 0 en caso de error
int selec_setConvocados(Seleccion *this, int convocados);

/// \brief funcion que obtiene la catidad de convocados de seleccion y lo almacena en un puntero
///
/// \param this Puntero a seleccion
/// \param id puntero a variable convocados
/// \return retorna 1 en caso de exito y 0 en caso de error
int selec_getConvocados(Seleccion *this, int *convocados);

/// \brief Funcion que reduce el contador de convocados en selecciones
///
/// \param pSeleccion puntero a seleccion
/// \param idSeleccion id de seleccion a modificar
/// \return
int selec_eliminarUnConvocado(LinkedList *pSeleccion, int idSeleccion);

/// \brief Ordena selecciones por nombre de confederacion
///
/// \param pPrimerSeleccion puntero a seleccion
/// \param pSegundaSeleccion puntero a seleccion
/// \return retorna 1 si esta ordenado, -1 si no lo esta, y 0 si son iguales
int selec_ordenarPorConfederacion(void *pPrimerSeleccion,
		void *pSegundaSeleccion);

/// \brief busca una seleccion por id y obtiene el nombre del pais
///
/// \param pArrayListSeleccion lista de selecciones
/// \param idBusqueda id a buscar
/// \param paisBuscado puntero a char que almacenara el valor
/// \return retorna 1 en caso de exito y 0 en caso de error
int selec_encontrarPaisDeSeleccion(LinkedList *pArrayListSeleccion,
		int idBusqueda, char *paisBuscado);

/// \brief busca una seleccion por id y retorna un puntero a la misma
///
/// \param pArrayListSeleccion array de selecciones
/// \param idBusqueda id a buscar
/// \return retorna puntero a seleccion en caso de exito y null en caso de error
Seleccion* selec_buscarSeleccionPorId(LinkedList *pArrayListSeleccion,
		int idBusqueda);

#endif // selec_H_INCLUDED
