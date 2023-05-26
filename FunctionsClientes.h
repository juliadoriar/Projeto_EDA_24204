/*****************************************************************//**
 * \file   FunctionsClientes.h
 * \brief  Biblioteca de assinatura das funções de gestão dos clientes.
 * 
 * \author julia
 * \date   April 2023
 *********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX 100
#pragma once

typedef struct {
	int id;
	char nome[MAX];
	int nif;
	char morada[MAX];
	float saldo; 
}Cliente;

typedef struct {
	Cliente cliente;
	struct ListaCliente* proximo;
}ListaCliente, *ListaClientePtr;

//Função para criar novo cliente dentro da estrutura ListaCliente
ListaCliente* criarCliente(Cliente* c);

//Função para verificar se o cliente já existe em uma lista
bool existeCliente(ListaClientePtr c, int id);

//Função recursiva para salvar lista de clientes em ficheiro binário
bool guardarClienteBin(ListaClientePtr inicio);

//Função para listar clientes na tela
void listarClientes(ListaClientePtr inicio);

//Função recursiva para imprimir os dados de um cliente
void MostraCliente(ListaClientePtr no);

//função para remover um nó da lista de clientes
ListaClientePtr inserirCliente(ListaClientePtr c, Cliente* inicio);

//Função para remover cliente da lista
ListaClientePtr removerCliente(ListaClientePtr inicio, int identificador);

//função recursiva que encontra um nó na lista através do id
ListaClientePtr buscarCliente(ListaClientePtr inicio, int identificador);

//função para alterar dados de uma struct dentro de uma lista
ListaClientePtr alterarCliente(ListaClientePtr inicio, int identificador, int novoid, char novonome[], int novonif, char novamorada[], float novosaldo);

//função que lê um ficheiro de texto e insere os dados em uma lista
ListaClientePtr lerFicheiroCliente(ListaClientePtr inicio, char nomeFicheiro[]);

