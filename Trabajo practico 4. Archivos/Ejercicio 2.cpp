#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void copiarArchivo(FILE *archivoOrigen, FILE *archivoDestino) {
	int caracter;
	while ((caracter = fgetc(archivoOrigen)) != EOF) {
		fputc(caracter, archivoDestino);
	}
}

int main() {
	char nombreArchivoOrigen[100];
	char nombreArchivoDestino[100];
	
	//del primer archivo 
	printf("Ingresa el nombre del archivo origen (con extensión): ");
	scanf("%s", nombreArchivoOrigen);
	
	//al segundo archivo 
	printf("Ingresa el nombre del archivo destino (con extensión): ");
	scanf("%s", nombreArchivoDestino);
	
	FILE *archivoOrigen = fopen(nombreArchivoOrigen, "rb");
	if (archivoOrigen == NULL) {
		printf("No se pudo abrir el archivo origen.\n");
		return 1;
	}
	
	FILE *archivoDestino = fopen(nombreArchivoDestino, "wb");
	if (archivoDestino == NULL) {
		printf("No se pudo crear el archivo destino.\n");
		return 1;
	}
	
	copiarArchivo(archivoOrigen, archivoDestino);
	
	fclose(archivoOrigen);
	fclose(archivoDestino);
	
	printf("Archivo copiado exitosamente de %s a %s.\n", nombreArchivoOrigen, nombreArchivoDestino);
	
	return 0;
}

