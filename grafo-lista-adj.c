/******************************************************************************
GRAFOS - LISTA DE ADJANCENCIA 
Uma possível represetação de grafos
Desenvolvido com o objetivo de ensino
Paulo Martins
contato: paulo.martins@unesp.br ou pgsm5@hotmail.com 
*******************************************************************************/

//Este material é complementar, se quiser entender este algoritmo com imagens acesse: 

#include <stdio.h>
#include <stdlib.h>
#define true 1
#define fase 0
typedef int bool
typedef TIPOPESO;

typedef struct adjacencia {
    int vertice; // vertice de destino 
    TIPOPESO peso; // peso associado a aresta que leva ao vertice de destino
    strutc adjacencia *prox; // O próximo elemento da lista de adjacencias
}ADJACENCIA;

typedef struct vertice {
    /* Dados armazenados vão aqui */
    ADJACENCIA *cab; //possui apenas a cabeça da lista de adjacencia (linha 16)
}VERTICE;

typedef struct grafo { 
    int vertice; // numero de vertice total do grafo     /*Apesar de não ser nescessario guardar o numero de vertices  e arestas, o fazemos, pois caso quisermos*/
    int arestas; // numero de arestas totais do grafo  	/*saber desta informação, teriamos que percorrer toda a estrutura. Parece melhor perder 8bits de memória salvando isto ;)*/
    VERTICE *adj; // Arranjo de vertices da estrutura (linha 22)	
}GRAFO;

int main()
{
    return 0;
}
