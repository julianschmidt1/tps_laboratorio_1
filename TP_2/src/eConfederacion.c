/*
 * eConfederacion.c
 *
 *  Created on: 16 Oct 2022
 *      Author: Julian
 */

#include "eConfederacion.h"

int abm_obtenerIdConfederacion(void) {
	static int idIncrementalConfederacion = 0;
	return idIncrementalConfederacion++;
}

int abm_inicializarConfederacion(eConfederacion *lista, int tam) {
	int i;
	int rtn = 0;

	if (lista != NULL && tam > 0) {
		rtn = 1;
		for (i = 0; i < tam; i++) {
			lista[i].isEmpty = LIBRE;
		}
	}

	return rtn;
}

int abm_obtenerIndiceLibreConfederacion(eConfederacion *lista, int tam) {
	int rtn = -1;

	if (lista != NULL && tam > 0) {
		for (int i = 0; i < tam; i++) {
			if (lista[i].isEmpty == LIBRE) {
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

int abm_encontrarConfederacionPorId(eConfederacion *lista, int tam, int id) {
	int rtn = -1;
	int i;

	if (lista != NULL && tam > 0) {
		for (i = 0; i < tam; i++) {
			if (lista[i].id == id && lista[i].isEmpty == OCUPADO) {
				// Retorno indice de Confederacion ocupado
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

void abm_mostrarUnConfederacion(eConfederacion Confederacion) {
	// Modificar esto para que muestre data generica siempre
	printf("\n| %d     |  %-8s     |     %-22s |  %d        |",
			Confederacion.id, Confederacion.nombre, Confederacion.region,
			Confederacion.anioCreacion);
}

int abm_mostrarTodosConfederacion(eConfederacion *lista, int tam) {
	int i;
	int rtn = 0;
	int cantidad = 0;

	if (lista != NULL && tam > 0) {
		puts(
				"=======================================================================");
		puts(
				"\n|  ID     |  NOMBRE       |     REGION                 | AÑO CREACION |");
		puts(
				"\n-----------------------------------------------------------------------");
		for (i = 0; i < tam; i++) {
			if (lista[i].isEmpty == OCUPADO) {
				abm_mostrarUnConfederacion(lista[i]);
				cantidad++;
			}
		}
		puts(
				"\n=======================================================================");
	}

	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}

int abm_altaConfederacion(eConfederacion *lista, int tam, int id,
		eConfederacion Confederacion) {
	int rtn = 0;

	int index = abm_obtenerIndiceLibreConfederacion(lista, tam);
	//SI INDEX == -1 ARRAY LLENO
	//SI INDEX != -1 TENGO EN INDEX POSICION DE ARRAY LIBRE
	if (index != -1 && lista != NULL) {

		Confederacion.id = id;
		Confederacion.isEmpty = OCUPADO;
		lista[index] = Confederacion;

		rtn = 1;
	}
	return rtn;
}

int abm_listadoBajaConfederacion(eConfederacion *lista, int tam) {
	int rtn = -1;
	int idConfederacion;
	int flag = 0;
	int confirmar = 0;

	if (abm_mostrarTodosConfederacion(lista, tam)) {
		flag = 1;
	}

	if (flag) {
		utn_getNumero(&idConfederacion, "\nIngrese ID a dar de baja",
				"Valor incorrecto", 0, tam, 9999);

		while (abm_encontrarConfederacionPorId(lista, tam, idConfederacion)
				== -1) {
			puts("\n --- ID INEXISTENTE ---");

			utn_getNumero(&idConfederacion, "\nIngrese ID a dar de baja: ",
					"Valor incorrecto", 0, tam, 99999);
		}

		printf("\nUsuario a dar de baja: ");
		abm_mostrarUnConfederacion(
				lista[abm_encontrarConfederacionPorId(lista, tam,
						idConfederacion)]);
		utn_getNumero(&confirmar,
				"\nEsta seguro que desea dar de baja? (1. SI - 0. NO)",
				"Opcion incorrecta", 0, 1, 9999);
		if (confirmar) {
			abm_bajaConfederacion(lista, tam, idConfederacion);
		}
	}

	return rtn;
}

int abm_bajaConfederacion(eConfederacion *lista, int tam, int id) {
	int rtn = 0;
	int index;

	index = abm_encontrarConfederacionPorId(lista, tam, id);
	if (index != -1) {
		lista[index].isEmpty = BAJA;
		//printf("\n ---- Usuario: %s %s dado de baja exitosamente ---- \n",
		//	lista[index].name, lista[index].lastName);
		rtn = 1;
	}

	return rtn;
}

eConfederacion abm_modificacionConfederacion(eConfederacion Confederacion) {
	eConfederacion auxiliar = Confederacion;
	/*
	 utn_getString("Nuevo nombre: ", "Error, de nuevo", 9999, MAX_CHARS,
	 auxiliar.name);
	 utn_getString("Nuevo apellido: ", "Error, de nuevo", 9999, MAX_CHARS,
	 auxiliar.lastName);
	 */
	return auxiliar;
}

int abm_listadoModificacionConfederacion(eConfederacion *lista, int tam) {
	int rtn = 0;
	int idConfederacion;
	int index;
	int flag = 0;
	eConfederacion auxiliar;
	int confirmar = 0;

	if (abm_mostrarTodosConfederacion(lista, tam)) {
		flag = 1;
	}

	if (flag) {
		utn_getNumero(&idConfederacion, "\nIngrese ID a modificar: ",
				"Valor incorrecto", 0, tam, 99999);

		while (abm_encontrarConfederacionPorId(lista, tam, idConfederacion)
				== -1) {
			puts("NO EXISTE ID.");

			utn_getNumero(&idConfederacion, "\nIngrese ID a modificar: ",
					"Valor incorrecto", 0, tam, 99999);
		}

		index = abm_encontrarConfederacionPorId(lista, tam, idConfederacion);
		auxiliar = abm_modificacionConfederacion(lista[index]);

		printf("\nUsuario a modificar: ");
		abm_mostrarUnConfederacion(lista[index]);

		utn_getNumero(&confirmar,
				"\nEsta seguro que modificar el usuario? (1. SI - 0. NO)",
				"Opcion incorrecta", 0, 1, 9999);
		if (confirmar) {
			lista[index] = auxiliar;
			rtn = 1;
		}
	}

	return rtn;
}
