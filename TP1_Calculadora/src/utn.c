#include <stdio_ext.h>
#include <stdlib.h>

int utn_getnumeroFloat (float* fResultado, char* mensaje, char* mensajeError, int intentos){

		int retorno = -1;
		int resultadoScan ;
		float bufferFloat;
		if (fResultado != NULL && mensaje != NULL && mensajeError != NULL && intentos>=0) {
		do {
			printf("%s\n", mensaje);
			__fpurge(stdin);
			resultadoScan = scanf ("%f", &bufferFloat);

			if (resultadoScan != 0 )
			{
			*fResultado= bufferFloat;
			retorno = 0;
			break;
			}
			else
			{
			printf("%s \n", mensajeError);
			intentos--;
			}
		} while (intentos >= 0 );

		} else {
			printf("\n INGRESA BIEN LOS PARAMETROS ");
		}
		return retorno;
}
/**
 * \brief - Solicita UN caracter al user
 * \param - char* pResultado - Puntero al espacio de memoria donde se guarda el caracter.
 * \param - char* mensaje - Mensaje a mostrar al usuario
 * \param - char* mensajeError - Mensaje de error a mostrar al usuario
 * \param - char minimo - valor minimo que se puede ingresar
 * \param - char maximo - valor maximo que se peude ingresar
 * \param - int intentos - cantidad de intentos que se le da al usuario.
 * \return -
 */

int utn_getMenu (int* pResultado, char* mensaje, char* mensajeError,char minimo, char maximo, int intentos)
{
	int retorno = -1;
	int resultadoScan ;
	int bufferInt;
	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL && maximo>minimo && intentos>=0) {
	do {
		printf("%s\n", mensaje);
		__fpurge(stdin);
		resultadoScan = scanf ("%d", &bufferInt);

		if (resultadoScan != 0 && bufferInt >= minimo && bufferInt <= maximo)
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
	} else {
		printf("\n INGRESA BIEN LOS PARAMETROS ");
	}
	return retorno;
}
float sumar (float operador1,float operador2) {
	float resul;
	resul = operador1 + operador2 ;
	return resul ;
}

float restar (float operador1,float operador2){
	float resul;
	resul = operador1 - operador2 ;
	return resul ;
}

float multiplicar(float operador1, float operador2) {
		float resul;
		resul = operador1 * operador2 ;
		return resul ;
	}


float dividir (float operador1,float operador2, float* pResultado) {
		float resul;
		int huboError;
		if (operador2 == 0.00) {
			huboError = 1;
		} else {
			resul = operador1 / operador2 ;
			*pResultado = resul;
			huboError =0 ;
		}
		return huboError;
}

// revisar el factorial - probar con int
int factorial(float operador1,float* pFactorial){
		int factorialOperador1 = 1;
		int retorno = -1;
		if (pFactorial != NULL) {
			if (operador1>=0.00){
			for (float j = 1.00 ; j<operador1; j++) {
			factorialOperador1 = factorialOperador1 * j;
			*pFactorial = factorialOperador1;
			retorno = 0;
		}
		} else if (operador1 == 0){
			*pFactorial = 1;
			retorno = 0;
		} else {
			retorno = -1;
		}

		} else {
			printf ("ERROR - INGRESAR BIEN LOS PARAMETROS");
		}
		return retorno;
}


void  menuOpciones(float operando1,float operando2){
	printf ("1) Ingresar 1er Operando \n");
	printf ("2) Ingresar 2do Operando \n");
	printf ("3) Calcular las operaciones \n");
	printf ("4) Mostrar Resultados \n");
	printf ("5) SALIR \n");
	printf ("Operando 1 = %.2f", operando1);
	printf ("operando 2 = %.2f", operando2);


}


