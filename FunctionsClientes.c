/*****************************************************************//**
 * \file   FunctionsClientes.c
 * \brief  Fun��es de administr���o dos dados dos clientes
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

/**
 * Fun��o que cria novo cliente.
 *
 * \param inicio
 * \param id
 * \param nome
 * \param nif
 * \param morada
 * \param saldo
 * \return
 */
ListaCliente* criarCliente(Cliente c)
{
	ListaCliente* novoCliente = (ListaCliente*)malloc(sizeof(ListaCliente));
	if (novoCliente == NULL) return NULL;
	novoCliente->cliente = c;
	novoCliente->proximo = NULL;
	
	return novoCliente;
}

/**
 * Fun��o que insere o cliente criado em uma lista.
 * 
 * \param c
 * \param inicio
 * \return 
 */
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

/**
 * Fun��o que verifica se o cliente de id passado por par�metro j� existe na lista.
 * 
 * \param c
 * \param id
 * \return 
 */
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

/**
 * Fun��o recursiva para guardar clientes da lista em um ficheiro bin�rio.
 *
 * \param inicio
 * \return
 */
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

/**
 * Fun��o que recebe a lista de clientes como par�metro e imprime na tela os dados de todos os clientes.
 *
 * \param inicio
 */
void listarClientes(ListaClientePtr inicio)
{
	ListaClientePtr aux = inicio;

	while (aux != NULL)
	{
		MostraCliente(aux);
		aux = aux->proximo;
	}
}

/**
 * Fun��o para imprimir os dados de um s� cliente.
 * 
 * \param no
 */
void MostraCliente(ListaClientePtr no)
{
	if (no != NULL) {

		printf("Id = %d; Nome = %s; NIF = %d; Morada = %s; Saldo = %f\n", no->cliente.id, no->cliente.nome, no->cliente.nif, no->cliente.morada, no->cliente.saldo);

	}
}

/**
 * Fun��o para remo��o de uma struct Cliente da lista atrav�s do seu id.
 *
 * \param inicio
 * \param identificador
 * \return
 */
ListaClientePtr removerCliente(ListaClientePtr inicio, int identificador)
{
	ListaClientePtr atual = inicio;
	ListaClientePtr anterior = NULL;

	//remover o primeiro n� da lista
	if (atual != NULL && atual->cliente.id == identificador) {
		inicio = atual->proximo;
		free(atual);
		return (inicio);
	}
	//percorrer a lista para navegar todos os n�s e remover o que foi passado no par�metro
	while (atual != NULL && atual->cliente.id != identificador) {
		anterior = atual;
		atual = atual->proximo;
	}
	//no caso do n� n�o ser encontrado na lista, retorna a lista
	if (atual == NULL) {
		return inicio;
	}
	//sendo encontrado o n� ele � removido, e sua mem�ria liberada
	else {
		anterior->proximo = atual->proximo;
		free(atual);
	}
	return (inicio);
}

/**
 * Fun��o recursiva para buscar um n� na lista de clientes.
 *
 * \param inicio
 * \param identificador
 * \return
 */
ListaClientePtr buscarCliente(ListaClientePtr inicio, int identificador) {
	
	ListaClientePtr atual = inicio;
	
	while (atual != NULL) {
		if (atual->cliente.id == identificador) { 
			return atual; //se o id do atual for igual ao id encontrado, retorna atual
		}
		atual = atual->proximo;
	}
	return NULL; //n�o sendo nenhum encontrado, retorna null
}

/**
 * fun��o que altera os dados da struct Cliente dentro da lista.
 *
 * \param inicio
 * \param identificador
 * \param novoid
 * \param novonome
 * \param novonif
 * \param novamorada
 * \param novosaldo
 */
ListaClientePtr alterarCliente(ListaClientePtr inicio, int identificador, int novoid, char novonome[], int novonif, char novamorada[], float novosaldo) {
	
	ListaClientePtr cliente = buscarCliente(inicio, identificador); 
	if (cliente != NULL) {
		cliente->cliente.id = novoid;
		strcpy(cliente->cliente.nome, novonome);
		cliente->cliente.nif = novonif;
		strcpy(cliente->cliente.morada, novamorada);
		cliente->cliente.saldo = novosaldo;

	} return inicio;
}


/**
 * Fun��o que l� um ficheiro de texto contendo os dados de um cliente, e insere-os em uma lista.
 * 
 * \param inicio
 * \param nomeFicheiro
 * \return 
 */
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
	while (fgets(linha, sizeof(linha), fp) != NULL) {
		if (sscanf(linha, "%d;%[^;];%d;%[^;];%f", &aux.id, aux.nome, &aux.nif, aux.morada, &aux.saldo) == 5) {
			ListaClientePtr novoCliente = criarCliente(aux); 
			c = inserirCliente(c, novoCliente); 
		}
	}

	fclose(fp);
	
	return c;
}