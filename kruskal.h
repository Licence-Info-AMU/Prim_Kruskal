/**
*\file kruskal.h
*\brief 
*\author Gaëtan,Lucas
*\version 0.1
*\date 14 octobre 2017
*
*/

#ifndef KRUSKAL.H
#define	KRUSKAL.H

#include <stdio.h>
#include <stdlib.h>
#include "graphe.h"

void try_add_edge(Edge * edge, Graph* result, int * num_edge, int * parent, int * treeDepth);

Graph kruskal(Graph * graph);

#endif	/* KRUSKAL.H */
