#ifndef Class_Tri_Data
#define Class_Tri_Data

#include<iostream>
#include<map>

using namespace std;

class Triangle_Data{

	public:
	
	map<pair<int, int>, int> map_Tri;

	map<pair<int, int>, int>::iterator ii_find;

	void Add_Triangle(int A, int B, int C);

	void Delete_Triangle(int A, int B, int C);

	void Delete_Triangle_1(int A, int B);

	int Adjacent(int A, int B);

};

#endif
