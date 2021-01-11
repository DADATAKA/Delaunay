
#include"Triangle_Data.h"

void Triangle_Data::Add_Triangle(int A, int B, int C){

	map_Tri[pair<int, int>(A, B)] = C;

	map_Tri[pair<int, int>(B, C)] = A;

	map_Tri[pair<int, int>(C, A)] = B;

}

void Triangle_Data::Delete_Triangle(int A, int B, int C){

	map_Tri.erase(pair<int, int>(A, B));

	map_Tri.erase(pair<int, int>(B, C));

	map_Tri.erase(pair<int, int>(C, A));

}

void Triangle_Data::Delete_Triangle_1(int A, int B){

	map_Tri.erase(pair<int, int>(A, B));//pair‚ÍA,B‚ÆB,A‚Ìˆá‚¢‚ð‹æ•Ê‚Å‚«‚é

}

int Triangle_Data::Adjacent(int A, int B){

	ii_find = map_Tri.find(pair<int, int>(A, B));

	if (map_Tri[pair<int, int>(A, B)]) return ii_find->second;

	else return -1;

}

