#ifndef __EXCEPTION_HEADER_H__
#define __EXCEPTION_HEADER_H__

class intException {
private:
	char *err;
	
public:
	intException(char ar) : err(&ar) {}
	void ShowInfo(void) const {
		std::cout << err << "은 유효하지 않습니다." << std::endl;
	}
};

class charException {
private:
	int err;

public:
	charException(int er) : err(er) {}
	void ShowInfo(void) const {
		std::cout << err << "은 유효하지 않습니다." << std::endl;
	}

};

class MinusException {
private:
	int minus;

public:
	MinusException(int val) : minus(val) {}
	void Showinfo() const {
		std::cout << minus << "은 유효하지 않습니다." << std::endl;
	}
};

class OverException {
private:
	int over;

public:
	OverException(int val) : over(val) {}
	void Showinfo() const {
		std::cout << over << "금액이 초과되었습니다." << std::endl;
	}

};








#endif