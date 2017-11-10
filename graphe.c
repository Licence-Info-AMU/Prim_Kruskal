/**
*\file graphe.c
*\brief 
*\author Gaëtan,Lucas
*\version 0.1
*\date 14 octobre 2017
*/
#include "graphe.h"

Graph * constructor_graph(){
	Graph * graph = NULL;
	graph = malloc(sizeof(Graph));
	if (graph == NULL){
		perror("malloc Graph");
		exit(EXIT_FAILURE); // Allocation impossible
    }
    graph->edges = NULL;
	graph->nb_edges = 0;
	graph->nodes = NULL;
	graph->nb_nodes = 0;
    return graph;
}

void init_graph(Graph* graph, int nb_edges, int nb_nodes){
	graph->edges = malloc(sizeof(Edge*)*nb_edges);
	if (graph->edges == NULL){
		perror("malloc Graph");
		exit(EXIT_FAILURE); // Allocation impossible
    }
	graph->nb_edges = nb_edges ;
	graph->nodes = malloc(sizeof(Node*)*nb_nodes);
	if (graph->nodes == NULL){
		perror("malloc Graph:Nodes");
		exit(EXIT_FAILURE); // Allocation impossible
    }
	graph->nb_nodes = nb_nodes;
}

int edgeCmpFuncMin(const void * a, const void * b){
	Edge * edgeA = (Edge*)a;
	Edge * edgeB = (Edge*)b;
	return (edgeA->weight < edgeB->weight);
}

void sort_edge_by_weight(Graph * graph){
	qsort(graph->edges,graph->nb_edges,sizeof(Edge*),edgeCmpFuncMin);
}
