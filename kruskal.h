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

Graph * kruskal(Graph * graph);

void base_try_add_edge(Edge * edge, Graph* result, int * num_edge, int * root,int nb_nodes);

Graph * base_kruskal(Graph * graph);

void better_try_add_edge(Edge * edge, Graph* result, int * num_edge, int * parent, int * treeDepth);

Graph * better_kruskal(Graph * graph);

#endif	/* KRUSKAL_H */
