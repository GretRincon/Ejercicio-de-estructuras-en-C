//Ejercicio 1 Guillermo Jair Montiel Juárez
//1. Usa un apuntador para modificar los datos de una estructura Coche. (0.5 pts.)

#include <stdio.h>
#include <stdlib.h>

typedef struct Coche {
    char marca[20];
    char modelo[20];
    int year;
} Coche;

void imprimirCoche(Coche coche){
    printf("Marca: %s\n", coche.marca);
    printf("Modelo: %s\n", coche.modelo);
    printf("Año: %d\n", coche.year);
}

int main (){
    Coche coche1 = {"BYD", "Dolphin", 2025};

    Coche *ptrCoche = &coche1; // Apuntador a la estructura Coche

    imprimirCoche(*ptrCoche); // Imprime los datos del coche original
    
    // Modificar los datos del coche usando el apuntador
    printf("Ingrese la nueva marca: ");
    scanf("%s", ptrCoche->marca);
    printf("Ingrese el nuevo modelo: ");
    scanf("%s", ptrCoche->modelo);
    printf("Ingrese el nuevo año: ");
    scanf("%d", &ptrCoche->year);

    imprimirCoche(*ptrCoche); // Imprime los datos del coche modificado

    return 0;
}