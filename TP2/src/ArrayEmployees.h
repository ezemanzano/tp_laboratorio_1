/*
 * employees.h
 *
 *  Created on: Sep 25, 2020
 *      Author: ezemanzano
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

#define LONG 51
#define TRUE 1
#define FALSE 0
#define EMPLOYEE_QTY 1000


typedef struct {
	char name[LONG];
	char lastname [LONG];
	int sector;
	float salary;
	int isEmpty;
	int id;
	} Employee;


int initEmployees(Employee * pArrayEmployee, int len);
int newEmployee (Employee* list, int len);
int printEmployees (Employee* list, int length);
int findEmployeeById(Employee* list, int len,int id);
int removeEmployee(Employee* list, int len, int id);
int modifyEmployee (Employee*list, int len , int id);
int sortEmployees(Employee* list, int len, int order);
int averageSalary(Employee * list , int len);
int printEmployeesAvarage (Employee* list, int length , float average);
int askForId (Employee * pArray,int limite,int * id);
#endif /* ARRAYEMPLOYEES_H_ */
