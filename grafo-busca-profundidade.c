/******************************************************************************
GRAFOS BUSCAS DE PROFUNDIDADE - LISTA DE ADJANCENCIA

Desenvolvido com o objetivo de ensino
Paulo Martins
contato: paulo.martins@unesp.br ou pgsm5@hotmail.com 
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
typedef int bool;
typedef int TIPOPESO;

#define BRANCO 0 //vamos definir aqui as cores apenas para fim ditaticos
#define AMARELO 1
#define VERMELHO 2

//desta linha até a 36 ja foi feita e explicada o desenvolvimento nos anteriores
typedef struct adjacencia {
    int vertice; // vertice de destino 
    TIPOPESO peso; // peso associado a aresta que leva ao vertice de destino
    struct adjacencia *prox; // O próximo elemento da lista de adjacencias
}ADJACENCIA;

typedef struct vertice {
    /* Dados armazenados vão aqui */
    ADJACENCIA *cab; //possui apenas a cabeça da lista de adjacencia
}VERTICE;

typedef struct grafo { //lembrando que cada grafo possui:
    int vertices; // numero de vertice total do grafo
    int arestas; // numero de arestas totais do grafo
    VERTICE *adj; // Arranjo de vertices da estrutura
}GRAFO;

void profundida (GRAFO *g){
	int cor[g->vertices];//crio um vetor com arranjo de cores (o valor tem que bater com o do grafo)
	
	int u;
	for(u=0;u<g->vertices;u++){ //inicialmente todos vérties são brancos
		cor[u] = BRANCO;
	}
	for(u=0;u<g->vertices;u++){
		if (cor[u] == BRANCO) // se for branco visita todos em profundida
		visitaP(g,u,cor); // repare que é recursivo, visita até o final depois volta 	
	}	
}

void visitaP(GRAFO *g, int u, int *cor){
	cor[u] = AMARELO; //visitar um nó marca como amarelo
	ADJACENCIA *v = g->adj[u].cab; //visito adjacencia
	while (v){ //então visitamos sua adjacencia, aresta u e v recursivamente
		if(cor[v->vertice]==BRANCO) //se a cor for branco eu visito
		visitaP(g,v->vertice,cor); //veja que visito chamando a função de novo, ou seja recursivo
		v = v->prox;
	}
	cor[u] = VERMELHO;
}


int main () {
	return 0;
}
