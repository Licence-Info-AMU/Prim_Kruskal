/**
*\file graphe.h
*\brief 
*\author Gaëtan,Lucas
*\version 0.1
*\date 14 octobre 2017
*
*/
#include "node.h"

#ifndef GRAPHE.H
#define	GRAPHE.H

typedef struct FibonacciHeap{
	Node * min; //pointeurs sur le min
	Node ** fibonacciNodes; //tableau de pointeurs sur les noeuds
}FibonacciHeap;

#endif	/* GRAPHE.H */
