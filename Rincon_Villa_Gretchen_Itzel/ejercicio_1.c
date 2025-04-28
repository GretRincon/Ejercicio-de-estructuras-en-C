//Usa un apuntador para modificar los datos de una estructura Coche 

#include<stdio.h>
#include<string.h>

//Usualmente para un auto nos fijamos en la marca, modelo, color, año, precio y si es automático o manual
//Definamos la estructura Coche
struct Coche {
	char marca[20];
	char modelo[20];
	int año;
	float precio;
	char color[20];
	int automatico; // 1 para automático, 0 para manual
	};

//Definamos una función que imprima los datos de un coche
void imprimirCoche(struct Coche coche) {
	printf("Marca: %s, ", coche.marca);
	printf("Modelo: %s, ", coche.modelo);
	printf("Año: %d, ", coche.año);
	printf("Precio: %.2f, ", coche.precio);
	printf("Color: %s, ", coche.color);
	printf("Transmisión: %s./n", coche.automatico ? "Automático" : "Manual");
}
int main() {
	//Declaramos coche y puntero
	struct Coche *ptrcoche1;
	struct Coche coche1={"Toyota", "Corolla", 2025, 421100, "Rojo", 1};
	

	//Asignamos el puntero al coche
	ptrcoche1 = &coche1;

	imprimirCoche(coche1);
	//Definamos un coche
	//struct Coche coche1;
	//coche1.marca = "Toyota";
	//coche1.modelo = "Corolla";
	//coche1.año = 2025;
	//coche1.precio = 421100;
	//coche1.color = "Rojo";
	//coche1.automatico = 1; 

	//Supongamosque estoy escribiendo mi  coche ideal, pero luego no me alcanza y debo modificar
	//el precio y el año

	//AHora cambiemos el precio y el año

	ptrcoche1->año = 2023;
	ptrcoche1->precio = 350000;

	printf("Coche modificado:\n");

	imprimirCoche(coche1);
	return 0;
}


