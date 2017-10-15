/**
*\file node.c
*\brief 
*\author Gaëtan,Lucas
*\version 0.1
*\date 14 octobre 2017
*/
#include "node.h"

Node * constructor_NodeValue(int id){
	Node * node = NULL;
	node = malloc(sizeof(Node));
	if (node == NULL){
		exit(EXIT_FAILURE); // Allocation impossible
    }
	node->id_node = id;
	node->parent = null;
	node->next = node;
	node->prev = node;
	node->fils = null;
	node->degree = 0;
	node->priority = -1;
	node->marked; 
	return node;
}

Node * constructor_Node(){
	Node * node = malloc(sizeof(Node));
	if (node == NULL){
		exit(EXIT_FAILURE); // Allocation impossible
    }
	node->id_node = -1;
	node->parent = null;
	node->next = node;
	node->prev = node;
	node->fils = null;
	node->degree = 0;
	node->priority = -1;
	node->marked; 
	return node;
}

void destructor_Node(Node * node){
	free(node);
	node = NULL;
}
