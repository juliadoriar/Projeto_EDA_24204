/*****************************************************************//**
 * \file   FunctionsAlugueres.c
 * \brief  Funções de gestão dos alugueres
 * 
 * \author julia
 * \date   April 2023
 *********************************************************************/
#include "FunctionsAlugueres.h"
#include "Structs.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * Função para criar um novo aluguel e ao final alterar o saldo do cliente locatário.
 *
 * \param inicioC
 * \param inicioA
 * \param id
 * \param idMeio
 * \param idCliente
 * \param custo
 * \return
 */
Aluguer* criarAluguer(Cliente* inicioC, Aluguer* inicioA, int id, int idMeio, int idCliente, float custo)
{
	Aluguer* novoAluguer = (Aluguer*)malloc(sizeof(Aluguer));

	if (novoAluguer == NULL) return NULL;
	novoAluguer->proximo = NULL;

	novoAluguer->id = id;
	novoAluguer->idMeio = idMeio;
	novoAluguer->idCliente = idCliente;
	novoAluguer->custo = custo;

	if (inicioA == NULL) {
		inicioA = novoAluguer;
	}
	else {
		novoAluguer->proximo = inicioA;
		inicioA = novoAluguer;
	}

	Cliente* clienteUtente = buscarCliente(inicioC, idCliente);
	int identificador = clienteUtente->id;
	float novoSaldo = clienteUtente->saldo - novoAluguer->custo;

	alterarCliente(inicioC, identificador, clienteUtente->id, clienteUtente->nome, clienteUtente->nif, clienteUtente->morada, novoSaldo);

	return novoAluguer;
}

/**
 * Função para guardar a lista de alugueres em um ficheiro binário.
 *
 * \param inicio
 * \param arquivo
 */
bool guardarAluguerBin(Aluguer* inicio, char arquivo[]) {
	FILE* fp = fopen("Aluguer.bin", "wb");
	if (inicio == NULL) return false;
	if (fp == NULL)
	{
		printf("Erro ao abrir o arquivo!");
		return;
	}

	Aluguer* atual = inicio;
	while (atual != NULL)
	{
		Aluguer aux = *atual;
		aux.proximo = NULL;
		fwrite(&aux, sizeof(Aluguer), 1, fp);
		atual = atual->proximo;
	}
	fclose(fp);
	return true;
}

/**
 * Função que lista os alugueres em memória na tela e em um ficheiro de texto e binário.
 *
 * \param inicio
 */
void listarAlugueres(Aluguer* inicio)
{
	FILE* fp = fopen("Aluguer.txt", "a");
	Aluguer* aux = inicio;

	if (fp == NULL) {
		printf("Erro ao abrir arquivo");
		return;
	}
	while (aux != NULL)
	{
		fprintf(fp, "%d; %d; %d; %f\n", aux->id, aux->idMeio, aux->idCliente, aux->custo);
		printf("% d; % d; % d; % f\n", aux->id, aux->idMeio, aux->idCliente, aux->custo);
		aux = aux->proximo;
	}
	fclose(fp);
	guardarAluguerBin(inicio, "Aluguer.bin");
}

