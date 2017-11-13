/**
*\file kruskal.h
*\brief 
*\author Gaëtan,Lucas
*\version 0.1
*\date 14 octobre 2017
*
*/

#ifndef KRUSKAL_H
#define	KRUSKAL_H

#include <stdio.h>
#include <stdlib.h>
#include "graphe.h"

typedef struct Tab2d{
	int ** tab;
	int size_x;
	int size_y;
}Tab2d;

Graph * kruskal(Graph * graph);

void base_try_add_edge(Edge * edge, Graph* result, int * num_edge, int * root,int nb_nodes);

Graph * base_kruskal(Graph * graph);

void better_try_add_edge(Edge * edge, Graph* result, int * num_edge, int * parent, int * treeDepth);

Graph * better_kruskal(Graph * graph);


Tab2d * constructor_Tab2d(int size_x,int size_y);

void destructor_Tab2d(Tab2d * tab2d);

void show_ultram(Tab2d * ultram);

Tab2d * try_add_edge_ultrametrie(Edge * edge, Graph* result, int * num_edge, int * root,Tab2d * ultram, int nb_nodes);

Graph * kruskal_ultrametrie(Graph * graph,Tab2d * ultram);

#endif	/* KRUSKAL_H */
