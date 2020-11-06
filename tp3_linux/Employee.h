#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char * idStr,char* nombre,char * horasTrabajadas,char *sueldo);
void employee_delete(Employee *this);

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int isValidHorasTrabajadas(int horasTrabajadas);
int isValidNombre(char * nombre);
int isValidSueldo(int sueldo);


int employee_ordenarEmpleados(void*thisA,void* thisB);
int	employee_generarNuevoId (void);
#endif // employee_H_INCLUDED
