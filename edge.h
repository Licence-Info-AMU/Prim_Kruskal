/**
*\file edge.h
*\brief 
*\author Gaëtan,Lucas
*\version 0.1
*\date 14 octobre 2017
*
*/

#ifndef EDGE_H
#define	EDGE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

typedef struct Edge{
	Node *sourceNode;
	Node *targetNode;
	int weight;
}Edge;

Edge * constructor_Edge();

Edge * constructor_EdgeValue(Node * sourceNode,Node * targetNode, int weight);

Edge * constructor_recopy(Edge * edge);

void destructor_Edged(Edge * edge);

#endif	/* EDGE_H */
