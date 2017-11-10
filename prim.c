/**
*\file prim.c
*\brief 
*\author Gaëtan,Lucas
*\version 0.1
*\date 14 octobre 2017
*/
#include "prim.h"

Graph * prim(Graph * graph){	
	Graph* result = constructor_graph();
	init_graph(result,graph->nb_nodes-1,graph->nb_nodes);
	BinariHeap * binariHeap=constructor_MinBinariHeap(graph->nb_edges);
	int num_node = 0;
	int num_edge = 0;

	Edge * edge;
	Node * node=graph->nodes[0];				//0=nombre random
	result->nodes[num_node]=constructor_recopyNode(node);
	num_node++;
	mark(node);
	for (int i = 0; i < node->degree; ++i){		//mettre toute les edge de node dans la liste / le tas
		edge=node->edges[i];
		if (!(edge->sourceNode->is_marked && edge->targetNode->is_marked)){
			insertKey(binariHeap,edge);
		}
	}
	edge=NULL;

	while (binariHeap->size){		//while list / tas non vide plustot
		edge=extractMin(binariHeap);
		if (edge==NULL){
			perror("pop");
		}
		else if( (edge->sourceNode->is_marked && !edge->targetNode->is_marked) || (!edge->sourceNode->is_marked && edge->targetNode->is_marked) ){
			result->edges[num_edge]=constructor_recopyEdge(edge);
			num_edge++;

			if(edge->sourceNode->is_marked){
				node=edge->targetNode;
			}
			else{
				node=edge->sourceNode;
			}

			result->nodes[num_node]=constructor_recopyNode(node);
			num_node++;
			mark(node);
			for (int i = 0; i < node->degree; ++i){		//mettre toute les edge de node dans la liste / le tas
				edge=node->edges[i];
				if (!(edge->sourceNode->is_marked && edge->targetNode->is_marked)){
					insertKey(binariHeap,edge);
				}
			}
		}
	}
	if (num_node > graph->nb_nodes || num_edge >= graph->nb_nodes){
		printf("j'ai un petit problème dans ma plantation num_edge = %d num_node = %d et il y a %d nodes\n",num_edge,num_node,graph->nb_nodes);
	}

	return result;
}
