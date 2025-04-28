//Crea una estructura Departamento que contenga un arreglo de EMpleado dinámico 
//usen Malloc 
//para la asignacion de memoria puede usar sales.employees=(EMployee*)malloc(sales.nEmployees*sizeof(Employee));
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Definamos una estructura empleado, nombre, id y salario
struct Employee {
    char name[50];
    int id;
    float salary;
};
//Ahora una estructura departamento con nombre, numero de empleados y un puntero a un arreglo de empleados
struct Department {
    char name[50];
    int nEmployees;
    struct Employee *employees; // Puntero a un arreglo de empleados
};

int main(){
    //Creemos un departamento, llamado ventas (sales), al cual pediremos definir el # de empleados
    struct Department sales;
    strcpy(sales.name, "Ventas");
    printf("Cuantos empleados tiene el departamento %s?\n", sales.name);
    scanf("%d", &sales.nEmployees);
    //Definimos el array dinámico sales.employees, al cual le asignas memoria para nEmployees 
    sales.employees=(struct Employee*)malloc(sales.nEmployees*sizeof(struct Employee));
    //Cuando quieras acceder a los Employee puedes hacerlo como un arreglo sales.employees[i] 
    //Y para acceder a sus atributos sales.employees[i].name  
    

    //Para probarlo hagamos que puedas ingresar los datos
    for (int i = 0; i < sales.nEmployees; i++) {
        printf("Ingrese el nombre del empleado %d: ", i + 1);
        scanf("%s", sales.employees[i].name);
        printf("Ingrese el ID del empleado %d: ", i + 1);
        scanf("%d", &sales.employees[i].id);
        printf("Ingrese el salario del empleado %d: ", i + 1);
        scanf("%f", &sales.employees[i].salary);
    }
    //Ahora imprimamos los datos de los empleados
    printf("Empleados del departamento %s:\n", sales.name);
    for (int i = 0; i < sales.nEmployees; i++) {
        printf("Empleado %d. %s, ID: %d, Salario: %f\n", i + 1, sales.employees[i].name, sales.employees[i].id, sales.employees[i].salary);
    }
    //Y liberamos la memoria asignada
    free(sales.employees);
    return 0;
}
