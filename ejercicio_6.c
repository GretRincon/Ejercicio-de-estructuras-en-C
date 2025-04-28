//Reutilizamos el codigo del ejercicio 5 de la carpeta Rincon_Villa_Gretchen_Itzel 
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <stdbool.h>

//Definimos la estructura Libro
struct Libro {
    char titulo[50]; 
    char autor[50];
    int año;
    bool disponible; 
};

void imprimirBiblioteca(struct Libro *biblioteca, int nLibros) {
    //MOvemos esta parte del codigo a una funcion
    printf("\nLibros en la biblioteca:\n");
    for (int i = 0; i < nLibros; i++) {
        printf("Libro %d. Titulo: %s, Autor: %s, Año: %d, Disponible: %s\n", 
               i + 1, 
               biblioteca[i].titulo, 
               biblioteca[i].autor, 
               biblioteca[i].año, 
               biblioteca[i].disponible ? "Si" : "No");
    }
}

void pedirDatosLibro(struct Libro *biblioteca, int nLibros){
    //Movemos esta parte del codigo a una funcion
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
}

void eliminarLibro(struct Libro *biblioteca, int *nLibros){
    int libroEliminar;
    printf("¿Qué libro quieres eliminar? Ingresa el número (1-%d): ", *nLibros);
    scanf("%d", &libroEliminar);
    getchar(); 

    if (libroEliminar < 1 || libroEliminar > *nLibros) {
        printf("Número de libro inválido.\n");
        return;
    }
    //AHora hay que mover los libros que van despues del recien eliminado
    for (int i = libroEliminar - 1; i < *nLibros - 1; i++) {
        biblioteca[i] = biblioteca[i + 1];
    }
    *nLibros = *nLibros - 1; //Y al conteo de libros le restamos el eliminado

    //Imprimimos la biblioteca actualizada
    //imprimirBiblioteca(biblioteca, *nLibros);
    //ELimine que se imprima automaticamente para agregarlo en el menu
}

void añadirLibro(struct Libro *biblioteca, int *nLibros){
    //Primero debemos aumentar el tamaño del arreglo 
    biblioteca = realloc(biblioteca, (*nLibros + 1) * sizeof(struct Libro));
    pedirDatosLibro(&biblioteca[*nLibros], 1); //Pedimos los datos del nuevo libro
    *nLibros += 1; //Aumentamos el numero de libros
    //imprimirBiblioteca(biblioteca, *nLibros); //Imprimimos la biblioteca actualizada
}

int main(){

    int nLibros;
    struct Libro *biblioteca;

    //Pedimos al usuario el número de libros. Usaremos 7 para el ejemplo en main
    printf("Cuantos libros tiene la biblioteca?\n");
    scanf("%d", &nLibros);
    getchar(); 
    biblioteca = (struct Libro*)malloc(nLibros * sizeof(struct Libro));

    pedirDatosLibro(biblioteca, nLibros);

    imprimirBiblioteca(biblioteca, nLibros);


    //Agregemos un menu para manejar la biblioteca
    int opcion;
    do {
        printf("\nMenu:\n");
        printf("1. Eliminar libro\n");
        printf("2. Añadir libro\n");
        printf("3. Imprimir biblioteca\n");
        printf("4. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        getchar(); 

        switch (opcion) {
            case 1:
                eliminarLibro(biblioteca, &nLibros);
                break;
            case 2:
                añadirLibro(biblioteca, &nLibros);
                break;
            case 3:
                imprimirBiblioteca(biblioteca, nLibros);
                break;
            case 4:
                printf("Gracias por usar nuestro servicio de registro\n");
                break;
            default:
                printf("Opcion no válida.\n");
        }
    } while (opcion != 4);

    //Liberamos la memoria asignada
    free(biblioteca);

    return 0;
}