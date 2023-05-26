/*****************************************************************//**
 * \file   FunctionsAlugueres.h
 * \brief  Biblioteca de assinatura das funções de gestão dos alugueres de meios de mobilidade.
 *
 * \author julia
 * \date   March 2023
 *********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "FunctionsClientes.h"

#pragma once

typedef struct {
	int id;
	int idMeio; //identificacao do meio alugado
	int idCliente; //identificacao do locatário
	float custo;
}Aluguer;

typedef struct {
	Aluguer aluguer;
	struct ListaAluguer *proximo;
}ListaAluguer, *ListaAluguerPtr;

//Função para criar novo aluguer
ListaAluguerPtr criarAluguer(Aluguer* a);

//Função para inserir o aluguer criado em uma lista
ListaAluguerPtr inserirAluguer(ListaAluguerPtr inicio, Aluguer* a, Cliente* c);

//Função para verificar se existe o aluguer na lista
bool existeAluguer(ListaAluguerPtr a, int id);

//Função que guarda os alugueres em um arquivo binário
bool guardarAluguerBin(ListaAluguerPtr* inicio, char arquivo);

//Função para listar os alugueres na tela
bool listarAlugueres(ListaAluguerPtr* inicio);

//Função que imprime um aluguer
void MostraAluguer(Aluguer* no);