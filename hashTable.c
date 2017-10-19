/**
*\file hashTable.c
*\brief 
*\author Gaëtan,Lucas
*\version 0.1
*\date 15 octobre 2017
*/
#include "hashTable.h"


HashTable * constructor_HashTable(int hashTableSize){
	HashTable * hashTable = NULL;
	hashTable = malloc(sizeof(HashTable)*hashTableSize);
	if (hashTable == NULL){
		exit(EXIT_FAILURE); // Allocation impossible
    }
    return hashTable;
}

void insertNodeInHashTable(FibonacciHeap * fibonacciHeap,int id_node,Node * node){
	fibonacciHeap->hashTable[fibonacciHeap->numberOfNode+1].id_node = id_node;
	fibonacciHeap->hashTable[fibonacciHeap->numberOfNode+1].node = node;
}
