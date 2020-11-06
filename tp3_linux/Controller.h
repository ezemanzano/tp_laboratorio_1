int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_addEmployee(LinkedList* pArrayListEmployee);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);


int employee_lastId(LinkedList* pArrayListEmployee);
int controller_buscarEmployeeIndicePorId(LinkedList* pArrayListEmployee, int idBuscar, int*indexEncontrado);
int controller_encontrarLastId(LinkedList* pArrayListEmployee);
int controller_deleteLinkedList(LinkedList * this);
