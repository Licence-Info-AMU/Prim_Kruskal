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

void trace_graph(Ez_event *ev,Graph* drawGraph,int width,enum showWeight showWeightYN){
	double weight = 0;
	for (int j = 0 ; j < drawGraph->nb_edges; j++){
		char str_weight[50];
		sprintf(str_weight , "%lf" , drawGraph->edges[j]->weight);

		if(showWeightYN == YES){
			ez_set_color (ez_red);
			ez_draw_text(ev->win,EZ_TL, (drawGraph->edges[j]->sourceNode->x + drawGraph->edges[j]->targetNode->x)/2,
				(drawGraph->edges[j]->sourceNode->y + drawGraph->edges[j]->targetNode->y)/2 - 20, str_weight);
		}
					
		ez_set_color (ez_grey);
		ez_draw_line(ev->win,drawGraph->edges[j]->sourceNode->x, drawGraph->edges[j]->sourceNode->y, drawGraph->edges[j]->targetNode->x, drawGraph->edges[j]->targetNode->y);
		
		weight += drawGraph->edges[j]->weight;
	}
	for(int i = 0; i < drawGraph->nb_nodes; i ++){
		ez_set_color (ez_black);
		//if(showWeightYN == YES){
			char str_id_node[10];
			sprintf(str_id_node , "%d" , drawGraph->nodes[i]->id_node);
			ez_draw_text(ev->win,EZ_TL, drawGraph->nodes[i]->x+10, drawGraph->nodes[i]->y+10, str_id_node);
		//}
		ez_fill_circle(ev->win, drawGraph->nodes[i]->x+2, drawGraph->nodes[i]->y+2,drawGraph->nodes[i]->x-2, drawGraph->nodes[i]->y-2);
	}
	
	ez_set_color (ez_red);
	char str_weightShow[50];
	sprintf(str_weightShow , "%lf" , weight/2);
	ez_draw_text(ev->win,EZ_TR, width-2, 1, str_weightShow);
}

void draw_points(Ez_event *ev,Points * points){
	ez_set_color (ez_red);
	for(int i = 0; i < points->size;i++){
		if((points->points[i].x != 0) || ( points->points[i].y != 0))
			ez_fill_circle(ev->win, points->points[i].x+2, points->points[i].y+2,points->points[i].x-2, points->points[i].y-2);
	}
}
