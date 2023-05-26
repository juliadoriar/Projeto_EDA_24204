/*****************************************************************//**
 * \file   FunctionsMeio.c
 * \brief  Fun��es de gest�o dos meios de mobilidade
 * 
 * \author julia
 * \date   April 2023
 *********************************************************************/
#include "FunctionsMeios.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


/**
 * Fun��o que cria novo meio de mobilidade dentro da estrutura ListaMeio.
 *
 * \param inicio
 * \param id
 * \param tipo
 * \param carga
 * \param autonomia
 * \param localizacao
 * \return
 */
ListaMeioPtr criarMeio(MeioMob* m)
{
	ListaMeioPtr novoMeio = (MeioMob*)malloc(sizeof(MeioMob));
	if (novoMeio == NULL) return NULL;
	novoMeio->meio = *m;
	novoMeio->proximo= NULL;

	return novoMeio;
}

/**
 * Fun��o que insere o meio criado na lista encadeada de meios de mobilidade.
 * 
 * \param m
 * \param inicio
 * \return 
 */
ListaMeioPtr inserirMeio(ListaMeioPtr m, MeioMob* inicio)
{
	if (existeMeio(m, inicio->id)) return m;

	ListaMeioPtr aux = (ListaMeioPtr)malloc(sizeof(ListaMeio));
	aux->meio = *inicio;
	aux->proximo = NULL;

	if (m == NULL) {
		m = aux;
	}
	else {
		aux->proximo = m->proximo;
		m->proximo = aux;
	}

	return m;
	
}

/**
 * Fun��o recursiva para verificar se o meio do id passado por par�metro j� existe na lista
 * Em caso afirmativo, a fun��o devolve verdadeiro. Em caso negativo, devolve falso.
 * 
 * \param m
 * \param id
 * \return 
 */
bool existeMeio(ListaMeioPtr m, int id) {

	if (m == NULL) return false;
	ListaMeioPtr aux = m;
	while (aux != NULL) {
		if (aux->meio.id == id)
			return true;
		aux = aux->proximo;
	}
	return false;
}



/**
 *  * Fun��o recursiva para guardar os meios de mobilidade da lista em um ficheiro bin�rio.
 *
 * \param inicio
 * \param arquivo
 */
bool guardarMeioMobBin(ListaMeioPtr inicio, char arquivo)
{
	FILE* fp = fopen(arquivo, "wb");
	
	if (fp == NULL)
	{
		return false;
	}

	ListaMeioPtr atual = inicio;
	MeioMob auxMeio; 
	while (atual != NULL)
	{
		auxMeio = atual->meio;
		fwrite(&auxMeio, sizeof(MeioMob), 1, fp);
		atual = atual->proximo;
	}

	fclose(fp);
	return true;
}

/**
 * Fun��o que recebe a lista de meios de mobilidade como par�metro e lista todos eles na tela.
 *
 * \param inicio
 */
bool listarMeiosMob(ListaMeioPtr inicio)
{
	if (inicio == NULL) return false;
	ListaMeioPtr aux = inicio;

	while (aux != NULL)
	{
		MostraMeio(aux);
		aux = aux->proximo;
	}

	return true;
}

/**
 * Fun��o recursiva para imprimir um meio de mobilidade.
 * 
 * \param no
 */
void MostraMeio(MeioMob* no)
{
	if (no != NULL) {

		printf("Id = %d; Tipo = %s; Carga = %f; Autonomia = %f; Custo = %f; Localizacao = %s\n", no->id, no->tipo, no->carga, no->autonomia, no->custo, no->localizacao);

	}
}


/**
 * Fun��o para remo��o de um meio da lista atrav�s do seu id.
 *
 * \param inicio
 * \param identificador
 * \return
 */
ListaMeioPtr removerMeioMob(ListaMeioPtr inicio, int identificador)
{
	ListaMeioPtr atual = inicio;
	ListaMeioPtr anterior = NULL;

	//remover o primeiro n� da lista
	if (atual != NULL && atual->meio.id == identificador) {
		inicio = atual->proximo;
		free(atual);
		return (inicio);
	}
	//percorrer a lista para navegar todos os n�s e remover o que foi passado no par�metro
	while (atual != NULL && atual->meio.id != identificador) {
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
 * Fun��o recursiva para buscar um n� na lista de meios de mobilidade.
 *
 * \param inicio
 * \param identificador
 * \return
 */
ListaMeioPtr buscarMeioMob(ListaMeioPtr inicio, int identificador) {
	ListaMeioPtr atual = inicio;

	while (atual != NULL) {
		if (atual->meio.id == identificador) {
			return atual;
		}
		atual = atual->proximo;
	}
	return NULL;
}

/**
 * Fun��o que altera os dados da struct MeioMob dentro da lista.
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
ListaMeioPtr alterarMeioMob(ListaMeioPtr* inicio, int identificador, int id, char tipo[], float carga, float autonomia, float custo, char localizacao[]) {
	if (inicio == NULL) return false;
	ListaMeioPtr m = buscarMeioMob(inicio, identificador);
	if (m != NULL) {
		m->meio.id = id;
		strcpy(m->meio.tipo, tipo);
		m->meio.carga = carga;
		m->meio.autonomia = autonomia;
		m->meio.custo = custo;
		strcpy(m->meio.localizacao, localizacao);
	} return  true;
}

/**
 * Fun��o que ordena os meios de mobilidade em ordem decrescente e salva na mem�ria.
 *
 * \param inicio
 */
bool ordenarMeioMob(ListaMeioPtr inicio) {
	if (inicio == NULL) return false;
	ListaMeioPtr atual;
	ListaMeioPtr seguinte;
	
	int troca = 1;

	while (troca) {
		troca = 0;
		atual = inicio;

		while (atual->proximo != NULL) {
			seguinte = atual->proximo;
			if (atual->meio.autonomia < seguinte->meio.autonomia) {
				float aux = atual->meio.autonomia;
				atual->meio.autonomia = seguinte->meio.autonomia;
				seguinte->meio.autonomia = aux;
				troca = 1;
			}
			atual = atual->proximo;
		}
	} return true;
}

/*
void trocaMeio(ListaMeioPtr atual, ListaMeioPtr seguinte) {

	MeioMob aux = atual->meio;
	atual->meio = seguinte->meio;
	seguinte->meio = aux;

}

bool ordenaMeio(ListaMeioPtr inicio) {

	int troca;
	ListaMeioPtr atual;
	ListaMeioPtr seguinte = NULL;

	if (inicio = NULL) return false;

	do {

		troca = 0;
		atual = inicio;

		while (atual->proximo != seguinte) {

			if (atual->meio.autonomia < seguinte->meio.autonomia) {

				trocaMeio(atual, atual->proximo);
				troca = 1;

			}

			seguinte = atual;
		} while (troca);
	}
}
	*/










