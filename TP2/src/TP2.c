
#include <stdio_ext.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "utn.h"
#include "menu.h"
#define EMPLOYEE_QTY 1000

int main(void) {
	Employee ArrayEmployees[EMPLOYEE_QTY];
	initEmployees(ArrayEmployees, EMPLOYEE_QTY);
	menu(ArrayEmployees,EMPLOYEE_QTY);

}
