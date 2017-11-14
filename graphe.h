/**
*\file graphe.h
*\brief 
*\author Gaëtan,Lucas
*\version 0.1
*\date 14 octobre 2017
*
*/

#ifndef GRAPHE_H
#define	GRAPHE_H

#include <stdio.h>
#include <stdlib.h>
#include "edge.h"
#include "node.h"

typedef struct Graph{
	Edge ** edges;
	int nb_edges;
	Node ** nodes;
	int nb_nodes;
}Graph;

Graph * constructor_Graph();

void init_Graph(Graph* graph, int nb_edges, int nb_nodes);

void add_edge(Graph* graph,Edge * edge,int pos);

void add_node(Graph* graph,Node * node,int pos);

void init_GraphNodesRandom(Graph* graph);

void init_GraphEdgesRandom(Graph* graph);

void generate_random_Graph(Graph* graph, int minNodes, int maxNodes);

int edgeCmpFuncMin(const void * a, const void * b);

void sort_edge_by_weight(Graph * graph);

void show_Graph(Graph * graph);

void destructor_Graph(Graph * graph);

//void sort_edge_by_node(Graph * graph);			//A faire peut etre

#endif	/* GRAPHE_H */
