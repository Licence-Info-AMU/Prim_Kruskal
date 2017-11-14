/**
*\file graphe.c
*\brief 
*\author Gaëtan,Lucas
*\version 0.1
*\date 14 octobre 2017
*/

#include <math.h>
#include "graphe.h"

Graph * constructor_Graph(){
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

void init_Graph(Graph* graph, int nb_edges, int nb_nodes){
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
		int x = rand()%800;
		int y = rand()%800;
		graph->nodes[i] = constructor_NodeValue(i,x,y,graph->nb_nodes-1);
	}
}

void init_GraphNodesRandom_rectangle(Graph* graph, int x1, int y1, int x2, int y2){
	if(x1>x2){
		int tmp=x2;
		x2=x1;
		x1=tmp;
	}
	if(y1>y2){
		int tmp=y2;
		y2=y1;
		y1=tmp;
	}
	for(int i = 0;i < graph->nb_nodes;i++){
		int x = rand()%(x1-x2) +x1;
		int y = rand()%(y1-y2) +y1;
		graph->nodes[i] = constructor_NodeValue(i,x,y,graph->nb_nodes-1);
	}
}

void init_GraphNodesRandom_anneau(Graph* graph, int x1, int y1, double longueur1, double longueur2){	//longueur1 = 0 si cercle
	if(longueur1>longueur2){
		double tmp=longueur2;
		longueur2=longueur1;
		longueur1=tmp;
	}
	for(int i = 0;i < graph->nb_nodes;i++){
		int x = rand()%(int)(2*longueur2) +x1-(int)longueur2;
		int y = rand()%(int)(2*longueur2) +y1-(int)longueur2;
		int dx= x1-x;
		int dy= y1-y;
		double distance = sqrt(dx*dx + dy*dy);
		if (distance>=longueur1 && distance<=longueur2){
			graph->nodes[i] = constructor_NodeValue(i,x,y,graph->nb_nodes-1);
		}
		else
			i--;
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

void generate_random_Graph_rectangle(Graph* graph, int minNodes, int maxNodes,int x1, int y1, int x2, int y2){
	int nbNodes = rand() % (maxNodes + 1 - minNodes) + minNodes;
	int nbEdges = (nbNodes * (nbNodes-1))/2;
	init_Graph(graph,nbEdges,nbNodes);
	init_GraphNodesRandom_rectangle(graph,x1, y1, x2, y2);
	init_GraphEdgesRandom(graph);
}

void generate_random_Graph_anneau(Graph* graph, int minNodes, int maxNodes,int x1, int y1, double longueur1, double longueur2){
	int nbNodes = rand() % (maxNodes + 1 - minNodes) + minNodes;
	int nbEdges = (nbNodes * (nbNodes-1))/2;
	init_Graph(graph,nbEdges,nbNodes);
	init_GraphNodesRandom_anneau(graph,x1, y1, longueur1, longueur2);
	init_GraphEdgesRandom(graph);
}

void generate_random_Graph(Graph* graph, int minNodes, int maxNodes){
	int nbNodes = rand() % (maxNodes + 1 - minNodes) + minNodes;
	int nbEdges = (nbNodes * (nbNodes-1))/2;
	init_Graph(graph,nbEdges,nbNodes);
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

void show_Graph(Graph * graph){
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
	for (int i = 0; i < graph->nb_edges; ++i){
		destructor_Edge(graph->edges[i]);
	}
	free(graph->edges);
	graph->edges = NULL;
	for (int i = 0; i < graph->nb_nodes; ++i){
		destructor_Node(graph->nodes[i]);
	}
	free(graph->nodes);
	graph->nodes = NULL;
	free(graph);
	graph = NULL;
}
