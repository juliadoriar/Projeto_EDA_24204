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
	MeioMob m2 = {2, "bicicleta", 40, 40, 3, "Salvador"};
	m = inserirMeio(m, &m2); 
	MeioMob m3 = {3, "trotinete", 50, 50, 2, "Feira"};
	m = inserirMeio(m, &m3);

	c = alterarCliente(c, 1, 7, "Maria", 777777777, "Rua da siriguela", 35.00);

	c = removerCliente(c, 3);  

	listarClientes(c);

	alterarMeioMob(m, 3, 9, "trotinete", 77, 77, 3.5, "Itacare");

	m = removerMeioMob(m, 1);

	ordenarMeioMob(m);

	listarMeiosMob(m);

	Aluguer a1 = {1, 1, 1, 10.00 };
	a = inserirAluguer(a, &a1, &c1);
	Aluguer a2 = { 2, 2, 3, 5.00 };
	a = inserirAluguer(a, &a2, &c2);

	listarAlugueres(a);

	guardarClienteBin(c);



	Adj* adj = NULL;
	Vertice* v = NULL;


	Vertice* grafo = criarGrafo();

	bool vis;

	grafo = inserirVertice(grafo, "Salvador", 1, &vis); 

	grafo = inserirVertice(grafo, "Feira", 2, &vis); 

	grafo = inserirVertice(grafo, "Itacare", 3, &vis); 
	

	
	mostrarGrafo(grafo); 

	grafo = destruirGrafo(grafo);

	

	return(0);
}