#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void increase(int &num) {
	num++;
}

void change(int &num) {
	if (num > 0 || num < 0)
		num = -num;
	else
		return;
}



int q2_1_1(void) {
	int num1 = 0;
	increase(num1);
	std::cout << num1 << std::endl;
	increase(num1);
	std::cout << num1 << std::endl;
	change(num1);
	std::cout << num1 << std::endl;
	return 0;
}

void swap2(int *num1, int *num2) {
	int temp;
	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

int q2_1_3(void) {
	int num1 = 5;
	int *ptr1 = &num1;
	int num2 = 10;
	int *ptr2 = &num2;
	//std::cout << *ptr1;
	swap2(ptr1, ptr2);
	std::cout << *ptr1 << " " << *ptr2;
	return 0;
}

int q2_2_1(void) {
	const int num = 12;
	const int *ptr = &num;
	const int &ref = *ptr;

	std::cout << num << ' ' << *ptr << ' ' << ref;

	return 0;
}

typedef struct __point {
	int xpos;
	int ypos;
} Point;

Point& Adder(const Point &p1, const Point &p2) {
	Point *temp = new Point;
	temp->xpos = p1.xpos + p2.xpos;
	temp->ypos = p1.ypos + p2.ypos;
	return *temp;
}

int q2_3_1(void) {
	Point p1, p2;
	p1.xpos = 3;
	p1.ypos = 4;
	p2.xpos = 5;
	p2.ypos = 6;
	Point &ref = Adder(p1, p2);
	std::cout << ref.xpos << ' ' << ref.ypos;

	return 0;
}

int q2_4_1(void) {
	char str[30] = "ABCDEFGH";
	std::cout << strlen(str) << std::endl;
	strcat_s(str, "호우호우");
	std::cout << str << std::endl;
	char str2[30];
	strcpy_s(str2, str);
	std::cout << str2 << std::endl;
	std::cout << strcmp(str, str2) << std::endl;
	return 0;
}

int q2_4_2(void) {
	srand(time(NULL));
	for (int i = 0; i < 5; i++) {
		std::cout << rand() % 100 << ' ';
	}

	return 0;
}

int ch_2_cpp(void) {
	//q2_1_1();
	//q2_1_3();
	//q2_2_1();
	//q2_3_1();
	//q2_4_1();
	q2_4_2();
	return 0;
}