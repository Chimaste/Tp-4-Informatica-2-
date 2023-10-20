#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_MEDIDAS 100

struct medida {
	int codigo;
	char nombre[50];
	char extension[10];
	int tamanoBytes;
	float precio;
};

int numMedidas = 0;
struct medida stock[MAX_MEDIDAS];

// Prototipos de funciones
void agregarMedida();
void mostrarStock();
void eliminarMedida();
void guardarStock();
void cargarStock();

int main() {
	cargarStock();
	
	int opcion;
	
	do {
		
		printf("Menu:\n");
		printf("1. Agregar Medida al stock\n");
		printf("2. Mostrar stock de Medidas\n");
		printf("3. Eliminar Medida del stock\n");
		printf("4. Guardar y salir\n");
		printf("Seleccione una opción: ");
		scanf("%d", &opcion);
		
		switch (opcion) {
		case 1:
			system("cls");
			agregarMedida();
			
			break;
		case 2:
			system("cls");
			mostrarStock();
		
			
			break;
		case 3:
			system("cls");
			eliminarMedida();
			
			break;
		case 4:
			system("cls");
			guardarStock();
			printf("Guardando y saliendo...\n");
			break;
		default:
			system("cls");
			printf("Opción no válida.\n");
		}
	} while (opcion != 4);
	
	return 0;
}

// Función para agregar una nueva medida al stock
void agregarMedida() {
	if (numMedidas < MAX_MEDIDAS) {
		struct medida nuevaMedida;
		
		printf("Ingrese el código de inventario: ");
		scanf("%d", &nuevaMedida.codigo);
		
		printf("Ingrese el nombre del archivo: ");
		scanf("%s", nuevaMedida.nombre);
		
		printf("Ingrese la extensión del archivo: ");
		scanf("%s", nuevaMedida.extension);
		
		printf("Ingrese el tamaño en bytes: ");
		scanf("%d", &nuevaMedida.tamanoBytes);
		
		printf("Ingrese el precio de la medida: ");
		scanf("%f", &nuevaMedida.precio);
		
		stock[numMedidas] = nuevaMedida;
		numMedidas++;
		
		printf("Medida agregada al stock.\n");
	} else {
		printf("El stock de medidas está lleno.\n");
	}
}

void mostrarStock() {
	printf("Stock de medidas:\n");
	for (int i = 0; i < numMedidas; i++) {
		printf("Código: %d\n", stock[i].codigo);
		printf("Nombre: %s\n", stock[i].nombre);
		printf("Extensión: %s\n", stock[i].extension);
		printf("Tamaño (bytes): %d\n", stock[i].tamanoBytes);
		printf("Precio: %.2f\n\n", stock[i].precio);
	}
}

void eliminarMedida() {
	int codigo;
	printf("Ingrese el código de la medida a eliminar: ");
	scanf("%d", &codigo);
	
	for (int i = 0; i < numMedidas; i++) {
		if (stock[i].codigo == codigo) {
			for (int j = i; j < numMedidas - 1; j++) {
				stock[j] = stock[j + 1];
			}
			numMedidas--;
			printf("Medida eliminada del stock.\n");
			return;
		}
	}
	printf("Medida con código %d no encontrada.\n", codigo);
}

void guardarStock() {
	FILE *archivo = fopen("stock.dat", "wb");
	
	if (archivo == NULL) {
		printf("No se pudo abrir el archivo para escritura.\n");
		return;
	}
	
	fwrite(stock, sizeof(struct medida), numMedidas, archivo);
	fclose(archivo);
}

void cargarStock() {
	FILE *archivo = fopen("stock.dat", "rb");
	
	if (archivo != NULL) {
		numMedidas = fread(stock, sizeof(struct medida), MAX_MEDIDAS, archivo);
		fclose(archivo);
	}
}
