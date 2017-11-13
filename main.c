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
	Graph * graph = constructor_Graph();
	int min=10;
	int max=20;
	generate_random_Graph(graph,min,max);
	show_Graph(graph);
	Graph * result=base_kruskal(graph);
	show_Graph(result);
	result=better_kruskal(graph);
	show_Graph(result);
	Tab2d * ultram=constructor_Tab2d(graph->nb_nodes,graph->nb_nodes);
	show_ultram(ultram);
	result=kruskal_ultrametrie(graph,ultram);
	show_Graph(result);
	show_ultram(ultram);
	
	
	// Graph * resultPrim=prim(graph);
	// show_Graph(resultPrim);
	destructor_Graph(graph);
	destructor_Graph(result);
	destructor_Tab2d(ultram);
	// destructor_Graph(resultPrim);
	return  0;
}
