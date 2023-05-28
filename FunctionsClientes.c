/*****************************************************************//**
 * \file   FunctionsClientes.c
 * \brief  Funções de administrãção dos dados dos clientes
 * 
 * \author julia
 * \date   April 2023
 *********************************************************************/
#include "FunctionsClientes.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define CHAR 500

/** Função que cria novo cliente */
ListaCliente* criarCliente(Cliente c)
{
	ListaCliente* novoCliente = (ListaCliente*)malloc(sizeof(ListaCliente));
	if (novoCliente == NULL) return NULL;
	novoCliente->cliente = c;
	novoCliente->proximo = NULL;
	
	return novoCliente;
}

/** Função que insere o cliente criado em uma lista */
ListaClientePtr inserirCliente(ListaClientePtr c, Cliente* inicio)
{
	if (existeCliente(c, inicio->id)) return c;	

	ListaClientePtr aux = (ListaClientePtr)malloc(sizeof(ListaCliente));
	aux->cliente = *inicio;
	aux->proximo = NULL; 
	
	if (c == NULL)		
	{
		c = aux;
	}
	else
	{
		aux->proximo = c->proximo;	
		c->proximo = aux;
	}
	return c;
}

/** Função que verifica se o cliente de id passado por parâmetro já existe na lista */
bool existeCliente(ListaClientePtr c, int id) {

	if (c == NULL) return false;
	ListaClientePtr aux = c;
	while (aux != NULL) {
		if (aux->cliente.id == id) {
			return true;
					}
		aux = aux->proximo;
		}
	return false;
}

/** Função recursiva para guardar clientes da lista em um ficheiro binário */
bool guardarClienteBin(ListaClientePtr inicio)
{
	FILE* fp = fopen("Clientes.bin", "wb");
	if (inicio == NULL || fp == NULL) {

		return false;

	}
	ListaClientePtr atual = inicio;
	Cliente auxCliente;
	while (atual != NULL)
	{
		auxCliente = atual->cliente;
		fwrite(&auxCliente, sizeof(Cliente), 1, fp);
		atual = atual->proximo;
	}

	fclose(fp);
	return true;
}

/** Função que recebe a lista de clientes como parâmetro e imprime na tela os dados de todos os clientes */
void listarClientes(ListaClientePtr inicio)
{
	ListaClientePtr aux = inicio;

	while (aux != NULL)
	{
		MostraCliente(aux);
		aux = aux->proximo;
	}
}

/** Função para imprimir os dados de um só cliente */
void MostraCliente(ListaClientePtr no)
{
	if (no != NULL) {

		printf("Id = %d; Nome = %s; NIF = %d; Morada = %s; Saldo = %f\n", no->cliente.id, no->cliente.nome, no->cliente.nif, no->cliente.morada, no->cliente.saldo);

	}
}

/** Função para remoção de uma struct Cliente da lista através do seu id */
ListaClientePtr removerCliente(ListaClientePtr inicio, int identificador)
{
	ListaClientePtr atual = inicio;
	ListaClientePtr anterior = NULL;

	//remover o primeiro nó da lista
	if (atual != NULL && atual->cliente.id == identificador) {
		inicio = atual->proximo;
		free(atual);
		return (inicio);
	}
	//percorrer a lista para navegar todos os nós e remover o que foi passado no parâmetro
	while (atual != NULL && atual->cliente.id != identificador) {
		anterior = atual;
		atual = atual->proximo;
	}
	//no caso do nó não ser encontrado na lista, retorna a lista
	if (atual == NULL) {
		return inicio;
	}
	//sendo encontrado o nó ele é removido, e sua memória liberada
	else {
		anterior->proximo = atual->proximo;
		free(atual);
	}
	return (inicio);
}

/** Função recursiva para buscar um nó na lista de clientes */
ListaClientePtr buscarCliente(ListaClientePtr inicio, int identificador) {
	
	ListaClientePtr atual = inicio;
	
	while (atual != NULL) {
		if (atual->cliente.id == identificador) { 
			return atual; //se o id do atual for igual ao id encontrado, retorna atual
		}
		atual = atual->proximo;
	}
	return NULL; //não sendo nenhum encontrado, retorna null
}

/** Função que altera os dados da struct Cliente dentro da lista */
ListaClientePtr alterarCliente(ListaClientePtr inicio, int identificador, int novoid, char novonome[], int novonif, char novamorada[], float novosaldo) {
	
	ListaClientePtr cliente = buscarCliente(inicio, identificador); //busca cliente na lista através do id informado
	if (cliente != NULL) {
		cliente->cliente.id = novoid;
		strcpy(cliente->cliente.nome, novonome);
		cliente->cliente.nif = novonif;
		strcpy(cliente->cliente.morada, novamorada);
		cliente->cliente.saldo = novosaldo;

	} return inicio; //retorna a lista de cliente com as alterações realizadas
}

/** Função que lê um ficheiro de texto contendo os dados de um cliente, e insere-os em uma lista */
ListaClientePtr lerFicheiroCliente(ListaClientePtr inicio,  char nomeFicheiro[]) {
	FILE* fp;
	fp = fopen(nomeFicheiro, "r");

	if (fp == NULL)
	{
		return NULL;
	}

	ListaClientePtr c = NULL;
	Cliente aux;
	

	char linha[256];
	while (fgets(linha, sizeof(linha), fp) != NULL) { //laço para ler cada linha não nula e armazenar na variavel linha
		if (sscanf(linha, "%d;%[^;];%d;%[^;];%f", &aux.id, aux.nome, &aux.nif, aux.morada, &aux.saldo) == 5) {
			ListaClientePtr novoCliente = criarCliente(aux); 
			c = inserirCliente(c, novoCliente); 
		}
	}

	fclose(fp);
	
	return c;
}