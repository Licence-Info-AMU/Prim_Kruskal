/**
*\file kruskal.c
*\brief 
*\author Gaëtan,Lucas
*\version 0.1
*\date 14 octobre 2017
*/
#include "kruskal.h"

Graph * kruskal(Graph * graph){			//selecteur
	return better_kruskal(graph);
	// return base_kruskal(graph);
}

void try_add_edge(Edge * edge, Graph* result, int * num_edge, int * root, int nb_nodes){
	int sourceNodeRoot=root[edge->sourceNode->id_node];
	int targetNodeRoot=root[edge->targetNode->id_node];

	if (sourceNodeRoot != targetNodeRoot){
		result->edges[*num_edge]=constructor_recopyEdge(edge);		// faire un fonciton add eges qui maintiens l'intégritée ?
		(*num_edge)++;

		for (int i = 0; i < nb_nodes; ++i){
			if (root[i]==targetNodeRoot){
				root[i]=sourceNodeRoot;
			}
		}
	}
}

Graph * base_kruskal(Graph * graph){
	Graph* result = constructor_graph();
	int root[graph->nb_nodes] ;
	for (int i = 0; i < graph->nb_nodes; ++i){
		root[i]=i;
	}
	init_graph(result,graph->nb_nodes-1,graph->nb_nodes);
	sort_edge_by_weight(graph);
	Edge * edge;
	int num_edge=0;

	for (int i = 0; i < graph->nb_edges; ++i){
		edge=graph->edges[i];
		try_add_edge(edge,result,&num_edge,root,graph->nb_nodes);
	}
	for (int i = 0; i < graph->nb_nodes; ++i){		//+copier les nodes sauf si fonction add edge qui le fera
		result->nodes[i]=constructor_recopyNode(graph->nodes[i]);
	}
	if (num_edge >= graph->nb_nodes){
		printf("j'ai un petit problème dans ma plantation num_edge = %d et il y a %d nodes\n",num_edge,graph->nb_nodes);
	}
	return result;
}

void better_try_add_edge(Edge * edge, Graph* result, int * num_edge, int * parent, int * treeDepth){
	int sourceNodeRoot=edge->sourceNode->id_node;
	int targetNodeRoot=edge->targetNode->id_node;

	while(parent[sourceNodeRoot]!=sourceNodeRoot){
		sourceNodeRoot=parent[sourceNodeRoot];
	}
	while(parent[targetNodeRoot]!=targetNodeRoot){
		targetNodeRoot=parent[targetNodeRoot];
	}
	if (sourceNodeRoot != targetNodeRoot){
		result->edges[*num_edge]=constructor_recopyEdge(edge);		// faire un fonciton add eges qui maintiens l'intégritée ?
		(*num_edge)++;
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

Graph * better_kruskal(Graph * graph){
	Graph* result = constructor_graph();
	int parent[graph->nb_nodes] ,treeDepth[graph->nb_nodes];
	for (int i = 0; i < graph->nb_nodes; ++i){
		parent[i]=i;
		treeDepth[i]=1;
	}
	init_graph(result,graph->nb_nodes-1,graph->nb_nodes);
	sort_edge_by_weight(graph);
	Edge * edge;
	int num_edge=0;

	for (int i = 0; i < graph->nb_edges; ++i){
		edge=graph->edges[i];
		better_try_add_edge(edge,result,&num_edge,parent,treeDepth);
	}
	for (int i = 0; i < graph->nb_nodes; ++i){		//+copier les nodes sauf si fonction add edge qui le fera
		result->nodes[i]=constructor_recopyNode(graph->nodes[i]);
	}
	if (num_edge >= graph->nb_nodes){
		printf("j'ai un petit problème dans ma plantation num_edge = %d et il y a %d nodes\n",num_edge,graph->nb_nodes);
	}
	return result;
}