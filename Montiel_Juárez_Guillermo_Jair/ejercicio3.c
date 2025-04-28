//Ejercicio 3 Guillermo Jair Montiel Juárez
//Crea una función que retorne una estructura Punto con coordenadas aleatorias. (1 pto.)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Punto {
    int x;
    int y;
} Punto;

// Función para imprimir las coordenadas de un punto
void imprimirPunto(Punto coordenada) {
    printf("Coordenadas: (%d, %d)\n", coordenada.x, coordenada.y);
}

// Función para generar un número aleatorio entre -100 y 100
int num_aleatorio() {
    // (max - min + 1) + min
    int numero = rand() % (100 - (-100) + 1) + (-100);
    return numero; // Retorna el número aleatorio generado
}

// Función que retorna una estructura Punto con coordenadas aleatorias
Punto punto_aleatorio() {
    Punto p; // Crear una variable de tipo Punto
    p.x = num_aleatorio();
    p.y = num_aleatorio();
    return p; // Retorna el punto generado
}

int main() {
    // Inicializar la semilla para la generación de números aleatorios
    srand(time(NULL)); // Semilla para la generación de números aleatorios

    //Imprimir el punto generado
    imprimirPunto(punto_aleatorio()); // Imprimir el punto generado
    return 0;
}