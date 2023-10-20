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

// Prototipos de funciones
void agregarImagen();
void mostrarStock();
void eliminarImagen();
void guardarStock();
void cargarStock();

int main() {
	cargarStock();
	
	int opcion;
	
	do {
		printf("Menu:\n");
		printf("1. Agregar imagen al stock\n");
		printf("2. Mostrar stock de im�genes\n");
		printf("3. Eliminar imagen del stock\n");
		printf("4. Guardar y salir\n");
		printf("Seleccione una opci�n: ");
		scanf("%d", &opcion);
		
		switch (opcion) {
		case 1:
			agregarImagen();
			break;
		case 2:
			mostrarStock();
			break;
		case 3:
			eliminarImagen();
			break;
		case 4:
			guardarStock();
			printf("Guardando y saliendo...\n");
			break;
		default:
			printf("Opci�n no v�lida.\n");
		}
	} while (opcion != 4);
	
	return 0;
}

void agregarImagen() {
	if (numImagenes < MAX_IMAGES) {
		struct Imagen nuevaImagen;
		
		printf("Ingrese el c�digo de inventario: ");
		scanf("%d", &nuevaImagen.codigo);
		
		printf("Ingrese el nombre del archivo: ");
		scanf("%s", nuevaImagen.nombre);
		
		printf("Ingrese la extensi�n del archivo: ");
		scanf("%s", nuevaImagen.extension);
		
		printf("Ingrese el tama�o en bytes: ");
		scanf("%d", &nuevaImagen.tamanoBytes);
		
		printf("Ingrese el precio de la imagen: ");
		scanf("%f", &nuevaImagen.precio);
		
		stock[numImagenes] = nuevaImagen;
		numImagenes++;
		
		printf("Imagen agregada al stock.\n");
	} else {
		printf("El stock de im�genes est� lleno.\n");
	}
}

void mostrarStock() {
	printf("Stock de im�genes:\n");
	for (int i = 0; i < numImagenes; i++) {
		printf("C�digo: %d\n", stock[i].codigo);
		printf("Nombre: %s\n", stock[i].nombre);
		printf("Extensi�n: %s\n", stock[i].extension);
		printf("Tama�o (bytes): %d\n", stock[i].tamanoBytes);
		printf("Precio: %.2f\n\n", stock[i].precio);
	}
}

void eliminarImagen() {
	int codigo;
	printf("Ingrese el c�digo de la imagen a eliminar: ");
	scanf("%d", &codigo);
	
	for (int i = 0; i < numImagenes; i++) {
		if (stock[i].codigo == codigo) {
			for (int j = i; j < numImagenes - 1; j++) {
				stock[j] = stock[j + 1];
			}
			numImagenes--;
			printf("Imagen eliminada del stock.\n");
			return;
		}
	}
	printf("Imagen con c�digo %d no encontrada.\n", codigo);
}

void guardarStock() {
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
