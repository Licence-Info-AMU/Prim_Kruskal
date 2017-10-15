/**
*\file heap.c
*\brief 
*\author Gaëtan,Lucas
*\version 0.1
*\date 15 octobre 2017 
*/
#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "hashTable.h"
#include "heap.h"

FibonacciHeap * constructor_Heap(){
	FibonacciHeap * fibonacciHeap = NULL;
	fibonacciHeap = malloc(sizeof(FibonacciHeap));
	if (fibonacciHeap == NULL){
		exit(EXIT_FAILURE); // Allocation impossible
    }
	return fibonacciHeap;
}

void insertNode(FibonacciHeap * fibonacciHeap,Node * node, int priority) {
	node->priority = priority;
	if (fibonacciHeap->min != null) { // on ajoute le noeud dans liste des racines
		node->left = fibonacciHeap->min;
		node->right = fibonacciHeap->min.right;
		fibonacciHeap->min.right = node;
		node->right.left = node;
		if (priority < fibonacciHeap->min.priority) { // si la priorité est inférieur le noeud devient min
			fibonacciHeap->min = node;
		}
	} else {
		fibonacciHeap->min = node;
	}
	insertNodeInHashTable(fibonacciHeap,node->id_node,node);
	fibonacciHeap->numberOfNode++;
}

Node * find_min(FibonacciHeap * fibonacciHeap){
	
}

Node * delete_min(FibonacciHeap * fibonacciHeap){
	
}

void decreaseKey(Node node, int priority) {

}

int isEmpty(FibonacciHeap * fibonacciHeap){
	if(fibonacciHeap->min == NULL)
		return TRUE;
	else
		return FALSE;
}
