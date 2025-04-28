//Ejercicio 7

/*
Crea un programa donde simule la gestión de pacientes de un hospital (nombre, edad,
diagnostico y prioridad). En prioridad ( 1- 3, donde 1 es urgente) (3 pts.). Hint: Use una
lista enlazada, donde cada nodo sea un Paciente y un apuntador al siguiente nodo.

1. Funciones para: Un paciente al inicio de la lista, Eliminar un paciente por nombre,
Imprimir la lista actualizada
2. En el Main: Se añaden 10 pacientes con diferentes prioridades, se eliminan a 2
pacientes en específicos, y se actualiza la lista.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Paciente {
    char nombre[50];
    int edad;
    char diagnostico[100];
    int prioridad; // Prioridad del paciente (1-3) donde 1 es urgente
    struct Paciente *siguiente; // Puntero al siguiente nodo
} Paciente;

// Función para añadir un paciente al inicio de la lista
void nuevoPaciente(Paciente **inicio, char *nombre, int edad, char *diagnostico, int prioridad) {
    // Asigna memoria para un nuevo nodo
    Paciente *nuevo = (Paciente*)malloc(sizeof(Paciente));
    if (nuevo == NULL) {
        printf("Error al asignar memoria\n");
        exit(1);
    }
    // Asigna valores al nuevo nodo
    strcpy(nuevo->nombre, nombre);
    nuevo->edad = edad;
    strcpy(nuevo->diagnostico, diagnostico);
    nuevo->prioridad = prioridad;
    nuevo->siguiente = *inicio; // El nuevo nodo apunta al inicio actual de la lista
    *inicio = nuevo; // Actualiza el inicio de la lista
}

// Función para eliminar un paciente por nombre
void eliminarPaciente(Paciente **inicio, char *nombre) {
    //Recorre la lista buscando el paciente
    Paciente *actual = *inicio;
    // Puntero al nodo anterior para poder eliminar el nodo actual sin perder la referencia
    Paciente *anterior = NULL;
    // Busca el paciente en la lista enlazada
    // Primero verifica que no se haya llegado al final de la lista
    // y que el nombre del paciente actual no sea el que se busca
    while (actual != NULL && strcmp(actual->nombre, nombre) != 0) { //strcmp compara cadenas
        // Si el paciente no es el que se busca, avanza al siguiente nodo
        anterior = actual;
        actual = actual->siguiente;
    }

    // Si el paciente no existe, imprime un mensaje y termina la función
    if (actual == NULL) {
        printf("El paciente %s no existe\n", nombre);
        return;
    }

    // Si el paciente es el primero en la lista
    if (anterior == NULL) {
        *inicio = actual->siguiente; // Actualiza el inicio de la lista
    // Si el paciente no es el primero, enlaza el nodo anterior con el siguiente del nodo actual
    } else {
        //Actualiza el puntero del nodo anterior para que apunte al siguiente nodo del nodo actual
        anterior->siguiente = actual->siguiente; // Elimina el nodo actual de la lista
    }

    free(actual); // Libera la memoria del nodo eliminado
}

// Función para imprimir la lista de pacientes
void imprimirLista(Paciente *inicio) {
    Paciente *actual = inicio; // Comienza desde el inicio de la lista
    // Recorre la lista e imprime los datos de cada paciente
    while (actual != NULL) {
        printf("Nombre: %s, Edad: %d, Diagnostico: %s, Prioridad: %d\n",
               actual->nombre, actual->edad, actual->diagnostico, actual->prioridad);
        actual = actual->siguiente; // Avanza al siguiente nodo
    }
}

//Función para liberar la memoria de la lista al final del programa
void liberarLista(Paciente *inicio) {
    Paciente *actual = inicio; // Comienza desde el inicio de la lista
    Paciente *siguiente; // Puntero para almacenar el siguiente nodo
    // Recorre la lista y libera la memoria de cada nodo
    while (actual != NULL) {
        siguiente = actual->siguiente; // Guarda el siguiente nodo
        free(actual); // Libera la memoria del nodo actual
        actual = siguiente; // Avanza al siguiente nodo
    }
}

int main() {
    // Creamos una lista vacía
    Paciente *inicio = NULL; 
    char nombre[50], diagnostico[100];
    int edad, prioridad;

    // Añadimos 10 pacientes con diferentes prioridades usando la función nuevoPaciente
    printf("Ingrese los datos de 10 pacientes:\n");
    for (int i = 0; i < 10; i++) {
        printf("Paciente %d:\n", i + 1);
        printf("Nombre: ");
        // Usamos " %[^\n]" para leer una línea completa con espacios
        scanf(" %[^\n]", nombre);
        printf("Edad: ");
        scanf("%d", &edad);
        printf("Diagnostico: ");
        scanf(" %[^\n]", diagnostico);
        printf("Prioridad (1-3): ");
        scanf("%d", &prioridad);
        printf("\n");
        // Llama a la función nuevoPaciente para añadir el paciente a la lista
        nuevoPaciente(&inicio, nombre, edad, diagnostico, prioridad);
    }

    // Imprimimos la lista de pacientes
    printf("Lista de pacientes:\n");
    imprimirLista(inicio);
    printf("\n");

      // Solicitamos eliminar a 2 pacientes específicos
      for (int i = 0; i < 2; i++) {
        printf("\nIngrese el nombre del paciente a eliminar (%d de 2): ", i + 1);
        scanf(" %[^\n]", nombre);
        eliminarPaciente(&inicio, nombre);
    }

    // Imprimimos la lista actualizada
    printf("\n");
    printf("Lista de pacientes actualizada:\n");
    imprimirLista(inicio);

    // Liberamos la memoria de la lista para evitar fugas de memoria
    liberarLista(inicio);
    
    return 0;

    }