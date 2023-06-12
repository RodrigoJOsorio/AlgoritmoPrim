#include "include/grafo.h"

Grafo* crear_grafo(int conteoNodos)
{
	Grafo* grafo = (Grafo*)malloc(sizeof(Grafo)); // Se reserva espacio en memoria dinámica para almacear el grafo.
	grafo->conteoNodos = conteoNodos; // Se establece el número de nodos que tenfdrá el grafo.
	grafo->matrizAdyacencia = crear_matriz(grafo->conteoNodos);
	return grafo; // Se retorna el puntero de memoria para el grafo creado.
}

void agregar_arista(Grafo* grafo, int origen, int destino, int peso)
{
	// Se comprueba si el grafo existe, y si los nodos de origen y destino pertenecen al grafo.
	if (grafo == NULL || grafo->conteoNodos < origen || grafo->conteoNodos < destino)
		return;

	// Se agrega la arista con su peso al grafo.
	grafo->matrizAdyacencia[origen][destino] = peso;
	grafo->matrizAdyacencia[destino][origen] = peso;
}

void imprimir_matriz(int** matriz, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			printf("[%2d]", matriz[i][j]);
		printf("\n");
	}
}

void free_grafo(Grafo* grafo)
{
	// Se libera espacio en memoria de todos los elementos del grafo.
	for (int i = 0; i < grafo->conteoNodos; i++)
		free(grafo->matrizAdyacencia[i]);
	free(grafo->matrizAdyacencia);
	free(grafo);
}

int** algoritmo_prim(Grafo* grafo)
{
	int** mady = copiar_matriz(grafo->matrizAdyacencia, grafo->conteoNodos);
	int** arbol = crear_matriz(grafo->conteoNodos);
	imprimir_matriz(mady, grafo->conteoNodos);

}

int** crear_matriz(int size)
{
	int** pointer = (int**)malloc(size * sizeof(int*)); // Se reserva espacio en memria para almacenar la matriz.
	for (int i = 0; i < size; i++) // Se reserva espacio en memoria para las columnas de la matriz.
		pointer[i] = (int*)malloc(size * sizeof(int));

	// Se llena la matriz de ceros.
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			pointer[i][j] = 0;
	return pointer;
}

int** copiar_matriz(int** origen, int size)
{
	int** nm = crear_matriz(size);
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			nm[i][j] = origen[i][j];
	return nm;
}