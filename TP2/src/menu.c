#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "utn.h"

/** \brief Menu for the user.
* position of the array
* \param list Employee* pArrayEmployee to array of employees
* \param len int Array length

*/

void menu(Employee * list , int len ){
	int menuOption;
	int idLookingFor;
	int indexID;
	int flagFirstInit = 0;
	int order;

	do{
			utn_getNumber(&menuOption, "\n Menu \n 1- ADD \n 2- MODIFY  \n 3- REMOVE \n 4- INFORM... \n 5- EXIT", "\n Error", 1,5, 2);
			switch(menuOption)
			{
			case 1:
				if (newEmployee(list, len) == 0){
					flagFirstInit = 1;
				} else
				{
					printf("Error- You run out of attempts...");
				}

				break;

			case 2:
				if (flagFirstInit == 1) {
				printEmployees (list, len);
				if (askForId(list, len,&idLookingFor) == 0)
				{
					if (modifyEmployee(list,len,idLookingFor)== 0)
					{
						printf("\nEmployee Succesfully modified.");
					}

				}
				else
				{
					printf("\nWe coudnt find the ID.");
				}
				} else {
					printf("\nThere is no employees to modify, please add a new one");
				}
				break;

			case 3:
				if (flagFirstInit == 1)
				{
					printEmployees (list, len);
					if (askForId(list, len,&idLookingFor) == 0 )
					{
						if (removeEmployee(list,len,idLookingFor)== 0)
						{
						printf("\nEmployee Succesfully removed.");
						}

					}
						else
					{
						printf("\n We coudnt find the ID");
					}
				}
				else
				{
					printf("\nThere is NO employees to remove, please add a new one");
				}
				break;
			case 4:

				if (flagFirstInit == 1){
					menu4(list,len);
				}
					else
				{
					printf("\nThere no employees to show, please add a new one");
				}
				break;
			}


		}while (menuOption!=5);
}

/** \brief Menu for the 4th option in the MAIN menu.
* position of the array
* \param list Employee* pArrayEmployee to array of employees
* \param len int Array length

*/


void menu4 (Employee * list, int len){
	int option;
	int order;
	if (utn_getNumber(&option, "\n What would you like to do? \n 1) SORT BY LASTNAME \n 2) SHOW AVARAGE SALARY \n 3) MAIN MENU", "Wrong - JUST CHOOSE 1 - 2 - 3) EXIT", 1, 3, 2) ==0){
		if (option == 1){
			askForOrder (&order);
			sortEmployees(list,len, order);
			printEmployees(list, len);
		} else if (option == 2){
			averageSalary(list, len);
		}
	}
}
