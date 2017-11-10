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
	Node * node=graph->nodes[0];	//0=nombre random

	result->nodes[num_node]=node;		//fonction recopie
	num_node++;
		//mark node
	//mettre toute les edge de node dans la liste / le tas
	for (num_node ; num_node < graph->nb_nodes; ++num_node){		//while list / tas non vide plustot
		Edge * edge=//prendre le plus petit POP
		if( (is_marked(edge->sourceNode) && !is_marked(edge->targetNode)) || (!is_marked(edge->sourceNode) && is_marked(edge->targetNode)) ){
			if(is_marked(edge->sourceNode))
				node=edge->targetNode;
			else
				node=edge->sourceNode;
			result->nodes[num_node]=node;		//fonction recopie
			num_node++;
			//mark node
			//mettre toute les edge de node dans la liste / le tas
		}
	}
	
	
	

	return result;
}
