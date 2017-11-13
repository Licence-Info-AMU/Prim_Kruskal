/**
*\file prim.c
*\brief 
*\author Gaëtan,Lucas
*\version 0.1
*\date 14 octobre 2017
*/
#include "prim.h"

Graph * prim(Graph * graph){	
	Graph* result = constructor_Graph();
	init_Graph(result,graph->nb_nodes-1,graph->nb_nodes);
	BinariHeap * binariHeap=constructor_MinBinariHeap(graph->nb_edges);
	int num_node = 0;
	int num_edge = 0;

	Edge * edge;
	Node * node=graph->nodes[0];				//0=nombre random
	show_node(node);
	result->nodes[num_node]=constructor_recopyNode(node);
	num_node++;
	mark(node);
	for (int i = 0; i < node->degree; ++i){		//mettre toute les edge de node dans la liste / le tas
		edge=node->edges[i];
		show_edge(edge);
		if (!(edge->sourceNode->is_marked && edge->targetNode->is_marked)){
			insertKey(binariHeap,edge);
		}
	}
	
	sortBinariHeap(binariHeap);
	
	//DEBUG
	printf("Début arbre\n");
	inorderTraversal(binariHeap,0);
	printf("Fin arbre\n");
	
	printf("Début arbre\n");
	preorderTraversal(binariHeap,0);
	printf("Fin arbre\n");
		
	printf("Début arbre\n");
	postorderTraversal(binariHeap,0);
	printf("Fin arbre\n");
		
	printf("Début\n");
	for (int i = 0; i < binariHeap->size; ++i){
		printf("%d\t:",i );
		show_edge(binariHeap->edges[i]);
	}
	//DEBUG
	
	edge=NULL;
	printf("\n");

	while (!isEmptyBinariHeap(binariHeap)){		//while list / tas non vide plustot
		edge=extractMin(binariHeap);
		show_edge(edge);
		if (edge==NULL){
			perror("pop");
		}
		else if( (edge->sourceNode->is_marked && !(edge->targetNode->is_marked)) || (!(edge->sourceNode->is_marked) && edge->targetNode->is_marked) ){
			result->edges[num_edge]=constructor_recopyEdge(edge);
			num_edge++;

			if(edge->sourceNode->is_marked){
				node=edge->targetNode;
			}
			else{
				node=edge->sourceNode;
			}
			printf("\n");
			show_node(node);
			result->nodes[num_node]=constructor_recopyNode(node);
			num_node++;
			mark(node);
			for (int i = 0; i < node->degree; ++i){		//mettre toute les edge de node dans la liste / le tas
				edge=node->edges[i];
				show_edge(edge);
				if (!(edge->sourceNode->is_marked && edge->targetNode->is_marked)){
					insertKey(binariHeap,edge);
				}
			}
			sortBinariHeap(binariHeap);
		}
	}
	if (num_node > graph->nb_nodes || num_edge >= graph->nb_nodes){
		printf("j'ai un petit problème dans ma plantation num_edge = %d num_node = %d et il y a %d nodes\n",num_edge,num_node,graph->nb_nodes);
	}

	return result;
}
