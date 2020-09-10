/*
 * utn.h
 *
 *  Created on: Sep 3, 2020
 *      Author: ezemanzano
 */

#ifndef UTN_H_
#define UTN_H_

int utn_getnumeroFloat (float* fResultado, char* mensaje, char* mensajeError, int intentos);
int utn_getMenu (int* pResultado, char* mensaje, char* mensajeError,char minimo, char maximo, int intentos);
float dividir (float operador1,float operador2, float* pResultado);
float sumar (float operador1,float operador2);
float restar (float operador1,float operador2);
float multiplicar(float operador1,float operador2);
int factorial(float operador1, float* pFactorial);
void  menuOpciones(float operando1,float operando2);

#endif /* UTN_H_ */
