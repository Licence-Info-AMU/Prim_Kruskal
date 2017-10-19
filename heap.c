/**
*\file heap.c
*\brief 
*\author Gaëtan,Lucas
*\version 0.1
*\date 15 octobre 2017 
*/
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

int delete(FibonacciHeap * fibonacciHeap,Node node) {

}

//Expérimentale, pas encore terminé
FibonacciHeap * union_heap(FibonacciHeap * fibonacciHeapx,FibonacciHeap * fibonacciHeapy){
	FibonacciHeap * new_fibonacciHeap = constructor_Heap();
	new_fibonacciHeap->min = fibonacciHeapx->min;
	new_fibonacciHeap->numberOfNode = fibonacciHeapx->numberOfNode + fibonacciHeapy->numberOfNode;
	new_fibonacciHeap->hashTable = constructor_HashTable(new_fibonacciHeap->numberOfNode);
	//concatenate the root list of H2 with the root list of H1 = hashTable

	if ( (fibonacciHeapx->min == NULL) || ( (fibonacciHeapy->min != NULL) && (fibonacciHeapy->min.priority < fibonacciHeapx->min.priority) ) ){
		new_fibonacciHeap->min = fibonacciHeapy->min;
	}
	destructor_FibonacciHeap(fibonacciHeapx);
	destructor_FibonacciHeap(fibonacciHeapy);
	return new_fibonacciHeap;
}

int isEmpty(FibonacciHeap * fibonacciHeap){
	if(fibonacciHeap->min == NULL)
		return TRUE;
	else
		return FALSE;
}

void destructor_FibonacciHeap(FibonacciHeap * fibonacciHeap){
	free(fibonacciHeap);
	fibonacciHeap = NULL;
}
