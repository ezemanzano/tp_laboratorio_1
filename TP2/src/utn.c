/*
 * utn.c
 *
 *  Created on: Sep 10, 2020
 *      Author: ezemanzano
 */

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "menu.h"



static int myGets (char* cadena, int longitud);
static int getInt (int* pResultado);
static int getFlt (float* pResultado);
static int esNumerica (char* cadena);
static int esNombre (char*cadena, int limite);

/** \brief Get data from the console.
* position of the array
* \param char * cadena -> Pointer where to save the fgets.
* \param int longitud -> cadena length
* \return 1
*/
static int myGets (char* cadena, int longitud){
		__fpurge (stdin);
		fgets(cadena,longitud,stdin);
		cadena[strnlen(cadena,sizeof(cadena))-1]='\0';
		return 1;
}
/** \brief Get an integer with mygets and checks if the string are just numbers.
* position of the array
* \param int * pResultado -> Pointer where to save the result
* return 0 if success otherwise 1
*/
static int getInt (int* pResultado){
	int retorno = -1 ;
	char buffer[4096];
	if (myGets(buffer,sizeof(buffer)) == 1  && esNumerica(buffer)== 1){
		retorno = 0;
		*pResultado = atoi(buffer);
	}
	return retorno;
}
/** \brief Get a float  and checks if the string are just numbers with one dot.
* position of the array
* \param float * pResultado -> Pointer where to save the result
* return 0 if success otherwise 1
*/

static int getFlt (float* pResultado){
	int retorno = -1 ;
	char buffer[4096];
	if (myGets(buffer,sizeof(buffer)) == 1  && esNumerica(buffer)== 1){
		retorno = 0;
		*pResultado = atof(buffer);
	}
	return retorno;
}
/** \brief checks if the string is made up of just numbers, also checks the positivity of the number and the excess of commas.
* position of the array
* \param float * pResultado -> Pointer where to save the result
* return 0 if success otherwise 1
*/

int esNumerica(char*cadena){
	int retorno = 1 ;
	int i = 0;
	int contadorPuntos = 0 ;
	if (cadena[0] == '-' || cadena[0] == '+'){
		i = 1;
	}
	for (;cadena[i] != '\0';i++) {
		if (cadena[i] > '9' || cadena[i] < '0')
		{
			if (cadena[i] == '.'){
				contadorPuntos++;
				if (contadorPuntos >1){
					retorno = 0;
					break;
				}
			}
			else
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
/** \brief get a number from the user.
* \param int * order -> Pointer where to save the result
* \param char * mensaje -> message to show
* \param char * mesajeError -> message to show in case of error.
* \param int minimo -> min number accepted by the program
* \param int maximo -> max number accepted by the program
* \param int intentos -> max amount of attempts.
* return 0 if success otherwise 1
*/
int utn_getNumber (int* pResultado, char* mensaje, char* mensajeError,int minimo, int maximo, int intentos){

	int retorno = -1;
	int bufferInt;
	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL && maximo>minimo && intentos>=0) {
	do {
		printf("%s\n", mensaje);
		if (getInt(&bufferInt) == 0 && bufferInt >= minimo && bufferInt <= maximo)
		{
		*pResultado = bufferInt;
		retorno = 0;
		break;
		}
		else
		{
		printf("%s \n", mensajeError);
		intentos--;
		}
	} while (intentos >= 0 );

	}
	return retorno;
}
/** \brief get a float number from the user.
* \param float * pResutlado -> Pointer where to save the result
* \param char * mensaje -> message to show
* \param char * mesajeError -> message to show in case of error.
* \param int minimo -> min number accepted by the program
* \param int maximo -> max number accepted by the program
* \param int intentos -> max amount of attempts.
* return 0 if success otherwise 1
*/
int utn_getFloat (float* pResultado, char* mensaje, char* mensajeError,float minimo, float maximo, int intentos){

	int retorno = -1;
	float bufferFloat;
	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL && maximo>minimo && intentos>=0) {
	do {
		printf("%s\n", mensaje);
		if (getFlt(&bufferFloat) == 0 && bufferFloat >= minimo && bufferFloat <= maximo)
		{
		*pResultado = bufferFloat;
		retorno = 0;
		break;
		}
		else
		{
		printf("%s \n", mensajeError);
		intentos--;
		}
	} while (intentos >= 0 );

	}
	return retorno;
}

/** \brief get a string with just letters from the user.
* \param char * pResutlado -> Pointer where to save the result
* \param char * mensaje -> message to show
* \param char * mesajeError -> message to show in case of error.
* \param int len -> max size of the result

* return 0 if success otherwise 1
*/
int utn_getName (char * pResultado, int len, char *mensaje, char* mensajeError, int intentos){
	int retorno = -1 ;
	char buffer[4096];
	if (pResultado != NULL && len>0 && mensaje != NULL && mensajeError != NULL  && intentos>=0) {
		do {
			printf("%s\n", mensaje);
			if ( myGets(buffer,sizeof(buffer)) && esNombre(buffer,len) )
			{
				retorno = 0;
				strncpy(pResultado,buffer,len);
				break;
			}
			else
			{
			printf("%s \n", mensajeError);
			intentos--;
			}
		} while (intentos >= 0 );

		}



	return retorno;
}
/** \brief checks if the string is made up of just letters.
* position of the array
* \param char * pResultado -> Pointer where to save the result
* \param int limite -> max size of the string
* return 0 if success otherwise 1
*/

static int esNombre (char*cadena, int limite) {
	int retorno = 1;
	int i ;
	for (i = 0 ; i<=limite && cadena[i] != '\0'; i++){
		if	((cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < 'A' || cadena[i] > 'Z'))
		{
			retorno = 0;
			break;
		}}
	return retorno;
}


/** \brief ask the user for the order
* position of the array
* \param int * order -> Pointer where to save the result
* return 0 if success otherwise 1
*/

int askForOrder (int * order){
	int output = -1;
	int whichOrder;
if (utn_getNumber(&whichOrder, "\n Input 0 to order from a-z, otherwise input 1", "Error", 0, 1, 2) == 0 )
			{
				*order = whichOrder;
				output = 0;
			}
			else
			{
				printf("error");
			}
return output;

}

