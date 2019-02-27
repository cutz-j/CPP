#include <iostream>
#include <cstring>
#include <cstdlib>

class Person {
private:
	char * name;
	int age;

public:
	Person(const char * myname, int myage) {
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy_s(name, strlen(myname) + 1, myname);
		age = myage;
	}

	void ShowPersonInfo() const {
		std::cout << "name: " << name << std::endl;
		std::cout << "age: " << age << std::endl;
	}

	~Person() {
		delete[]name;
	}

	Person& operator= (const Person& ref) {
		delete[] name;
		name = new char[strlen(ref.name)+1];
		strcpy_s(name, strlen(ref.name) + 1, ref.name);
		age = ref.age;
		return *this;
	}

};

class Gun {
private:
	int bullet;
public:
	Gun(int bnum) : bullet(bnum) {  }
	void Shot() {
		std::cout << "bbang! " << bullet << std::endl;
		bullet--;
	}
};

class Police {
private:
	int handcuffs;
	Gun * pistol;

public:
	Police(int bnum, int bcuff) : handcuffs(bcuff) {
		if (bnum > 0)
			pistol = new Gun(bnum);
		else
			pistol = NULL;
	}

	Police(const Police& ref): handcuffs(ref.handcuffs) {
		if (ref.pistol == NULL)
			pistol = NULL;
		else
			pistol = new Gun(*(ref.pistol));
	}

	Police& operator=(const Police& ref) {
		if (pistol != NULL)
			delete pistol;
		if (ref.pistol != NULL)
			pistol = new Gun(*(ref.pistol));
		else
			pistol = NULL;

		handcuffs = ref.handcuffs;
		return *this;
	}

	void PutHandcuff() {
			std::cout << "snap " << handcuffs << std::endl;
			handcuffs--;
	}

	void Shot() {
		if (pistol == NULL)
			std::cout << "Hut BBang!" << std::endl;
		else
			pistol->Shot();
	}

	~Police() {
		if (pistol != NULL)
			delete pistol;
	}

};

int police_test() {
	Police p1(3, 4);
	Police p2 = p1;
	p2.PutHandcuff();
	p2.Shot();

	Police p3(1, 2);
	p3 = p1;
	p3.PutHandcuff();
	p3.Shot();
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

	Book(const Book& ref) : price(ref.price) {
		title = new char[strlen(ref.title) + 1];
		strcpy_s(title, strlen(ref.title) + 1, ref.title);
		isbn = new char[strlen(ref.isbn) + 1];
		strcpy_s(isbn, strlen(ref.isbn) + 1, ref.isbn);
	}

	Book& operator=(const Book& ref) {
		price = ref.price;
		title = new char[strlen(ref.title) + 1];
		strcpy_s(title, strlen(ref.title) + 1, ref.title);
		isbn = new char[strlen(ref.isbn) + 1];
		strcpy_s(isbn, strlen(ref.isbn) + 1, ref.isbn);
		return *this;
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

class EBook : Book {
private:
	char * DRMKey;
public:
	EBook(const char *ti, const char *is, int pr, const char *DRM)
		:Book(ti, is, pr) {
		DRMKey = new char[strlen(DRM) + 1];
		strcpy_s(DRMKey, strlen(DRM) + 1, DRM);
	}

	EBook(const EBook& ref): Book(ref) {
		DRMKey = new char[strlen(ref.DRMKey) + 1];
		strcpy_s(DRMKey, strlen(ref.DRMKey) + 1, ref.DRMKey);
	}

	EBook& operator=(const EBook& ref) {
		Book::operator=(ref); // 부모클래스 대입연산자 선언
		delete []DRMKey; // 대입연산자의 이유
		DRMKey = new char[strlen(ref.DRMKey) + 1];
		strcpy_s(DRMKey, strlen(ref.DRMKey) + 1, ref.DRMKey);
		return *this;
	}

	void ShowEBookInfo() {
		using namespace std;
		ShowbookInfo();
		cout << "인증키: " << DRMKey << endl;
	}
};

int q11_1_2() {
	Book bk1("abc", "11", 10000);
	Book bk2 = bk1;
	Book bk3("def", "22", 20000);
	bk3 = bk1;
	bk2.ShowbookInfo();
	bk3.ShowbookInfo();
	
	EBook ebk1("abc", "11", 10000, "123");
	EBook ebk2 = ebk1;
	EBook ebk3("def", "22", 20000, "456");
	ebk3 = ebk1;
	ebk2.ShowEBookInfo();
	ebk3.ShowEBookInfo();
	return 0;
}

class Point {
private:
	int xpos, ypos;
	
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}

	friend std::ostream& operator<<(std::ostream& os, const Point& pos);
	friend std::ostream& operator<<(std::ostream& os, const Point* pos);
};

std::ostream& operator<<(std::ostream& os, const Point* pos) {
	os << '[' << pos->xpos << ", " << pos->ypos << "]" << std::endl;
	return os;
}

class BoundCheck {
private:
	int *arr;
	int arrlen;
	BoundCheck(const BoundCheck& arr) { }
	BoundCheck& operator=(const BoundCheck& arr) { }

public:
	BoundCheck(int len) : arrlen(len) {
		arr = new int[len];
	}

	int& operator[] (int idx) {
		if (idx < 0 || idx >= arrlen) {
			std::cout << arrlen << idx;
			std::cout << "out of bound 1" << std::endl;
			exit(1);
		}
		return arr[idx];
	}


	int operator[] (int idx) const {
		if (idx < 0 || idx >= arrlen) {
			std::cout << "out of bound 2" << std::endl;
			exit(1);
		}
		return arr[idx];
	}

	int GetArrLen() const {
		return arrlen;
	}

	~BoundCheck() {
		delete[]arr;
	}
};

class BoundCheck2D {
private:
	BoundCheck **arr;
	int arrlen;
	BoundCheck2D(const BoundCheck2D& arr) {}
	BoundCheck2D& operator=(const BoundCheck2D& arr) {}

public:
	BoundCheck2D(int row, int col) : arrlen(col) {
		arr = new BoundCheck*[row];
		for (int i = 0; i < row; i++) {
			arr[i] = new BoundCheck(col);
		}
	}

	BoundCheck& operator[] (int num) {
		if (num < 0 || num > arrlen) {
			std::cout << "out of bounds 3" << std::endl;
			exit(1);
		}
		return *(arr[num]);
	}

	~BoundCheck2D() {
		for (int i = 0; i < arrlen; i++)
			delete arr[i];
		delete[]arr;
	}

};

int q11_2_1() {
	BoundCheck arr(3);
	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 2;

	for (int i = 0; i < arr.GetArrLen(); i++) {
		std::cout << " ";
		std::cout << arr[i];
		std::cout << std::endl;
	}
	
	return 0;
}

int q11_2_2() {
	BoundCheck2D arr(3, 4);

	for (int n = 0; n < 3; n++)
		for (int m = 0; m < 4; m++)
			arr[n][m] = n + m;

	for (int n = 0; n < 3; n++) {
		for (int m = 0; m < 4; m++) {
			std::cout << arr[n][m] << ' ';
		}
		std::cout << std::endl;
	}

	return 0;
}

int ch_11_cpp(void) {
	//police_test();
	//q11_1_2();
	//q11_2_1();
	//q11_2_2();
	int *arr = new int[3];
	std::cout << *arr;

	return 0;
}





















