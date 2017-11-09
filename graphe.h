/**
*\file graphe.h
*\brief 
*\author Gaëtan,Lucas
*\version 0.1
*\date 14 octobre 2017
*
*/

#ifndef GRAPHE.H
#define	GRAPHE.H

#include <stdio.h>
#include <stdlib.h>
#include "edge.h"

typedef struct Graph{
	Edge * edges;
	int nb_edges;
	Node * nodes;
	int nb_node;
}Graph;

Graph * constructor_graph();

void init_graph(Graph* graph, int nb_edges, int nb_nodes);		//A faire

void sort_edge_by_weight(Graph * graph);			//A faire

//void sort_edge_by_node(Graph * graph);			//A faire peut etre

#endif	/* GRAPHE.H */
