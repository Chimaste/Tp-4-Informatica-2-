#include <stdio.h>
#include <string.h>

#define MAX_IMAGES 100

struct Imagen {
	int codigo;
	char nombre[50];
	char extension[10];
	int tamanoBytes;
	float precio;
};

int numImagenes = 0;


struct Imagen stock[MAX_IMAGES];

// Función para agregar una nueva imagen al stock
void agregarImagen(struct Imagen stock[], int *numImagenes) {
	if (*numImagenes < MAX_IMAGES) {
		struct Imagen nuevaImagen;
		
		printf("Ingrese el código de inventario: ");
		scanf("%d", &nuevaImagen.codigo);
		
		printf("Ingrese el nombre del archivo: ");
		scanf("%s", nuevaImagen.nombre);
		
		printf("Ingrese la extensión del archivo: ");
		scanf("%s", nuevaImagen.extension);
		
		printf("Ingrese el tamaño en bytes: ");
		scanf("%d", &nuevaImagen.tamanoBytes);
		
		printf("Ingrese el precio de la imagen: ");
		scanf("%f", &nuevaImagen.precio);
		
		stock[*numImagenes] = nuevaImagen;
		(*numImagenes)++;
		
		printf("Imagen agregada al stock.\n");
	} else {
		printf("El stock de imágenes está lleno.\n");
	}
}

// Función para mostrar el stock de imágenes
void mostrarStock(struct Imagen stock[], int numImagenes) {
	printf("Stock de imágenes:\n");
	for (int i = 0; i < numImagenes; i++) {
		printf("Código: %d\n", stock[i].codigo);
		printf("Nombre: %s\n", stock[i].nombre);
		printf("Extensión: %s\n", stock[i].extension);
		printf("Tamaño (bytes): %d\n", stock[i].tamanoBytes);
		printf("Precio: %.2f\n\n", stock[i].precio);
	}
}

//Funcion eliminar Imagen
void eliminarImagen(int codigo) {
	for (int i = 0; i < numImagenes; i++) {
		if (stock[i].codigo == codigo) {
			for (int j = i; j < numImagenes - 1; j++) {
				stock[j] = stock[j + 1];
			}
			numImagenes--;
			printf("Imagen eliminada del stock.");
			return;
		}
	}
	printf("Imagen con código %d no encontrada.\n", codigo);
}

// Función para guardar el stock de imágenes en un archivo binario
void guardarStock(struct Imagen stock[], int numImagenes) {
	FILE *archivo = fopen("stock.dat", "wb");
	
	if (archivo == NULL) {
		printf("No se pudo abrir el archivo para escritura.\n");
		return;
	}
	
	fwrite(stock, sizeof(struct Imagen), numImagenes, archivo);
	fclose(archivo);
}

void cargarStock() {
	FILE *archivo = fopen("stock.dat", "rb");
	
	if (archivo == NULL) {
		printf("No se pudo abrir el archivo para lectura.\n");
		return;
	}
	
	numImagenes = fread(stock, sizeof(struct Imagen), MAX_IMAGES, archivo);
	fclose(archivo);
}
int main() {
	int opcion;
	int codigo;
	
	cargarStock();
	
	do {
		printf("Menu:\n");
		printf("1. Agregar imagen al stock\n");
		printf("2. Mostrar stock de imágenes\n");
		printf("3. Eliminar imagen del stock\n");
		printf("4. Guardar y salir\n");
		printf("Seleccione una opción: ");
		scanf("%d", &opcion);
		
		switch (opcion) {
		case 1:
			agregarImagen(stock, &numImagenes);
			break;
		case 2:
			mostrarStock(stock, numImagenes);
			break;
		case 3:
			printf("Ingrese el código de la imagen a eliminar: ");
			scanf("%d", &codigo);
			eliminarImagen(codigo);
			break;
		case 4:
			guardarStock(stock, numImagenes);
			printf("Guardando y saliendo...\n");
			break;
		default:
			printf("Opción no válida.\n");
		}
	} while (opcion != 4);
	
	return 0;
}








