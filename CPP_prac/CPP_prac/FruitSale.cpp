#include <iostream>
#include "FruitSale.h"

bool FruitSeller::InitMembers(const int price, int num, int money) {
	if (price < 0 || num < 0 || money < 0)
		return false;
	APPLE_PRICE = price;
	numOfApples = num;
	myMoney = money;
	return true;
}

int FruitSeller::SaleApples(int money) {
	int num = money / APPLE_PRICE;
	numOfApples -= num;
	myMoney += money;
	return num;
}

void FruitSeller::ShowSalesResult() const {
	std::cout << "남은 사과: " << numOfApples << std::endl;
	std::cout << "판매 수익: " << myMoney << std::endl;
}

bool FruitBuyer::InitMembers(int money) {
	if (money < 0)
		return false;
	myMoney = money;
	numOfApples = 0;
}

void FruitBuyer::BuyApples(FruitSeller &seller, int money) {
	numOfApples += seller.SaleApples(money);
	myMoney = money;
}

void FruitBuyer::ShowBuyResult() const {
	std::cout << "현재 잔액: " << myMoney << std::endl;
	std::cout << "사과 개수: " << numOfApples << std::endl;
}