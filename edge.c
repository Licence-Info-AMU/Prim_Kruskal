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
		perror("malloc");
		exit(EXIT_FAILURE); // Allocation impossible
    }
	edge->weight = 0;
	edge->sourceNode = NULL;
	edge->targetNode = NULL;
	return edge;
}

Edge * constructor_EdgeValue(Node * sourceNode,Node * targetNode, int weight){
	Edge * edge = NULL;
	edge = malloc(sizeof(Edge));
	if (edge == NULL){
		perror("malloc");
		exit(EXIT_FAILURE); // Allocation impossible
    }
	edge->weight = weight;
	edge->sourceNode = sourceNode;
	edge->targetNode = targetNode;
	return edge;
}

Edge * constructor_recopy(Edge * edge){
	Edge * newEdge = NULL;
	memcpy(newEdge,edge,sizeof(Edge));
	return newEdge;
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
