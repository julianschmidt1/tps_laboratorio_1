#ifndef PARSER_H_
#define PARSER_H_

int parser_JugadorFromText(FILE *pFile, LinkedList *pArrayListJugador);
int parser_JugadorFromBinary(FILE *pFile, LinkedList *pArrayListJugador);
int parser_SeleccionFromText(FILE *pFile, LinkedList *pArrayListSeleccion);
int parser_ObtenerUltimoId(FILE *pFile, int *pId);
#endif /* PARSER_H_ */
