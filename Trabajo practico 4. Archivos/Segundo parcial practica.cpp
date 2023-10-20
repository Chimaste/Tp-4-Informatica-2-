#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición de estructuras
struct Punto {
	float x;
	float y;
	struct Punto* siguiente;
};

struct Climatica {
	char ciudad[50];
	float temperatura;
	float humedad;
	struct Climatica* siguiente;
};

struct Electrica {
	char dispositivo[50];
	float voltaje;
	float corriente;
	struct Electrica* siguiente;
};

// Funciones para adquirir y mostrar datos
void solicitarPunto(struct Punto** listaPuntos) {
	struct Punto* nuevoPunto = (struct Punto*)malloc(sizeof(struct Punto));
	printf("Ingrese la coordenada x: ");
	scanf("%f", &nuevoPunto->x);
	printf("Ingrese la coordenada y: ");
	scanf("%f", &nuevoPunto->y);
	nuevoPunto->siguiente = *listaPuntos;
	*listaPuntos = nuevoPunto;
}

void solicitarClimatica(struct Climatica** listaClimaticas) {
	struct Climatica* nuevaClimatica = (struct Climatica*)malloc(sizeof(struct Climatica));
	printf("Ingrese el nombre de la ciudad: ");
	scanf("%s", nuevaClimatica->ciudad);
	printf("Ingrese la temperatura: ");
	scanf("%f", &nuevaClimatica->temperatura);
	printf("Ingrese la humedad: ");
	scanf("%f", &nuevaClimatica->humedad);
	nuevaClimatica->siguiente = *listaClimaticas;
	*listaClimaticas = nuevaClimatica;
}

void solicitarElectrica(struct Electrica** listaElectricas) {
	struct Electrica* nuevaElectrica = (struct Electrica*)malloc(sizeof(struct Electrica));
	printf("Ingrese el nombre del dispositivo: ");
	scanf("%s", nuevaElectrica->dispositivo);
	printf("Ingrese el voltaje: ");
	scanf("%f", &nuevaElectrica->voltaje);
	printf("Ingrese la corriente: ");
	scanf("%f", &nuevaElectrica->corriente);
	nuevaElectrica->siguiente = *listaElectricas;
	*listaElectricas = nuevaElectrica;
}

void mostrarPuntos(struct Punto* listaPuntos) {
	printf("\n--- Puntos en el plano ---\n");
	while (listaPuntos != NULL) {
		printf("Coordenada x: %.2f, Coordenada y: %.2f\n", listaPuntos->x, listaPuntos->y);
		listaPuntos = listaPuntos->siguiente;
	}
}

void mostrarClimaticas(struct Climatica* listaClimaticas) {
	printf("\n--- Variables climáticas ---\n");
	while (listaClimaticas != NULL) {
		printf("Ciudad: %s, Temperatura: %.2f, Humedad: %.2f\n", listaClimaticas->ciudad, listaClimaticas->temperatura, listaClimaticas->humedad);
		listaClimaticas = listaClimaticas->siguiente;
	}
}

void mostrarElectricas(struct Electrica* listaElectricas) {
	printf("\n--- Variables eléctricas ---\n");
	while (listaElectricas != NULL) {
		printf("Dispositivo: %s, Voltaje: %.2f, Corriente: %.2f\n", listaElectricas->dispositivo, listaElectricas->voltaje, listaElectricas->corriente);
		listaElectricas = listaElectricas->siguiente;
	}
}

// Función principal
int main() {
	struct Punto* listaPuntos = NULL;
	struct Climatica* listaClimaticas = NULL;
	struct Electrica* listaElectricas = NULL;
	
	char opcion;
	do {
		printf("\nOpciones:\n");
		printf("1. Ingresar Punto en el plano.\n");
		printf("2. Ingresar Variable climática.\n");
		printf("3. Ingresar Variable eléctrica.\n");
		printf("4. Mostrar Puntos en el plano.\n");
		printf("5. Mostrar Variables climáticas.\n");
		printf("6. Mostrar Variables eléctricas.\n");
		printf("0. Salir.\n");
		printf("Ingrese una opción: ");
		scanf(" %c", &opcion);
		
		switch (opcion) {
		case '1':
			solicitarPunto(&listaPuntos);
			break;
		case '2':
			solicitarClimatica(&listaClimaticas);
			break;
		case '3':
			solicitarElectrica(&listaElectricas);
			break;
		case '4':
			mostrarPuntos(listaPuntos);
			break;
		case '5':
			mostrarClimaticas(listaClimaticas);
			break;
		case '6':
			mostrarElectricas(listaElectricas);
			break;
		case '0':
			printf("Saliendo del programa.\n");
			break;
		default:
			printf("Opción no válida.\n");
		}
	} while (opcion != '0');
	
	// Liberar memoria utilizada por las listas
	while (listaPuntos != NULL) {
		struct Punto* temp = listaPuntos;
		listaPuntos = listaPuntos->siguiente;
		free(temp);
	}
	
	while (listaClimaticas != NULL) {
		struct Climatica* temp = listaClimaticas;
		listaClimaticas = listaClimaticas->siguiente;
		free(temp);
	}
	
	while (listaElectricas != NULL) {
		struct Electrica* temp = listaElectricas;
		listaElectricas = listaElectricas->siguiente;
		free(temp);
	}
	
	return 0;
}
