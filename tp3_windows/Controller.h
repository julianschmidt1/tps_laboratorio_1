#include "Jugador.h"
#include "Seleccion.h"

int controller_cargarJugadoresDesdeTexto(char *path,
		LinkedList *pArrayListJugador);
int controller_cargarJugadoresDesdeBinario(char *path,
		LinkedList *pArrayListJugador);
int controller_agregarJugador(LinkedList *pArrayListJugador);
int controller_editarJugador(LinkedList *pArrayListJugador);
int controller_removerJugador(LinkedList *pArrayListJugador);
int controller_listarJugadores(LinkedList *pArrayListJugador);
int controller_ordenarJugadores(LinkedList *pArrayListJugador);

int controller_guardarJugadoresModoTexto(char *path,
		LinkedList *pArrayListJugador);
int controller_guardarJugadoresModoBinario(char *path,
		LinkedList *pArrayListJugador);
int controller_cargarSeleccionesDesdeTexto(char *path,
		LinkedList *pArrayListSeleccion);

int controller_editarSeleccion(LinkedList *pArrayListSeleccion);
int controller_listarSelecciones(LinkedList *pArrayListSeleccion);
int controller_ordenarSelecciones(LinkedList *pArrayListSeleccion);
int controller_guardarSeleccionesModoTexto(char *path,
		LinkedList *pArrayListSeleccion);

Jugador* controller_buscarJugadorPorId(LinkedList *pArrayListJugador,
		int idBusqueda);
Seleccion* controller_buscarSeleccionPorId(LinkedList *pArrayListSeleccion,
		int idBusqueda);
int controller_listarJugadoresConvocados(LinkedList *pArrayListJugador);
int controller_crearListaJugadoresConvocados(LinkedList *pArrayListJugador,
		LinkedList *pArrayListSeleccion, LinkedList *pArrayListJugadorConvocado);
int controller_guardarUltimoId(char *path, int *pId);
