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
#include "prim.h"

int main(int argc, char * argv[]){
	srand(time(NULL));
	Graph * graph = constructor_graph();
	int min=10;
	int max=20;
	generate_random_graph(graph,min,max);
	show_graph(graph);
	Graph * result=base_kruskal(graph);
	show_graph(result);
	result=better_kruskal(graph);
	show_graph(result);
	// Graph * resultPrim=prim(graph);
	// show_graph(resultPrim);
	destructor_Graph(graph);
	destructor_Graph(result);
	// destructor_Graph(resultPrim);
	return  0;
}
