/*****************************************************************//**
 * \file   FunctionsAlugueres.h
 * \brief  Biblioteca de assinatura das fun��es de gest�o dos alugueres de meios de mobilidade.
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
	int idCliente; //identificacao do locat�rio
	float custo;
}Aluguer;

typedef struct {
	Aluguer aluguer;
	struct ListaAluguer *proximo;
}ListaAluguer, *ListaAluguerPtr;

//Fun��o para criar novo aluguer
ListaAluguerPtr criarAluguer(Aluguer* a);

//Fun��o para inserir o aluguer criado em uma lista
ListaAluguerPtr inserirAluguer(ListaAluguerPtr inicio, Aluguer* a, Cliente* c);

//Fun��o para verificar se existe o aluguer na lista
bool existeAluguer(ListaAluguerPtr a, int id);

//Fun��o que guarda os alugueres em um arquivo bin�rio
bool guardarAluguerBin(ListaAluguerPtr* inicio, char arquivo);

//Fun��o para listar os alugueres na tela
bool listarAlugueres(ListaAluguerPtr* inicio);

//Fun��o que imprime um aluguer
void MostraAluguer(Aluguer* no);