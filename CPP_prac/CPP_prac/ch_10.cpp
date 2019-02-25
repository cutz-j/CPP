#include <iostream>

//namespace mystd {
//	using namespace std;
//	class ostream {
//	public:
//		ostream& operator<< (char *str) {
//			printf("%s", str);
//			return *this;
//		}
//
//		ostream& operator<< (const char *str) {
//			printf("%s", str);
//			return *this;
//		}
//
//		ostream& operator<< (char str) {
//			printf("%c", str);
//			return *this;
//		}
//
//		ostream& operator<< (int num) {
//			printf("%d", num);
//			return *this;
//		}
//
//		ostream& operator<< (double e) {
//			printf("%g", e);
//			return *this;
//		}
//
//		ostream& operator<< (ostream& (*fp)(ostream &ostm)) {
//			return fp(*this);
//		}
//
//		ostream& operator>> (const int num) {
//			scanf_s("%d", num, sizeof(int) * num);
//			return *this;
//		}
//	};
//
//	ostream endl(ostream &ostm) {
//		ostm << '\n';
//		fflush(stdout);
//		return ostm;
//	}
//
//
//	ostream cout;
//	ostream cin;
//}

class Point {
private:
	int xpos;
	int ypos;

public:
	Point(int x=0, int y=0): xpos(x), ypos(y) {}

	void ShowPosition(void) const {
		std::cout << "[" << xpos << ", " << ypos << "]" << std::endl;
	}

	friend Point operator- (const Point &pos1, const Point &pos2);
	
	Point operator+=(Point &pos2) {
		xpos += pos2.xpos;
		ypos += pos2.ypos;
		return 0;
	}

	Point operator-=(Point &pos2) {
		xpos -= pos2.xpos;
		ypos -= pos2.ypos;
		return 0;
	}

	Point operator-() {
		xpos = -xpos;
		ypos = -ypos;
		return *this;
	}

	friend bool operator==(Point &pos1, Point &pos2);
	
	friend bool operator!=(Point &pos1, Point &pos2);

	friend Point operator~(Point &pos1);

	friend std::ostream& operator<<(std::ostream&, const Point&);

	friend std::istream& operator>>(std::istream&, Point&);

};

std::ostream& operator<<(std::ostream& os, const Point& pos) {
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << std::endl;
	return os;
}

std::istream& operator>>(std::istream& is, Point& pos) {
	is >> pos.xpos >> pos.ypos;
	return is;
}

Point operator- (const Point &pos1, const Point &pos2) {
	Point pos(pos1.xpos - pos2.xpos, pos1.ypos - pos2.ypos);
	return pos;
}

bool operator==(Point &pos1, Point &pos2) {
	if ((pos1.xpos == pos2.xpos) && (pos1.ypos == pos2.ypos)) {
		std::cout << "true" << std::endl;
		return true;
	}
	else {
		std::cout << "false" << std::endl;
		return false;
	}
}

bool operator!=(Point &pos1, Point &pos2) {
	if (pos1 == pos2) {
		std::cout << "false" << std::endl;
		return false;
	}
	else {
		std::cout << "true" << std::endl;
		return true;
	}
}

Point operator~(Point &pos1) {
	Point pos = { pos1.ypos, pos1.xpos };
	return pos;
}

int q10_1_1(void) {
	Point pos1 = Point(1, 2);
	Point pos2 = Point(3, 4);
	Point pos3 = pos2 - pos1;
	pos3.ShowPosition();
	return 0;
}

int q10_1_2(void) {
	Point pos1 = Point(1, 2);
	Point pos2 = Point(3, 4);
	pos1 += pos2;
	pos1.ShowPosition();
	pos1 += pos2;
	pos1.ShowPosition();
	return 0;
}

int q10_1_3(void) {
	Point pos1 = Point(1, 2);
	Point pos2 = Point(3, 4);
	Point pos3 = Point(1, 2);
	pos1 == pos3;
	pos1 != pos2;
	return 0;
}

int q10_2_1() {
	Point pos1 = Point(1, 2);
	Point pos3 = -pos1;
	pos3.ShowPosition();
	Point pos2 = ~pos1;
	pos2.ShowPosition();
	return 0;
}

int q10_3_1() {
	Point pos1;
	std::cin >> pos1;
	std::cout << pos1;
	return 0;
}


int ch_10_cpp(void) {
	//q10_1_1();
	//q10_1_2();
	//q10_1_3();
	//q10_2_1();
	//std::cout << 123 << std::endl << 3.14 << std::endl;
	q10_3_1();
	return 0;
}