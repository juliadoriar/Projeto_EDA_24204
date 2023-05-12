/*****************************************************************//**
 * \file   FunctionsClientes.h
 * \brief  Biblioteca das fun��es de gest�o dos clientes.
 * 
 * \author julia
 * \date   April 2023
 *********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#pragma once

typedef struct {
	int id;
	char nome[50];
	int nif;
	char morada[100];
	float saldo; //montante dispon�vel para cada cliente
	//struct Cliente* proximo; //ponteiro para o pr�ximo n� da lista
}Cliente;

typedef struct {
	Cliente cliente;
	struct ListaCliente* proximo;
}ListaCliente, * ListaClientePtr;

//Fun��o para criar novo cliente
ListaCliente* criarCliente(Cliente* c);

//Fun��o recursiva para salvar lista de clientes em ficheiro bin�rio
bool guardarClienteBin(Cliente* c, char arquivo[]);

//Fun��o para listar clientes ao final de um ficheiro de texto
bool listarClientes(Cliente* inicio);

//fun��o para remover um n� da lista de clientes
Cliente* removerCliente(Cliente* inicio, int id);

//fun��o recursiva que encontra um n� na lista atrav�s do id
Cliente* buscarCliente(Cliente* inicio, int identificador);

//fun��o para alterar dados de uma struct dentro de uma lista
bool alterarCliente(Cliente* inicio, int identificador, int novoid, char novonome[], int novonif, char novamorada[], float novosaldo);

//fun��o que l� um ficheiro de texto e insere os dados em uma lista
Cliente* lerFicheiroCliente(Cliente* inicio);

