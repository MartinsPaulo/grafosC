/******************************************************************************
VISUAL GRAFOS

GRAFOS - LISTA DE ADJANCENCIA 

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

/**função para criar um GRAFO**/
GRAFO *criaGrafo (int v) {
	int i;
	
	GRAFO *g = (GRAFO *)malloc(sizeof(GRAFO)); //aloca espaço para estrtura grafo
	g->vertices = v; //atualizo o numero de vertice
	g->arestas = 0;  //atualizo o numero de vertice
	g->adj = (VERTICE *)malloc(v*sizeof(VERTICE)); //ler abaixo
	//Dentro da estrturua tem só o arranjo para o ponteiro de vertice, não o arranjo em si 	
	// então aloco o arranjo com (v) o numero de vertice desejado
	for (i=0; i<v; i++){ 
		g->adj[i].cab=NULL; //coloco NULL em todas arestas
	}
	return(g);
}

/**função para adicionar arestas no GRAFO**/

ADJACENCIA *criaAdj(int v, int peso){ 
	ADJACENCIA *temp = (ADJACENCIA *) malloc (sizeof(ADJACENCIA)); //aloca espaço para um nó
	temp->vertice =v; //vertice alvo da adjacencia
	temp->peso = peso; //peso da aresta
	temp->prox = NULL; 
	return(temp); //retorno endereço da adjacencia
}

bool criaAresta(GRAFO *gr, int vi, int vf, TIPOPESO p) { //vai de vi a vf
	if(!gr) return (false);  //validações se o grafo existe 
	if((vf<0)||(vf >= gr->vertices))return(false); //validações se os valores não são neg
	if((vi<0)||(vf >= gr->vertices))return(false); //ou maiores que o numero de vértice do grafo
	
	ADJACENCIA *novo = criaAdj(vf,p); //crio adjacencia com o vértice final e o peso
	//coloco a adjacencia na lista do vértice inicial
	novo->prox = gr->adj[vi].cab; //o campo prox da adjacencia vai receber a cabeça da lista
	gr->adj[vi].cab=novo; // e a cabeça da lista passa a ser o novo elemento
	gr->arestas++; // atualizo o numero de aresta no grafo
	return (true);
}

void imprime(GRAFO *gr){
	//validações se o grafo existe 
	
	printf("Vertices: %d. Arestas: %d. \n",gr->vertices,gr->arestas); //imprime numero de vértice e arestas
	int i;
	
	for(i=0; i<gr->vertices; i++){
		printf("v%d: ",i); //Imprimo em qual aresta estou
		ADJACENCIA *ad = gr->adj[i].cab; //chamo a cabeça da lista de adjacencia desta aresta
			while(ad){ //enquanto as adjacencias não forem nula
				printf("v%d(%d) ",ad->vertice,ad->peso); //imprimo a adjacencia e seu peso
				ad=ad->prox; //passo para proxima adjacencia
			}
		printf("\n");	
	}
}

int main()
{
	
	GRAFO * gr = criaGrafo(5);
	criaAresta(gr, 0, 1, 2);
	criaAresta(gr, 1, 2, 4);
	criaAresta(gr, 2, 0, 12);
	criaAresta(gr, 2, 4, 40);
	criaAresta(gr, 3, 1, 3);
	criaAresta(gr, 4, 3, 8);
    
    imprime(gr);
}
