#include<iostream>
#include<fstream>
#include<list>
#include<ctime>
#include<cmath>
#include<cstdlib>

#include"Point.h"
#include"Triangle_Data.h"
#include"Calculation.h"

int main() {

	int Boundary_x = 30;	int Boundary_y = 30;

	int num = 30;

	int A, B, C;

	//“_ŒQ‚ðƒ‰ƒ“ƒ_ƒ€”z’u
	Point *P;

	Calculation Cal;

	P = new Point[num];

	srand((unsigned int)time(NULL));

	for (int i = 3; i < num; i++) {

		P[i].x = rand() % Boundary_x;	P[i].y = rand() % Boundary_y;

	}

	//‘S‘Ì‚ðŠÜ‚ÞŽOŠpŒ`‚ðì‚é
	double c_x, c_y, r;

	//“_ŒQ‚ð‚·‚×‚ÄŠÜ‚ÞŠiŽq‚ÉŠOÚ‚·‚é‰~R‚Ì’†SÀ•W‚Æ”¼Œa
	//c_x = Boundary_x * 0.5;	c_y = Boundary_y * 0.5;
	c_x = 30.0 * 0.5;	c_y = 30.0 * 0.5;

	//r = sqrt(pow(Boundary_x, 2.0) + pow(Boundary_y, 2.0)) * 0.5;
	r = sqrt(pow(30.0, 2.0) + pow(30.0, 2.0)) * 0.5;

	//‰~R‚ÉŠOÚ‚·‚é³ŽOŠpŒ`‚Ì’¸“_‚ÌÀ•W
	P[0].x = c_x - r * sqrt(3.0);	P[0].y = c_y - r;

	P[1].x = c_x + r * sqrt(3.0);	P[1].y = c_y - r;

	P[2].x = c_x;	P[2].y = c_y + 2 * r;


	//ŽOŠpŒ`012‚ðÅ‰‚É’Ç‰Á
	for (int i = 0; i < 3; i++) Cal.lst.push_back(i);

	Cal.data.Add_Triangle(0, 1, 2);

	Cal.Loop_Delaunay(P, num);

	double origin_x = 20000.0;	double origin_y = 20000.0;

	Cal.Delete_FirstTriangle(0, 1, 2);

	ofstream c;

	c.open("picture.eps");

	c << "%!PS-Adobe-2.0 EPSF-2.0" << endl;
	c << "%%BoundingBox: 0 0 " << 1000 * 50 + 5000 << " " << 1000 * 50 + 5000 << endl;
	c << "%%EndComments" << endl;
	c << "/mydict 120 dict def" << endl;
	c << "mydict begin" << endl;
	c << "gsave" << endl;

	c << 0.0 << " " << 0.0 << " " << 0.0 << " setrgbcolor" << endl;

	c << 0.5 << " setlinewidth" << endl;

	c << 500 * 0.0 + origin_x << ' ' << 500 * 0.0 + origin_y << " moveto" << endl;
	c << 500 * 0.0 + origin_x << ' ' << 500 * 0.0 + origin_y + 500 * 30.0 << " lineto" << endl;
	c << "stroke" << endl;

	c << 500 * 30.0 + origin_x << ' ' << 500 * 0.0 + origin_y << " moveto" << endl;
	c << 500 * 30.0 + origin_x << ' ' << 500 * 0.0 + origin_y + 500 * 30.0 << " lineto" << endl;
	c << "stroke" << endl;

	c << 500 * 0.0 + origin_x << ' ' << 500 * 0.0 + origin_y << " moveto" << endl;
	c << 500 * 30.0 + origin_x << ' ' << 500 * 0.0 + origin_y << " lineto" << endl;
	c << "stroke" << endl;

	c << 500 * 0.0 + origin_x << ' ' << 500 * 30.0 + origin_y << " moveto" << endl;
	c << 500 * 30.0 + origin_x << ' ' << 500 * 30.0 + origin_y << " lineto" << endl;
	c << "stroke" << endl;

	c << 0.0 << " " << 0.0 << " " << 0.0 << " setrgbcolor" << endl;

	c << 0.5 << " setlinewidth" << endl;

	for (int i = 0; i < num; i++) {

		c << 500 * P[i].x + origin_x << ' ' << 500 * P[i].y + origin_y << ' ' << 50.0 << " 0 360 arc" << endl;

		c << "fill" << endl;

		c << "stroke" << endl;

	}

	c << 0.0 << " " << 0.0 << " " << 0.0 << " setrgbcolor" << endl;

	c << 1.0 << " setlinewidth" << endl;

	Cal.p = Cal.lst.begin();

	while (Cal.p != Cal.lst.end()) {

		A = *Cal.p;	Cal.p++;

		B = *Cal.p;	Cal.p++;

		C = *Cal.p;	Cal.p++;

		c << 500 * P[A].x + origin_x << ' ' << 500 * P[A].y + origin_y << " moveto" << endl;
		c << 500 * P[B].x + origin_x << ' ' << 500 * P[B].y + origin_y << " lineto" << endl;
		c << 500 * P[C].x + origin_x << ' ' << 500 * P[C].y + origin_y << " lineto" << endl;
		c << "closepath" << endl;
		c << "stroke" << endl;

	}

	c << "grestore" << endl;

	c << "end" << endl;

	c.close();

}


	