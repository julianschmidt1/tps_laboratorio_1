#include "Jugador.h"

// --------- CONSTRUCTORES ---------

Jugador* jug_new() {
	Jugador *pJugador = (Jugador*) malloc(sizeof(Jugador));

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

	if (this != NULL && nombreCompleto != NULL
			&& strlen(nombreCompleto) <= NOMBRE_CHARS) {
		strcpy(this->nombreCompleto, nombreCompleto);
		rtn = 1;
	} else {
		puts("\nNOMBRE INVALIDO.");
	}

	return rtn;
}

int jug_setId(Jugador *this, int id) {
	int rtn = 0;

	if (this != NULL) {
		this->id = id;
		rtn = 1;
	}

	return rtn;
}

void jug_delete(Jugador *this) {
	free(this);
}

int jug_setPosicion(Jugador *this, char *posicion) {
	int rtn = 0;

	if (this != NULL && posicion != NULL && strlen(posicion) <= POSICION_CHARS) {
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

//  --------- GETTERS ---------

int jug_getId(Jugador *this, int *id) {
	int rtn = 0;
	if (this != NULL && id != NULL) {
		*id = this->id;
		rtn = 1;
	}
	return rtn;
}

int jug_getNombreCompleto(Jugador *this, char *nombreCompleto) {
	int rtn = 0;
	if (this != NULL && nombreCompleto != NULL) {
		strcpy(nombreCompleto, this->nombreCompleto);
		rtn = 1;
	}
	return rtn;
}

int jug_getPosicion(Jugador *this, char *posicion) {
	int rtn = 0;
	if (this != NULL && posicion != NULL) {
		strcpy(posicion, this->posicion);
		rtn = 1;
	}
	return rtn;
}

int jug_getNacionalidad(Jugador *this, char *nacionalidad) {
	int rtn = 0;
	if (this != NULL && nacionalidad != NULL) {
		strcpy(nacionalidad, this->nacionalidad);
		rtn = 1;
	}
	return rtn;
}

int jug_getEdad(Jugador *this, int *edad) {
	int rtn = 0;
	if (this != NULL && edad != NULL) {
		*edad = this->edad;
		rtn = 1;
	}
	return rtn;
}

int jug_getSIdSeleccion(Jugador *this, int *idSeleccion) {
	int rtn = 0;
	if (this != NULL && idSeleccion != NULL) {
		*idSeleccion = this->idSeleccion;
		rtn = 1;
	}
	return rtn;
}

// funciones auxiliares

int validarPosicionJugador(char *posicion) {
	int rtn = 0;
	char auxPosicion[POSICION_CHARS];
	if (posicion != NULL) {
		strcpy(auxPosicion, strupr(posicion));
		if (!strcmp(auxPosicion, "PORTERO")
				|| !strcmp(auxPosicion, "DEFENSA CENTRAL")
				|| !strcmp(auxPosicion, "LATERAL IZQUIERDO")
				|| !strcmp(auxPosicion, "LATERAL DERECHO")
				|| !strcmp(auxPosicion, "PIVOTE")
				|| !strcmp(auxPosicion, "MEDIOCENTRO")
				|| !strcmp(auxPosicion, "EXTREMO IZQUIERDO")
				|| !strcmp(auxPosicion, "EXTREMO DERECHO")
				|| !strcmp(auxPosicion, "MEDIAPUNTA")
				|| !strcmp(auxPosicion, "DELANTERO CENTRO")
				|| !strcmp(auxPosicion, "MEDIOCENTRO OFENSIVO")
				|| !strcmp(auxPosicion, "INTERIOR DERECHO")
				|| !strcmp(auxPosicion, "INTERIOR IZQUIERDO")) {
			strcpy(posicion, auxPosicion);
			rtn = 1;
		} else {
			rtn = -1;
		}
	}
	return rtn;
}

int jug_ordenarPorNacionalidad(void *pPrimerJugador, void *pSegundoJugador) {
	int rtn = 0;
	Jugador *auxPrimerJugador;
	Jugador *auxSegundoJugador;
	char nacionalidadPrimerJugador[NACIONALIDAD_CHARS];
	char nacionalidadSegundoJugador[NACIONALIDAD_CHARS];
	int resultadoOrdenamiento;

	if (pPrimerJugador != NULL && pSegundoJugador != NULL) {
		auxPrimerJugador = (Jugador*) pPrimerJugador;
		auxSegundoJugador = (Jugador*) pSegundoJugador;
		if (jug_getNacionalidad(auxPrimerJugador, nacionalidadPrimerJugador)
				&& jug_getNacionalidad(auxSegundoJugador,
						nacionalidadSegundoJugador)) {
			resultadoOrdenamiento = stricmp(nacionalidadPrimerJugador,
					nacionalidadSegundoJugador);
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

int jug_ordenarPorNombreCompleto(void *pPrimerJugador, void *pSegundoJugador) {
	int rtn = 0;
	Jugador *auxPrimerJugador;
	Jugador *auxSegundoJugador;
	char nombrePrimerJugador[NACIONALIDAD_CHARS];
	char nombreSegundoJugador[NACIONALIDAD_CHARS];
	int resultadoOrdenamiento;

	if (pPrimerJugador != NULL && pSegundoJugador != NULL) {
		auxPrimerJugador = (Jugador*) pPrimerJugador;
		auxSegundoJugador = (Jugador*) pSegundoJugador;
		if (jug_getNombreCompleto(auxPrimerJugador, nombrePrimerJugador)
				&& jug_getNombreCompleto(auxSegundoJugador,
						nombreSegundoJugador)) {
			resultadoOrdenamiento = stricmp(nombrePrimerJugador,
					nombreSegundoJugador);
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

int jug_ordenarPorEdad(void *pPrimerJugador, void *pSegundoJugador) {
	int rtn = 0;
	Jugador *auxPrimerJugador;
	Jugador *auxSegundoJugador;
	int auxPrimerEdad;
	int auxSegundaEdad;

	if (pPrimerJugador != NULL && pSegundoJugador != NULL) {
		auxPrimerJugador = (Jugador*) pPrimerJugador;
		auxSegundoJugador = (Jugador*) pSegundoJugador;
		if (jug_getEdad(auxPrimerJugador, &auxPrimerEdad)
				&& jug_getEdad(auxSegundoJugador, &auxSegundaEdad)) {
			if (auxPrimerEdad > auxSegundaEdad) {
				rtn = 1;
			} else {
				if (auxPrimerEdad < auxSegundaEdad) {
					rtn = -1;
				}
			}
		}
	}
	return rtn;
}

Jugador* jug_buscarJugadorPorId(LinkedList *pArrayListJugador, int idBusqueda) {
	Jugador *rtn = NULL;
	int tamArray;
	int i;
	int auxIdJugador;
	Jugador *pJugador;
	if (pArrayListJugador != NULL) {
		if (!ll_isEmpty(pArrayListJugador)) {
			tamArray = ll_len(pArrayListJugador);
			for (i = 0; i < tamArray; i++) {
				pJugador = (Jugador*) ll_get(pArrayListJugador, i);
				jug_getId(pJugador, &auxIdJugador);
				if (auxIdJugador == idBusqueda) {
					rtn = pJugador;
					break;
				}
			}
			if (rtn != pJugador) {
				rtn = NULL;
			}
		}
	}

	return rtn;
}

