/*****************************************************************//**
 * \file   FunctionsMeios.h
 * \brief  Biblioteca de assinatura das funções de gestão dos meios de mobilidade. 
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

//Função para criar novo meio de mobilidadade
ListaMeioPtr criarMeio(MeioMob* m);

//Função para inserir o meio criado em uma lista
ListaMeioPtr inserirMeio(ListaMeioPtr m, MeioMob* inicio); 

//Função para verificar existência de um meio em uma lista
bool existeMeio(ListaMeioPtr m, int id);

//Função recursiva para salvar lista de meios de mobilidade em ficheiro binário
bool guardarMeioMobBin(ListaMeioPtr inicio, char arquivo);

//Função para listar meios de mobilidade em um ficheiro de texto
bool listarMeiosMob(ListaMeioPtr inicio);

void MostraMeio(MeioMob* no);

//função para remover um nó da lista de clientes
ListaMeioPtr removerMeioMob(ListaMeioPtr inicio, int identificador);

//função recursiva que encontra um nó na lista através do id
ListaMeioPtr buscarMeioMob(ListaMeioPtr inicio, int identificador);

//função para alterar dados de uma struct dentro de uma lista
ListaMeioPtr alterarMeioMob(ListaMeioPtr* inicio, int identificador, int id, char tipo[], float carga, float autonomia, float custo, char localizacao[]);

//função para ordenar meio por ordem decrescente de autonomia
bool ordenarMeioMob(ListaMeioPtr inicio);


