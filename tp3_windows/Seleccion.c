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
		if (!(selec_setId(pSeleccion, atoi(idStr))
				&& selec_setConfederacion(pSeleccion, confederacionStr)
				&& selec_setConvocados(pSeleccion, atoi(convocadosStr))
				&& selec_setPais(pSeleccion, paisStr))) {
			free(pSeleccion);
			pSeleccion = NULL;
		}
	} else {
		puts("\nOcurrio un error.");
	}
	return pSeleccion;
}

//  --------- SETTERS ---------

int selec_setPais(Seleccion *this, char *pais) {
	int rtn = 0;
	if (this != NULL && pais != NULL && strlen(pais) <= MAX_CHARS) {
		strcpy(this->pais, pais);
		rtn = 1;
	} else {
		puts("\nPAIS INVALIDO.");
	}

	return rtn;
}

int selec_setId(Seleccion *this, int id) {
	int rtn = 0;

	if (this != NULL) {
		this->id = id;
		rtn = 1;
	}

	return rtn;
}

void selec_delete(Seleccion *this) {
	free(this);
}

int selec_setConfederacion(Seleccion *this, char *confederacion) {
	int rtn = 0;

	char auxCadena[MAX_CHARS];
	if (this != NULL && confederacion != NULL
			&& strlen(confederacion) <= MAX_CHARS) {
		strcpy(auxCadena, confederacion);
		//strlwr(auxCadena);
		strcpy(this->confederacion, confederacion);
		rtn = 1;
	} else {
		puts("\nPOSICION INVALIDA");
	}

	return rtn;
}

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

