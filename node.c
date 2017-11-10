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
		perror("malloc Edge");
		exit(EXIT_FAILURE); // Allocation impossible
    }
	node->id_node = -1;
	node->parent = NULL;
	node->next = node;
	node->prev = node;
	node->child = NULL;
	node->degree = 0;
	node->priority = -1;
	node->is_marked = 0;
	return node;
}

Node * constructor_NodeValue(int id){
	Node * node = constructor_Node();
	node->id_node = id;
	return node;
}

Node * constructor_recopyNode(Node * node){
	Node * newNode = NULL;
	memcpy(newNode,node,sizeof(Node));
	return newNode;
}

void mark(Node * node){
	node->is_marked = 1;
}

void unmark(Node * node){
	node->is_marked = 0;
}

void destructor_Node(Node * node){
	free(node);
	node = NULL;
}
