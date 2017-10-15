/**
*\file node.h
*\brief 
*\author Gaëtan,Lucas
*\version 0.1
*\date 14 octobre 2017
*
*/
#ifndef NODE.H
#define	NODE.H

typedef struct Node{
	Node * parent; //parents si null racine
	Node * next; // élément suivant dans la liste
	Node * prev; // élément précédent dans la liste
	Node * child; // fils
	uint degree; //nombre d'arcs donc de fils
	int priority; 
	int marked; //Si le noeud est marquçe ou pas
	int id_node;
}Node;

Node * constructor_NodeValue(int id);

Node * constructor_Node();

void destructor_Node(Node * node);

#endif	/* NODE.H */
