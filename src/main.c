#include "include/grafo.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * Para facilitar la creación del grafo, mediante un enum se le dará un
 * "nombre" a cada índice del grafo
 */
enum
{
	A = 0,
	B = 1,
	C = 2,
	D = 3,
	E = 4,
	F = 5,
	G = 6
};

const char* nombres_nodos = "ABCDEFG";

int main()
{
	Grafo *grafo = crear_grafo(7);
	agregar_arista(grafo, A, B, 7);
	agregar_arista(grafo, A, D, 5);
	agregar_arista(grafo, B, D, 9);
	agregar_arista(grafo, B, C, 8);
	agregar_arista(grafo, B, E, 7);
	agregar_arista(grafo, C, E, 5);
	agregar_arista(grafo, D, E, 15);
	agregar_arista(grafo, D, F, 6);
	agregar_arista(grafo, E, F, 8);
	agregar_arista(grafo, E, G, 9);
	agregar_arista(grafo, F, G, 11);

	imprimir_matriz(grafo->matrizAdyacencia, grafo->conteoNodos);

	algoritmo_prim(grafo);
	
	free_grafo(grafo);
	return 0;
}