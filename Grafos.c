/*****************************************************************//**
 * \file   Grafos.c
 * \brief  Fun��es que implementam os grafos e adjacencias
 * 
 * \author julia
 * \date   May 2023
 *********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Grafos.h"
#include "FunctionsClientes.h"
#include "FunctionsMeios.h"

/** Fun��o para criar grafo pesado vazio e n�o orientado */
Vertice* criarGrafo() {
	return NULL;
}

#pragma region VERTICE_GRAFO

/** Fun��o para criar um v�rtica para o grafo */
Vertice* criarVertice(char* cidade, int id) {
	Vertice* novoVertice = (Vertice*)calloc(1, sizeof(Vertice)); //fun��o calloc recebe o par�metro da quantidade de elementos a serem salvos
	if (novoVertice == NULL) return NULL;
	novoVertice->id = id;
	strcpy(novoVertice->localizacao, cidade);
	novoVertice->proximo = NULL;
	novoVertice->adj = NULL;	
	return novoVertice;
}

/** Fun��o que insere um v�rtice no grafo j� criado */
Vertice* inserirVertice(Vertice* v, char* localizacao, int id, bool* vis) {
	
	Vertice* novoVertice = criarVertice(localizacao, id);
	
	if (novoVertice == NULL) {
		*vis = false;
		return v;
	}

	if (v == NULL) {
		v = novoVertice;
		*vis = true;
		return novoVertice;
	}

	else
	{
		Vertice* aux = v;
		Vertice* ant = aux;
		while (aux && strcmp(aux->localizacao, novoVertice->localizacao) < 0) {
			ant = aux;
			aux = aux->proximo;
		}
		if (aux == v) {
			novoVertice->proximo = v;
			v = novoVertice;
		}
		else
		{
			novoVertice->proximo = aux;
			ant->proximo = novoVertice;
		}
		*vis = true;
	}
	return v;
}

/** Fun��o que destr�i o grafo da mem�ria */
Vertice* destruirGrafo(Vertice* v) {
	if (v == NULL) return NULL;
	Vertice* aux = NULL;
	while (v) {
		if (v->proximo)
			aux = v->proximo;
		v->adj = destruirAdjacencia(v->adj);
		free(v);
		v = aux;
		aux = NULL;
	}
	return v;
}

/** Fun��o para imprimir o grafo na tela */
void mostrarGrafo(Vertice* v) {
		if (v == NULL) return;
		printf("\nV: %d - %s", v->id, v->localizacao);
		mostrarAdj(v->adj);
		mostrarGrafo(v->proximo);
	
}

/** Fun��o para buscar um vertice atrav�s da sua localizacao */
Vertice* buscarVertice(Vertice* v, char* cidade) {

	if (v == NULL) return NULL;
	if (strcmp(v->localizacao, cidade) == 0) return v;

	return(buscarVertice(v->proximo, cidade));
}

/** Fun��o para buscar um vertice pelo seu id */
Vertice* buscarVerticeId(Vertice* v, int id) {

	if (v == NULL) return NULL;
	if (v->id == id) return v;
	return(buscarVerticeId(v->proximo, id));
}

/** Fun��o que insere um meio da lista ligada em um determinado v�rtice */
int inserirMeioVertice(Vertice* v, MeioMob meio) {
	if (v == NULL) return 0;

	ListaMeioPtr novo = (ListaMeioPtr)malloc(sizeof(ListaMeio));
	if (novo == NULL) return 0;

	novo->meio = meio;
	novo->proximo = v->meio;
	v->meio = novo;

	return 1;
}

/** Fun��o que insere um cliente da lista em um determinado vertice */
int inserirClienteVertice(Vertice* v, Cliente cliente) {
	if (v == NULL) return 0;

	ListaClientePtr novo = (ListaClientePtr)malloc(sizeof(ListaCliente));
	if (novo == NULL) return 0;

	novo->cliente = cliente;
	novo->proximo = v->cliente;
	v->cliente = novo;

	return 1;
}

/** Fun��o para guardar as informa��es de cada vertice em um ficheiro de texto */
bool guardarVerticesFicheiro(Vertice* v, char nomeFicheiro[]) {

	FILE* fp;
	fp = fopen(nomeFicheiro, "w");

	if (v == NULL || fp == NULL) {
		return false;
	}

	Vertice* atualVertice = v;

	while (atualVertice != NULL) {

		fprintf(fp, "- - - - - - - - ");
		fprintf(fp, "\nVertice: %5d \t| Cidade: %11s \t|\n", atualVertice->id, atualVertice->localizacao);

		ListaMeioPtr atualMeio = atualVertice->meio;
		while (atualMeio != NULL) {
			fprintf(fp, "Meio: Id: %5d \t| Tipo: %11s \t| Autonomia: %7.2f \t| Custo: %7.2f \t|\n", atualMeio->meio.id, atualMeio->meio.tipo, atualMeio->meio.autonomia, atualMeio->meio.custo);
			atualMeio = atualMeio->proximo;
		}

		ListaClientePtr atualCliente = atualVertice->cliente;
		while (atualCliente != NULL) {
			fprintf(fp, "Cliente Id: %5d \t| Nome: %11s \t| NIF: %5d \t| Saldo: %7.2f \t| Endere�o: %30s \t|\n", atualCliente->cliente.id, atualCliente->cliente.nome, atualCliente->cliente.nif, atualCliente->cliente.saldo, atualCliente->cliente.morada);
			atualCliente = atualCliente->proximo;
		}

		atualVertice = atualVertice->proximo;
	}
	return true;
}

bool lerGrafoFicheiro(Vertice* v, char* nomeFicheiro[]) {

	FILE* fp;
	fp = fopen(nomeFicheiro, "r");

	if (fp == NULL)
	{
		return NULL;
	}

	Vertice* vertice = NULL;
	Vertice aux;

	bool vis;
	
	char linha[100];
	while (fgets(linha, sizeof(linha), fp) != NULL) {
		if (sscanf(linha, "%d;%[^;]", &aux.id, aux.localizacao) == 2) {
			vertice = inserirVertice(vertice, aux.localizacao, aux.id, &vis);
		}
	}

	fclose(fp);

	return v;
}





#pragma endregion

#pragma region ADJ_GRAFO

/** Fun��o para criar uma nova adjacencia a partir do id e distancia informados */
Adj* criarAdj(int id, float distancia) {
	Adj* novaAdj = (Adj*)calloc(1, sizeof(Adj));
	if (novaAdj == NULL) return NULL;
	novaAdj->id = id;
	novaAdj->distancia = distancia;
	novaAdj->proximo= NULL;
	return novaAdj;
}


/** Fun��o para mostrar as adjacencias do grafo */
void mostrarAdj(Adj* adj) {
	if (adj == NULL) return;
	printf("\n\tAdjac�ncia com: %d | Dist�ncia %.0f km\n", adj->id, adj->distancia);
	mostrarAdj(adj->proximo);
}

/** Fun��o recursiva para destruir as adjacencias do grafo */
Adj* destruirAdjacencia(Adj* adj) {
	if (adj == NULL) return NULL;
	Adj* aux = NULL;
	while (adj) {
		if (adj->proximo!= NULL)
			aux = adj->proximo;
		free(adj);
		adj = aux;
		aux = NULL;
	}
	return adj;
}

/** Fun��o para verificar se a adjacencia j� existe no grafo, atrav�s do seu id */
bool existeAdj(Adj* adj, int id) {
	if (adj == NULL) return false;
	if (adj->id == id) return true;
	return existeAdj(adj->proximo, id);
}

/** Fun��o que insere uma adjacencia no grafo */
Adj* inserirAdj(Adj* adj, Adj* novaAdj, bool* vis) {

	*vis = false;	

	if (novaAdj == NULL)	
		return adj;

	if (existeAdj(adj, novaAdj->id) == true) return adj; 

	
	*vis = true;
	if (adj == NULL) {	
		adj = novaAdj;
		return adj;
	}
	
	novaAdj->proximo = adj;
	adj = novaAdj;

	return adj;
}

/** Fun��o que insere a adjacencia em um v�rtice do grafo */
Vertice* inserirAdjVerticeId(Vertice* v, int idInicio, int idFim, float distancia, bool* vis) {

	*vis = false;				

	if (v == NULL) return v;	

	Vertice* inicio = buscarVerticeId(v, idInicio);   
	Vertice* fim = buscarVerticeId(v, idFim);	
	if (inicio == NULL || fim == NULL) return v;		

	if (existeAdj(inicio->adj, idFim) == true) 
		return v; 

	 
	Adj* novaAdj = criarAdj(idFim, distancia);
	inicio->adj= inserirAdj(inicio->adj, novaAdj, vis); 
	return v;



}

#pragma endregion

#pragma region CAMINHO

/** Fun��o recursiva para calcular caminhos entre dois v�rtices pelo Id */
int calcularCaminho(Vertice* v, int idorigem, int iddestino, int contaCaminho) {
	if (v == NULL) return 0;

	if (idorigem == iddestino) return (++contaCaminho);

	Vertice* aux = buscarVerticeId(v, idorigem);
	if (aux == NULL) return 0;

	Adj* adj = aux->adj;
	while (adj) {
		Vertice* ver = buscarVerticeId(v, adj->id);
		if (v != NULL) {
			contaCaminho = calcularCaminho(v, ver->id, iddestino, contaCaminho);
		}
		adj = adj->proximo;
	}

	return contaCaminho;
}

/** Fun��o recursiva para calcular caminho entre dois v�rtices pelo nome */
int calcularCaminhoNomeVertice(Vertice* v, char* origem, char* destino, int contaCaminho) {
	int o = buscarVerticeId(v, origem);
	int d = buscarVerticeId(v, destino);
	return calcularCaminho(v, o, d, 0); 
}

/** Fun��o que visita vertices e adjacencias para verificar se existe caminnho entre dois vertices */
bool existeCaminho(Vertice* v, int origem, int destino) {
	if (origem == destino) return true;
	Vertice* aux = buscarVerticeId(v, origem);
	aux->visitado = true;

	Adj* adj = aux->adj;
	while (adj) {
		Vertice* ver = buscarVerticeId(v, adj->id);
		if (ver->visitado == false) {
			bool existe = existeCaminho(v, adj->id, destino);
			return existe;
		}
		else {
			aux = aux->proximo;
		}
	}
	return true;
}

/** Fun��o que visita vertices e adjacencias para verificar se existe caminnho entre dois vertices atrav�s dos seus nomes */
int existeCaminhoNome(Vertice* v, char* origem, char* destino) {
	int o = buscarVerticeId(v, origem);
	int d = buscarVerticeId(v, destino);
	return existeCaminho(v, o, d);
}

/** Fun��o que retira a condi��o de visitado dos vertices de true para false */
Vertice* zerarVerticeVisitado(Vertice* v) {
	Vertice* aux = v;
	while (aux) {
		aux->visitado = false;
		aux = aux->proximo;
	}
	return v;
}

/** Fun��o que lista meios de determinado tipo em um raio de distancia do cliente */
int listarMeiosPorTipoERaio(Vertice* v, char* localizacaoCliente, char* tipoMeio, float raio) {
	
	Vertice* cliente = buscarVertice(v, localizacaoCliente);

	if (cliente == NULL) {
		return -1;
	}
	
	printf("\nMeios de mobilidade do tipo %s encontrados dentro de um raio de %.2f km:\n", tipoMeio, raio);

	// Percorrer os v�rtices adjacentes ao cliente
	Adj* adjAtual = cliente->adj;

	while (adjAtual != NULL) {
		Vertice* adj = buscarVerticeId(v, adjAtual->id); 

		ListaMeioPtr meioAtual = adj->meio;

		while (meioAtual != NULL) {
			if (strcmp(meioAtual->meio.tipo, tipoMeio) == 0) {
				float distancia = calcularCaminho(v, cliente->id, adj->id, 0);
				if (distancia <= raio) {
					printf("ID: %d, Autonomia: %.2f km, Custo: %.2f\n", meioAtual->meio.id, meioAtual->meio.autonomia, meioAtual->meio.custo);
				}
			}
			meioAtual = meioAtual->proximo;
		}

		adjAtual = adjAtual->proximo;
	}
	return v;
}

/** Fun��o que guarda vertices e ajacencias em um arquivo bin�rio */
int guardarGrafoBinario(Vertice* v, char* nomeFicheiro) {
	if (v == NULL) return -1;
	FILE* fp;
	fp = fopen(nomeFicheiro, "wb");
	if (fp == NULL) return -2;

	int save;

	Vertice* aux = v;
	Vertice auxFicheiro;
	while (aux != NULL) {
		auxFicheiro.id = aux->id;
		strcpy(auxFicheiro.localizacao, aux->localizacao);
		fwrite(&auxFicheiro, 1, sizeof(Vertice), fp);

		if (aux->adj) {
			save = guardarAdjacencia(aux->adj, aux->localizacao, aux->id);
		}
		aux = aux->proximo;
	}
	fclose(fp);
	return 1;
}


int guardarAdjacencia(Adj* adj, char* nomeFicheiro, int codVerticeOrigem) {
	FILE* fp;

	if (adj == NULL) return -2;
	fp = fopen(nomeFicheiro, "ab");
	if (fp == NULL) return -1;
	Adj* aux = adj;
	Adj auxFicheiro;
	while (aux) {
		auxFicheiro.id = aux->id;
		auxFicheiro.id = codVerticeOrigem;
		auxFicheiro.distancia = aux->distancia;
		fwrite(&auxFicheiro, 1, sizeof(Adj), fp);
		aux = aux->proximo;
	}
	fclose(fp);
	return 1;
}



#pragma endregion








