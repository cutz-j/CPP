#ifndef __BOUND_CHECK_ARR_H__
#define __BOUND_CHECK_ARR_H__

#include "Account.h"

template <class C>
class BoundCheckAcc {
private:
	C *arr;
	int arrlen;
	BoundCheckAcc(const BoundCheckAcc& arr) { }
	BoundCheckAcc& operator=(const BoundCheckAcc& arr) { }

public:
	BoundCheckAcc(int len = 100);

	C& operator[] (int idx);

	C operator[] (int idx) const;

	int GetArrLen() const;

	~BoundCheckAcc();
};

template <class C>
BoundCheckAcc<C>::BoundCheckAcc(int len) : arrlen(len) {
	arr = new C[len];
}

template <class C>
C& BoundCheckAcc<C>::operator[] (int idx) {
	if (idx < 0 || idx >= arrlen)
		exit(1);
	return arr[idx];
}

template <class C>
C BoundCheckAcc<C>::operator[] (int idx) const {
	if (idx < 0 || idx >= arrlen)
		exit(1);
	return arr[idx];
}

template <class C>
int BoundCheckAcc<C>::GetArrLen() const {
	return arrlen;
}

template <class C>
BoundCheckAcc<C>::~BoundCheckAcc() {
	delete[]arr;
}

#endif