/**
*\file drawing.c
*\brief 
*\author Gaëtan,Lucas
*\version 0.1
*\date 13 novembre 2017
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ez-draw.h"
#include "drawing.h"

void trace_graph(Ez_event *ev,Graph* drawGraph,int width){
	double weight = 0;
	for(int i = 0; i < drawGraph->nb_nodes; i ++){
		ez_set_color (ez_black);
		char str_id_node[10];
		sprintf(str_id_node , "%d" , drawGraph->nodes[i]->id_node);
		ez_draw_text(ev->win,EZ_TL, drawGraph->nodes[i]->x+10, drawGraph->nodes[i]->y+10, str_id_node);
		ez_fill_circle(ev->win, drawGraph->nodes[i]->x, drawGraph->nodes[i]->y,drawGraph->nodes[i]->x+10, drawGraph->nodes[i]->y+10);
		for (int j = 0 ; j < drawGraph->nodes[i]->degree; j++){
			char str_weight[50];
			sprintf(str_weight , "%lf" , drawGraph->nodes[i]->edges[j]->weight);

			ez_set_color (ez_red);
			ez_draw_text(ev->win,EZ_TL, (drawGraph->nodes[i]->x + drawGraph->nodes[i]->edges[j]->targetNode->x)/2,
				(drawGraph->nodes[i]->y + drawGraph->nodes[i]->edges[j]->targetNode->y)/2 - 20, str_weight);	
						
			ez_set_color (ez_grey);
			ez_draw_line(ev->win,drawGraph->nodes[i]->x, drawGraph->nodes[i]->y, drawGraph->nodes[i]->edges[j]->targetNode->x, drawGraph->nodes[i]->edges[j]->targetNode->y);
			
			weight += drawGraph->nodes[i]->edges[j]->weight;
		}
	}
	ez_set_color (ez_red);
	char str_weightShow[50];
	sprintf(str_weightShow , "%lf" , weight/2);
	ez_draw_text(ev->win,EZ_TR, width-2, 1, str_weightShow);
}
