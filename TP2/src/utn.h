/*
 * utn.h
 *
 *  Created on: Sep 10, 2020
 *      Author: ezemanzano
 */

#ifndef UTN_H_
#define UTN_H_
#include "ArrayEmployees.h"
int utn_getNumber (int* pResultado, char* mensaje, char* mensajeError,int minimo, int maximo, int intentos);
int utn_getName (char * pResultado, int len, char * mensaje, char * mensajeError, int intentos);
int utn_getFloat (float* pResultado, char* mensaje, char* mensajeError,float minimo, float maximo, int intentos);
int askForOrder (int * order);

#endif /* UTN_H_ */
