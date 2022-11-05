#include "Jugador.h"

// --------- CONSTRUCTORES ---------

Jugador* jug_new() {
	Jugador *pJugador = (Jugador*) malloc(sizeof(Jugador) * 2);

	return pJugador;
}

Jugador* jug_newParametros(char *idStr, char *nombreCompletoStr, char *edadStr,
		char *posicionStr, char *nacionalidadStr, char *idSelccionStr) {

	Jugador *pJugador = jug_new();

	if (pJugador != NULL && idStr != NULL && nombreCompletoStr != NULL
			&& edadStr != NULL && posicionStr != NULL && nacionalidadStr != NULL
			&& idSelccionStr != NULL) {
		if (!(jug_setId(pJugador, atoi(idStr))
				&& jug_setNombreCompleto(pJugador, nombreCompletoStr)
				&& jug_setEdad(pJugador, atoi(edadStr))
				&& jug_setNacionalidad(pJugador, nacionalidadStr)
				&& jug_setIdSeleccion(pJugador, atoi(idSelccionStr))
				&& jug_setPosicion(pJugador, posicionStr))) {
			free(pJugador);
			pJugador = NULL;
		}
	} else {
		puts("\nOcurrio un error.");
	}
	return pJugador;
}

//  --------- SETTERS ---------

int jug_setNombreCompleto(Jugador *this, char *nombreCompleto) {
	int rtn = 0;

	char auxCadena[NOMBRE_CHARS];
	if (this != NULL && nombreCompleto != NULL
			&& strlen(nombreCompleto) <= NOMBRE_CHARS) {
		strcpy(auxCadena, nombreCompleto);
		strlwr(auxCadena);
		auxCadena[0] = toupper(auxCadena[0]);
		strcpy(this->nombreCompleto, auxCadena);
		rtn = 1;
	} else {
		puts("\nNOMBRE INVALIDO.");
	}

	return rtn;
}

int jug_setId(Jugador *this, int id) {
	int rtn = 0;

	// TODO: VALIDAR QUE ONDA ESE ID
	if (this != NULL) {
		this->id = id;
		rtn = 1;
	}

	return rtn;
}

int jug_setPosicion(Jugador *this, char *posicion) {
	int rtn = 0;

	char auxCadena[POSICION_CHARS];
	// TODO: VALIDAR POSICIONES ?
	if (this != NULL && posicion != NULL && strlen(posicion) <= POSICION_CHARS) {
		strcpy(auxCadena, posicion);
		//strlwr(auxCadena);
		strcpy(this->posicion, posicion);
		rtn = 1;
	} else {
		puts("\nPOSICION INVALIDA");
	}

	return rtn;
}

int jug_setNacionalidad(Jugador *this, char *nacionalidad) {
	int rtn = 0;

	if (this != NULL && nacionalidad != NULL
			&& strlen(nacionalidad) <= POSICION_CHARS) {
		strcpy(this->nacionalidad, nacionalidad);
		rtn = 1;
	} else {
		puts("\nNACIONALIDAD INVALIDA");
	}

	return rtn;
}

int jug_setEdad(Jugador *this, int edad) {
	int rtn = 0;

	if (this != NULL && edad > 0 && edad < 100) {
		this->edad = edad;
		rtn = 1;
	} else {
		puts("\nEDAD INVALIDA");
	}

	return rtn;
}

int jug_setIdSeleccion(Jugador *this, int idSeleccion) {
	int rtn = 0;

	// VALIDAR QUE ONDA ESE ID
	if (this != NULL) {
		this->idSeleccion = idSeleccion;
		rtn = 1;
	} else {
		puts("\nID INVALIDO");
	}

	return rtn;
}

int jug_setIsEmpty(Jugador *this, int isEmpty) {
	int rtn = 0;

	// VALIDAR QUE ONDA ESE ID
	if (this != NULL) {
		this->isEmpty = isEmpty;
		rtn = 1;
	} else {
		puts("\nVALOR INVALIDO");
	}

	return rtn;
}

//  --------- GETTERS ---------

