/*****************************************************************//**
 * \file   FunctionsClientes.h
 * \brief  Biblioteca de assinatura das fun��es de gest�o dos clientes.
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

//Fun��o para criar novo cliente dentro da estrutura ListaCliente
ListaCliente* criarCliente(Cliente* c);

//Fun��o para verificar se o cliente j� existe em uma lista
bool existeCliente(ListaClientePtr c, int id);

//Fun��o recursiva para salvar lista de clientes em ficheiro bin�rio
bool guardarClienteBin(ListaClientePtr inicio);

//Fun��o para listar clientes na tela
void listarClientes(ListaClientePtr inicio);

//Fun��o recursiva para imprimir os dados de um cliente
void MostraCliente(ListaClientePtr no);

//fun��o para remover um n� da lista de clientes
ListaClientePtr inserirCliente(ListaClientePtr c, Cliente* inicio);

//Fun��o para remover cliente da lista
ListaClientePtr removerCliente(ListaClientePtr inicio, int identificador);

//fun��o recursiva que encontra um n� na lista atrav�s do id
ListaClientePtr buscarCliente(ListaClientePtr inicio, int identificador);

//fun��o para alterar dados de uma struct dentro de uma lista
ListaClientePtr alterarCliente(ListaClientePtr inicio, int identificador, int novoid, char novonome[], int novonif, char novamorada[], float novosaldo);

//fun��o que l� um ficheiro de texto e insere os dados em uma lista
ListaClientePtr lerFicheiroCliente(ListaClientePtr inicio, char nomeFicheiro[]);

