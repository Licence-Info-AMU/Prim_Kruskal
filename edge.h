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
	struct Node *sourceNode;
	struct Node *targetNode;
	double weight;
}Edge;

Edge * constructor_Edge();

Edge * constructor_EdgeValue(struct Node * sourceNode,struct Node * targetNode, double weight);

Edge * constructor_recopyEdge(Edge * edge);

void destructor_Edged(Edge * edge);

void show_edge(Edge * edge)

void swap(Edge *x, Edge *y);

#endif	/* EDGE_H */
