#include <iostream>
#include <cstring>
#include <cstdlib>
#include "AccountArray.h"

BoundCheckAcc::BoundCheckAcc(int len): arrlen(len) {
	arr = new Account*[len];
}

Account*& BoundCheckAcc::operator[] (int idx) {
	if (idx < 0 || idx >= arrlen)
		exit(1);
	return arr[idx];
}

Account* BoundCheckAcc::operator[] (int idx) const {
	if (idx < 0 || idx >= arrlen)
		exit(1);
	return arr[idx];
}

int BoundCheckAcc::GetArrLen() const {
	return arrlen;
}

BoundCheckAcc::~BoundCheckAcc() {
	delete[]arr;
}