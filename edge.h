/**
*\file edge.h
*\brief 
*\author Gaëtan,Lucas
*\version 0.1
*\date 14 octobre 2017
*
*/

#ifndef EDGE.H
#define	EDGE.H

#include <stdio.h>
#include <stdlib.h>

typedef struct Edge{
	Node *sourceNode;
	Node *targetNode;
	uint weight;
}Edge;

Edge * constructor_Edge();

Edge * constructor_EdgeValue(Node * sourceNode,Node * targetNode, uint weight);

Edge * constructor_recopy(Edge * edge);

void destructor_Edged(Edge * edge);

#endif	/* EDGE.H */
