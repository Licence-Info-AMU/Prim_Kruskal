/**
*\file prim.c
*\brief 
*\author Gaëtan,Lucas
*\version 0.1
*\date 14 octobre 2017
*/
#include <stdio.h>
#include <stdlib.h>
#include "graphe.h"
#include "prim.h"

Graph * prim(Graph * graph){	
	Graph* result = constructor_graph();
	init_graph(result,graph->nb_nodes-1,graph->nb_nodes);

	int num_node = 0;
	result->nodes[num_node]=graph->nodes[0];		//0=nombre random
	for (num_node = 0; num_node < graph->nb_nodes; ++num_node){
		//faire list de  priorité
		//prendre le plus petit
	}
	
	
	

	return result;
}
