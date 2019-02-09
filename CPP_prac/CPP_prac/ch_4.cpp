#include <iostream>
#include "FruitSale.h"


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
	void Init(int x, int y) {
		xpos = x;
		ypos = y;
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
	void Init(int x, int y, int num) {
		pnt.Init(x, y);
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
	bool Init(int x1, int y1, int r1, int x2, int y2, int r2) {
		if (x1 > x2 || y1 > y2)
			return false;
		inner.Init(x1, y1, r1);
		outter.Init(x2, y2, r2);
		return true;
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
	Ring ring;
	ring.Init(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();
	return 0;
}

int main(void) {
	//q4_1_1();
	q4_2_1();
	return 0;
}