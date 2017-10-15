/**
*\file edge.c
*\brief 
*\author Gaëtan,Lucas
*\version 0.1
*\date 14 octobre 2017
*/

Edge * constructor_Edge(){
	Edge * edge = NULL;
	edge = malloc(sizeof(Edge));
	if (edge == NULL){
		exit(EXIT_FAILURE); // Allocation impossible
    }
	edge->weight = 0;
	edge->sourceNode = NULL;
	edge->targetNode = NULL;
	return edge;
}

Edge * constructor_EdgeValue(Node * sourceNode,Node * targetNode, uint weight){
	Edge * edge = NULL;
	edge = malloc(sizeof(Edge));
	if (edge == NULL){
		exit(EXIT_FAILURE); // Allocation impossible
    }
	edge->weight = weight;
	edge->sourceNode = sourceNode;
	edge->targetNode = targetNode;
	return edge;
}

void destructor_Edged(Edge * edge){
	free(edge);
	edge=NULL;
}
