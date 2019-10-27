/******************************************************************************
CRIANDO GRAFOS

GRAFOS - LISTA DE ADJANCENCIA 

Desenvolvido com o objetivo de ensino
Paulo Martins
contato: paulo.martins@unesp.br ou pgsm5@hotmail.com 
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define true 1
#define fase 0
typedef int bool
typedef TIPOPESO;

typedef struct adjacencia {
    int vertice; // vertice de destino 
    TIPOPESO peso; // peso associado a aresta que leva ao vertice de destino
    strutc adjacencia *prox; // O pr�ximo elemento da lista de adjacencias
}ADJACENCIA;

typedef struct vertice {
    /* Dados armazenados v�o aqui */
    ADJACENCIA *cab; //possui apenas a cabe�a da lista de adjacencia
}VERTICE;

typedef struct grafo { //lembrando que cada grafo possui:
    int vertices; // numero de vertice total do grafo
    int arestas; // numero de arestas totais do grafo
    VERTICE *adj; // Arranjo de vertices da estrutura
}GRAFO;

/**fun��o para criar um GRAFO**/
GRAFO *criaGrafo (int v) {
	int i;
	
	GRAFO *g = (GRAFO *)malloc(sizeof(GRAFO)); //aloca espa�o para estrtura grafo
	g->vertices = v; //atualizo o numero de vertice
	g->arestas = 0;  //atualizo o numero de vertice
	g->adj = (VERTICE *)malloc(v*sizeof(VERTICE)); //ler abaixo
	//Dentro da estrturua tem s� o arranjo para o ponteiro de vertice, n�o o arranjo em si 	
	// ent�o aloco o arranjo com (v) o numero de vertice desejado
	for (i=0; i<v; i++){ 
		g->adj[i].cab=NULL; //coloco NULL em todas arestas
	}
	return(g);
}

/**fun��o para adicionar arestas no GRAFO**/

ADJACENCIA *criadAdj(int v, int peso){ 
	ADJACENCIA *temp = (ADJACENCIA *) malloc (sizeof(ADJACENCIA)); //aloca espa�o para um n�
	temp->vertice =v; //vertice alvo da adjacencia
	temp->peso = peso; //peso da aresta
	temp->prox = NULL; 
	return(temp); //retorno endere�o da adjacencia
}

bool criaAresta(GRAFO *gr, int vi, int vf, TIPOPESO p) { //vai de vi a vf
	if(!gr) return (false);  //valida��es se o grafo existe 
	if((vf<0)||(vf >= gr->vertices)return(false); //valida��es se os valores n�o s�o neg
	if((vi<0)||(vf >= gr->vertices)return(false); //ou maiores que o numero de v�rtice do grafo
	
	ADJACENCIA *novo = criaAdj(vf,p); //crio adjacencia com o v�rtice final e o peso
	//coloco a adjacencia na lista do v�rtice inicial
	novo->prox = gr->adj[vi].cab; //o campo prox da adjacencia vai receber a cabe�a da lista
	gr->adj[vi].cab=novo; // e a cabe�a da lista passa a ser o novo elemento
	gr->arestas++; // atualizo o numero de aresta no grafo
	return (true);
}


int main()
{
    return 0;
}
