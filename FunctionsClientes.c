/*****************************************************************//**
 * \file   FunctionsClientes.c
 * \brief  Fun��es de administr���o dos dados dos clientes
 * 
 * \author julia
 * \date   April 2023
 *********************************************************************/
#include "FunctionsClientes.h"
#include "Structs.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

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
ListaCliente* criarCliente(Cliente* c)
{
	ListaCliente* novoCliente = (Cliente*)malloc(sizeof(Cliente));
	if (novoCliente == NULL) return NULL;
	novoCliente->cliente = *c;
	novoCliente->proximo = NULL;
	return novoCliente;

}

ListaClientePtr* inserirCliente(ListaClientePtr c, Cliente* inicio)
{


	if (inicio == NULL) {
		inicio = c;
	}
	else {
		c->proximo = inicio;
		inicio = c;
	}

	return c;

}



/**
 * Fun��o recursiva para guardar clientes da lista em um ficheiro bin�rio.
 *
 * \param inicio
 * \return
 */
bool guardarClienteBin(Cliente* inicio, char arquivo[])
{
	FILE* fp = fopen("Clientes.bin", "wb");
	if (inicio == NULL) return false;
	if (fp == NULL){
		return false;
	}

	Cliente* atual = inicio;
	while (atual != NULL)
	{
		Cliente aux = *atual;
		aux.proximo = NULL;
		fwrite(&aux, sizeof(Cliente), 1, fp);
		//fwrite(&(atual->id),&(atual->nome),&(atual->nif),&(atual->morada),&(atual->saldo), aux, sizeof(Cliente), 1, fp);
		atual = atual->proximo;
	}

	fclose(fp);
	return true;
}

/**
 * Fun��o que recebe a lista de clientes como par�metro e a salva em ficheiro de texto e bin�rio, assim como lista na tela.
 *
 * \param inicio
 */
bool listarClientes(Cliente* inicio)
{
	FILE* fp = fopen("Clientes.txt", "a");
	if (inicio == NULL) return false;
	Cliente* aux = inicio;

	if (fp == NULL) {
		return false;
	}
	while (aux != NULL)
	{
		fprintf(fp, "%d; %s; %d; %s; %f\n", aux->id, aux->nome, aux->nif, aux->morada, aux->saldo);
		printf("% d; %s; % d; %s; % f\n", aux->id, aux->nome, aux->nif, aux->morada, aux->saldo);
		aux = aux->proximo;
	}
	fclose(fp);
	//guardarClienteBin(inicio, "Clientes.bin");
	return true;
}

/**
 * Fun��o para remo��o de uma struct Cliente da lista atrav�s do seu id.
 *
 * \param inicio
 * \param identificador
 * \return
 */
Cliente* removerCliente(Cliente* inicio, int identificador)
{
	Cliente* atual = inicio;
	Cliente* anterior = NULL;

	//remover o primeiro n� da lista
	if (atual != NULL && atual->id == identificador) {
		inicio = atual->proximo;
		free(atual);
		return (inicio);
	}
	//percorrer a lista para navegar todos os n�s e remover o que foi passado no par�metro
	while (atual != NULL && atual->id != identificador) {
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
Cliente* buscarCliente(Cliente* inicio, int identificador) {
	Cliente* atual = inicio;

	while (atual != NULL) {
		if (atual->id == identificador) {
			return atual;
		}
		atual = atual->proximo;
	}
	return NULL;
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
bool alterarCliente(Cliente* inicio, int identificador, int novoid, char novonome[], int novonif, char novamorada[], float novosaldo) {
	if (inicio == NULL) return false;

	Cliente* cliente = buscarCliente(inicio, identificador);
	if (cliente != NULL) {
		cliente->id = novoid;
		strcpy(cliente->nome, novonome);
		cliente->nif = novonif;
		strcpy(cliente->morada, novamorada);
		cliente->saldo = novosaldo;

	} return true;
}

/**
 * Fun��o para ler ficheiro de texto e alocar em lista.
 *
 * \param inicio
 * \param arquivo
 * \return
 */
Cliente* lerFicheiroCliente(Cliente* inicio, char *nomeFi) {
	FILE* fp;
	fp = fopen("Clientes.txt", "r");
	int id;
	char nome[50];
	int nif;
	char morada[100];
	float saldo;


	if (fp == NULL)
	{
		return NULL;
		//printf("Erro ao abrir arquivo");
		//exit(1);
	}	
	Cliente* cliente = NULL;
	while (!feof(fp) != NULL)
	{
		//criar cliente com malloc
		cliente = criarCliente(cliente, id, nome, nif, morada, saldo);
		fscanf(fp, "%d;%50[^;];%d;%100[^;];%f\n", &id, nome, &nif, morada, &saldo);

		


	}

	fclose(fp);
	return inicio;
}
