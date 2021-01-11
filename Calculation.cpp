#include"Calculation.h"

void Calculation::Loop_Delaunay(Point *P_, int num){

	for (int i = 3; i < num; i++) {

		n = 0;

		p = lst.begin();

		//全ての三角形を探索
		while (p != lst.end()) {

			A_ = *p;	p++;

			B_ = *p;	p++;

			C_ = *p;	p++;

			//三角形の中から点iが中にあるものを探す
			if (Judge_InTriangle(P_, A_, B_, C_, i) == 1) {

				//三角形リストの中から三角形ABCを削除
				p--;

				lst.erase(p);

				p = lst.begin();

				for (int k = 0; k < 3 * n + 1; k++) p++;

				lst.erase(p);

				p = lst.begin();

				for (int k = 0; k < 3 * n; k++) p++;

				lst.erase(p);

				Delete_Add_1(A_, B_, C_, i);

				break;

			}//if(Judge_InTriangle)

			else if (Judge_InTriangle(P_, A_, B_, C_, i) == 2){

				//三角形リストの中から三角形ABCを削除
				p--;

				lst.erase(p);

				p = lst.begin();

				for (int k = 0; k < 3 * n + 1; k++) p++;

				lst.erase(p);

				p = lst.begin();

				for (int k = 0; k < 3 * n; k++) p++;

				lst.erase(p);

				Delete_Add_2(A_, B_, C_, i);

				break;

			}

			else if (Judge_InTriangle(P_, A_, B_, C_, i) == 3){

				//三角形リストの中から三角形ABCを削除
				p--;

				lst.erase(p);

				p = lst.begin();

				for (int k = 0; k < 3 * n + 1; k++) p++;

				lst.erase(p);

				p = lst.begin();

				for (int k = 0; k < 3 * n; k++) p++;

				lst.erase(p);

				Delete_Add_3(A_, B_, C_, i);

				break;

			}//else if(Judge_Triangle == 3)

			else if (Judge_InTriangle(P_, A_, B_, C_, i) == 4){

				//三角形リストの中から三角形ABCを削除
				p--;

				lst.erase(p);

				p = lst.begin();

				for (int k = 0; k < 3 * n + 1; k++) p++;

				lst.erase(p);

				p = lst.begin();

				for (int k = 0; k < 3 * n; k++) p++;

				lst.erase(p);

				Delete_Add_4(A_, B_, C_, i);

				break;

			}//else if(Judge_Triangle == 4)

			else {

				n++;

				continue;

			}

		}//while(p != lst.end())

		//ストックリストを検証
		while (!lst_stock.empty()){

			p = lst_stock.begin();

			A_ = *p;	p++;

			B_ = *p; p++;

			C_ = data.Adjacent(A_, B_);

			lst_stock.pop_front();	lst_stock.pop_front();	lst_stock.pop_front();

			D_ = data.Adjacent(B_, A_);

			if (D_ != -1) {

				Flip_Method(P_, A_, B_, C_, D_);

			}//if(D != -1)

			else {

				lst.push_back(A_);	lst.push_back(B_);	lst.push_back(C_);

			}//else(D!=-1)

		}//while

		Replace_List();

	}//for i

}

void Calculation::Delete_Add_1(int A, int B, int C, int X){

	//三角形データの中から三角形ABCを削除
	data.Delete_Triangle(A, B, C);

	//三角形データに三角形ABX, BCX, CAXを追加
	data.Add_Triangle(A, B, X);	data.Add_Triangle(B, C, X);	data.Add_Triangle(C, A, X);

	//ストックリストに三角形ABX, BCX, CAXを追加
	lst_stock.push_back(A);	lst_stock.push_back(B);	lst_stock.push_back(X);

	lst_stock.push_back(B);	lst_stock.push_back(C);	lst_stock.push_back(X);

	lst_stock.push_back(C);	lst_stock.push_back(A);	lst_stock.push_back(X);

}

void Calculation::Delete_Add_2(int A, int B, int C, int X){

	//三角形データの中から三角形ABCを削除
	data.Delete_Triangle(A, B, C);

	//三角形データに三角形BCX, CAXを追加
	data.Add_Triangle(B, C, X);	data.Add_Triangle(C, A, X);

	//ストックリストに三角形BCX, CAXを追加
	lst_stock.push_back(B);	lst_stock.push_back(C);	lst_stock.push_back(X);

	lst_stock.push_back(C);	lst_stock.push_back(A);	lst_stock.push_back(X);

	D_ = data.Adjacent(B, A);

	if (D_ != -1){

		data.Delete_Triangle_1(B, A);	data.Delete_Triangle_1(A, D_);	data.Delete_Triangle_1(D_, B);

		data.Add_Triangle(A, D_, X);	data.Add_Triangle(D_, B, X);

		lst_stock.push_back(A);	lst_stock.push_back(D_);	lst_stock.push_back(X);

		lst_stock.push_back(D_);	lst_stock.push_back(B);	lst_stock.push_back(X);

	}

}

void Calculation::Delete_Add_3(int A, int B, int C, int X){

	//三角形データの中から三角形ABCを削除
	data.Delete_Triangle(A, B, C);

	//三角形データに三角形BCi, CAiを追加
	data.Add_Triangle(A, B, X);	data.Add_Triangle(C, A, X);

	//ストックリストに三角形ABX, CAXを追加
	lst_stock.push_back(A);	lst_stock.push_back(B);	lst_stock.push_back(X);

	lst_stock.push_back(C);	lst_stock.push_back(A);	lst_stock.push_back(X);

	D_ = data.Adjacent(C, B);

	if (D_ != -1){

		data.Delete_Triangle_1(C, B);	data.Delete_Triangle_1(B, D_);	data.Delete_Triangle_1(D_, C);

		data.Add_Triangle(B, D_, X);	data.Add_Triangle(D_, C, X);

		lst_stock.push_back(B);	lst_stock.push_back(D_);	lst_stock.push_back(X);

		lst_stock.push_back(D_);	lst_stock.push_back(C);	lst_stock.push_back(X);

	}

}

void Calculation::Delete_Add_4(int A, int B, int C, int X){

	//三角形データの中から三角形ABCを削除
	data.Delete_Triangle(A, B, C);

	//三角形データに三角形BCi, CAiを追加
	data.Add_Triangle(A, B, X);	data.Add_Triangle(B, C, X);

	//ストックリストに三角形ABi, CAiを追加
	lst_stock.push_back(A);	lst_stock.push_back(B);	lst_stock.push_back(X);

	lst_stock.push_back(B);	lst_stock.push_back(C);	lst_stock.push_back(X);

	D_ = data.Adjacent(A, C);

	if (D_ != -1){

		data.Delete_Triangle_1(A, C);	data.Delete_Triangle_1(C, D_);	data.Delete_Triangle_1(D_, A);

		data.Add_Triangle(C, D_, X);	data.Add_Triangle(D_, A, X);

		lst_stock.push_back(C);	lst_stock.push_back(D_);	lst_stock.push_back(X);

		lst_stock.push_back(D_);	lst_stock.push_back(A);	lst_stock.push_back(X);

	}

}

void Calculation::Flip_Method(Point *P_, int A, int B, int C, int D){

	if (Judge_Crossing(P_, A, B, C, D)){

		L = sqrt(pow(P_[C].x - P_[D].x, 2.0) + pow(P_[C].y - P_[D].y, 2.0));

		LL = sqrt(pow(P_[B].x - P_[A].x, 2.0) + pow(P_[B].y - P_[A].y, 2.0));

		if (L < LL) {//同じ円周上にある場合は？

			//BADがリストから削除されないという問題がある
			data.Delete_Triangle_1(A, B);	data.Delete_Triangle_1(B, C);	data.Delete_Triangle_1(C, A);

			data.Delete_Triangle_1(B, A);	data.Delete_Triangle_1(A, D);	data.Delete_Triangle_1(D, B);

			data.Add_Triangle(A, D, C);	data.Add_Triangle(D, B, C);

			lst_stock.push_back(A);	lst_stock.push_back(D);	lst_stock.push_back(C);

			lst_stock.push_back(D);	lst_stock.push_back(B);	lst_stock.push_back(C);

		}//if(L<LL)

		else {

			lst.push_back(A);	lst.push_back(B);	lst.push_back(C);

		}//else(L<LL)

	}//if(Judge_Crossing)

	else{

		lst.push_back(A);	lst.push_back(B);	lst.push_back(C);

	}//else(Judge_Crossing)

}

void Calculation::Replace_List(){

	p = lst.begin();

	while (p != lst.end()) {

		A_ = *p;	p++;

		B_ = *p;	p++;

		C_ = *p;	p++;

		D_ = data.Adjacent(A_, B_);

		if (C_ == D_){

			lst_.push_back(A_);	lst_.push_back(B_);	lst_.push_back(C_);

		}

		else continue;

	}

	lst.clear();

	p = lst_.begin();

	while (p != lst_.end()) {

		lst.push_back(*p);

		p++;

	}

	lst_.clear();

}

void Calculation::Delete_FirstTriangle(int A, int B, int C){

	p = lst.begin();

	while (p != lst.end()) {

		A_ = *p;	p++;

		B_ = *p;	p++;

		C_ = *p;	p++;

		if ((A_ == A) || (B_ == A) || (C_ == A)) continue;
		
		else if ((A_ == B) || (B_ == B) || (C_ == B)) continue;

		else if ((A_ == C) || (B_ == C) || (C_ == C)) continue;

		else {

			lst_.push_back(A_);	lst_.push_back(B_);	lst_.push_back(C_);

		}

	}

	lst.clear();

	p = lst_.begin();

	while (p != lst_.end()) {

		lst.push_back(*p);

		p++;

	}

	lst_.clear();


}

int Calculation::Judge_Incircle(Point *P_, int A, int B, int C, int X){

	J[0][0] = P_[A].x - P_[X].x;	J[0][1] = P_[B].x - P_[X].x;	J[0][2] = P_[C].x - P_[X].x;

	J[1][0] = P_[A].y - P_[X].y;	J[1][1] = P_[B].y - P_[X].y;	J[1][2] = P_[C].y - P_[X].y;

	J[2][0] = pow(J[0][0], 2.0) + pow(J[1][0], 2.0);	J[2][1] = pow(J[0][1], 2.0) + pow(J[1][1], 2.0);	J[2][2] = pow(J[0][2], 2.0) + pow(J[1][2], 2.0);

	for (int i = 0; i < 3; i++) J_I += J[0][i % 3] * J[1][(i + 1) % 3] * J[2][(i + 2) % 3] - J[0][(i + 1) % 3] * J[1][i % 3] * J[2][(i + 2) % 3];

	if (J_I > 0.0) return 1;//A, B, C, Xが反時計回りかつXが三角形ABCの外接円の中にある

	else if (J_I == 0.0) return 0;//Xが三角形ABCの外接円の中にある

	else return -1;//A, B, C, Xが反時計回りかつXが三角形ABCの外接円の外にある

}

int Calculation::Judge_InTriangle(Point *P_, int A, int B, int C, int X){

	O1 = (P_[B].x - P_[A].x) * (P_[X].y - P_[A].y) - (P_[B].y - P_[A].y) * (P_[X].x - P_[A].x);

	O2 = (P_[C].x - P_[B].x) * (P_[X].y - P_[B].y) - (P_[C].y - P_[B].y) * (P_[X].x - P_[B].x);

	O3 = (P_[A].x - P_[C].x) * (P_[X].y - P_[C].y) - (P_[A].y - P_[C].y) * (P_[X].x - P_[C].x);

	if ((O1 > 0.0) && (O2 > 0.0) && (O3 > 0.0)) return 1;

	else if (O1 == 0.0)  {

		if (Comparison(P_[A].x, P_[B].x, P_[X].x)) return 2;

		else {

			if (Comparison(P_[A].y, P_[B].y, P_[X].y)) return 2;

			else return 0;

		}

	}

	else if (O2 == 0.0) {

		if (Comparison(P_[B].x, P_[C].x, P_[X].x)) return 3;

		else {

			if (Comparison(P_[B].y, P_[C].y, P_[X].y)) return 3;

			else return 0;

		}

	}

	else if (O3 == 0.0) {

		if (Comparison(P_[C].x, P_[A].x, P_[X].x)) return 4;

		else {

			if (Comparison(P_[C].y, P_[A].y, P_[X].y)) return 4;

			else return 0;

		}

	}

	else return 0;

}

int Calculation::Orient_2(Point *P_, int A, int B, int X){

	O[0][0] = P_[A].x - P_[X].x;	O[0][1] = P_[A].y - P_[X].y;

	O[1][0] = P_[B].y - P_[X].y;	O[1][1] = P_[B].y - P_[X].y;

	O_2 = O[0][0] * O[1][1] - O[0][1] * O[1][0];

	if (O_2 > 0.0) return 1;//A, B, Xがこの順で反時計回り

	else if (O_2 == 0.0) return 0;//A, B, Xがこの順で直線

	else return -1;//A, B, Xがこの順で時計回り

}

bool Calculation::Judge_Crossing(Point *P_, int A, int B, int C, int D){

	//変形四角形？の場合を除外するために四角形の対角線の交差判定を行う
	//線分ABと直線CDの交差判定
	TA = (P_[C].x - P_[D].x) * (P_[A].y - P_[C].y) + (P_[C].y - P_[D].y) * (P_[C].x - P_[A].x);

	TB = (P_[C].x - P_[D].x) * (P_[B].y - P_[C].y) + (P_[C].y - P_[D].y) * (P_[C].x - P_[B].x);

	TC = (P_[A].x - P_[B].x) * (P_[C].y - P_[A].y) + (P_[A].y - P_[B].y) * (P_[A].x - P_[C].x);

	TD = (P_[A].x - P_[B].x) * (P_[D].y - P_[A].y) + (P_[A].y - P_[B].y) * (P_[A].x - P_[D].x);

	if ((TA * TB < 0.0) && (TC * TD < 0.0)) return 1;

	else return 0;

}

bool Calculation::Comparison(double A, double B, double X) {

	if (A == B) return 0;

	else {

		if ((A < X) && (B > X)) return 1;

		else if ((A > X) && (B < X)) return 1;

		else return 0;

	}

}