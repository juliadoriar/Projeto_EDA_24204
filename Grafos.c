/*****************************************************************//**
 * \file   Grafos.c
 * \brief  Fun��es que implementam os grafos e adjacencias
 * 
 * \author julia
 * \date   May 2023
 *********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include "Grafos.h"


/**
 * Fun��o para criar grafo pesado vazio e n�o orientado.
 * 
 * \return 
 */
Vertice* criarGrafo() {
	return NULL;
}

#pragma region VERTICE_GRAFO

/**
 * Fun��o para criar um v�rtica para o grafo.
 * 
 * \param cidade
 * \param id
 * \return 
 */
Vertice* criarVertice(char* cidade, int id) {
	Vertice* novoVertice = (Vertice*)calloc(1, sizeof(Vertice)); //fun��o calloc recebe o par�metro da quantidade de elementos a serem salvos
	if (novoVertice == NULL) return NULL;
	novoVertice->id = id;
	strcpy(novoVertice->localizacao, cidade);
	novoVertice->proximo = NULL;
	novoVertice->adj = NULL;	
	return novoVertice;
}

/**
 * Fun��o que insere um v�rtice no grafo j� criado.
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
 * Fun��o que destr�i o grafo da mem�ria.
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

/** Fun��o para imprimir o grafo na tela */
void mostrarGrafo(Vertice* v) {
	if (v == NULL) return;
	printf("V: %d - %s\n", v->id, v->localizacao);
	mostrarAdj(v->adj);
	mostrarGrafo(v->proximo);
}


#pragma endregion

#pragma region ADJ

/** Fun��o para criar uma nova adjacencia a partir do id e distancia informados */
Adj* criarAdj(int id, float distancia) {
	Adj* novaAdj = (Adj*)calloc(1, sizeof(Adj));
	if (novaAdj == NULL) return NULL;
	novaAdj->id = id;
	novaAdj->distancia = distancia;
	novaAdj->proximo= NULL;
	return novaAdj;
}


/** Fun��o para mostrar as adjacencias do grafo */
void mostrarAdj(Adj* adj) {
	if (adj == NULL) return;
	printf("\tAdj: %d - (%.0f)\n", adj->id, adj->distancia);
	mostrarAdj(adj->proximo);
}

/**
 * Fun��o recursiva para destruir as adjacencias do grafo.
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
