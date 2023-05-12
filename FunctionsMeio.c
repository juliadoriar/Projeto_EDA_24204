/*****************************************************************//**
 * \file   FunctionsMeio.c
 * \brief  Funções de gestão dos meios de mobilidade
 * 
 * \author julia
 * \date   April 2023
 *********************************************************************/
#include "FunctionsMeios.h"
#include "Structs.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Função que cria novo meio de mobilidade e insere na lista.
 *
 * \param inicio
 * \param id
 * \param tipo
 * \param carga
 * \param autonomia
 * \param localizacao
 * \return
 */
MeioMob* criarMeio(MeioMob* inicio, int id, char tipo[], float carga, float autonomia, float custo, char localizacao[])
{
	MeioMob* m = (MeioMob*)malloc(sizeof(MeioMob));
	if (m == NULL) return NULL;
	m->proximo = NULL;

	m->id = id;
	strcpy(m->tipo, tipo);
	m->carga = carga;
	m->autonomia = autonomia;
	m->custo = custo;
	strcpy(m->localizacao, localizacao);

	if (inicio == NULL) {
		inicio = m;
	}
	else {
		m->proximo = inicio;
		inicio = m;
	}

	return m;

}

/**
 *  * Função recursiva para guardar os meios de mobilidade da lista em um ficheiro binário.
 *
 * \param inicio
 * \param arquivo
 */
bool guardarMeioMobBin(MeioMob* inicio, char arquivo[])
{
	FILE* fp = fopen("MeiosMob.bin", "wb");
	if (inicio == NULL) return false;
	if (fp == NULL)
	{
		printf("Erro ao abrir o arquivo");
		return;
	}

	MeioMob* atual = inicio;
	while (atual != NULL)
	{
		MeioMob aux = *atual;
		aux.proximo = NULL;
		fwrite(&aux, sizeof(MeioMob), 1, fp);
		atual = atual->proximo;
	}

	fclose(fp);
	return true;
}

/**
 * Função que recebe a lista de meios de mobilidade como parâmetro e a salva em ficheiro de texto e binário, assim como lista na tela.
 *
 * \param inicio
 */
void listarMeiosMob(MeioMob* inicio)
{
	FILE* fp = fopen("MeiosMob.txt", "a");
	
	MeioMob* aux = inicio;

	if (fp == NULL) {
		printf("Erro ao abrir arquivo");
		return;
	}
	while (aux != NULL)
	{
		fprintf(fp, "%d; %s; %f	; %f; %f; %s\n", aux->id, aux->tipo, aux->carga, aux->autonomia, aux->custo, aux->localizacao);
		printf("%d; %s; %f	; %f; %f; %s\n", aux->id, aux->tipo, aux->carga, aux->autonomia, aux->custo, aux->localizacao);
		aux = aux->proximo;
	}
	fclose(fp);
	guardarMeioMobBin(inicio, "MeiosMob.bin");
	
}

/**
 * Função para remoção de uma struct MeioMob da lista através do seu id.
 *
 * \param inicio
 * \param identificador
 * \return
 */
MeioMob* removerMeioMob(MeioMob* inicio, int identificador)
{
	MeioMob* atual = inicio;
	MeioMob* anterior = NULL;

	//remover o primeiro nó da lista
	if (atual != NULL && atual->id == identificador) {
		inicio = atual->proximo;
		free(atual);
		return (inicio);
	}
	//percorrer a lista para navegar todos os nós e remover o que foi passado no parâmetro
	while (atual != NULL && atual->id != identificador) {
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

/**
 * Função recursiva para buscar um nó na lista de meios de mobilidade.
 *
 * \param inicio
 * \param identificador
 * \return
 */
MeioMob* buscarMeioMob(MeioMob* inicio, int identificador) {
	MeioMob* atual = inicio;

	while (atual != NULL) {
		if (atual->id == identificador) {
			return atual;
		}
		atual = atual->proximo;
	}
	return NULL;
}

/**
 * Função que altera os dados da struct MeioMob dentro da lista.
 *
 * \param inicio
 * \param identificador
 * \param id
 * \param tipo
 * \param carga
 * \param autonomia
 * \param custo
 * \param localizacao
 */
bool alterarMeioMob(MeioMob* inicio, int identificador, int id, char tipo[], float carga, float autonomia, float custo, char localizacao[]) {
	if (inicio == NULL) return false;
	MeioMob* meio = buscarMeioMob(inicio, identificador);
	if (meio != NULL) {
		meio->id = id;
		strcpy(meio->tipo, tipo);
		meio->carga = carga;
		meio->autonomia = autonomia;
		meio->custo = custo;
		strcpy(meio->localizacao, localizacao);
	} return  true;
}

/**
 * Função que ordena os meios de mobilidade em ordem decresente e salva na memória.
 *
 * \param inicio
 */
bool ordenarMeioMob(MeioMob* inicio) {
	if (inicio == NULL) return false;
	MeioMob* atual;
	MeioMob* seguinte;
	int troca = 1;

	while (troca) {
		troca = 0;
		atual = inicio;

		while (atual->proximo != NULL) {
			seguinte = atual->proximo;
			if (atual->autonomia < seguinte->autonomia) {
				float aux = atual->autonomia;
				atual->autonomia = seguinte->autonomia;
				seguinte->autonomia = aux;
				troca = 1;
			}
			atual = atual->proximo;
		}
	} return true;
}

/*
bool listarMeioMobLocalizacao(MeioMob* inicio, char localizacao[]){
	if (inicio == NULL) return false;
	MeioMob* meio = (MeioMob*)malloc(sizeof(MeioMob));



}*/






