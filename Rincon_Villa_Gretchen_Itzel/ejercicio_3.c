//Crea una funcion que retorne una estructura Punto con coordenadas aleatorias
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Definimos la estructura Punto
struct Punto {
    int x;
    int y;
};


//Utilizamos la estructura para definir una función que genere un punto aleatorio
struct Punto punto_aleatorio(int max) {
    //Generamos coordenadas aleatorias entre 0 y un maximo dado al llamar la funcion
    //Creamos una variable de tipo Punto para asignarle los valores
    struct Punto p;
    //rand crea un punto semi-aleatorio entre 0 y max
    p.x=rand() % max;
    p.y=rand() % max;
    //Para un numero entre M y N se describe con: rand () % (N-M+1) + M
    return p; //No olvides devolver el punto!
}

int main(){
    //Para no caer en secuencias repetidas de números aleatorios
    //Debemos inicializar la semilla de la función rand() con srand() solo se llama una vez en main
    //Debemos darle una semilla que cambie siempre que ejecutemos el programa, como el tiempo
    //time(NULL) devuelve el tiempo actual en segundos desde el 1 de enero de 1970
    srand(time(NULL)); 

    //Ahora si generemos un punto aleatorio e imprimamos
    struct Punto un_punto= punto_aleatorio(100);
    printf("Punto aleatorio: (%d, %d)\n", un_punto.x, un_punto.y);
    return 0;
}
