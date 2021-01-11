#ifndef _Class_Calculation
#define _Class_Calculation

#include<iostream>
#include<list>

#include"Point.h"
#include"Triangle_Data.h"

class Calculation{

public:

	Triangle_Data data;

	//現在あるドロネー三角形要素番号リスト, ドロネー三角形かどうか検証するストックリスト, 仮のリスト
	list<int> lst, lst_, lst_stock;

	list<int>::iterator p;
		
	double J[3][3];

	double J_I;

	double O[2][2];

	double O_2;

	double O1, O2, O3;

	double TA, TB, TC, TD;

	double L, LL;

	int n;

	int A_, B_, C_, D_;

	void Loop_Delaunay(Point *P_, int num);

	void Delete_Add_1(int A, int B, int C, int X);

	void Delete_Add_2(int A, int B, int C, int X);

	void Delete_Add_3(int A, int B, int C, int X);

	void Delete_Add_4(int A, int B, int C, int X);

	void Flip_Method(Point *P_, int A, int B, int C, int D);

	void Replace_List();
	
	void Delete_FirstTriangle(int A, int B, int C);

	int Judge_Incircle(Point *P_, int A, int B, int C, int X);

	int Judge_InTriangle(Point *P_, int A, int B, int C, int X);

	int Orient_2(Point *P_, int A, int B, int X);

	bool Judge_Crossing(Point *P_, int A, int B, int C, int D);

	bool Comparison(double A, double B, double X);
	
};

#endif