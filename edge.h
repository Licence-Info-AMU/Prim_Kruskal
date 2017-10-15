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

typedef struct Edge{
	Node *sourceNode;
	Node *targetNode;
	uint weight;
}Edge;

Edge * constructor_Edge(Node * sourceNode,Node * targetNode, uint weight);

void destructor_Edged(Edge * edge);

#endif	/* EDGE.H */
