#ifndef __FRUITSALE_H__
#define __FRUITSALE_H__

class FruitSeller {
private:
	int APPLE_PRICE;
	int numOfApples;
	int myMoney;

public:
	bool InitMembers(const int price, int num, int money);
	int SaleApples(int money);
	void ShowSalesResult() const;
};

class FruitBuyer {
private:
	int myMoney;
	int numOfApples;
public:
	bool InitMembers(int money);
	void BuyApples(FruitSeller &seller, int money);
	void ShowBuyResult() const;
};




#endif