#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "LinkedList.h"
#include "Controller.h"



/** \brief Crea un espacio de memoria dinamica para un empleado
 *
 * \param void
 * \return int
 *
 */
Employee* employee_new(void)
{
	return (Employee*)malloc(sizeof(Employee));
}

/** \brief Crea un empleado pasandole los datos como parametro
 * \param char * idStr - id del usuario en formato string
 * \param char * nombre - nombre del usuario en formato string
 * \param char * horasTrabajdas - horas trabajdas del usuario en formato string
 * \param char * sueldo - Sueldo del usuario en formato string
 * \return devuelve por retorno el puntero del empleado si se cargo correctamente sino devuelve null para indicar error
 */


Employee* employee_newParametros(char * idStr,char* nombre,char * horasTrabajadas,char *sueldo)
{
	Employee* this = employee_new();
	if(this != NULL)
	{
		if((employee_setNombre(this, nombre)==0)
			&& (employee_setHorasTrabajadas(this, atoi(horasTrabajadas)))==0
			&& (employee_setSueldo(this, atoi(sueldo))) ==0
			&& employee_setId(this,atoi(idStr))==0)

		{
			return this;
		}
	}
	return NULL;
}
/** \brief Crea un empleado pasandole los datos como parametro
 * \param Employee *this -> puntero al empleado
 */


void employee_delete(Employee *this)
{
	if (this !=NULL)
	{
		free(this);
	}
}
/**
 * \brief Define el id de un empleado
 * \param Employee* this, Es el puntero al empleado.
 * \param int val -> valor a guardar
 * \return (-1) Error / (0) Ok
 */
int employee_setId(Employee* this,int val)
{
	int ret=-1;
	if(this!=NULL && val>0)
	{
		this->id =val;
		ret=0;
	}
	return ret;
}

/**
 * \brief Lee el nombre de un empleado
 * \param Employee* this, Es el puntero al array.
 * \param char * nombre, Puntero donde devuelve el nombre del empleado.
 * \return (-1) Error / (0) Ok
 */

int employee_getNombre(Employee* this,char* nombre)
{    if(this != NULL)
    {
        strncpy(nombre, this->nombre,(int)sizeof(this->nombre));
        return 0;
    }
    else
        return -1;
}
/**
 * \brief Define el nombre de un empleado
 * \param Employee* this, Es el puntero al empleado.
 * \param char *nombre -> valor a guardar
 * \return (-1) Error / (0) Ok
 */


int employee_setNombre(Employee* this,char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL && isValidNombre(nombre)==0)
    {
        strncpy(this->nombre,nombre,sizeof(this->nombre));
        retorno=0;
    }
    return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{    if(this != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        return 0;
    }
    else
        return -1;
}

/**
 * \brief Define el las horas Trabajadas de un empleado
 * \param Employee* this, Es el puntero al empleado.
 * \param int horasTrabajadas -> valor a guardar
 * \return (-1) Error / (0) Ok
 */

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    if(this != NULL && isValidHorasTrabajadas(horasTrabajadas)==0)
    {
        this->horasTrabajadas = horasTrabajadas;
        return 0;
    }
    return -1;
}



int isValidNombre(char * nombre)
{
	int retorno = 0;
		int i ;
		for (i = 0 ; i<=sizeof(nombre) && nombre[i] != '\0'; i++)
		{
		if	((nombre[i] < 'a' || nombre[i] > 'z') && (nombre[i] < 'A' || nombre[i] > 'Z'))
			{
				retorno = 1;
				break;
			}
		}
		return retorno;
}
/**
 * \brief Define el sueldo de un empleado
 * \param Employee* this, Es el puntero al empleado.
 * \param int sueldo -> valor a guardar
 * \return (-1) Error / (0) Ok
 */


int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno = -1;
    if(this != NULL && isValidSueldo(sueldo)==0)
    {
        this->sueldo = sueldo;
        retorno = 0;
    }
    return retorno;
}

/**
 * \brief Lee el sueldo de un empleado
 * \param Employee* this, Es el puntero al empleado.
 * \param int *sueldo -> puntero por donde se devuelve el sueldo.
 * \return (-1) Error / (0) Ok
 */

int employee_getSueldo(Employee* this,int* sueldo)
{    if(this != NULL)
    {
        *sueldo =this->sueldo;
        return 0 ;
    }
    else
        return -1;
}

int isValidSueldo(int sueldo)
{
	int retorno=-1;
	if(sueldo>=0)
	{
		retorno = 0;
	}
	return retorno;
}


int isValidHorasTrabajadas(int horasTrabajadas)
{
	int retorno=-1;
	if(horasTrabajadas>=0)
	{
		retorno = 0;
	}
	return retorno;
}

/**
 * \brief Lee el id de un empleado
 * \param Employee* this, Es el puntero al empleado.
 * \param int *id -> puntero por donde se devuelve el id.
 * \return (-1) Error / (0) Ok
 */


int employee_getId(Employee* this,int* id)
 {
	int retorno =-1;
	 if(this != NULL)
     {
         *id =this->id;
        retorno=0;
     }
  return retorno;
 }


/**
 * \brief funcion parametro para el ll_sort por nombre
 * \return 1 para mayor -1 para menor 0 si son iguales.
 */


int employee_ordenarEmpleados(void*thisA,void* thisB){
	Employee  * empleadoA= thisA;
	Employee * empleadoB= thisB;
	int retorno=-1;
	char nombreA[128];
	char nombreB[128];
	int rtaStrCmp;
	if (employee_getNombre(empleadoA, nombreA) == 0 &&	employee_getNombre(empleadoB, nombreB)==0)
	{
		rtaStrCmp=strcmp(nombreA,nombreB);
		if (rtaStrCmp>0)
		{
			retorno =1;
		}
		else if (rtaStrCmp<0)
		{
			retorno =-1;
		}
		else
		{
			retorno =0;
		}
	}

	return retorno;
}


