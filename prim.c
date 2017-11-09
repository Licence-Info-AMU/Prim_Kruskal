/**
*\file prim.c
*\brief 
*\author Gaëtan,Lucas
*\version 0.1
*\date 14 octobre 2017
*/
#include "prim.h"

void PrimFHeap(){
		FibonacciHeap * fibonacciHeap = constructor_Heap();
		Node * node = constructor_Node();
}


Graph prim(Graph * graph){	
	Graph* result = new_graph();
	init_graph(result,graph->nb_nodes-1,graph->nb_nodes);

	int num_node;
	result->nodes[num_node]=graph->nodes[0];		//0=nombre random
	for (num_node = 0; num_node < nb_nodes; ++num_node){
		//faire list de  priorité
		//prendre le plus petit
	}
	
	
	

	return result;
}