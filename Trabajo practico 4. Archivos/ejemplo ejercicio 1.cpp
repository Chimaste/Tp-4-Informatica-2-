#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXIMONOMBRE 1000
#define MAXIMALONGITUDTEXTO 1000


//Funcion para validar nombre
int esNombreArchivoValido(const char *nombreArchivo) {
	size_t longitud = strlen(nombreArchivo);
	
	if (longitud < 5 || longitud > MAXIMONOMBRE) {
		return 0;
	}
	
	if (!isalnum((unsigned char)nombreArchivo[0]) || nombreArchivo[longitud - 1] == '.' || nombreArchivo[longitud - 2] == '.') {//Verifica letras y números dentro del nombre para el archivo
		return 0;
	}
	
	for (int i = longitud - 3; i >= longitud - 5; i--) {
		if (!isalnum((unsigned char)nombreArchivo[i])) {
			return 0;
		}
	}
	
	return 1;
}


int main() {
	char nombreArchivo[MAXIMONOMBRE];
	char texto[MAXIMALONGITUDTEXTO];
	
	printf("Ingresa el nombre del archivo (con su respectiva extensión): ");
	scanf("%s", nombreArchivo);
	
	if (!esNombreArchivoValido(nombreArchivo)) {
		printf("Nombre de archivo inválido.\n");
		return 1;
	}
	
	FILE *archivo = fopen(nombreArchivo, "a");
	if (archivo == NULL) {
		archivo = fopen(nombreArchivo, "w");
		if (archivo == NULL) {
			printf("No se pudo crear el archivo.\n");
			return 1;
		}
	}
	
	printf("Ingresa el texto a almacenar en el archivo:\n");
	getchar();
	fgets(texto, sizeof(texto), stdin);
	
	fprintf(archivo, "%s", texto);
	fclose(archivo);
	
	printf("Texto almacenado en el archivo.\n");
	
	archivo = fopen(nombreArchivo, "r");
	if (archivo == NULL) {
		printf("No se pudo abrir el archivo.\n");
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
