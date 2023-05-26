/*****************************************************************//**
 * \file   Grafos.c
 * \brief  Funções que implementam os grafos e adjacencias
 * 
 * \author julia
 * \date   May 2023
 *********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include "Grafos.h"


/**
 * Função para criar grafo pesado vazio e não orientado.
 * 
 * \return 
 */
Vertice* criarGrafo() {
	return NULL;
}

#pragma region VERTICE_GRAFO

/**
 * Função para criar um vértica para o grafo.
 * 
 * \param cidade
 * \param id
 * \return 
 */
Vertice* criarVertice(char* cidade, int id) {
	Vertice* novoVertice = (Vertice*)calloc(1, sizeof(Vertice)); //função calloc recebe o parâmetro da quantidade de elementos a serem salvos
	if (novoVertice == NULL) return NULL;
	novoVertice->id = id;
	strcpy(novoVertice->localizacao, cidade);
	novoVertice->proximo = NULL;
	novoVertice->adj = NULL;	
	return novoVertice;
}

/**
 * Função que insere um vértice no grafo já criado.
 * 
 * \param v
 * \param localizacao
 * \param id
 * \param vis
 * \return 
 */
Vertice* inserirVertice(Vertice* v, char* localizacao, int id, bool* vis) {
	
	Vertice* novoVertice = criarVertice(localizacao, id);
	
	if (novoVertice == NULL) {
		*vis = false;
		return v;
	}

	if (v == NULL) {
		v = novoVertice;
		*vis = true;
		return novoVertice;
	}

	else
	{
		Vertice* aux = v;
		Vertice* ant = aux;
		while (aux && strcmp(aux->localizacao, novoVertice->localizacao) < 0) {
			ant = aux;
			aux = aux->proximo;
		}
		if (aux == v) {
			novoVertice->proximo = v;
			v = novoVertice;
		}
		else
		{
			novoVertice->proximo = aux;
			ant->proximo = novoVertice;
		}
		*vis = true;
	}
	return v;
}

/**
 * Função que destrói o grafo da memória.
 * 
 * \param v
 * \return 
 */
Vertice* destruirGrafo(Vertice* v) {
	if (v == NULL) return NULL;
	Vertice* aux = NULL;
	while (v) {
		if (v->proximo)
			aux = v->proximo;
		v->adj = destruirAdjacencia(v->adj);
		free(v);
		v = aux;
		aux = NULL;
	}
	return v;
}

/** Função para imprimir o grafo na tela */
void mostrarGrafo(Vertice* v) {
	if (v == NULL) return;
	printf("V: %d - %s\n", v->id, v->localizacao);
	mostrarAdj(v->adj);
	mostrarGrafo(v->proximo);
}


#pragma endregion

#pragma region ADJ

/** Função para criar uma nova adjacencia a partir do id e distancia informados */
Adj* criarAdj(int id, float distancia) {
	Adj* novaAdj = (Adj*)calloc(1, sizeof(Adj));
	if (novaAdj == NULL) return NULL;
	novaAdj->id = id;
	novaAdj->distancia = distancia;
	novaAdj->proximo= NULL;
	return novaAdj;
}


/** Função para mostrar as adjacencias do grafo */
void mostrarAdj(Adj* adj) {
	if (adj == NULL) return;
	printf("\tAdj: %d - (%.0f)\n", adj->id, adj->distancia);
	mostrarAdj(adj->proximo);
}

/**
 * Função recursiva para destruir as adjacencias do grafo.
 * 
 * \param adj
 * \return 
 */
Adj* destruirAdjacencia(Adj* adj) {
	if (adj == NULL) return NULL;
	Adj* aux = NULL;
	while (adj) {
		if (adj->proximo!= NULL)
			aux = adj->proximo;
		free(adj);
		adj = aux;
		aux = NULL;
	}
	return adj;
}

#pragma endregion
