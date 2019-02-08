#include <iostream>
#include "Calculator.h"
#include "Printer.h"

struct Point {
	int xpos;
	int ypos;

	void ShowPosition() {
		std::cout << "[" << xpos << ", " << ypos << "]" << std::endl;
	}

	void MovePos(int x, int y) {
		xpos += x;
		ypos += y;
	}

	void AddPoint(const Point &pos) {
		xpos += pos.xpos;
		ypos += pos.ypos;
	}
};

int q3_1_1(void) {
	Point pos1 = { 12, 4 };
	Point pos2 = { 20, 30 };
	pos1.MovePos(-7, 10);
	pos1.ShowPosition();
	pos1.AddPoint(pos2);
	pos1.ShowPosition();

	return 0;
}

int q3_2_1(void) {
	using namespace std;
	Calculator cal;
	cal.Init();
	cout << "3.2 + 2.4 = " << cal.Add(3.2, 2.4) << endl;
	cout << "3.5 / 1.7 = " << cal.Div(3.5, 1.7) << endl;
	cout << "2.2 - 1.5 = " << cal.Min(2.2, 1.5) << endl;
	cout << "4.9 / 1.2 = " << cal.Div(4.9, 1.2) << endl;
	cal.ShowOpCount();
	return 0;
}



int q3_2_2(void) {
	Printer pnt;
	pnt.SetString("Hello world");
	pnt.ShowString();
	pnt.SetString("I love C++");
	pnt.ShowString();

	return 0;
}

int ch_3_cpp(void) {
	//q3_1_1();
	//q3_2_1();
	q3_2_2();
	return 0;
}