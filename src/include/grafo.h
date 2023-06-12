#ifndef __GRAFO_H__
#define __GRAFO_H__

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Grafo ponderado mediante una matriz de adyacencia.
 */
typedef struct Grafo
{
	int conteoNodos;
	int **matrizAdyacencia;
} Grafo;

/**
 * @brief Crea un grafo dado un número de nodos.
 *
 * @param conteoNodos Número de nodos en el grafo.
 * @return Grafo* Puntero a un grafo en memoria.
 */
Grafo *crear_grafo(int conteoNodos);

/**
 * @brief Agrega una arista al grafo.
 *
 * @param grafo Puntero a un grafo en memoria.
 * @param origen Índice del nodo de origen.
 * @param destino Índice del nodo de destino.
 * @param peso Peso de la arista.
 */
void agregar_arista(Grafo *grafo, int origen, int destino, int peso);

/**
 * @brief Imprime la matriz de adyacencia de un grafo.
 *
 * @param grafo Puntero a un grafo en memoria.
 */
void imprimir_matriz(int** matriz, int size);

/**
 * @brief Libera la memoria utilizada por un grafo.
 */
void free_grafo(Grafo *grafo);

/**
 * @brief Implementación del algoritmo de Prim.
 *
 * @param grafo
 */
int** algoritmo_prim(Grafo* grafo);

int** crear_matriz(int size);

int** copiar_matriz(int** origen, int size);

#endif
