/*****************************************************************//**
 * \file   FunctionsMeios.h
 * \brief  Biblioteca de assinatura das fun��es de gest�o dos meios de mobilidade. 
 *
 * \author julia
 * \date   March 2023
 *********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#pragma once

#define MAX 50

typedef struct {
	int id;
	char tipo[MAX];
	float carga; // carga de energia disponivel 
	float autonomia;
	float custo;
	char localizacao[MAX];
}MeioMob;

typedef struct {
	MeioMob meio;
	struct ListaMeio *proximo;
}ListaMeio, * ListaMeioPtr;

//Fun��o para criar novo meio de mobilidadade
ListaMeioPtr criarMeio(MeioMob* m);

//Fun��o para inserir o meio criado em uma lista
ListaMeioPtr inserirMeio(ListaMeioPtr m, MeioMob* inicio); 

//Fun��o para verificar exist�ncia de um meio em uma lista
bool existeMeio(ListaMeioPtr m, int id);

//Fun��o recursiva para salvar lista de meios de mobilidade em ficheiro bin�rio
bool guardarMeioMobBin(ListaMeioPtr inicio, char arquivo);

//Fun��o para listar meios de mobilidade em um ficheiro de texto
bool listarMeiosMob(ListaMeioPtr inicio);

void MostraMeio(MeioMob* no);

//fun��o para remover um n� da lista de clientes
ListaMeioPtr removerMeioMob(ListaMeioPtr inicio, int identificador);

//fun��o recursiva que encontra um n� na lista atrav�s do id
ListaMeioPtr buscarMeioMob(ListaMeioPtr inicio, int identificador);

//fun��o para alterar dados de uma struct dentro de uma lista
ListaMeioPtr alterarMeioMob(ListaMeioPtr* inicio, int identificador, int id, char tipo[], float carga, float autonomia, float custo, char localizacao[]);

//fun��o para ordenar meio por ordem decrescente de autonomia
bool ordenarMeioMob(ListaMeioPtr inicio);


