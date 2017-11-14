/**
*\file drawing.h
*\brief 
*\author Gaëtan,Lucas
*\version 0.1
*\date 13 novembre 2017
*
*/
#include "point.h"
#include "graphe.h"

#ifndef DRAWING_H
#define	DRAWING_H

enum showWeight{YES,NO};

void trace_graph(Ez_event *ev,Graph* drawGraph,int width,enum showWeight showWeightYN);

void draw_points(Ez_event *ev,Points * points);

#endif	/* DRAWING_H */
