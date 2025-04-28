//Crea un arreglo dinámico de estructuras Libro usando Malloc
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <stdbool.h>

//Definimos la estructura Libro
struct Libro {
    char titulo[50]; //Creo que 50 caracteres es suficiente
    char autor[50];
    int año;
    bool disponible; // 1 para disponible, 0 para no disponible
};


int main(){

    int nLibros;
    //Definimos un puntero a la estructura Libro
    struct Libro *biblioteca;

    //Pedimos al usuario el número de libros
    printf("Cuantos libros tiene la biblioteca?\n");
    scanf("%d", &nLibros);
    getchar(); // Debemos limpiamos el "buffer" de entrada o leera el salto de línea en la siguiente pregunta
    //Asignamos memoria para el arreglo de libros como en el ejercicio 4
    biblioteca = (struct Libro*)malloc(nLibros * sizeof(struct Libro));

    //Pedimos los datos de cada libro
    for (int i = 0; i < nLibros; i++) {
        printf("Ingrese el titulo del libro %d: ", i + 1);
        fgets(biblioteca[i].titulo,sizeof(biblioteca[i].titulo),stdin); //Usamos fgets para leer cadenas con espacios
        biblioteca[i].titulo[strcspn(biblioteca[i].titulo, "\n")] = 0; // Hay que eliminar el salto de línea para imprimir correctamente
        
        printf("Ingrese el autor del libro %d: ", i + 1);
        fgets(biblioteca[i].autor,sizeof(biblioteca[i].autor), stdin);
        biblioteca[i].autor[strcspn(biblioteca[i].autor, "\n")] = 0; //Esta linea de texto tambien

        printf("Ingrese el año del libro %d: ", i + 1);
        scanf("%d", &biblioteca[i].año);
        printf("El libro %d esta disponible? (1 para si, 0 para no): ", i + 1);
        scanf("%d", &biblioteca[i].disponible);
        getchar(); // Limpiamos de nuevo para el siguiente libro
    }

    //Imprimimos los datos de los libros
    printf("\nLibros en la biblioteca:\n");
    for (int i = 0; i < nLibros; i++) {
        printf("Libro %d. Titulo: %s, Autor: %s, Año: %d, Disponible: %s\n", 
               i + 1, 
               biblioteca[i].titulo, 
               biblioteca[i].autor, 
               biblioteca[i].año, 
               biblioteca[i].disponible ? "Si" : "No");
    }

    //Liberamos la memoria asignada
    free(biblioteca);

    return 0;
}