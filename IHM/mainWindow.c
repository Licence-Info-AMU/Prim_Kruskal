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
#include "graphe.h"
#include "kruskal.h"
#include "prim.h"
#include "ez-draw.h"
#include "drawing.h"
#include "mainWindow.h"

Graph * graph;
Graph * result;
enum Algos algos;

void mainWindows_on_expose (Ez_event *ev){
	int w, h;
	ez_window_get_size (ev->win, &w, &h);
	switch(algos){
		case GRAPHEBASIC : trace_graph(ev,graph,w); break;
		case KRUSKALBASIC : kurskalBasic();trace_graph(ev,result,w); destructor_Graph(result); break;
		case KRUSKALAMELIORE : kurskalAmeliore();trace_graph(ev,result,w);destructor_Graph(result); break;
		case PRIMBASIC : primBasic();trace_graph(ev,result,w);destructor_Graph(result); break;
		case PRIMAMELIORE : primAmeliore(); trace_graph(ev,result,w);destructor_Graph(result); break;
		case ULTRAMETRIE  : ultrametrie(); trace_graph(ev,result,w);destructor_Graph(result); break;		
	}

	ez_set_color (ez_blue);
	ez_draw_text(ev->win,EZ_BL, 2, h-2, "O : Prim    P : Prim(Tas)\nI : Kruskal K : Kruskal(Forets)\nR : Reset\nQ : Quit");
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

void grapheBasic(){
	graph=constructor_Graph();
	int min=10;
	int max=20;
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
    }
}

void mainWindows_on_event (Ez_event *ev){
    switch (ev->type) {
        case Expose   : mainWindows_on_expose    (ev); break;
        case KeyPress : mainWindows_on_key_press (ev); break;
    }
}

//retourne 0 en cas de réussite et -1 en cas d'echec
int runMainWindow(char * windowName,int width, int height){
    if (ez_init() < 0)
		return -1;
	Ez_window mainWindow;
	grapheBasic();
	mainWindow = ez_window_create (width, height, windowName, mainWindows_on_event);
    
    /* Enable double buffer to prevent window flashes */
    ez_window_dbuf (mainWindow, 1);

    ez_main_loop ();
    
    return 0;
}
