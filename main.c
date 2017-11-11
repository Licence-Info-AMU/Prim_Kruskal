/**5;
*\file main.c
*\brief 
*\author Gaëtan,Lucas
*\version 0.1
*\date 14 octobre 2017
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "kruskal.h"

int main(int argc, char * argv[]){
	srand(time(NULL));
	Graph * graph = constructor_graph();
	int min=5;
	int max=15;
	generate_random_graph(graph,min,max);
	show_graph(graph);
	Graph * result=kruskal(graph);
	show_graph(graph);
	printf("%d %d\n",result->nb_nodes,result->nb_edges );
	show_graph(result);
	destructor_Graph(graph);
	return  0;
}
