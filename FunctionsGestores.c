/*****************************************************************//**
 * \file   FunctionsAux.c
 * \brief  Fun��es auxiliares/recursivas das demais fun��es.
 *
 * \author julia
 * \date   March 2023
 *********************************************************************/
#include "FunctionsGestores.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * Fun��o que cria gestor.
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
