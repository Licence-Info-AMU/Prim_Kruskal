/**
*\file node.h
*\brief 
*\author Gaëtan,Lucas
*\version 0.1
*\date 14 octobre 2017
*
*/
#ifndef NODE_H
#define	NODE_H
#include <stdio.h>
#include <stdlib.h>
#include "edge.h"

typedef struct Node{
	struct Node * parent;	//parents si null racine
	struct Node * next;		// élément suivant dans la liste
	struct Node * prev;		// élément précédent dans la liste
	struct Node * child;	// fils
	Edge ** edges;
	int x, y;				//position
	int degree; //nombre d'arcs donc de fils
	int priority; 
	int marked; //Si le noeud est marquçe ou pas
	int id_node;
}Node;

//fonction pour reset les marked 

//fonction is marked

Node * constructor_NodeValue(int id);

Node * constructor_Node();

void destructor_Node(Node * node);

#endif	/* NODE_H */
