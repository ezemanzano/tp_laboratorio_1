#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"
#include <string.h>
#include "parser.h"
#include "Controller.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	FILE* pFile;
	if (pArrayListEmployee!=NULL)
	{
		pFile = fopen(path,"r");
		if (pFile == NULL)
		{
			retorno=-1;
		}
		if (parser_EmployeeFromText(pFile, pArrayListEmployee)==0)
		{
			printf("\n-Carga de datos Correcta-");
			retorno =0;
	}

	}



	return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    if(pArrayListEmployee !=NULL)
    {
        FILE* file;
        file = fopen(path, "rb");
        if (file!=NULL)
        {
		 if(parser_EmployeeFromBinary(file,pArrayListEmployee)==0)
		{
			printf("\n-Carga de datos correcta-");
			retorno =0;
		}
        }

    }
    else
    {
    printf("\n ERROR");
    }
    return retorno;
} /*
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	FILE* pFile;
	if (pArrayListEmployee!=NULL)
	{
		pFile = fopen(path,"rb");
		if (pFile == NULL)
		{
			retorno=-1;
		}
		else
		{
		parser_EmployeeFromBinary(pFile, pArrayListEmployee);
		retorno = 0;
		}
	}

return retorno;
}
*/
/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{

	int retorno=-1;
	char nombre[64];
	int sueldo;
	int horasTrabajadas;

 	if (utn_getNombre(nombre,64, "\nIngrese nombre","Error",2)== 0 &&
 		utn_getNumero(&sueldo,"\nIngrese Sueldo", "error",0,99999,2)== 0 &&
		utn_getNumero(&horasTrabajadas,"\nIngrese horas trabajadas", "error",0,9999,2)== 0)

 	{
 		Employee * Aux = employee_new();
 		if(Aux!=NULL)
 		{
 			employee_setNombre(Aux, nombre);
 			employee_setHorasTrabajadas(Aux, horasTrabajadas);
 			employee_setSueldo(Aux, sueldo);
 			employee_setId(Aux, controller_encontrarLastId(pArrayListEmployee));
 		}
 		ll_add(pArrayListEmployee,Aux);
 		printf("\nAlta de empleado correcta..");
 		retorno=0;


 	}
 	return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int retorno =-1;
	int idAModificar;
	int auxIndex;
	int auxId;
	int auxHT;
	int auxSueldo;
	char auxNombre[128];
	char nombreModify[128];
	int horasTModify;
	int sueldoModify;
	int opcionModify;
	Employee * empleadoAux = employee_new();
	if (empleadoAux!=NULL)
	{
		controller_ListEmployee(pArrayListEmployee);
		if (utn_getNumero(&idAModificar,"ingrese ID a Modificar","Error",0,9999, 2)==0)
		{
			if (controller_buscarEmployeeIndicePorId(pArrayListEmployee, idAModificar, &auxIndex)==0)
			{
				empleadoAux = ll_get(pArrayListEmployee, auxIndex);
				employee_getId(empleadoAux, &auxId);
				employee_getHorasTrabajadas(empleadoAux, &auxHT);
				employee_getSueldo(empleadoAux, &auxSueldo);
				employee_getNombre(empleadoAux, auxNombre);
				printf("\nEmpleado a modificar:");
				printf("\n ID   NOMBRE            HORAS TRABAJADAS    SUELDO\n");
				printf(" %04d | %-15s | %-16d | %-6d \n", auxId, auxNombre, auxHT, auxSueldo);
				if (utn_getNumero(&opcionModify,"\nQue desea modificar? \n1- Nombre 2- Sueldo 3-HorasTrabajadas", "error", 1, 4, 2)==0)
				{
					switch(opcionModify)
					{
					case 1:
						if (utn_getNombre(nombreModify,128, "\nIngrese nuevo nombre","Error",2)== 0)
							{
							employee_setNombre(empleadoAux, nombreModify);
							}
						break;
					case 2:
						if (utn_getNumero(&sueldoModify, "\nIngrese nuevo sueldo","Error",0,99999,2)== 0)
							{
							employee_setSueldo(empleadoAux, sueldoModify);
							}
						break;
					case 3:
						if (utn_getNumero(&horasTModify, "\nIngrese nuevas horas Trabajadas","Error",0,99999,2)== 0)
							{
							employee_setSueldo(empleadoAux, sueldoModify);
							}
						break;
					}
					printf("\nEmpleado Modificado correctamente.");
				}

			}
		}
	}

    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int idABorrar;
	int auxIndex;
	int opcion;
	Employee * empleadoAux;
			controller_ListEmployee(pArrayListEmployee);
			if (utn_getNumero(&idABorrar,"ingrese ID a Borrar","Error",0,99999, 2)==0)
			{
				if (controller_buscarEmployeeIndicePorId(pArrayListEmployee, idABorrar, &auxIndex)==0)
					{
						if(utn_getNumero(&opcion,"Desea continuar? 1 Si - 2 No", "Error", 1, 2, 2)==0)
						{
							if(opcion==1)
							{
							ll_remove(pArrayListEmployee, auxIndex);
							empleadoAux =ll_get(pArrayListEmployee, auxIndex);
							employee_delete(empleadoAux);
							printf("\nEmpleado eliminado.");
							}
							else
							{
								printf("\nVolviendo la menu princial..");
							}
						}
					}
				else
					printf("No se encotnro el id");
			}
return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 1;
    int auxId;
    int auxHT;
    int auxSueldo;
    char auxNombre[128];
    int len = ll_len(pArrayListEmployee);
    Employee* empleado = employee_new();
    if ( empleado != NULL && len != 0)
    {
        printf("\n ID   NOMBRE            HORAS TRABAJADAS    SUELDO\n");
        for (int i = 1; i < len; i++)
        {
            empleado = ll_get(pArrayListEmployee, i);
            employee_getId(empleado, &auxId);
            employee_getHorasTrabajadas(empleado, &auxHT);
            employee_getSueldo(empleado, &auxSueldo);
            employee_getNombre(empleado, auxNombre);
            printf(" %04d | %-15s | %-16d | %-6d \n", auxId, auxNombre, auxHT, auxSueldo);
         }
        retorno = 0;
    }
    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int ordenar;
	utn_getNumero(&ordenar, "Como desea ordenar? 0-ASC 1-DESC", "Error", 0, 1, 2);
	printf("gat");
	if (ll_sort(pArrayListEmployee,employee_ordenarEmpleados, ordenar) == 0)
	{
		printf("\nSe ordenaron los empleados");
	}
	else
	{
		printf("\nError");
	}
	return retorno;

}


/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int idAux;
	int horasAux;
	int sueldoAux;
	char nombreAux[128];
	int len = ll_len(pArrayListEmployee);
	Employee *empleado;
	empleado=employee_new();
	FILE* pFile;
	if (empleado!=NULL&&pArrayListEmployee!=NULL&&len>0)
	{
		pFile = fopen(path,"w");
				fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n");
				for (int i= 0;i<len;i++)
				{
					empleado=ll_get(pArrayListEmployee, i);
					if (employee_getId(empleado,&idAux)==0 &&
						employee_getNombre(empleado,nombreAux)==0	&&
						employee_getHorasTrabajadas(empleado,&horasAux)==0&&
						employee_getSueldo(empleado,&sueldoAux)==0)
					{
						fprintf(pFile,"%d,%s,%d,%d\n",idAux,nombreAux,horasAux,sueldoAux);
						retorno=0;
					}

				}
				printf("\nEl archivo fue guardado exitosamente..");
			}

	fclose(pFile);
return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	    Employee* empleadoAux;
	    int len = ll_len(pArrayListEmployee);
	    FILE* pFile;
	    if(path != NULL && pArrayListEmployee != NULL &&  len > 0)
	    {
	        pFile = fopen(path,"wb");
	        if (pFile != NULL)
	        {
	            for(int i = 1; i < len; i++)
	            {
	                empleadoAux = ll_get(pArrayListEmployee, i);
	                fwrite(empleadoAux,sizeof(Employee),1,pFile);
	            }
	            retorno = 0;
	            printf("\nEl archivo fue guardado exitosamente..");
	        }
	        else
	        {
	            printf("No se pudo abrir el archivo\n");
	        }
	    }
	    fclose(pFile);
	    return retorno;
}

/** \brief Recorre la lista buscando el indice donde està ubicado el id ingresado por paramentro
 *
 * \param int idBuscar- Id a buscar en la lista
 * int * indiceEncontrado - Devuelve por puntero el indice
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */


int controller_buscarEmployeeIndicePorId(LinkedList* pArrayListEmployee, int idBuscar, int*indexEncontrado){
	int retorno =-1;
	int idEncontrado;
	int i;
	Employee * empleado=employee_new();
	int len = ll_len(pArrayListEmployee);
	for (i=0;i<len;i++)
	{
		empleado = ll_get(pArrayListEmployee, i);
		employee_getId(empleado, &idEncontrado);

		if (idBuscar == idEncontrado)
		{
			*indexEncontrado = i;
			retorno = 0;
			break;
		}
	}
	return retorno;
}

/** \brief Recorre la lista buscando el id maximo
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_encontrarLastId(LinkedList* pArrayListEmployee){
	int retorno=-1;
	int auxId;
	int max;
	Employee * empleadoAux;
	int len = ll_len(pArrayListEmployee);
	if (pArrayListEmployee!=NULL)
	{
		for (int i = 0;i<len;i++)
		{
			empleadoAux=ll_get(pArrayListEmployee, i);
			employee_getId(empleadoAux, &auxId);
			if (i==1||auxId>max)
			{
				max = auxId;
				retorno = max+1;
			}
		}
	}
	return retorno;
}

/** \brief Borra la lista si se desea.
 * \param pArrayListEmployee LinkedList*
 * \return -1 error 0 ok
 *
 */

int controller_deleteLinkedList(LinkedList * this){
	int retorno=-1;
	int opcion;
	printf("\n Ya se cargò una lista previamente...");
	if (utn_getNumero(&opcion,"Que desea hacer? 0-Borrar la lista anterior y cargar una nueva 1-Volver al menu anterior", "\nOpcion incorrecta", 0, 1, 2)==0)
	{
		if (opcion==0)
		{
			if (ll_clear(this)==0 &&  ll_deleteLinkedList(this)==0)
			{
				printf("\nLa lista fue eliminada \n No hay listas cargadas");
				retorno=0;
			}

		}
	}

	return retorno;
}

