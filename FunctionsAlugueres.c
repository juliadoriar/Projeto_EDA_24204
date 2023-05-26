/*****************************************************************//**
 * \file   FunctionsAlugueres.c
 * \brief  Fun��es de gest�o dos alugueres
 * 
 * \author julia
 * \date   April 2023
 *********************************************************************/
#include "FunctionsAlugueres.h"
#include "FunctionsClientes.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * Fun��o que cria um aluguer dentro da estrutura ListaAluguer.
 * 
 * \param a
 * \return 
 */
ListaAluguerPtr criarAluguer(Aluguer* a)
{
	ListaAluguerPtr novoAluguer = (ListaAluguer*)malloc(sizeof(ListaAluguer));
	if (novoAluguer == NULL) return NULL;
	novoAluguer->aluguer = *a;
	novoAluguer->proximo = NULL;

	return novoAluguer;
}

/**
 * Fun��o para inserir o aluguer criado em uma lista encadeada de alugueres.
 * 
 * \param inicio
 * \param a
 * \param c
 * \return 
 */
ListaAluguerPtr inserirAluguer(ListaAluguerPtr inicio, Aluguer* a, Cliente* c)
{
	if (existeAluguer(inicio, a->id)) return inicio;
	
	ListaAluguerPtr novoAluguer = (ListaAluguerPtr)malloc(sizeof(ListaAluguer));
	novoAluguer->aluguer = *a;
	novoAluguer->proximo = NULL;


	if (inicio == NULL) {
		inicio = novoAluguer;
	}
	else {
		novoAluguer->proximo = inicio;
		inicio = novoAluguer;
	}

	Cliente* clienteUtilizador = c;
	clienteUtilizador->saldo = clienteUtilizador->saldo - novoAluguer->aluguer.custo;

	alterarCliente(clienteUtilizador, clienteUtilizador->id, clienteUtilizador->id, clienteUtilizador->nome, clienteUtilizador->nif, clienteUtilizador->morada, clienteUtilizador->saldo);
	
	return novoAluguer;
}


/**
 * Fun��o recursiva para obter a informa��o se existe ou n�o o aluguer passado por par�metro dentro da lista.
 * 
 * \param a
 * \param id
 * \return 
 */
bool existeAluguer(ListaAluguerPtr a, int id) {

	if (a == NULL) return false;
	ListaAluguerPtr aux = a;
	while (aux != NULL) {
		if (aux->aluguer.id == id)
			return true;
		aux = aux->proximo;
	}
	return false;
}



/**
 * Fun��o para guardar a lista de alugueres em um ficheiro bin�rio.
 *
 * \param inicio
 * \param arquivo
 */
bool guardarAluguerBin(ListaAluguerPtr* inicio, char arquivo) {
	FILE* fp = fopen(arquivo, "wb");
	if (inicio == NULL) return false;
	if (fp == NULL)
	{
		printf("Erro ao abrir o arquivo!");
		return false;
	}

	ListaAluguerPtr atual = inicio;
	Aluguer auxAluguer;

	while (atual != NULL)
	{
		auxAluguer = atual->aluguer;
		fwrite(&auxAluguer, sizeof(Aluguer), 1, fp);
		atual = atual->proximo;
	}
	fclose(fp);
	return true;
}

/**
 * Fun��o que lista os alugueres em mem�ria na tela.
 *
 * \param inicio
 */
bool listarAlugueres(ListaAluguerPtr* inicio)
{
	FILE* fp = fopen("Aluguer.txt", "a");
	ListaAluguerPtr aux = inicio;

	if (fp == NULL) {
		return false;
	}
	while (aux != NULL)
	{
		{
			MostraAluguer(aux);
			aux = aux->proximo;
		}
	}
	fclose(fp);
	return true;
}

/**
 * Fun��o recursiva que imprime para a tela os dados de um aluguer.
 * 
 * \param no
 */
void MostraAluguer (Aluguer* no)
{
	if (no != NULL) {

		printf("Id = %d; IdMeio = %d; IdCliente = %d; Custo = %f\n", no->id, no->idMeio, no->idCliente, no->custo);

	}
}