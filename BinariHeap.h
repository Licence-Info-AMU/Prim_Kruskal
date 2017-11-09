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

typedef struct BinariHeap{
	int size;
}BinariHeap;

//Récupère le Fils gauche
int childLeft(int i);

//Récupère le Fils droit
int childRight(int i);

//Récupère le père
int father(int i);

void max_Heapfy(BinariHeap * binariHeap, int i);

BinariHeap * constructor_BinariHeap(Graph * graph);
#endif	/* BINARIHEAP_H */
