#include <iostream>
#include <cstring>

class Car {
private:
	int gasolineGauge;

public:
	Car(): gasolineGauge(60) {}

	Car(int n) : gasolineGauge(n) {}

	int GestGasGauge() {
		return gasolineGauge;
	}
};

class HybridCar : public Car {
private:
	int electricaGauge;
	
public:
	HybridCar() : electricaGauge(100), Car() {}
	HybridCar(int n) : electricaGauge(n), Car() {}
	HybridCar(int n, int m) : electricaGauge(n), Car(m) {}

	int GetElecGauge() {
		return electricaGauge;
	}
};

class HybridWaterCar : public HybridCar {
private:
	int waterGauge;

public:
	HybridWaterCar() : waterGauge(50), HybridCar() {}
	HybridWaterCar(int n) : waterGauge(n), HybridCar() {}
	HybridWaterCar(int n, int m) : waterGauge(n), HybridCar(m) {}
	HybridWaterCar(int n, int m, int z) : waterGauge(n), HybridCar(m, z) {}


	void ShowCurrentGauge() {
		std::cout << "잔여 가솔린: " << GestGasGauge() << std::endl;
		std::cout << "잔여 전기량: " << GetElecGauge() << std::endl;
		std::cout << "잔여 워터량: " << waterGauge << std::endl;
	}
};

int q7_1_1(void) {
	HybridWaterCar wCar(79, 65, 35);
	wCar.ShowCurrentGauge();
	return 0;
}

class MyFriendInfo {
private:
	char * name;
	int age;
public:
	MyFriendInfo(const char * na, int a) : age(a) {
		name = new char[strlen(na) + 1];
		strcpy_s(name, strlen(na) + 1, na);
	}

	~MyFriendInfo() {
		delete[]name;
	}

	void ShowMyFriendInfo() {
		std::cout << "이름: " << name << std::endl;
		std::cout << "나이: " << age << std::endl;
	}
};

class MyFriendDetailInfo : public MyFriendInfo {
private:
	char * addr;
	char * phone;
public:
	MyFriendDetailInfo(const char * tmp, int age, const char * add, const char * ph)
		: MyFriendInfo(tmp, age) {
		addr = new char[strlen(add) + 1];
		phone = new char[strlen(ph) + 1];
		strcpy_s(addr, strlen(add) + 1, add);
		strcpy_s(phone, strlen(ph) + 1, ph);
	}

	~MyFriendDetailInfo() {
		delete[]addr;
		delete[]phone;
	}

	void ShowMyFriendDetailInfo() {
		ShowMyFriendInfo();
		std::cout << "주소: " << addr << std::endl;
		std::cout << "전화: " << phone << std::endl << std::endl;
	}
};

int q7_1_2() {
	MyFriendDetailInfo fren1("김진성", 22, "충남 아산", "010-1234-0000");
	MyFriendDetailInfo fren2("이주성", 19, "경기 인천", "010-3333-0000");
	fren1.ShowMyFriendDetailInfo();
	fren2.ShowMyFriendDetailInfo();
	return 0;
}

class Rectangle {
private:
	int x, y;
public:
	Rectangle(int a, int b): x(a), y(b) {}
	
	void ShowAreaInfo() {
		std::cout << "면적: " << x * y << std::endl;
	}
};

class Square: public Rectangle {
public:
	Square(int r) : Rectangle(r, r) {}
};

int q7_2_1(void) {
	Rectangle rec(4, 3);
	rec.ShowAreaInfo();

	Square sqr(7);
	sqr.ShowAreaInfo();

	return 0;
}

class Book {
private:
	char * title;
	char * isbn;
	int price;

public:
	Book(const char *ti, const char * is, int pr) : price(pr) {
		title = new char[strlen(ti) + 1];
		strcpy_s(title, strlen(ti) + 1, ti);
		isbn = new char[strlen(is) + 1];
		strcpy_s(isbn, strlen(is) + 1, is);
	}

	void ShowbookInfo() {
		using namespace std;
		cout << "제목: " << title << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "가격: " << price << endl;
	}

	~Book() {
		delete[]title;
		delete[]isbn;
	}
};

class EBook: Book {
private:
	char * DRMKey;
public:
	EBook(const char *ti, const char *is, int pr, const char *DRM)
		:Book(ti, is, pr) {
		DRMKey = new char[strlen(DRM) + 1];
		strcpy_s(DRMKey, strlen(DRM) + 1, DRM);
	}

	void ShowEBookInfo() {
		using namespace std;
		ShowbookInfo();
		cout << "인증키: " << DRMKey << endl;
	}
};

int q7_2_2() {
	Book book("좋은 C++", "555-12345-890-0", 20000);
	book.ShowbookInfo();
	std::cout << std::endl;
	EBook ebook("좋은 C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
	ebook.ShowEBookInfo();
	return 0;
}




int ch_7_cpp(void) {
	//q7_1_1();
	//q7_1_2();
	//q7_2_1();
	q7_2_2();
	return 0;
}


















