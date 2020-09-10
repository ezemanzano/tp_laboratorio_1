#include <stdio_ext.h>
#include <stdlib.h>

/**
 * \brief - Solicita UN numero flotante  al user
 * \param - char* pResultado - Puntero al espacio de memoria donde se guarda el numero.
 * \param - char* mensaje - Mensaje a mostrar al usuario
 * \param - char* mensajeError - Mensaje de error a mostrar al usuario
 * \param - int intentos - cantidad de intentos que se le da al usuario.
 * \return - retorna 0 si se pudo realizar correctamente la funcion. de caso contrario -1 indicando error.
 */


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
 * \brief - Solicita UN numero entero  al user
 * \param - char* pResultado - Puntero al espacio de memoria donde se guarda el numero.
 * \param - char* mensaje - Mensaje a mostrar al usuario
 * \param - char* mensajeError - Mensaje de error a mostrar al usuario
 * \param - int minimo - Establece limites desde donde empezar a aceptar lo que ingresa el usuario
 * \param - int maximo - Establece limites desde donde aceptar lo que ingresa el usuario
 * \param - int intentos - cantidad de intentos que se le da al usuario.
 * \return - retorna 0 si se pudo realizar correctamente la funcion. de caso contrario -1 indicando error.
 */

int utn_getMenu (int* pResultado, char* mensaje, char* mensajeError,int minimo, int maximo, int intentos)
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
/**
 * \brief - Realiza la suma entre 2 numeros.
 * \param - float operador1 - Parametro por el cual la funcion toma el primer operando
 * \param - float operador1 - Parametro por el cual la funcion toma el segundo operando
  * \return - resultado de la suma
 */

float sumar (float operador1,float operador2) {
	float resul;
	resul = operador1 + operador2 ;
	return resul ;
}
/**
 * \brief - Realiza la resta entre 2 numeros.
 * \param - float operador1 - Parametro por el cual la funcion toma el primer operando
 * \param - float operador1 - Parametro por el cual la funcion toma el segundo operando
  * \return - resultado de la resta
 */

float restar (float operador1,float operador2){
	float resul;
	resul = operador1 - operador2 ;
	return resul ;
}
/**
 * \brief - Realiza la multiplicacion entre 2 numeros.
 * \param - float operador1 - Parametro por el cual la funcion toma el primer operando
 * \param - float operador1 - Parametro por el cual la funcion toma el segundo operando
  * \return - resultado de la multiplicacion
 */

float multiplicar(float operador1, float operador2) {
		float resul;
		resul = operador1 * operador2 ;
		return resul ;
	}
/**
 * \brief - Realiza la division entre 2 numeros.
 * \param - float operador1 - Parametro por el cual la funcion toma el primer operando
 * \param - float operador1 - Parametro por el cual la funcion toma el segundo operando
 * \param - float* pResultado - Puntero donde se guarda el resultado de la division.
 * \return - Indica si hubo error - por ej al dividir por 0 .
 */

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
/**
 * \brief - Realiza el factorial de 1 numero
 * \param - float operador1 - Parametro por el cual la funcion toma el primer operando
  * \param - float* pResultado - Puntero donde se guarda el resultado del factorial.
 * \return - Indica si hubo error
 */
int factorial(float operador1,float* pFactorial){
		int factorialOperador1 = 1;
		int retorno = -1;
		if (pFactorial != NULL) {
			if (operador1>=0.00){
			for (float j = 1.00 ; j<=operador1; j++) {
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

/**
 * \brief - Imprime en consola el menu de opciones y el estado de los dos operandos a ingresar o ya ingresados.
 * \param - float operador1 - Parametro por el cual la funcion toma el primer operando
 * \param - float operador2 - Parametro por el cual la funcion toma el segundo operando
 * \param - ini init1 - Parametro por el cual se indica el estado de inicializacion
 *  del operador para poder indicar si estan ingresado o no.
* \param - ini init2 - Parametro por el cual se indica el estado de inicializacion
 *  del operador para poder indicar si estan ingresado o no.
 * \return - Indica si hubo error
 */

void  menuOpciones(float operando1,float operando2, int init1, int init2){
	printf ("1) Ingresar 1er Operando \n");
	printf ("2) Ingresar 2do Operando \n");
	printf ("3) Calcular las operaciones \n");
	printf ("4) Mostrar Resultados \n");
	printf ("5) SALIR \n");
	if (init1 == 0 && init2 == 0 ){
		printf ("Operando 1 = %.2f", operando1);
		printf ("operando 2 = %.2f", operando2);
	}else if (init1 == -1 && init2 == 0){
	printf ("Operando 1 = Sin ingresar");
	printf ("operando 2 = %.2f", operando2);
	} else if (init1 == 0 && init2 == -1){
		printf ("operando 1 = %.2f", operando1);
		printf ("Operando 2 = Sin ingresar");
	} else {
		printf ("Operando 1 = Sin ingresar");
		printf ("Operando 2 = Sin ingresar");
	}

}


