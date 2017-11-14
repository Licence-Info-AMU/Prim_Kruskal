/**
*\file mainWindow.h
*\brief 
*\author Gaëtan,Lucas
*\version 0.1
*\date 13 novembre 2017
*
*/

#ifndef MAINWINDOW_H
#define	MAINWINDOW_H

enum Algos {GRAPHEBASIC,KRUSKALBASIC,KRUSKALAMELIORE,PRIMBASIC,PRIMAMELIORE,ULTRAMETRIE};

//retourne 0 en cas de réussite et -1 en cas d'echec
int runMainWindow(char * windowName,int width, int height);

void kurskalBasic();

void kurskalAmeliore();

void primBasic();

void primAmeliore();

void grapheBasic();

void ultrametrie();

#endif	/* MAINWINDOW_H */
