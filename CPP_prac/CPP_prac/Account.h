#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

class Account {
private:
	int num;
	char * name;
	int balance;

public:
	Account(int n, int b, const char *cus);

	Account(const Account &ref);

	Account& operator=(const Account& ref);

	int getNum(void) const;

	virtual void deposit(int money);

	int withdraw(int money);

	void ShowAccInfo() const;

	~Account();
};

#endif