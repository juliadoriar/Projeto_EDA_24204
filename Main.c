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
#include "FunctionsAux.h"
#include "FunctionsAlugueres.h"
#include "FunctionsMeios.h"
#include "FunctionsClientes.h"
#include "Structs.h"

int main() {

	Cliente* c = NULL;
	MeioMob* m = NULL;
	Aluguer* a = NULL;
	Gestor* g = NULL;
	/*Cliente* ptr = NULL;
	Cliente* inicio = NULL;
	Cliente* atual = NULL;*/
	Aluguer* inicioA = NULL;

	g = criarGestor(g, 99, "Julia");

	c = criarCliente(c, 3, "Maria", 333333333, "Rua do umbu", 40.00);
	c = criarCliente(c, 4, "Joana", 444444444, "Rua da jaca", 50.00);
	c = criarCliente(c, 5, "Luis", 555555555, "Rua do caju", 30.00);
	c = criarCliente(c, 6, "Luisa", 666666666, "Rua da amora", 40.00);

	m = criarMeio(m, 1, "trotinete", 55, 55, 2.5, "Feira");
	m = criarMeio(m, 2, "bicicleta", 44, 44, 3.5, "Salvador");
	m = criarMeio(m, 3, "trotinete", 33, 33, 2.5, "Feira");
	m = criarMeio(m, 4, "bicicleta", 88, 88, 2.5, "Feira");

	//c = lerFicheiroCliente(c);

	alterarCliente(c, 5, 7, "Luis", 777777777, "Rua da siriguela", 35.00);

	c = removerCliente(c, 4);

	listarClientes(c);

	alterarMeioMob(m, 3, 9, "trotinete", 77, 77, 3.5, "Itacare");

	m = removerMeioMob(m, 1);

	ordenarMeioMob(m);

	listarMeiosMob(m);

	//a = criarAluguer(c, a, 1, 2, 3, 10.00);
	//a = criarAluguer(c, a, 2, 2, 3, 5.00);

	//listarAlugueres(a);

	return(0);
}
