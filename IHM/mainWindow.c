/**
*\file mainWindow.c
*\brief 
*\author Gaëtan,Lucas
*\version 0.1
*\date 13 novembre 2017
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "point.h"
#include "graphe.h"
#include "kruskal.h"
#include "prim.h"
#include "ez-draw.h"
#include "drawing.h"
#include "mainWindow.h"

int min=20;
int max=50;

Graph * graph;
Graph * result;
enum Algos algos;
enum figure figures;
enum showWeight showWeightYN;
Points last_points;

void mainWindows_on_expose (Ez_event *ev){
	int w, h;
	ez_window_get_size (ev->win, &w, &h);
	switch(algos){
		case GRAPHEBASIC : trace_graph(ev,graph,w,showWeightYN); break;
		case KRUSKALBASIC : kurskalBasic();trace_graph(ev,result,w,showWeightYN); destructor_Graph(result); break;
		case KRUSKALAMELIORE : kurskalAmeliore();trace_graph(ev,result,w,showWeightYN);destructor_Graph(result); break;
		case PRIMBASIC : primBasic();trace_graph(ev,result,w,showWeightYN);destructor_Graph(result); break;
		case PRIMAMELIORE : primAmeliore(); trace_graph(ev,result,w,showWeightYN);destructor_Graph(result); break;
		case ULTRAMETRIE  : ultrametrie(); trace_graph(ev,result,w,showWeightYN);destructor_Graph(result); break;		
	}
	ez_set_color (ez_cyan);
	int x;
	int y;
	int dx;
	int dy;
	
	switch(figures){
		case DEFAULT : break;
		case RECTANGLE : ez_draw_rectangle(ev->win,last_points.points[0].x,last_points.points[0].y,last_points.points[1].x,last_points.points[1].y);break;
		case CERCLE : 
						x=last_points.points[1].x;
						y=last_points.points[1].y;
						dx = last_points.points[1].x - last_points.points[0].x;
						dy = last_points.points[1].y - last_points.points[0].y;
						int rayon=(int)sqrt(dx*dx+dy*dy);
						ez_draw_circle(ev->win,x-rayon,y-rayon,x+rayon,y+rayon); break;
		case ANNEAU : 
					x=last_points.points[2].x;
					y=last_points.points[2].y;
					dx = last_points.points[2].x - last_points.points[0].x;
					dy = last_points.points[2].y - last_points.points[0].y;
					int rayon1=(int)sqrt(dx*dx+dy*dy);
					dx = last_points.points[2].x - last_points.points[1].x;
					dy = last_points.points[2].y - last_points.points[1].y;
					int rayon2=(int)sqrt(dx*dx+dy*dy);
					ez_draw_circle(ev->win,x-rayon1,y-rayon1,x+rayon1,y+rayon1);
					ez_draw_circle(ev->win,x-rayon2,y-rayon2,x+rayon2,y+rayon2); break;
	}
	ez_set_color (ez_blue);
	ez_draw_text(ev->win,EZ_BL, 2, h-2, "O : Prim    P : Prim(Tas)\nI : Kruskal K : Kruskal(Forets)\nu : Ultramétrie\nR : Reset\nQ : Quit\nG : Graphe depuis random\nC : Graphe depuis cercle\nA : Graphe depuis anneau\nD : Graphe depuis rectangle\n");
}

void kurskalBasic(){
	result = base_kruskal(graph);
	show_Graph(result);
}

void kurskalAmeliore(){
	result = better_kruskal(graph);
	show_Graph(result);
}

void primBasic(){
	result = prim(graph);
	show_Graph(result);
}

void  primAmeliore(){
	result = better_prim(graph);
	show_Graph(result);
}

void ultrametrie(){
	Tab2d * ultram=constructor_Tab2d(graph->nb_nodes,graph->nb_nodes);
	show_ultram(ultram);
	result=kruskal_ultrametrie(graph,ultram);
	show_Graph(result);
	show_ultram(ultram);
}

void grapheBasicAnneau(){
	graph=constructor_Graph();
	int dx = last_points.points[2].x - last_points.points[1].x;
	int dy = last_points.points[2].y - last_points.points[1].y;
	double longueur1 = sqrt(dx*dx + dy*dy);
	dx = last_points.points[2].x - last_points.points[0].x;
	dy = last_points.points[2].y - last_points.points[0].y;
	double longueur2 = sqrt(dx*dx + dy*dy);
	generate_random_Graph_anneau(graph,min,max,last_points.points[2].x,last_points.points[2].y,longueur1,longueur2);
	show_Graph(graph);
}

void grapheBasicCercle(){
	graph=constructor_Graph();
	int dx = last_points.points[1].x - last_points.points[0].x;
	int dy = last_points.points[1].y - last_points.points[0].y;
	double longueur1 = sqrt(dx*dx + dy*dy);
	double longueur2 = 0;
	generate_random_Graph_anneau(graph,min,max,last_points.points[1].x,last_points.points[1].y,longueur1,longueur2);
	show_Graph(graph);
}

void grapheBasicRectangle(){
	graph=constructor_Graph();
	generate_random_Graph_rectangle(graph,min,max,last_points.points[0].x,last_points.points[0].y,last_points.points[1].x,last_points.points[1].y);
	show_Graph(graph);
}

void grapheBasic(){
	figures=DEFAULT;
	graph=constructor_Graph();
	generate_random_Graph(graph,min,max);
	show_Graph(graph);
}

void mainWindows_on_key_press (Ez_event *ev){
    switch (ev->key_sym) {
        case XK_q : ez_quit(); ez_send_expose(ev->win);break;
        case XK_g : algos=GRAPHEBASIC; ez_send_expose(ev->win);break;
        case XK_i : algos=KRUSKALBASIC; ez_send_expose(ev->win);break;
        case XK_k : algos=KRUSKALAMELIORE; ez_send_expose(ev->win);break; 
        case XK_o : algos=PRIMBASIC; ez_send_expose(ev->win);break;
        case XK_p : algos=PRIMAMELIORE; ez_send_expose(ev->win);break;
        case XK_u : algos=ULTRAMETRIE; ez_send_expose(ev->win);break;
        case XK_r : algos=GRAPHEBASIC; grapheBasic();ez_send_expose(ev->win);break;

        case XK_c : figures=CERCLE; grapheBasicCercle();ez_send_expose(ev->win);break;
        case XK_a : figures=ANNEAU; grapheBasicAnneau();ez_send_expose(ev->win);break;
        case XK_d : figures=RECTANGLE; grapheBasicRectangle();ez_send_expose(ev->win);break;
        
        case XK_y : showWeightYN=YES; ez_send_expose(ev->win);break;
        case XK_n : showWeightYN=NO; ez_send_expose(ev->win);break;
    }
}

void mainWindows_onButtonPress(Ez_event *ev){
	last_points.points[2].x = last_points.points[1].x;
	last_points.points[2].y =last_points.points[1].y;
	
	last_points.points[1].x = last_points.points[0].x;
	last_points.points[1].y = last_points.points[0].y;
	
	
	last_points.points[0].x = ev->mx;
	last_points.points[0].y = ev->my;
	draw_points(ev,&last_points);
}

void mainWindows_on_event (Ez_event *ev){
    switch (ev->type) {
        case Expose   : mainWindows_on_expose    (ev); break;
        case KeyPress : mainWindows_on_key_press (ev); break;
        case ButtonPress : mainWindows_onButtonPress (ev); break;                            
    }
}

//retourne 0 en cas de réussite et -1 en cas d'echec
int runMainWindow(char * windowName,int width, int height){
    if (ez_init() < 0)
		return -1;
	Ez_window mainWindow;
	grapheBasic();
	last_points.size = 3;
	last_points.points = malloc(sizeof(Point*)*last_points.size);
	if (last_points.points == NULL){
		perror("malloc Point");
		exit(EXIT_FAILURE); // Allocation impossible
    }
    figures=DEFAULT;
    showWeightYN=YES;
	mainWindow = ez_window_create (width, height, windowName, mainWindows_on_event);
    
    /* Enable double buffer to prevent window flashes */
    ez_window_dbuf (mainWindow, 1);

    ez_main_loop ();
    
    return 0;
}
