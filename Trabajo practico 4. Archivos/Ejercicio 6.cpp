#include <stdio.h>

#define MAX_PUNTOS 100

struct Point {
	double x;
	double y;
};

int main() {
	struct Point funcionPoints[MAX_PUNTOS];
	int n = 100;  // Número de puntos
	double minX = -5.0;
	double maxX = 5.0;
	double step = (maxX - minX) / (n - 1);
	
	// Almacenar los puntos de la función y = f(x)
	for (int i = 0; i < n; i++) {
		funcionPoints[i].x = minX + i * step;
		funcionPoints[i].y = maxX/* Calcular el valor y utilizando la función */;
	}
	
	// Guardar los puntos en un archivo binario
	FILE *archivo = fopen("function_points.dat", "wb");
	if (archivo != NULL) {
		fwrite(funcionPoints, sizeof(struct Point), n, archivo);
		fclose(archivo);
		printf("Puntos de la función guardados en el archivo 'function_points.dat'\n");
	} else {
		printf("No se pudo abrir el archivo para escritura.\n");
	}
	
	// Ingresar los parámetros de la línea (pendiente y ordenada al origen)
	double slope, yIntercept;
	printf("Ingrese la pendiente de la línea: ");
	scanf("%lf", &slope);
	printf("Ingrese la ordenada al origen de la línea: ");
	scanf("%lf", &yIntercept);
	
	// Verificar si la línea corta la función y cuántas veces
	int intersectionCount = 0;
	for (int i = 0; i < n; i++) {
		double x = funcionPoints[i].x;
		double y = funcionPoints[i].y;
		double lineValue = slope * x + yIntercept;
		
		if (y == lineValue) {
			printf("La línea corta la función en el punto (%.2f, %.2f)\n", x, y);
			intersectionCount++;
		}
	}
	
	if (intersectionCount == 0) {
		printf("La línea no corta la función en el rango especificado.\n");
	} else {
		printf("La línea corta la función %d veces en el rango especificado.\n", intersectionCount);
	}
	
	return 0;
}
