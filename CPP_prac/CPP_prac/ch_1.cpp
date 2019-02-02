#include <iostream>
#include "ch1_test.h"

int q1_1_1(void) {
	int num[5];
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		std::cout << i+1 << "번째 정수 입력: " << ' ';
		std::cin >> num[i];
		sum += num[i];
	}
	std::cout << sum << std::endl;
	return 0;
}

int q1_1_2(void) {
	char name[100];
	char phone[100];
	std::cout << "이름은: ";
	std::cin >> name;
	std::cout << "번호는: ";
	std::cin >> phone;
	std::cout << "이름: " << name << std::endl;
	std::cout << "번호: " << phone << std::endl;
	return 0;
}

int q1_1_3(void) {
	int num;
	std::cin >> num;
	for (int i = 1; i <= 9; i++) {
		std::cout << num << " X " << i << " = " << num * i << std::endl;
	}


	return 0;
}

int q1_1_4(void) {
	int num;
	int incentive;
	while (-1) {
		std::cout << "판매 금액을 만원 단위로 입력(-1 to end): ";
		std::cin >> num;
		if (num == -1) {
			std::cout << "프로그램 종료" << std::endl;
			break;
		}
		incentive = num * 0.12;
		std::cout << "이번 달 급여: " << incentive + 50 << "만원" << std::endl;
	}
	return 0;
}

void swap(int * num1, int * num2) {
	int temp;
	temp = * num1;
	* num1 = * num2;
	* num2 = temp;
}

void swap(char * num1, char * num2) {
	char temp;
	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

void swap(double * num1, double * num2) {
	double temp;
	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}



int q1_2_1(void) {
	int num1 = 20, num2 = 30;
	swap(&num1, &num2);
	std::cout << num1 << ' ' << num2 << std::endl;

	char ch1 = 'A', ch2 = 'Z';
	swap(&ch1, &ch2);
	std::cout << ch1 << ' ' << ch2 << std::endl;

	double dbl1 = 1.111, dbl2 = 5.555;
	swap(&dbl1, &dbl2);
	std::cout << dbl1 << ' ' << dbl2 << std::endl;


	return 0;
}

int BoxVolume(int length, int width, int height) {
	return length * width * height;
}
int BoxVolume(int length, int width) {
	return length * width;
}
int BoxVolume(int length) {
	return length;
}

int q1_3_1(void) {
	std::cout << "[3, 3, 3] : " << BoxVolume(3, 3, 3) << std::endl;
	std::cout << "[5, 5, D] : " << BoxVolume(5, 5) << std::endl;
	std::cout << "[7, D, D] : " << BoxVolume(7) << std::endl;
	return 0;
}

int q1_4_1(void) {
	BestCom::SimpleFunc();
	ProgCom::SimpleFunc();
	return 0;
}

int ch_1_cpp(void) {
	//q1_1_1();
	//q1_1_2();
	//q1_1_3();
	//q1_1_4();
	//q1_2_1();
	//q1_3_1();
	q1_4_1();
	return 0;
}