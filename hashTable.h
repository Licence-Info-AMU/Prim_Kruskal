/**
*\file hashTable.h
*\brief 
*\author Gaëtan,Lucas
*\version 0.1
*\date 15 octobre 2017
*
*/

#ifndef HASHTABLE.H
#define	HASHTABLE.H
#include <stdio.h>
#include <stdlib.h>
#include "node.h"

typedef struct HashTableElmt{
	int id_node;
	Node * node;
}HashTableElmt;

typedef HashTableElmt * HashTable;

HashTable * constructor_HashTable(int hashTableSize);

void insertNodeInHashTable(FibonacciHeap * fibonacciHeap,int id_node,Node * node);

#endif	/* HASHTABLE.H */
