/*****************************************************************//**
 * \file   FunctionsAux.c
 * \brief  Funções auxiliares/recursivas das demais funções.
 *
 * \author julia
 * \date   March 2023
 *********************************************************************/
#include "FunctionsGestores.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * Função que cria gestor.
 *
 * \param inicio
 * \param id
 * \param nome
 * \return
 */
ListaGestor* criarGestor(Gestor g)
{
	ListaGestor* novoGestor = (ListaGestor*)malloc(sizeof(ListaGestor));
	if (novoGestor != NULL)
		novoGestor->gestor = g;
		novoGestor->proximo = NULL;

		return novoGestor;
	
}
