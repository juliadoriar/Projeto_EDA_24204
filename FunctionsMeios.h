/*****************************************************************//**
 * \file   FunctionsMeios.h
 * \brief  Biblioteca de assinatura das fun��es de gest�o dos meios de mobilidade. 
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


//Fun��o para criar novo meio de mobilidadade
MeioMob* criarMeio(MeioMob* inicio, int id, char tipo[], float carga, float autonomia, float custo, char localizacao[]);

//Fun��o recursiva para salvar lista de meios de mobilidade em ficheiro bin�rio
bool guardarMeioMobBin(MeioMob* m, char arquivo[]);

//Fun��o para listar meios de mobilidade em um ficheiro de texto
void listarMeiosMob(MeioMob* inicio);

//fun��o para remover um n� da lista de clientes
MeioMob* removerMeioMob(MeioMob* inicio, int id);

//fun��o recursiva que encontra um n� na lista atrav�s do id
MeioMob* buscarMeioMob(MeioMob* inicio, int identificador);

//fun��o para alterar dados de uma struct dentro de uma lista
bool alterarMeioMob(MeioMob* inicio, int identificador, int id, char tipo[], float carga, float autonomia, float custo, char localizacao[]);

//fun��o para ordenar 
bool ordenarMeioMob(MeioMob* inicio);


