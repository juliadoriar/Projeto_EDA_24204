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
Vertice* buscarVertice(Vertice* v, char* cidade);
Vertice* buscarVerticeId(Vertice* v, int id);
Vertice* lerGrafoFicheiro(Vertice* v, char nomeFicheiro[]);
#pragma endregion

#pragma region ADJ
Adj* criarAdj(int id, float distancia);
Adj* destruirAdjacencia(Adj* adj);
void mostrarAdj(Adj* adj);
bool existeAdj(Adj* adj, int id);
Adj* inserirAdj(Adj* adj, Adj* novaAdj, bool* vis);
Vertice* inserirAdjVerticeId(Vertice* v, int idInicio, int idFim, float distancia, bool* vis);
int inserirMeioVertice(Vertice* v, MeioMob meio);
bool guardarVerticesFicheiro(Vertice* v, char nomeFicheiro[]);
int inserirClienteVertice(Vertice* v, Cliente cliente);
int calcularCaminho(Vertice* v, int idorigem, int iddestino, int contaCaminho);
int calcularCaminhoNomeVertice(Vertice* v, char* origem, char* destino, int contaCaminho);
bool existeCaminho(Vertice* v, int origem, int destino);
int existeCaminhoNome(Vertice* v, char* origem, char* destino);
Vertice* zerarVerticeVisitado(Vertice* v);
int listarMeiosPorTipoERaio(Vertice* v, char* localizacaoCliente, char* tipoMeio, float raio);




int guardarGrafoBinario(Vertice* v, char* nomeFicheiro);
int guardarAdjacencia(Adj* adj, char* nomeFicheiro, int codVerticeOrigem);
#pragma endregion