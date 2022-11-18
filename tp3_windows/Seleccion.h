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
