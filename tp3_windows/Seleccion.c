#include "Seleccion.h"
#include "Controller.h"
// --------- CONSTRUCTORES ---------

Seleccion* selec_new() {
	Seleccion *pSeleccion = (Seleccion*) malloc(sizeof(Seleccion));

	return pSeleccion;
}

Seleccion* selec_newParametros(char *idStr, char *paisStr,
		char *confederacionStr, char *convocadosStr) {

	Seleccion *pSeleccion = selec_new();

	if (pSeleccion != NULL && idStr != NULL && paisStr != NULL
			&& confederacionStr != NULL && convocadosStr != NULL) {
		pSeleccion->id = atoi(idStr);
		strcpy(pSeleccion->confederacion, confederacionStr);
		strcpy(pSeleccion->pais, paisStr);
		selec_setConvocados(pSeleccion, atoi(convocadosStr));
	} else {
		puts("\nOcurrio un error");
	}
	return pSeleccion;
}

void selec_delete(Seleccion *this) {
	free(this);
}

//  --------- SETTERS ---------

int selec_setConvocados(Seleccion *this, int convocados) {
	int rtn = 0;

	if (this != NULL) {
		this->convocados = convocados;
		rtn = 1;
	}

	return rtn;
}

//  --------- GETTERS ---------

int selec_getId(Seleccion *this, int *id) {
	int rtn = 0;
	if (this != NULL && id != NULL) {
		*id = this->id;
		rtn = 1;
	}
	return rtn;
}

int selec_getPais(Seleccion *this, char *pais) {
	int rtn = 0;
	if (this != NULL && pais != NULL) {
		strcpy(pais, this->pais);
		rtn = 1;
	}
	return rtn;
}

int selec_getConfederacion(Seleccion *this, char *confederacion) {
	int rtn = 0;
	if (this != NULL && confederacion != NULL) {
		strcpy(confederacion, this->confederacion);
		rtn = 1;
	}
	return rtn;
}

int selec_getConvocados(Seleccion *this, int *convocados) {
	int rtn = 0;
	if (this != NULL && convocados != NULL) {
		*convocados = this->convocados;
		rtn = 1;
	}
	return rtn;
}

// FUNCIONES AUXILIARES

int selec_eliminarUnConvocado(LinkedList *listaSelecciones, int idSeleccion) {
	int rtn = 0;
	int auxConvocados;
	Seleccion *pAuxSeleccion;

	if (listaSelecciones != NULL) {
		pAuxSeleccion = controller_buscarSeleccionPorId(listaSelecciones,
				idSeleccion);
		selec_getConvocados(pAuxSeleccion, &auxConvocados);
		auxConvocados--;
		selec_setConvocados(pAuxSeleccion, auxConvocados);
	}

	return rtn;
}

// ordenamiento

int selec_ordenarPorConfederacion(void *pPrimerSeleccion,
		void *pSegundaSeleccion) {
	int rtn = 0;
	Seleccion *auxPrimerSeleccion;
	Seleccion *auxSegundoSeleccion;
	char confederacionPrimerSeleccion[NACIONALIDAD_CHARS];
	char confederacionSegundoSeleccion[NACIONALIDAD_CHARS];
	int resultadoOrdenamiento;

	if (pPrimerSeleccion != NULL && pSegundaSeleccion != NULL) {
		auxPrimerSeleccion = (Seleccion*) pPrimerSeleccion;
		auxSegundoSeleccion = (Seleccion*) pSegundaSeleccion;
		if (selec_getConfederacion(auxPrimerSeleccion,
				confederacionPrimerSeleccion)
				&& selec_getConfederacion(auxSegundoSeleccion,
						confederacionSegundoSeleccion)) {
			resultadoOrdenamiento = strncmp(confederacionPrimerSeleccion,
					confederacionSegundoSeleccion, NACIONALIDAD_CHARS);
			if (resultadoOrdenamiento > 0) {
				rtn = 1;
			} else {
				if (resultadoOrdenamiento < 0) {
					rtn = -1;
				}
			}
		}
	}
	return rtn;
}

// auxiliares

int selec_encontrarPaisDeSeleccion(LinkedList *pArrayListSeleccion,
		int idBusqueda, char *paisBuscado) {
	int rtn = 0;
	Seleccion *pSeleccion;

	if (pArrayListSeleccion != NULL && paisBuscado != NULL) {
		pSeleccion = controller_buscarSeleccionPorId(pArrayListSeleccion,
				idBusqueda);
		if (!selec_getPais(pSeleccion, paisBuscado)) {
			strcpy(paisBuscado, "No convocado");
		}
		rtn = 1;
	}

	return rtn;
}

