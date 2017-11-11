/**5;
*\file main.c
*\brief 
*\author Gaëtan,Lucas
*\version 0.1
*\date 14 octobre 2017
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "graphe.h"

int main(int argc, char * argv[]){
	srand(time(NULL));
	Graph * graph = constructor_graph();
	int min=5;
	int max=15;
	generate_random_graph(graph,min,max);
	return  0;
}
