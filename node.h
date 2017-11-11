/**
*\file node.h
*\brief 
*\author Gaëtan,Lucas
*\version 0.1
*\date 14 octobre 2017
*
*/

#ifndef NODE_H
#define	NODE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "edge.h"

typedef struct Node{
    struct Edge ** edges;
    int x, y;                //position
    int degree; //nombre d'arcs donc de fils
    int is_marked; //Si le noeud est marquee ou pas
    int id_node;
}Node;

Node * constructor_Node();

Node * constructor_NodeValue(int id,int x,int y);

Node * constructor_recopyNode(Node * node);

void mark(Node * node);

void unmark(Node * node);

void destructor_Node(Node * node);

#endif	/* NODE_H */
