#include <iostream>

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




int main(void) {
	//q2_1_1();
	q2_1_3();
	return 0;
}