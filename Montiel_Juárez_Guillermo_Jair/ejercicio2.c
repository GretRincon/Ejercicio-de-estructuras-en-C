//Ejercicio 2 Guillermo Jair Montiel Juárez
//Crea un arreglo de estructuras Producto (nombre, precio, cantidad) y calcula el valor total de inventario (0.5 pts.)

#include <stdio.h>
#include <stdlib.h>

// Definimos la estructura Producto
typedef struct Producto {
    char nombre[50];
    float precio;
    int cantidad;
    int valor_total; // Valor total del producto (precio * cantidad)
} Producto;

// Función para calcular el valor total de inventario
void imprimirProducto(Producto producto) {
    printf("Nombre: %s\n", producto.nombre);
    printf("Precio: %.2f\n", producto.precio);
    printf("Cantidad: %d\n", producto.cantidad);
    printf("Valor total: %.2f\n", producto.precio * producto.cantidad);
}

int main() {
    Producto productos[3]; // Arreglo de estructuras Producto
    float valor_total_inventario = 0.0;

    // Ingresar datos de los productos con un ciclo for
    for (int i = 0; i < 3; i++) {
        printf("Ingrese el nombre del producto %d: ", i + 1);
        scanf("%s", productos[i].nombre);
        printf("Ingrese el precio del producto %d: ", i + 1);
        scanf("%f", &productos[i].precio);
        printf("Ingrese la cantidad del producto %d: ", i + 1);
        scanf("%d", &productos[i].cantidad);
        // Calcular el valor total del producto (precio * cantidad)
        productos[i].valor_total = productos[i].precio * productos[i].cantidad;
    }

    // Imprimir los datos de los productos con un ciclo for
    printf("\nDatos de los productos:\n");
    for (int i = 0; i < 3; i++) {
        printf("\nProducto %d:\n", i + 1);
        imprimirProducto(productos[i]);
    }

    // Calcular el valor total de inventario con un ciclo for
    for (int i = 0; i < 3; i++) {
        //valor_total_inventario += productos[i].precio * productos[i].cantidad;
        valor_total_inventario += productos[i].valor_total; // Sumar el valor total de cada producto
    }

    // Imprimir el valor total de inventario
    printf("\nValor total de inventario: %.2f\n", valor_total_inventario);

    return 0;
}