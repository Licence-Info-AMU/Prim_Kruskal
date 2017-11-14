/**
*\file main-app.c
*\brief 
*\author Gaëtan,Lucas
*\version 0.1
*\date 13 novembre 2017
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ez-draw.h"
#include "drawing.h"
#include "mainWindow.h"

int main (){
	srand(time(NULL));
	//Run main window
	(runMainWindow("Projet Algorithmique Kruskal et Prim",800,600) < 0)? exit(1) : exit(0);
}
