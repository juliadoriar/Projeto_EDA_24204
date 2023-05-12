/*****************************************************************//**
 * \file   StructsRegistos.h
 * \brief  Asssinatura de todas estruturas de armazenamento dos dados
 * dos gestores, clientes e meios de mobilidade.
 *
 * \author julia
 * \date   March 2023
 *********************************************************************/

#pragma once




typedef struct {
	int id;
	char tipo[20];
	float carga; // carga de energia disponivel 
	float autonomia;
	float custo;
	char localizacao[40];
	struct MeioMob* proximo; //ponteiro para o próximo nó da lista
}MeioMob;

typedef struct {
	int id;
	char nome[50];
}Gestor;

typedef struct {
	Gestor g;
	struct ListaGestor* proximo;
}ListaGestor;

typedef struct {
	int id; 
	int idMeio; //identificacao do meio alugado
	int idCliente; //identificacao do locatário
	float custo;
	struct Aluguer* proximo; //ponteiro para o próximo nó da lista
}Aluguer;
