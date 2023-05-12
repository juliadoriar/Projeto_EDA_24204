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
#include "Structs.h"

#pragma once

//Fun��o para criar novo aluguer
Aluguer* criarAluguer(Cliente* inicioC, Aluguer* inicioA, int id, int idMeio, int idCliente, float custo);

//Fun��o que guarda os alugu�is em um arquivo bin�rio
bool guardarAluguerBin(Aluguer* inicio, char arquivo[]);

//Fun��o para listar meios de mobilidade em um ficheiro de texto
void listarAlugueres(Aluguer* inicio);

