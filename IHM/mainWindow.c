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

void mainWindows_on_expose (Ez_event *ev){
	int i, w, h;
	ez_window_get_size (ev->win, &w, &h);
	trace_graph(ev,graph,w);
	ez_set_color (ez_blue);
	ez_draw_text(ev->win,EZ_BL, 2, h-2, "O : Prim    P : Prim(Tas)\nI : Kruskal K : Kruskal(Forets)\nR : Reset\nQ : Quit");
}

void kurskalBasic(){
	grapheBasic();
	graph=base_kruskal(graph);
	show_Graph(graph);
}

void kurskalAmeliore(){
	grapheBasic();
	graph=better_kruskal(graph);
	show_Graph(graph);
}

void primBasic(){

}

void primAmeliore(){
	grapheBasic();
	graph=prim(graph);
	show_Graph(graph);
}

void grapheBasic(){
	int min=10;
	int max=20;
	generate_random_Graph(graph,min,max);
	show_Graph(graph);
}

void mainWindows_on_key_press (Ez_event *ev){
    switch (ev->key_sym) {
        case XK_q : ez_quit(); ez_send_expose(ev->win);break;
        case XK_g : grapheBasic(); ez_send_expose(ev->win);break;
        case XK_i : kurskalBasic(); ez_send_expose(ev->win);break;
        case XK_k : kurskalAmeliore(); ez_send_expose(ev->win);break; 
        case XK_o : primBasic(); ez_send_expose(ev->win);break;
        case XK_p : primAmeliore(); ez_send_expose(ev->win);break;
        case XK_r : graph=constructor_Graph(); ez_send_expose(ev->win);break;
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
	graph=constructor_Graph();
	mainWindow = ez_window_create (width, height, windowName, mainWindows_on_event);
    
    /* Enable double buffer to prevent window flashes */
    ez_window_dbuf (mainWindow, 1);

    ez_main_loop ();
    
    return 0;
}
