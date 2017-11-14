/**
*\file point.h
*\brief 
*\author Gaëtan,Lucas
*\version 0.1
*\date 14 novembre 2017
*
*/

#ifndef POINT_H
#define	POINT_H

typedef struct Point{
	int x;
	int y;
}Point;

typedef struct Points{
	Point * points;
	int size;
}Points;

#endif	/* POINT_H */
