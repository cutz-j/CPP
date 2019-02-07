#include <iostream>
#include <cstring>

class Calculator {
private:
	int add;
	int minus;
	int product;
	int divide;

public:
	void Init();
	void ShowOpCount();
	float Add(float a, float b);
	float Div(float a, float b);
	float Min(float a, float b);
	float Pro(float a, float b);
};

inline float Calculator::Add(float a, float b) {
	add += 1;
	return a + b;
}

inline float Calculator::Div(float a, float b) {
	divide += 1;
	return a / b;
}

inline float Calculator::Min(float a, float b) {
	minus += 1;
	return a - b;
}

inline float Calculator::Pro(float a, float b) {
	product += 1;
	return a * b;
}