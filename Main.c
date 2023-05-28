/*****************************************************************//**
 * \file   Main.c
 * \brief  Função principal do programa, responsável por chamar as demais funções implementadas.
 * Esta função recebe valores por parâmetro, e executa funções como
 * inserir novos membros, passar pra arquivos de texto e binário, listar em ordem decrescente,
 * alterar dados e remover dados.
 * \author julia
 * \date   March 2023
 *********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "FunctionsAlugueres.h"
#include "FunctionsMeios.h"
#include "FunctionsClientes.h"
#include "Grafos.h"

int main() {

	setlocale(LC_ALL, "Portuguese");

#pragma region FASE1

	ListaClientePtr c = NULL; 
	ListaAluguerPtr a = NULL;
	ListaMeioPtr m = NULL;


	c = lerFicheiroCliente(c, "Clientes.txt");

	Cliente c1 = {1, "Maria", 333333333, "Rua do umbu", 40.00 }; 
	c = inserirCliente(c, &c1); 
	Cliente c2 = {2, "Joana", 444444444, "Rua da jaca", 50.00 };
	c = inserirCliente(c, &c2); 
	Cliente c3 = {3, "Luis", 555555555, "Rua do caju", 30.00 };
	c = inserirCliente(c, &c3);  

	MeioMob m1 = {1, "trotinete", 30, 30, 2, "Mucuge"};
	m = inserirMeio(m, &m1); 
	MeioMob m2 = {2, "bicicleta", 55, 55, 3, "Salvador"};
	m = inserirMeio(m, &m2); 
	MeioMob m3 = {3, "trotinete", 40, 40, 2, "Feira"};
	m = inserirMeio(m, &m3);
	MeioMob m4 = {4, "bicicleta", 70, 70, 3, "Itacare"};
	m = inserirMeio(m, &m4);
	MeioMob m5 = {5, "bicicleta", 35, 35, 4, "Itaberaba" };
	m = inserirMeio(m, &m5);

	c = alterarCliente(c, 1, 7, "Maria", 777777777, "Rua da siriguela", 35.00);

	c = removerCliente(c, 3);  

	printf("\nCLIENTES:\n");
	listarClientes(c);

	alterarMeioMob(m, 3, 9, "trotinete", 77, 77, 3.5, "Itacare");

	m = removerMeioMob(m, 1);

	ordenarMeioMob(m);

	printf("\nMEIOS DE MOBILIDADE:\n");
	listarMeiosMob(m);

	Aluguer a1 = {1, 1, 1, 10.00 };
	a = inserirAluguer(a, &a1, &c1);
	Aluguer a2 = { 2, 2, 3, 5.00 };
	a = inserirAluguer(a, &a2, &c2);

	printf("\nALUGUERES:\n");
	listarAlugueres(a);

	guardarClienteBin(c);

#pragma endregion

#pragma region FASE 2
	Adj* adj = NULL;
	Vertice* v = NULL;


	Vertice* grafo = criarGrafo();

	bool vis;

	grafo = lerGrafoFicheiro(v, "Vertices.txt");  

	grafo = inserirVertice(grafo, "Salvador", 1, &vis);  
	grafo = inserirVertice(grafo, "Feira", 2, &vis); 
	grafo = inserirVertice(grafo, "Itacare", 3, &vis); 
	grafo = inserirVertice(grafo, "Mucuge", 4, &vis); 
	grafo = inserirVertice(grafo, "Cachoeira", 5, &vis);
	grafo = inserirVertice(grafo, "Itacimirim", 6, &vis);


	grafo = inserirAdjVerticeId(grafo, 1, 2, 120, &vis); //  insere adjacencia de salvador para feira 
	grafo = inserirAdjVerticeId(grafo, 2, 3, 200, &vis); //  insere adjacencia de feira para itacare 
	grafo = inserirAdjVerticeId(grafo, 3, 4, 150, &vis); //  insere adjacencia de itacare para mucuge
	grafo = inserirAdjVerticeId(grafo, 4, 1, 300, &vis); //  insere adjacencia de mucuge para salvador
	grafo = inserirAdjVerticeId(grafo, 2, 4, 100, &vis); //  insere adjacencia de feira para mucugê
	grafo = inserirAdjVerticeId(grafo, 4, 5, 50, &vis);  //  insere adjacencia de mucuge para cachoeira
	grafo = inserirAdjVerticeId(grafo, 5, 6, 50, &vis); //  insere adjacencia de cachoeira para itacimirim
	grafo = inserirAdjVerticeId(grafo, 5, 1, 50, &vis);  //  insere adjacencia de cachoeira para salvador
	grafo = inserirAdjVerticeId(grafo, 6, 1, 80, &vis);  //  insere adjacencia de itacimirim para salvador
	grafo = inserirAdjVerticeId(grafo, 7, 2, 100, &vis); //  insere adjacencia de juazeiro para feira
	grafo = inserirAdjVerticeId(grafo, 7, 3, 100, &vis); //  insere adjacencia de juazeiro para itacare
	grafo = inserirAdjVerticeId(grafo, 5, 2, 30, &vis);  //  insere adjacencia de itacimirim para feira
	//grafo = inserirAdjVerticeId(grafo, 6, 8, 30, &vis);  //  insere adjacencia de itacimirim para itaberaba


	Vertice* vertice1 = buscarVerticeId(grafo, 4);
	if (vertice1 != NULL) {
		inserirMeioVertice(vertice1, m1);
	}

	Vertice* vertice2 = buscarVerticeId(grafo, 1);
	if (vertice2 != NULL) {
		inserirMeioVertice(vertice2, m2);
	}

	Vertice* vertice3 = buscarVerticeId(grafo, 2);
	if (vertice3 != NULL) {
		inserirMeioVertice(vertice3, m3);
	}

	Vertice* vertice4 = buscarVerticeId(grafo, 5);
	if (vertice4 != NULL) {
		inserirClienteVertice(vertice4, c1);
	}

	Vertice* vertice5 = buscarVerticeId(grafo, 6);
	if (vertice5 != NULL) {
		inserirClienteVertice(vertice5, c2);
	}

	Vertice* vertice6 = buscarVerticeId(grafo, 7);
	if (vertice6 != NULL) {
		inserirClienteVertice(vertice6, c3); 
	}

	Vertice* vertice7 = buscarVerticeId(grafo, 3);
	if (vertice7 != NULL) {
		inserirMeioVertice(vertice6, m4);
	}

	Vertice* vertice8 = buscarVerticeId(grafo, 8);
	if (vertice8 != NULL) {
		inserirMeioVertice(vertice8, m5);
	}

	//guardarVerticesFicheiro(grafo, "Vertices.txt");
	guardarGrafoBinario(grafo, "Grafo.bin");

	listarMeiosPorTipoERaio(grafo, "Cachoeira", "trotinete", 400); 
	listarMeiosPorTipoERaio(grafo, "Itacimirim", "bicicleta", 300);


	printf("\nGRAFO:\n"); 
	mostrarGrafo(grafo); 

	guardarVerticesFicheiro(grafo, "Grafo.txt");

	//grafo = destruirGrafo(grafo);

#pragma endregion
	
	return(0);
}

