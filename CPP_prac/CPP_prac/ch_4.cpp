#include <iostream>
#include "FruitSale.h"
#include <cstring>


int q4_1_1(void) {
	using namespace std;
	FruitSeller seller;
	seller.InitMembers(1000, 20, 0);
	FruitBuyer buyer;
	buyer.InitMembers(5000);
	buyer.BuyApples(seller, 2000);
	seller.ShowSalesResult();
	buyer.ShowBuyResult();
	return 0;
}

class Point {
private:
	int xpos, ypos;
public:
	//void Init(int x, int y) {
	//	xpos = x;
	//	ypos = y;
	//}
	Point(const int &x, const int &y) : xpos(x), ypos(y) {
	}

	void ShowPointInfo() const {
		std::cout << "[" << xpos << ", " << ypos << "]" << std::endl;
	}
};

class Circle {
private:
	Point pnt;
	int r;
public:
	//void Init(int x, int y, int num) {
	//	pnt.Init(x, y);
	//	if (num < 0)
	//		return;
	//	r = num;
	//}
	
	Circle(const int &x, const int &y, int num): pnt(x, y) {
		if (num < 0)
			return;
		r = num;
	}

	void ShowCircleInfo() const {
		std::cout << "radius: " << r << std::endl;
		pnt.ShowPointInfo();
	}
};
class Ring {
private:
	Circle inner;
	Circle outter;
public:
	//bool Init(int x1, int y1, int r1, int x2, int y2, int r2) {
	//	if (x1 > x2 || y1 > y2)
	//		return false;
	//	inner.Init(x1, y1, r1);
	//	outter.Init(x2, y2, r2);
	//	return true;
	//}

	Ring(const int &x1, const int &y1, const int &r1, const int &x2, const int &y2, const int &r2) : inner(x1, y1, r1), outter(x2, y2, r2) {
		if (x1 > x2 || y1 > y2)
			return;
	}

	void ShowRingInfo() const {
		using namespace std;
		cout << "Inner Circle Info..." << endl;
		inner.ShowCircleInfo();
		cout << "Outter Circle Info..." << endl;
		outter.ShowCircleInfo();
	}
};


int q4_2_1(void) {
	//Ring ring;
	//ring.Init(1, 1, 4, 2, 2, 9);
	//ring.ShowRingInfo();
	return 0;
}

int q4_3_1(void) {
	Ring ring(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();
	return 0;
}

namespace COMP_POS{
	enum{CLERK, SENIOR, ASSIST, MANAGER};
	void info(int num) {
		using namespace std;
		switch (num) {
		case CLERK:
			cout << "CLERK" << endl;
			break;
		case SENIOR:
			cout << "SENIOR" << endl;
			break;
		case ASSIST:
			cout << "ASSIST" << endl;
			break;
		case MANAGER:
			cout << "MANAGER" << endl;
			break;

		}
	}
}

class NameCard {
private:
	char *name;
	char *company;
	char *phone;
	int position;

public:
	NameCard(const char *name_var, const char* company_var, const char* phone_var, const int position_var) : position(position_var) {
		name = new char[strlen(name_var) + 1];
		company = new char[strlen(company_var) + 1];
		phone = new char[strlen(phone_var) + 1];
		strcpy_s(name, strlen(name_var)+1, name_var);
		strcpy_s(company, strlen(company_var)+1, company_var);
		strcpy_s(phone, strlen(phone_var)+1, phone_var);
	}

	void ShowNameCardInfo() {
		using namespace std;
		cout << "이름: " << name << endl;
		cout << "회사: " << company << endl;
		cout << "전화번호: " << phone << endl;
		cout << "직급: ";
		COMP_POS::info(position);
		cout << endl;

	}


};

int q4_3_2(void) {
	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
	NameCard manSENIOR("Hong", "OrangeEng", "010-1111-2222", COMP_POS::SENIOR);
	NameCard manASSIST("Kim", "SoGoodComp", "010-1111-2222", COMP_POS::ASSIST);
	manClerk.ShowNameCardInfo();
	manSENIOR.ShowNameCardInfo();
	manASSIST.ShowNameCardInfo();
	return 0;
}

int ch_4_cpp(void) {
	//q4_1_1();
	//q4_2_1();
	//q4_3_1();
	//q4_3_2();
	int num = -7;
	int *num1;
	num1 = &num;
	int &num2 = num;
	std::cout << *num1 << &num2;
	return 0;
}