/*****************************************************************//**
 * \file   Grafos.h
 * \brief  Biblioteca de assinatura das funções de grafos e suas estruturas
 * 
 * \author julia
 * \date   May 2023
 *********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "FunctionsClientes.h"
#include "FunctionsMeios.h"

#pragma once

#define MAX 50

/**
 * Estrutura de uma adjacencia.
 */
typedef struct Adj {
    int id;
    float distancia;		
    struct Adj* proximo;
}Adj;

/**
 * Estrutura de um vértice.
 */
typedef struct Vertice {
    int id;
    char localizacao[MAX];
    char origem[MAX];
    char destino[MAX];
    float distancia;
    bool visitado;
    struct Vertice* proximo;
    struct Adj* adj;
    struct ListaCliente* cliente;
    struct ListaMeio* meio;   
} Vertice;



#pragma region VERTICE_GRAFO

Vertice* criarGrafo();
Vertice* criarVertice(char* cidade, int id);
Vertice* inserirVertice(Vertice* v, char* localizacao, int id, bool* vis);
Vertice* destruirGrafo(Vertice* v);
void mostrarGrafo(Vertice* v);
#pragma endregion

#pragma region ADJ

Adj* destruirAdjacencia(Adj* adj);
void mostrarAdj(Adj* adj);
#pragma endregion