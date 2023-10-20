#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_WORD_LENGTH 50
#define BUFFER_SIZE 1024

int main() {
	char origenNombre[MAX_FILENAME_LENGTH];
	char destinoNombre[MAX_FILENAME_LENGTH];
	char palabraAntigua[MAX_WORD_LENGTH];
	char palabraNueva[MAX_WORD_LENGTH];
	
	// Pedir los nombres de los archivos origen y destino
	printf("Ingrese el nombre del archivo origen: ");
	scanf("%s", origenNombre);
	
	printf("Ingrese el nombre del archivo destino: ");
	scanf("%s", destinoNombre);
	
	FILE *archivoOrigen = fopen(origenNombre, "r");
	if (archivoOrigen == NULL) {
		printf("No se pudo abrir el archivo origen.\n");
		return 1;
	}
	
	FILE *archivoDestino = fopen(destinoNombre, "w");
	if (archivoDestino == NULL) {
		printf("No se pudo crear el archivo destino.\n");
		fclose(archivoOrigen);
		return 1;
	}
	
	// Pedir las palabras para reemplazar
	printf("Ingrese la palabra a reemplazar: ");
	scanf("%s", palabraAntigua);
	
	printf("Ingrese la palabra nueva: ");
	scanf("%s", palabraNueva);
	
	char buffer[BUFFER_SIZE];
	
	while (fgets(buffer, sizeof(buffer), archivoOrigen) != NULL) {
		char *pos = buffer;
		while ((pos = strstr(pos, palabraAntigua)) != NULL) {
			// Escribir todo desde el último punto de coincidencia hasta aquí
			fwrite(buffer, 1, pos - buffer, archivoDestino);
			
			// Escribir la palabra nueva
			fputs(palabraNueva, archivoDestino);
			
			// Mover el puntero 'pos' más allá de la palabra antigua
			pos += strlen(palabraAntigua);
		}
		
		// Escribir el resto del búfer si no se encontró más coincidencias
		fwrite(pos, 1, strlen(pos), archivoDestino);
	}
	
	fclose(archivoOrigen);
	fclose(archivoDestino);
	
	printf("Archivo copiado y modificado exitosamente.\n");
	
	return 0;
}
