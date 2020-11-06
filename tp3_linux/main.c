#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
    int option = 0;
    int flagInicio=0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
    	utn_getNumero(&option, "\nMenu:"
    			"\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)."
    			"\n2. Cargar los datos de los empleados desde el archivo data.bin (modo binario)"
    			"\n3. Alta de Empleado "
    			"\n4. Modificar datos de empleado"
    			"\n5. Baja de empleado"
    			"\n6. Listar empleados"
    			"\n7. Ordenar empleados" //hacer
    			"\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto)."
    			"\n9. Guardar los datos de los empleados en el archivo data.bin (modo binario)"
    			"\n10. Salir", "Error" - 1-10, 1, 10, 2);
        switch(option)
        {
            case 1:
            	if (flagInicio==0)
            	{
            		 controller_loadFromText("data.csv",listaEmpleados);
            		 flagInicio=1;
            	}
            	else
            	{
            		if (controller_deleteLinkedList(listaEmpleados)==0)
            		{
            			flagInicio=0;
            			listaEmpleados=ll_newLinkedList();
            		}
            	}

                break;
            case 2:
            	if (flagInicio==0)
				{
					 controller_loadFromBinary("data.bin",listaEmpleados);
					 flagInicio=1;
				}
				else
				{
					if (controller_deleteLinkedList(listaEmpleados)==0)
					{
						flagInicio=0;
						listaEmpleados=ll_newLinkedList();
					}
				}
				break;
            case 3:
            	if (flagInicio==1)
            	controller_addEmployee(listaEmpleados);
            	else
            		printf("\nNo se puede dar de alta sin antes cargar el archivo.");
				break;
            case 4:
            	if (flagInicio==1)
				controller_editEmployee(listaEmpleados);
				else
				printf("\nNo se puede editar un empleado sin antes cargar el archivo.");
               	break;
            case 5:
            	if (flagInicio==1)
				controller_removeEmployee(listaEmpleados);
				else
				printf("\nNo se puede eliminar un empleado sin antes cargar el archivo.");
				break;
            case 6:
            	if (flagInicio==1)
				controller_ListEmployee(listaEmpleados);
				else
				printf("\nNo se puede listar los empleados sin antes cargar el archivo.");
            	break;
            case 7:
            	if (flagInicio==1)
				controller_sortEmployee(listaEmpleados);
				else
				printf("\nNo se puede ordenar los empleados sin antes cargar el archivo.");
				break;
            case 8:
            	if (flagInicio==1)
				controller_saveAsText("data.csv",listaEmpleados);
				else
				printf("\nNo se puede guardar los empleados sin antes cargar el archivo.");
				break;
            case 9:
            	if (flagInicio==1)
				controller_saveAsBinary("data.bin",listaEmpleados);
				else
				printf("\nNo se puede guardar los empleados sin antes cargar el archivo.");
				break;
        }
    }while(option != 10);
    return 0;
}

