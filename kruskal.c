/**
*\file kruskal.c
*\brief 
*\author Gaëtan,Lucas
*\version 0.1
*\date 14 octobre 2017
*/
#include "kruskal.h"

Graph kruskal(Graph * graph){
	Graph* result = new_graph();
	init_graph(result,graph->nb_nodes-1,graph->nb_nodes);
	sort_by_weight(graph);
	Edge * edge=graph->edges[0];
	result->edges[0]=constructor_EdgeValue(edge->sourceNode,edge->targetNode,edge->weight);		//faire copie
	edge=graph->edges[1];
	result->edges[1]=constructor_EdgeValue(edge->sourceNode,edge->targetNode,edge->weight);		//faire copie
	int num_edge=2;
	for (int i = 2; i < edges->nb_edges; ++i){
		edge=graph->edges[i];
		if
		result->edges[num_edge]=constructor_EdgeValue(edge->sourceNode,edge->targetNode,edge->weight);		//faire copie
		num_edge++
	}


	return result;
}