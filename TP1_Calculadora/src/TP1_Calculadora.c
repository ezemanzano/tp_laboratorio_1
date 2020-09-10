

#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"

int main(void) {
		float numero1 ;
		float numero2 ;
		float resultados[6];
		char operaciones[6][14] = {"suma","resta","multiplicacion","division","factorial","factorial"};
		int opcionMenu;
		int flagCuentas = 0;
		int flagOperando1 = -1;
		int flagOperando2 = -1;


		menuOpciones(numero1,numero2,flagOperando1, flagOperando2);
		utn_getMenu(&opcionMenu, "\n Que desea hacer?", "\n Error - opcion incorrecta",1, 5, 3);
		do {
			switch (opcionMenu) {
			case 1 :
					flagOperando1 = utn_getnumeroFloat (&numero1,"\n Ingrese numero... ","\n Error - INGRESAR NUMERO",3);
					if (flagOperando1 == 0) {
					} else 	{
					printf("Se acabaron los intentos");
					}

					break;
			case 2 :
					flagOperando2 = utn_getnumeroFloat (&numero2,"\n Ingrese numero... ","\n Error - INGRESAR NUMERO",3) ;
					if (flagOperando2 == 0) {
						} else	{
							printf("Se acabaron los intentos");
						}

						break;
			case 3 :
						if ( flagOperando1 == 0 && flagOperando2 == 0 ) {
						resultados[0] = sumar(numero1,numero2);
						resultados[1] = restar(numero1,numero2);
						resultados[2] = multiplicar(numero1,numero2);
						if (dividir(numero1,numero2,&resultados[3]) == 0){

						} else {
							printf ("\n No se puede dividir por cero");
							}
						if (factorial(numero1,&resultados[4]) ==0 ){
							} else {
							printf ("\n Error primer operando negativo - no se pudo");
							}
							if (factorial(numero2,&resultados[5]) ==0 ){
							} else {
							printf ("\n Error primer operando negativo - no se pudo");
							}
						printf ("\n Operaciones Realizadas...");
						flagCuentas = 1;
						} else if (flagOperando1 != 0 && flagOperando2 == 0) {
							printf("\n No ingreso el primer Operando...");
						} else if (flagOperando2 != 0 && flagOperando1 == 0){
							printf("\n No ingreso el segundo Operando...");
						}
							break;
			case 4:
						if (flagCuentas == 1){
							for (int i = 0; i<6 ; i++) {
								printf ("\n El resultado de %s es : %.2f \n",operaciones[i],resultados[i]);
							}
						}else{
							printf("\n No realizò las cuentas.... \n");
							break;
						}
						break;
						default :
							printf("\n error");
							break;
			}
			menuOpciones(numero1,numero2,flagOperando1, flagOperando2);
			utn_getMenu(&opcionMenu, "\n Que desea hacer?", "Error - opcion incorrecta",1, 5, 3);
			}while(opcionMenu != 5);


}


