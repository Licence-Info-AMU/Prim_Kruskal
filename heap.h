/**
*\file heap.h
*\brief 
*\author Gaëtan,Lucas
*\version 0.1
*\date 15 octobre 2017
*
*/
#ifndef HEAP.H
#define	HEAP.H

typedef struct FibonacciHeap{
	Node * min; //pointeurs sur le min
	int numberOfNode;
	HashTable hashTable;
}FibonacciHeap;

#endif	/* HEAP.H */
