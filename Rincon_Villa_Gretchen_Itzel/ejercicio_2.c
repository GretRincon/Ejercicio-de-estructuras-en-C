//Crea un arreglo de estructuras Producto(nombre, precio, cantidad) y calcula el valor total de inventario
#include<stdio.h>
#include<string.h>

//Primero definamos la estructura Producto
struct Producto {
    char nombre[20];
    float precio;
    int cantidad;
};


int main() { 
    //Definimos el inventario, podemos hacerlo con un arreglo y asignando los valores de una vez
    struct Producto inventario[10]={
        {"Yogurt", 15.5, 5},
        {"Leche", 25.0, 10},
        {"Queso", 35.0, 2},
        {"Jamon", 25.0, 3},
        {"Mantequilla", 18.0, 4},
        {"Pan", 50.0, 8},
        {"Galletas", 22.0, 6},
        {"Cereal", 48.0, 7},
        {"Arroz", 16.0, 12},
        {"Frijoles", 14.0, 9}
    };

    //Definimos una variable para el total del inventario
    float totalInventario = 0.0;

    for (int i = 0; i < 10; i++) {
        totalInventario += inventario[i].precio * inventario[i].cantidad;
        //SUmamos el precio de cada producto por la cantidad de productos que tenemos disponibles
        //Asi para todos los productos que tenemos 
    }

    printf("El valor total del inventario es: %.2f\n", totalInventario);
    //%.2f es para imprimir el total con dos decimales
    return 0;
}
