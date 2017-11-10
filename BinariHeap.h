/**
*\file BinariHeap.h
*\brief 
*\author Gaëtan,Lucas
*\version 0.1
*\date 09 novembre 2017
*
*/

#ifndef BINARIHEAP_H
#define	BINARIHEAP_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "edge.h"

typedef struct BinariHeap{
	int size;
	int capacity;
	Edge ** edges;
}BinariHeap;

//Récupère le Fils gauche
int childLeft(int i);

//Récupère le Fils droit
int childRight(int i);

//Récupère le père
int father(int i);

//Récupère le min
Edge * getMin(BinariHeap * binariHeap);

BinariHeap * constructor_MinBinariHeap(int nbEdges);

void insertKey(BinariHeap * binariHeap,Edge * edge);

void decreaseKey(BinariHeap * binariHeap,int i, int new_val);

Edge* extractMin(BinariHeap * binariHeap);

void min_Heapfy(BinariHeap * binariHeap,int i);

#endif	/* BINARIHEAP_H */
