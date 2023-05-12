/*****************************************************************//**
 * \file   FunctionsMeios.h
 * \brief  Biblioteca de assinatura das funções de gestão dos meios de mobilidade. 
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


//Função para criar novo meio de mobilidadade
MeioMob* criarMeio(MeioMob* inicio, int id, char tipo[], float carga, float autonomia, float custo, char localizacao[]);

//Função recursiva para salvar lista de meios de mobilidade em ficheiro binário
bool guardarMeioMobBin(MeioMob* m, char arquivo[]);

//Função para listar meios de mobilidade em um ficheiro de texto
void listarMeiosMob(MeioMob* inicio);

//função para remover um nó da lista de clientes
MeioMob* removerMeioMob(MeioMob* inicio, int id);

//função recursiva que encontra um nó na lista através do id
MeioMob* buscarMeioMob(MeioMob* inicio, int identificador);

//função para alterar dados de uma struct dentro de uma lista
bool alterarMeioMob(MeioMob* inicio, int identificador, int id, char tipo[], float carga, float autonomia, float custo, char localizacao[]);

//função para ordenar 
bool ordenarMeioMob(MeioMob* inicio);


