/******************************************************************************
GRAFOS - LISTA DE ADJANCENCIA 
Uma poss�vel represeta��o de grafos
Desenvolvido com o objetivo de ensino
Paulo Martins
contato: paulo.martins@unesp.br ou pgsm5@hotmail.com 
*******************************************************************************/

//Este material � complementar, se quiser entender este algoritmo com imagens acesse: 

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
    ADJACENCIA *cab; //possui apenas a cabe�a da lista de adjacencia (linha 16)
}VERTICE;

typedef struct grafo { 
    int vertice; // numero de vertice total do grafo     /*Apesar de n�o ser nescessario guardar o numero de vertices  e arestas, o fazemos, pois caso quisermos*/
    int arestas; // numero de arestas totais do grafo  	/*saber desta informa��o, teriamos que percorrer toda a estrutura. Parece melhor perder 8bits de mem�ria salvando isto ;)*/
    VERTICE *adj; // Arranjo de vertices da estrutura (linha 22)	
}GRAFO;

int main()
{
    return 0;
}
