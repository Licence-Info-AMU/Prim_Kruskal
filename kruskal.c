/**
*\file kruskal.c
*\brief 
*\author Gaëtan,Lucas
*\version 0.1
*\date 14 octobre 2017
*/
#include "kruskal.h"

void try_add_edge(Edge * edge, Graph* result, int * num_edge, int * parent, int * treeDepth){

	int sourceNodeRoot=edge->sourceNode->id_node;				// a tester int * sourceNodeRoot=edge->sourceNode->id_node; ou int sourceNodeRoot=&edge->sourceNode->id_node; , on veux la valeur
	int targetNodeRoot=edge->targetNode->id_node;

	while(parent[sourceNodeRoot]!=sourceNodeRoot){
		sourceNodeRoot=parent[sourceNodeRoot];
	}
	while(parent[targetNodeRoot]!=targetNodeRoot){
		targetNodeRoot=parent[targetNodeRoot];
	}
	if (sourceNodeRoot != targetNodeRoot){
		result->edges[*num_edge]=constructor_recopy(edge);		// faire un fonciton add eges qui maintiens l'intégritée ?
		*num_edge++;
		if (treeDepth[sourceNodeRoot] >= treeDepth[targetNodeRoot]){
			parent[targetNodeRoot]=sourceNodeRoot;
		}
		else{
			int tmp=sourceNodeRoot;
			sourceNodeRoot=targetNodeRoot;
			targetNodeRoot=tmp;
			parent[targetNodeRoot]=sourceNodeRoot;
		}
		if(treeDepth[targetNodeRoot]+1 > treeDepth[sourceNodeRoot]){
			treeDepth[sourceNodeRoot]=treeDepth[targetNodeRoot]+1;
		}
	}
	
}

Graph * kruskal(Graph * graph){
	Graph* result = constructor_graph();
	int parent[graph->nb_nodes] ,treeDepth[graph->nb_nodes];
	for (int i = 0; i < graph->nb_nodes; ++i){
		parent[i]=i;
		treeDepth[i]=1;
	}
	init_graph(result,graph->nb_nodes-1,graph->nb_nodes);		//+copier les nodes sauf si fonction add edge qui le fera
	sort_edge_by_weight(graph);		//need this o(n*log(n))
	Edge * edge;
	int num_edge=0;

	for (int i = 0; i < graph->nb_edges; ++i){
		edge=graph->edges[i];
		try_add_edge(edge,result,&num_edge,parent,treeDepth);
	}
	if (num_edge >= graph->nb_nodes){
		printf("j'ai un petit problème dans ma plantation num_edge = %d et il y a %d nodes\n",num_edge,graph->nb_nodes);
	}

	return result;
}
