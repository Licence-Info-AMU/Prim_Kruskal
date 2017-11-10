/**
*\file BinariHeap.c
*\brief 
*\author Gaëtan,Lucas
*\version 0.1
*\date 09 novembre 2017
*/
#include "BinariHeap.h"

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
	return (i-1/2);
}

Edge * getMin(BinariHeap * binariHeap){
	return binariHeap->edges[0];
}

BinariHeap * constructor_MinBinariHeap(int nbEdges){
	BinariHeap * binariHeap = NULL;
	binariHeap = malloc(sizeof(BinariHeap));
	if (binariHeap == NULL){
		perror("malloc MinBinariHeap");
		exit(EXIT_FAILURE); // Allocation impossible
    }
    binariHeap->size=0;
    binariHeap->capacity = nbEdges;
    binariHeap->edges = malloc(sizeof(Edge*)*binariHeap->capacity);
	if (binariHeap->edges == NULL){
		perror("malloc MinBinariHeap");
		exit(EXIT_FAILURE); // Allocation impossible
    }
    return binariHeap;
}

void insertKey(BinariHeap * binariHeap,Edge * edge){
	if(binariHeap->size == binariHeap->capacity){
		perror("Overflow : Could not insertKey ");
	}else{
		//On insert à la fin
		binariHeap->size++;
		int i = binariHeap->size-1;
		binariHeap->edges[i] = edge;
		while(i != 0 && binariHeap->edges[father(i)]->weight > binariHeap->edges[i]->weight){
			swap(binariHeap->edges[i],binariHeap->edges[father(i)]);
			i=father(i);
		}
	}
}

void decreaseKey(BinariHeap * binariHeap,int i, int new_val){
	binariHeap->edges[i]->weight=new_val;
	while(i != 0 && binariHeap->edges[father(i)]->weight > binariHeap->edges[i]->weight){
		swap(binariHeap->edges[i],binariHeap->edges[father(i)]);
		i=father(i);
	}
}

Edge* extractMin(BinariHeap * binariHeap){
	if(binariHeap->size <= 0){
		return NULL;
	}else if(binariHeap->size == 1){
		binariHeap->size--;
		return 	binariHeap->edges[0];
	}else{
		Edge * root = binariHeap->edges[0];
		binariHeap->edges[0] = binariHeap->edges[binariHeap->size-1];
		binariHeap->size--;
		min_Heapfy(binariHeap,0);
		return root;
	}
}

void deleteKey(BinariHeap * binariHeap,int i){
	decreaseKey(binariHeap,i,INT_MIN);
	extractMin(binariHeap);
}

void min_Heapfy(BinariHeap * binariHeap,int i){
	int left = childLeft(i);
	int right = childRight(i);
	int smallest = i;
	
	if(left < binariHeap->size && binariHeap->edges[left]->weight < binariHeap->edges[i]->weight){
		smallest=left;
	}
	if(right < binariHeap->size && binariHeap->edges[right]->weight < binariHeap->edges[i]->weight){
		smallest=right;
	}
	if(smallest != i){
		swap(binariHeap->edges[smallest],binariHeap->edges[i]);
		min_Heapfy(binariHeap,smallest);
	}
}
