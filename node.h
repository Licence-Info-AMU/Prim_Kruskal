/**
*\file node.h
*\brief 
*\author Gaëtan,Lucas
*\version 0.1
*\date 14 octobre 2017
*
*/
#include "edge.h"
#ifndef NODE.H
#define	NODE.H

typedef struct Node{
	Edge * edges; //arcs = fils et poids pour y aller
	Node * parent; //parents
	uint degree; //nombre d'arcs
	uint totalWeight; //poids total depuis la racine
}Node;

#endif	/* NODE.H */
