/**
*\file BinariHeap.c
*\brief 
*\author Gaëtan,Lucas
*\version 0.1
*\date 09 novembre 2017
*/
#include <stdio.h>
#include <stdlib.h>
#include "graphe.h"
#include "BinariHeap.h"

//https://en.wikipedia.org/wiki/Binary_heap#Heap_operations

//Récupère le Fils gauche
int childLeft(int i){
	return (2*i+1);
}

//Récupère le Fils droit
int childRight(int i){
	return (2*i+2);
}
//Récupère le père
int father(int i){
	if(i%2 == 0)
		return (i/2)-1;
	return i/2;
}

void max_Heapfy(BinariHeap * binariHeap,int i){
	/*
	left ← 2*i // ← means "assignment"
    right ← 2*i + 1
    largest ← i
    
    if left ≤ heap_length[A] and A[left] > A[largest] then:
        largest ← left
    if right ≤ heap_length[A] and A[right] > A[largest] then:
        largest ← right
    
    if largest ≠ i then:
        swap A[i] and A[largest]
        Max-Heapify(A, largest)
	 */
}

BinariHeap * constructor_BinariHeap(Graph * graph){
	BinariHeap * binariHeap = NULL;
	binariHeap = malloc(sizeof(BinariHeap));
	if (binariHeap == NULL){
		perror("malloc BinariHeap");
		exit(EXIT_FAILURE); // Allocation impossible
    }
    binariHeap->size = graph->nb_edges;
    for(int i = (binariHeap->size/2); i >= 1;i--){
		max_Heapfy(binariHeap,i);
	}
    return binariHeap;
}
