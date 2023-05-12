/*****************************************************************//**
 * \file   Functions.h
 * \brief  Assinatura para todas as fun��es do programa.
 *
 * \author julia
 * \date   March 2023
 *********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Structs.h"

#pragma once


//Fun��o para criar um novo gestor com id e nome
Gestor* criarGestor(Gestor* inicio, int id, char nome[]);