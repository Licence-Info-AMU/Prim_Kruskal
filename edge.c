/**
*\file edge.c
*\brief 
*\author Gaëtan,Lucas
*\version 0.1
*\date 14 octobre 2017
*/
#include "edge.h"

Edge * constructor_Edge(){
	Edge * edge = NULL;
	edge = malloc(sizeof(Edge));
	if (edge == NULL){
		perror("malloc Edge");
		exit(EXIT_FAILURE); // Allocation impossible
    }
	edge->weight = 0.0;
	edge->sourceNode = NULL;
	edge->targetNode = NULL;
	return edge;
}

Edge * constructor_EdgeValue(struct Node * sourceNode,struct Node * targetNode, double weight){
	Edge * edge = constructor_Edge();
	edge->weight = weight;
	edge->sourceNode = sourceNode;
	edge->targetNode = targetNode;
	return edge;
}

Edge * constructor_recopyEdge(Edge * edge){
	Edge * newEdge = constructor_Edge();
	memcpy(newEdge,edge,sizeof(Edge));
	return newEdge;
}

void show_edge(Edge * edge){
	printf("edge  %d\t%d\tweight: %lf \n",edge->sourceNode->id_node,edge->targetNode->id_node,edge->weight );
}

void destructor_Edged(Edge * edge){
	free(edge);
	edge=NULL;
}

//Edge swap
void swap(Edge *x, Edge *y){
    Edge temp = *x;
    *x = *y;
    *y = temp;
}
