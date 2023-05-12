/*****************************************************************//**
 * \file   FunctionsClientes.h
 * \brief  Biblioteca das funções de gestão dos clientes.
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
	float saldo; //montante disponível para cada cliente
	//struct Cliente* proximo; //ponteiro para o próximo nó da lista
}Cliente;

typedef struct {
	Cliente cliente;
	struct ListaCliente* proximo;
}ListaCliente, * ListaClientePtr;

//Função para criar novo cliente
ListaCliente* criarCliente(Cliente* c);

//Função recursiva para salvar lista de clientes em ficheiro binário
bool guardarClienteBin(Cliente* c, char arquivo[]);

//Função para listar clientes ao final de um ficheiro de texto
bool listarClientes(Cliente* inicio);

//função para remover um nó da lista de clientes
Cliente* removerCliente(Cliente* inicio, int id);

//função recursiva que encontra um nó na lista através do id
Cliente* buscarCliente(Cliente* inicio, int identificador);

//função para alterar dados de uma struct dentro de uma lista
bool alterarCliente(Cliente* inicio, int identificador, int novoid, char novonome[], int novonif, char novamorada[], float novosaldo);

//função que lê um ficheiro de texto e insere os dados em uma lista
Cliente* lerFicheiroCliente(Cliente* inicio);

