//#include <iostream>
//#include <cstring>
//
//class String {
//private:
//	int len;
//	char *str;
//
//public:
//	String() {
//		// �⺻ ������ //
//		len = 0;
//		str = NULL;
//	}
//
//	String(const char * st) {
//		// string ������ // --> ���Կ����ڸ� ����
//		len = strlen(st) + 1;
//		str = new char[len];
//		strcpy_s(str, len, st);
//	}
//
//	String(const String& ref){
//		// ��������� //
//		std::cout << "copy";
//		len = ref.len;
//		str = new char[len];
//		strcpy_s(str, len, ref.str);
//	}
//
//	String& operator=(const String& st) {
//		//���Կ�����// String str(������ ��ȯ (NULL)) = "I like it"; (���Կ����� ����) --> str.operator=("I Like it");
//		//std::cout << "=" << std::endl;
//		if (str != NULL)
//			delete[]str;
//		len = st.len;
//		//std::cout << len << std::endl;
//		//std::cout << len << std::endl;
//		//std::cout << st.str << std::endl;
//		str = new char[len];
//		strcpy_s(str, len, st.str);
//		return *this;
//	}
//
//	String& operator+(const String& st) {
//		// + ������ --> str1.operator+(str2) //
//		char *temp = new char[len + st.len -1];
//		strcpy_s(temp, len + st.len-1, str);
//		strcat_s(temp, len + st.len-1, st.str);
//		str = temp;
//		len += st.len - 1;
//		return *this;
//	}
//
//	String& operator+=(const String& st) {
//		// += ������ -> str1 += str3 --> str1.operator+=(str3);
//		len += (st.len - 1);
//		char * temp = new char[len];
//		strcpy_s(temp, len, str);
//		strcat_s(temp, len , st.str);
//		str = temp;
//		return *this;
//	}
//
//	bool operator==(const String& st1) {
//		if (strcmp(str, st1.str))
//			return true;
//		else
//			return false;
//	}
//
//	~String() {
//		//�����Ҵ� �Ҹ���//
//		if(str!= NULL)
//			delete[]str;
//	}
//
//	friend std::ostream& operator<< (std::ostream& os, const String& st);
//	friend std::istream& operator>> (std::istream& is, const String& st);
//};
//
//std::ostream& operator<< (std::ostream& os, const String& st) {
//	os << st.str;
//	return os;
//}
//
//std::istream& operator>> (std::istream& is, String& st) {
//	char str[100];
//	is >> str;
//	st = String(str);
//	return is;
//}
//
//
//int ch_12_cpp(void) {
//	String str1 = "I Like ";
//	std::cout << str1 << std::endl;
//
//	String str2 = "string class";
//	std::cout << str2 << std::endl;
//
//	String str3;
//	str3 = str1 + str2;
//	std::cout << str3 << std::endl;
//
//	str1 += str2;
//	if (str1 == str3)
//		std::cout << "same" << std::endl;
//	else
//		std::cout << "different" << std::endl;
//
//	String str4;
//	std::cout << "input: ";
//	std::cin >> str4;
//	std::cout << "�Է� ���ڿ�: " << str4 << std::endl;
//	return 0;
//}