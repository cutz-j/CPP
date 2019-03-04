#include <iostream>

class Point {
private:
	int xpos, ypos;

public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}

	void SetPos(int x, int y) {
		xpos = x;
		ypos = y;
	}

	void ShowPosition() const {
		std::cout << "x: " << xpos << std::endl;
		std::cout << "y: " << ypos << std::endl;
	}
};

template <class T>
void SwapData(T& a, T& b) {
	T temp;
	temp = b;
	b = a;
	a = temp;
}

int q13_1_1(void) {
	Point p1 = Point(3, 4);
	Point p2 = Point(1, 2);
	SwapData(p1, p2);
	p1.ShowPosition();
	p2.ShowPosition();
	return 0;
}
template <class T>
T SumArr(T arr[], int len) {
	T sum = 0;
	for (int i = 0; i < len; i++) {
		sum += arr[i];
	}
	return sum;
}

int q13_1_2(void) {
	int arr1[3] = { 1, 2, 3 };
	double arr2[3] = { 1.1, 2.2, 3.3 };
	std::cout << SumArr(arr1, 3) << std::endl;
	std::cout << SumArr(arr2, 3) << std::endl;
	return 0;
}

template <class T>
class Point_T {
private:
	T xpos, ypos;

public:
	Point_T(T x, T y) : xpos(x), ypos(y) {}

	void SetPos(T x, T y) {
		xpos = x;
		ypos = y;
	}

	void ShowPos() {
		std::cout << "[x: " << xpos << ", y: " << ypos << "]" << std::endl;
	}
};

template <class T>
class BoundCheckArr {
public:
	T *arr;
	int len;
	BoundCheckArr(const BoundCheckArr& arr) {}
	BoundCheckArr& operator=(const BoundCheckArr& arr) {}
	
public:
	BoundCheckArr(int l) : len(l) {
		arr = new T[len + 1];
	}

	T& operator[] (int idx) {
		if (idx < 0 || idx > len)
			std::cout << "out of bound" << std::endl;
		return arr[idx];
	}

	T& operator[] (int idx) const {
		if (idx < 0 || idx > len)
			std::cout << "out of bound" << std::endl;
		return arr[idx];
	}

	int GetIndex() const {
		return len;
	}

	~BoundCheckArr() {
		delete[]arr;
	}
};

template <class C>
class SmartPtr {
private:
	C * posptr;

public:
	SmartPtr(C * ptr) : posptr(ptr) {}
	C& operator*() const {
		return *posptr;
	}
	C* operator->() const {
		return posptr;
	}
	~SmartPtr() {
		delete posptr;
	}
};

int q13_2_1() {
	SmartPtr<Point> sptr1(new Point(1, 2));
	SmartPtr<Point> sptr2(new Point(3, 4));
	sptr1->ShowPosition();
	sptr2->ShowPosition();
	sptr1->SetPos(10, 20);
	sptr2->SetPos(30, 40);
	sptr1->ShowPosition();
	sptr2->ShowPosition();
	return 0;
}

int ch_13_cpp() {
	//q13_1_1();
	//q13_1_2();
	q13_2_1();
	return 0;
}