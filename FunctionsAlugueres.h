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
#include "Structs.h"

#pragma once

//Função para criar novo aluguer
Aluguer* criarAluguer(Cliente* inicioC, Aluguer* inicioA, int id, int idMeio, int idCliente, float custo);

//Função que guarda os aluguéis em um arquivo binário
bool guardarAluguerBin(Aluguer* inicio, char arquivo[]);

//Função para listar meios de mobilidade em um ficheiro de texto
void listarAlugueres(Aluguer* inicio);

