/**
*\file node.c
*\brief 
*\author Gaëtan,Lucas
*\version 0.1
*\date 14 octobre 2017
*/
#include "node.h"

Node * constructor_Node(){
	Node * node = malloc(sizeof(Node));
	if (node == NULL){
		perror("malloc Node");
		exit(EXIT_FAILURE); // Allocation impossible
    }
	node->edges = NULL;
    node->x = 0;
    node->y = 0;                //position
    node->degree = 0; //nombre d'arcs donc de fils
    node->is_marked = 0; //Si le noeud est marquee ou pas
    node->id_node=-1;
	return node;
}

Node * constructor_NodeValue(int id,int x,int y,int nbEdges){
	Node * node = constructor_Node();
	node->edges = malloc(sizeof(Edge*)*nbEdges);
	if (node->edges == NULL){
		perror("malloc NodeValue");
		exit(EXIT_FAILURE); // Allocation impossible
    }
    node->degree = nbEdges;
	node->x = x;
	node->y = y;
	node->id_node = id;
	return node;
}

Node * constructor_recopyNode(Node * node){
	Node * newNode = constructor_Node();
	memcpy(newNode,node,sizeof(Node));
	return newNode;
}

void mark(Node * node){
	node->is_marked = 1;
}

void unmark(Node * node){
	node->is_marked = 0;
}

void show_node(Node * node){
	printf("node %d x:%d\ty:%d\tdegree:%d \n",node->id_node,node->x,node->y,node->degree);
}

void destructor_Node(Node * node){
	free(node);
	node = NULL;
}
