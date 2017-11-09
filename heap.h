/**
*\file heap.h
*\brief 
*\author Gaëtan,Lucas
*\version 0.1
*\date 15 octobre 2017
*
*/
#ifndef HEAP_H
#define	HEAP_H

#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "hashTable.h"

typedef struct FibonacciHeap{
	Node * min; //pointeurs sur le min
	int numberOfNode;
	HashTable hashTable;
}FibonacciHeap;

FibonacciHeap * constructor_Heap();

void insertNode(FibonacciHeap * fibonacciHeap,Node * node, int priority);

Node * find_min(FibonacciHeap * fibonacciHeap);

Node * delete_min(FibonacciHeap * fibonacciHeap);

void decreaseKey(Node node, int priority);

int delete(FibonacciHeap * fibonacciHeap,Node node);

FibonacciHeap * union_heap(FibonacciHeap * fibonacciHeapx,FibonacciHeap * fibonacciHeapy);

int isEmpty(FibonacciHeap * fibonacciHeap);

void destructor_FibonacciHeap(FibonacciHeap * fibonacciHeap);

#endif	/* HEAP_H */
