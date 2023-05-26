/*****************************************************************//**
 * \file   StructsRegistos.h
 * \brief  Asssinatura de estruturas e funções dos gestores
 *
 * \author julia
 * \date   March 2023
 *********************************************************************/

#pragma once

typedef struct {
	int id;
	char nome[50];
}Gestor;

typedef struct {
	Gestor gestor;
	struct ListaGestor* proximo;
}ListaGestor, *ListaGestorPtr;


ListaGestor* criarGestor(Gestor g);