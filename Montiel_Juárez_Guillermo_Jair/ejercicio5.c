//Ejercicio 5 Guillermo Jair Montiel Juárez
/*
Crea un arreglo dinámico de estructuras Libro usando Malloc. Toma el Hint del ejercicio
4. (1.5 pts.)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura de libro
typedef struct Libro {
    char titulo[100]; // Título del libro
    char autor[100]; // Autor del libro
    int year; // Año de publicación
    char editorial[100]; // Editorial del libro
} Libro;

//Función para imprimir los datos de un libro
void imprimirLibro(Libro libro) {
    printf("Título: %s\n", libro.titulo);
    printf("Autor: %s\n", libro.autor);
    printf("Año de publicación: %d\n", libro.year);
    printf("Editorial: %s\n", libro.editorial);
}

//Función principal
int main() {
    int total_libros; // Número de libros totales en el arreglo dinámico
    printf("Ingrese el número de libros: ");
    scanf("%d", &total_libros);

    // Asignamos memoria para el arreglo dinámico de libros
    Libro *libros = (Libro*)malloc(total_libros * sizeof(Libro));
    
    if (libros == NULL) { // Verifica si la memoria fue reservada correctamente
        printf("Error, memoria no asignada\n");
        exit(1); // Termina el programa si no se pudo reservar memoria
    }

    /* En algunos compiladores se tiene problemas para leer  scanf(" %[^\n]", que sirve para leer los espacios
    // Leemos los datos de los libros
    for(int i = 0; i < total_libros; i++) {
        printf("Ingrese el título del libro %d: ", i + 1);
        scanf(" %[^\n]", libros[i].titulo);
        printf("Ingrese el autor del libro %d: ", i + 1);
        scanf(" %[^\n]", libros[i].autor);
        printf("Ingrese la editorial del libro %d: ", i + 1);
        scanf(" %[^\n]", libros[i].editorial);
        printf("Ingrese el año de publicación del libro %d: ", i + 1);
        scanf("%d", &libros[i].year);
        printf("\n");
    }
    */

    // Leemos los datos de los libros
    for(int i = 0; i < total_libros; i++) {
        printf("Ingrese el título del libro %d: ", i + 1);
        getchar(); // Limpia el buffer de entrada antes de leer una cadena
        // Usamos fgets para leer cadenas con espacios
        // asigna memoria para la cadena de caracteres
        fgets(libros[i].titulo, sizeof(libros[i].titulo), stdin); //stdin se refiere a la entrada del teclado
        // strcspn busca el primer salto de línea y lo reemplaza por un terminador nulo
        libros[i].titulo[strcspn(libros[i].titulo, "\n")] = '\0'; // Elimina el salto de línea al final

        printf("Ingrese el autor del libro %d: ", i + 1);
        fgets(libros[i].autor, sizeof(libros[i].autor), stdin);
        libros[i].autor[strcspn(libros[i].autor, "\n")] = '\0';

        printf("Ingrese la editorial del libro %d: ", i + 1);
        fgets(libros[i].editorial, sizeof(libros[i].editorial), stdin);
        libros[i].editorial[strcspn(libros[i].editorial, "\n")] = '\0';

        printf("Ingrese el año de publicación del libro %d: ", i + 1);
        scanf("%d", &libros[i].year);
        printf("\n");
    }

    // Imprimimos los datos de los libros
    printf("Los libros disponibles son: \n");
    for(int i = 0; i < total_libros; i++) {
        printf("\nLibro %d:\n", i + 1);
        imprimirLibro(libros[i]);
    }

    // Liberamos la memoria asignada
    free(libros);

    return 0;
}   