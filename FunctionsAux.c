/*****************************************************************//**
 * \file   FunctionsAux.c
 * \brief  Fun��es auxiliares/recursivas das demais fun��es.
 *
 * \author julia
 * \date   March 2023
 *********************************************************************/
#include "FunctionsAux.h"
#include "Structs.h"
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
Gestor* criarGestor(Gestor* inicio, int id, char nome[])
{
	Gestor* g = malloc(sizeof(Gestor));
	if (g != NULL)
	{
		g->id = id;
		strcpy(g->nome, nome);

		return g;
	}
	else return(inicio);
}