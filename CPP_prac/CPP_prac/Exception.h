#ifndef __EXCEPTION_HEADER_H__
#define __EXCEPTION_HEADER_H__

class intException {
private:
	char *err;
	
public:
	intException(char ar) : err(&ar) {}
	void ShowInfo(void) const {
		std::cout << err << "�� ��ȿ���� �ʽ��ϴ�." << std::endl;
	}
};

class charException {
private:
	int err;

public:
	charException(int er) : err(er) {}
	void ShowInfo(void) const {
		std::cout << err << "�� ��ȿ���� �ʽ��ϴ�." << std::endl;
	}

};

class MinusException {
private:
	int minus;

public:
	MinusException(int val) : minus(val) {}
	void Showinfo() const {
		std::cout << minus << "�� ��ȿ���� �ʽ��ϴ�." << std::endl;
	}
};

class OverException {
private:
	int over;

public:
	OverException(int val) : over(val) {}
	void Showinfo() const {
		std::cout << over << "�ݾ��� �ʰ��Ǿ����ϴ�." << std::endl;
	}

};








#endif