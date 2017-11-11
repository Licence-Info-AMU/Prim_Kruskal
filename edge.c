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
	Edge * newEdge = NULL;
	memcpy(newEdge,edge,sizeof(Edge));
	return newEdge;
}

void show_edge(Edge * edge){
	printf("weight:");
	printf("%lf \n",edge->weight);
	printf("edge between ");
	printf("%d ",edge->sourceNode->id_node );
	printf("%d ",edge->targetNode->id_node );
	printf("\n");
	
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
