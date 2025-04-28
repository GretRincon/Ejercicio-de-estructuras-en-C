//Ejercicio 4 Guillermo Jair Montiel Juárez
/*
Crea una estructura Departamento que contenga un arreglo de Empleado dinámico (1.5 pts.)
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Empleado {
    char nombre[50]; // Nombre del empleado
    int edad; // Edad del empleado
} Empleado;

typedef struct Departamento {
    char area[50]; // Nombre del departamento
    int num_empleados; // Número de empleados en el departamento
    Empleado *empleados; // Puntero a un arreglo dinámico de empleados
} Departamento;

void imprimirEmpleado(Empleado empleado) {
    printf("Nombre: %s\n", empleado.nombre);
    printf("Edad: %d\n", empleado.edad);
}

int main() {
    Departamento depto;
    printf("Ingrese el nombre del departamento: ");
    scanf("%s", depto.area);
    printf("Ingrese el número de empleados: ");
    scanf("%d", &depto.num_empleados);

    // Asignamos memoria para el arreglo dinámico de empleados
    depto.empleados = (Empleado*)malloc(depto.num_empleados * sizeof(Empleado));
 
    if (depto.empleados == NULL) { // Verifica si la memoria fue reservada correctamente
          printf("Error, memoria no asignada\n");
          exit(1); // Termina el programa si no se pudo reservar memoria
     }
     
    //Leemos los datos de los empleados
    for(int i = 0; i < depto.num_empleados; i++) {
        printf("Ingrese el nombre del empleado %d: ", i + 1);
        scanf("%s", depto.empleados[i].nombre);
        printf("Ingrese la edad del empleado %d: ", i + 1);
        scanf("%d", &depto.empleados[i].edad);
    }

    // Imprimir los datos del departamento y de los empleados
    printf("\nDepartamento: %s\n", depto.area);
    for(int i = 0; i < depto.num_empleados; i++) {
        printf("\nEmpleado %d:\n", i + 1);
        imprimirEmpleado(depto.empleados[i]);
    }
    // Liberamos la memoria asignada
    free(depto.empleados);
    
    return 0;
}
