#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_TEXT_LENGTH 1000

int esNombreArchivoValido(const char *nombreArchivo) {
	size_t longitud = strlen(nombreArchivo);
	
	// Verificar que la longitud sea válida
	if (longitud < 5 || longitud > MAX_FILENAME_LENGTH) {
		return 0;
	}
	
	// Verificar que tenga extensión y sea alfanumérico
	if (!isalnum(nombreArchivo[0]) || nombreArchivo[longitud - 1] == '.' || nombreArchivo[longitud - 2] == '.') {
		return 0;
	}
	
	// Verificar que la extensión tenga 2-4 caracteres alfanuméricos
	for (int i = longitud - 3; i >= longitud - 5; i--) {
		if (!isalnum(nombreArchivo[i])) {
			return 0;
		}
	}
	
	return 1;
}

int main() {
	char nombreArchivo[MAX_FILENAME_LENGTH];
	char texto[MAX_TEXT_LENGTH];
	
	printf("Ingresa el nombre del archivo (con extensión): ");
	scanf("%s", nombreArchivo);
	
	if (!esNombreArchivoValido(nombreArchivo)) {
		printf("Nombre de archivo inválido.\n");
		return 1;
	}
	
	FILE *archivo = fopen(nombreArchivo, "a");
	if (archivo == NULL) {
		printf("No se pudo abrir el archivo.\n");
		return 1;
	}
	
	printf("Ingresa el texto a almacenar en el archivo:\n");
	getchar();
	fgets(texto, sizeof(texto), stdin);
	
	fprintf(archivo, "%s", texto);
	fclose(archivo);
	
	printf("Texto almacenado en el archivo.\n");
	
	archivo = fopen(nombreArchivo, "r");
	if (archivo == NULL) {
		printf("No se pudo abrir el archivo para lectura.\n");
		return 1;
	}
	
	printf("Contenido del archivo:\n");
	char caracter;
	while ((caracter = fgetc(archivo)) != EOF) {
		putchar(caracter);
	}
	
	fclose(archivo);
	
	return 0;
}
