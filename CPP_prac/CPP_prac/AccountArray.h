#ifndef __ACCOUNT_ARRAY_H__
#define __ACCOUNT_ARRAY_H__

#include "Account.h"

class BoundCheckAcc {
private:
	Account **arr;
	int arrlen;
	BoundCheckAcc(const BoundCheckAcc& arr) { }
	BoundCheckAcc& operator=(const BoundCheckAcc& arr) { }

public:
	BoundCheckAcc(int len=100);

	Account*& operator[] (int idx);

	Account* operator[] (int idx) const;

	int GetArrLen() const;

	~BoundCheckAcc();
};


#endif