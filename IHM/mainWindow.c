/**
*\file mainWindow.c
*\brief 
*\author Gaëtan,Lucas
*\version 0.1
*\date 13 novembre 2017
*/

#include "ez-draw.h"
#include "mainWindow.h"

void mainWindows_on_expose (Ez_event *ev){
	
}

void mainWindows_on_key_press (Ez_event *ev){
    switch (ev->key_sym) {
        case XK_q : ez_quit (); break;
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

    ez_window_create (width, height, windowName, mainWindows_on_event);
    ez_main_loop ();
    
    return 0;
}
