#include "Str.h"

Str::Str() {
	// 기본 생성자 //
	len = 0;
	str = NULL;
}

Str::Str(const char * st) {
	// string 생성자 // --> 대입연산자를 위한
	len = strlen(st) + 1;
	str = new char[len];
	strcpy_s(str, len, st);
}

Str::Str(const Str& ref){
	// 복사생성자 //
	std::cout << "copy";
	len = ref.len;
	str = new char[len];
	strcpy_s(str, len, ref.str);
}

Str& Str::operator=(const Str& st) {
	//대입연산자// String str(생성자 소환 (NULL)) = "I like it"; (대입연산자 실행) --> str.operator=("I Like it");
	//std::cout << "=" << std::endl;
	if (str != NULL)
		delete[]str;
	len = st.len;
	//std::cout << len << std::endl;
	//std::cout << len << std::endl;
	//std::cout << st.str << std::endl;
	str = new char[len];
	strcpy_s(str, len, st.str);
	return *this;
}

Str& Str::operator+(const Str& st) {
	// + 연산자 --> str1.operator+(str2) //
	char *temp = new char[len + st.len -1];
	strcpy_s(temp, len + st.len-1, str);
	strcat_s(temp, len + st.len-1, st.str);
	str = temp;
	len += st.len - 1;
	return *this;
}

Str& Str::operator+=(const Str& st) {
	// += 연산자 -> str1 += str3 --> str1.operator+=(str3);
	len += (st.len - 1);
	char * temp = new char[len];
	strcpy_s(temp, len, str);
	strcat_s(temp, len , st.str);
	str = temp;
	return *this;
}

bool Str::operator==(const Str& st1) {
	if (strcmp(str, st1.str))
		return true;
	else
		return false;
}

Str::~Str() {
	//동적할당 소멸자//
	if(str!= NULL)
		delete[]str;
}

std::ostream& operator<< (std::ostream& os, const Str& st) {
os << st.str;
return os;
}

std::istream& operator>> (std::istream& is, Str& st) {
char str[100];
is >> str;
st = Str(str);
return is;
}