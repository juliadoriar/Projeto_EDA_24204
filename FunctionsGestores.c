/*****************************************************************//**
 * \file   FunctionsAux.c
 * \brief  Funções dos gestores
 *
 * \author julia
 * \date   March 2023
 *********************************************************************/
#include "FunctionsGestores.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/** Função que cria gestor */
ListaGestor* criarGestor(Gestor g)
{
	ListaGestor* novoGestor = (ListaGestor*)malloc(sizeof(ListaGestor));
	if (novoGestor != NULL)
		novoGestor->gestor = g;
		novoGestor->proximo = NULL;

		return novoGestor;
	
}
