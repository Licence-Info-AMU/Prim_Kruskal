/**
*\file kruskal.c
*\brief 
*\author Gaëtan,Lucas
*\version 0.1
*\date 14 octobre 2017
*/
#include "kruskal.h"

Graph * kruskal(Graph * graph){			//selecteur
	return better_kruskal(graph);
	// return base_kruskal(graph);
}

void base_try_add_edge(Edge * edge, Graph* result, int * num_edge, int * root, int nb_nodes){
	int sourceNodeRoot=root[edge->sourceNode->id_node];
	int targetNodeRoot=root[edge->targetNode->id_node];

	if (sourceNodeRoot != targetNodeRoot){
		result->edges[*num_edge]=constructor_recopyEdge(edge);		// faire un fonciton add eges qui maintiens l'intégritée ?
		(*num_edge)++;

		for (int i = 0; i < nb_nodes; ++i){
			if (root[i]==targetNodeRoot){
				root[i]=sourceNodeRoot;
			}
		}
	}
}

Graph * base_kruskal(Graph * graph){
	Graph* result = constructor_Graph();
	int root[graph->nb_nodes] ;
	for (int i = 0; i < graph->nb_nodes; ++i){
		root[i]=i;
	}
	init_Graph(result,graph->nb_nodes-1,graph->nb_nodes);
	sort_edge_by_weight(graph);
	Edge * edge;
	int num_edge=0;

	for (int i = 0; i < graph->nb_edges; ++i){
		edge=graph->edges[i];
		base_try_add_edge(edge,result,&num_edge,root,graph->nb_nodes);
	}
	for (int i = 0; i < graph->nb_nodes; ++i){		//+copier les nodes sauf si fonction add edge qui le fera
		result->nodes[i]=constructor_recopyNode(graph->nodes[i]);
	}
	if (num_edge >= graph->nb_nodes){
		printf("j'ai un petit problème dans ma plantation num_edge = %d et il y a %d nodes\n",num_edge,graph->nb_nodes);
	}
	return result;
}

void better_try_add_edge(Edge * edge, Graph* result, int * num_edge, int * parent, int * treeDepth){
	int sourceNodeRoot=edge->sourceNode->id_node;
	int targetNodeRoot=edge->targetNode->id_node;

	while(parent[sourceNodeRoot]!=sourceNodeRoot){
		sourceNodeRoot=parent[sourceNodeRoot];
	}
	while(parent[targetNodeRoot]!=targetNodeRoot){
		targetNodeRoot=parent[targetNodeRoot];
	}
	if (sourceNodeRoot != targetNodeRoot){
		result->edges[*num_edge]=constructor_recopyEdge(edge);		// faire un fonciton add eges qui maintiens l'intégritée ?
		(*num_edge)++;
		if (treeDepth[sourceNodeRoot] >= treeDepth[targetNodeRoot]){
			parent[targetNodeRoot]=sourceNodeRoot;
		}
		else{
			int tmp=sourceNodeRoot;
			sourceNodeRoot=targetNodeRoot;
			targetNodeRoot=tmp;
			parent[targetNodeRoot]=sourceNodeRoot;
		}
		if(treeDepth[targetNodeRoot]+1 > treeDepth[sourceNodeRoot]){
			treeDepth[sourceNodeRoot]=treeDepth[targetNodeRoot]+1;
		}
	}
	
}

Graph * better_kruskal(Graph * graph){
	Graph* result = constructor_Graph();
	int parent[graph->nb_nodes] ,treeDepth[graph->nb_nodes];
	for (int i = 0; i < graph->nb_nodes; ++i){
		parent[i]=i;
		treeDepth[i]=1;
	}
	init_Graph(result,graph->nb_nodes-1,graph->nb_nodes);
	sort_edge_by_weight(graph);
	Edge * edge;
	int num_edge=0;

	for (int i = 0; i < graph->nb_edges; ++i){
		edge=graph->edges[i];
		better_try_add_edge(edge,result,&num_edge,parent,treeDepth);
	}
	for (int i = 0; i < graph->nb_nodes; ++i){		//+copier les nodes sauf si fonction add edge qui le fera
		result->nodes[i]=constructor_recopyNode(graph->nodes[i]);
	}
	if (num_edge >= graph->nb_nodes){
		printf("j'ai un petit problème dans ma plantation num_edge = %d et il y a %d nodes\n",num_edge,graph->nb_nodes);
	}
	for (int i = 0; i < graph->nb_nodes; ++i){
		printf("%d: parent: %d\tDepth: %d \n", i, parent[i], treeDepth[i]);
	}

	return result;
}

Tab2d * constructor_Tab2d(int size_x,int size_y){
	Tab2d * tab2d = NULL;
	tab2d = malloc(sizeof(Tab2d));
	tab2d->size_x=size_x;
	tab2d->size_y=size_y;
	tab2d->tab=malloc(sizeof(int*)*size_x);
	if (tab2d->tab == NULL){
		perror("malloc Tab2d");
		exit(EXIT_FAILURE); // Allocation impossible
	}
	for (int i = 0; i < size_x; ++i){
		tab2d->tab[i]=calloc(size_y,sizeof(int));
		if (tab2d->tab[i] == NULL){
			perror("calloc Tab2d");
			exit(EXIT_FAILURE); // Allocation impossible
		}
	}
	return tab2d;
}

void destructor_Tab2d(Tab2d * tab2d){
	for (int i = 0; i < tab2d->size_x; ++i){
		free(tab2d->tab[i]);
		tab2d->tab[i]=NULL;
	}
	free(tab2d->tab);
	tab2d->tab = NULL;
	free(tab2d);
	tab2d = NULL;
}

void show_ultram(Tab2d * ultram){
	for (int i = 0; i < ultram->size_y; ++i){
		printf("\t%d",i );
	}
	printf("\n");
	for (int i = 0; i < ultram->size_x; ++i){
		printf("%d\t",i );
		for (int j = 0; j < ultram->size_y; ++j){
			printf("%d\t",ultram->tab[i][j] );
		}
		printf("\n");
	}
}

Tab2d * try_add_edge_ultrametrie(Edge * edge, Graph* result, int * num_edge, int * root,Tab2d * ultram, int nb_nodes){
	int sourceNodeRoot=root[edge->sourceNode->id_node];
	int targetNodeRoot=root[edge->targetNode->id_node];
	if (sourceNodeRoot != targetNodeRoot){
		result->edges[*num_edge]=constructor_recopyEdge(edge);		// faire un fonciton add eges qui maintiens l'intégritée ?
		(*num_edge)++;

		for (int i = 0; i < nb_nodes; ++i){
			if (root[i]==targetNodeRoot){
				for (int j = 0; j < nb_nodes; ++j){
					if (root[j]==sourceNodeRoot){
						if(ultram->tab[i][j]==0)
							ultram->tab[i][j]=edge->weight;
						if(ultram->tab[j][i]==0)
							ultram->tab[j][i]=edge->weight;
					}
				}
				root[i]=sourceNodeRoot;
			}
		}
	}
	//show_ultram(ultram);
	return ultram;
}

Graph * kruskal_ultrametrie(Graph * graph,Tab2d * ultram){
	Graph* result = constructor_Graph();
	int root[graph->nb_nodes] ;
	for (int i = 0; i < graph->nb_nodes; ++i){
		root[i]=i;
	}
	init_Graph(result,graph->nb_nodes-1,graph->nb_nodes);
	sort_edge_by_weight(graph);
	Edge * edge;
	int num_edge=0;	
	for (int i = 0; i < graph->nb_edges; ++i){
		edge=graph->edges[i];
		ultram=try_add_edge_ultrametrie(edge,result,&num_edge,root,ultram,graph->nb_nodes);
	}
	for (int i = 0; i < graph->nb_nodes; ++i){		//+copier les nodes sauf si fonction add edge qui le fera
		result->nodes[i]=constructor_recopyNode(graph->nodes[i]);
	}
	if (num_edge >= graph->nb_nodes){
		printf("j'ai un petit problème dans ma plantation num_edge = %d et il y a %d nodes\n",num_edge,graph->nb_nodes);
	}
	return result;
}