/**
*\file graphe.c
*\brief 
*\author Gaëtan,Lucas
*\version 0.1
*\date 14 octobre 2017
*/

#include <math.h>
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

void init_GraphNodesRandom(Graph* graph){
	for(int i = 0;i < graph->nb_nodes;i++){
		int x = rand()%2000;
		int y = rand()%2000;
		graph->nodes[i] = constructor_NodeValue(i,x,y,graph->nb_nodes-1);
	}
}

void init_GraphEdgesRandom(Graph* graph){
	int num_edge=0;
	for(int i = 0;i < graph->nb_nodes;i++){
		for(int j = 0;j < i;j++){
			int dx = graph->nodes[j]->x - graph->nodes[i]->x;
			int dy = graph->nodes[j]->y - graph->nodes[i]->y;
			double weight = sqrt(dx*dx + dy*dy);
			graph->edges[num_edge] = constructor_EdgeValue(graph->nodes[i],graph->nodes[j],weight);
			graph->nodes[i]->edges[j] = constructor_recopyEdge(graph->edges[num_edge]);
			graph->nodes[j]->edges[i-1] = constructor_recopyEdge(graph->edges[num_edge]);
			num_edge++;
		}
	}
}

void generate_random_graph(Graph* graph, int minNodes, int maxNodes){
	int nbNodes = rand() % (maxNodes + 1 - minNodes) + minNodes;
	int nbEdges = (nbNodes * (nbNodes-1))/2;
	init_graph(graph,nbEdges,nbNodes);
	init_GraphNodesRandom(graph);
	init_GraphEdgesRandom(graph);
}

int edgeCmpFuncMin(const void * a, const void * b){
	Edge * edgeA = *(Edge**)a;
	Edge * edgeB = *(Edge**)b;
	return edgeA->weight - edgeB->weight;
}

void sort_edge_by_weight(Graph * graph){
	qsort(graph->edges,graph->nb_edges,sizeof(Edge*),edgeCmpFuncMin);
}

void show_graph(Graph * graph){
	printf("liste des %d nodes du graph :\n",graph->nb_nodes);
	for (int i = 0; i < graph->nb_nodes; ++i){
		printf("%d\t:",i );
		show_node(graph->nodes[i]);
	}
	printf("liste des %d edges du graph :\n",graph->nb_edges);
	for (int i = 0; i < graph->nb_edges; ++i){
		printf("%d\t:",i );
		show_edge(graph->edges[i]);
	}
}

void destructor_Graph(Graph * graph){
	free(graph->edges);
	graph->edges = NULL;
	free(graph->nodes);
	graph->nodes = NULL;
	free(graph);
	graph = NULL;
}
