#include <iostream>
#include "Calculator.h"

void Calculator::Init(void) {
	add = 0;
	divide = 0;
	minus = 0;
	product = 0;
}

void Calculator::ShowOpCount(void) {
	std::cout << "plus: " << add << std::endl << "minus: " << minus << std::endl << "product: " << product << std::endl << "divide: " << divide << std::endl;
}