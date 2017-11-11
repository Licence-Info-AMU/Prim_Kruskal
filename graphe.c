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

void add_edge(Graph* graph,Edge * edge,int pos){
	graph->edges[pos] = edge;
}

void add_node(Graph* graph,Node * node,int pos){
	graph->nodes[pos] = node;
}

void generate_random_graph(Graph* graph, int minNodes, int maxNodes){
	int nbNodes = rand() % (maxNodes + 1 - minNodes) + minNodes;
	int nbEdges = rand() % (maxNodes + 1 - nbNodes) + nbNodes;
}

int edgeCmpFuncMin(const void * a, const void * b){
	Edge * edgeA = (Edge*)a;
	Edge * edgeB = (Edge*)b;
	return (edgeA->weight < edgeB->weight);
}

void sort_edge_by_weight(Graph * graph){
	qsort(graph->edges,graph->nb_edges,sizeof(Edge*),edgeCmpFuncMin);
}

void destructor_Graph(Graph * graph){
	free(graph->edges);
	graph->edges = NULL;
	free(graph->nodes);
	graph->nodes = NULL;
	free(graph);
	graph = NULL;
}
