#define _CRT_SECURE_NO_WARNINGS


#include <iostream>




class string {

	// ������ �������� ������������ ��� string
	string operator=(string& s);

public:
	char* p;

	// ����������� ����������
	string(const char* s) {
		int n = strlen(s);
		p = new char[1 + n];
		strcpy(p, s);
	}

	// ����������
	~string() {
		delete[] p;
	}

	// �����, ������������ ����� ������
	static int length(const string& s) {
		int len = 0;
		while (s.p[len] != '\0') {
			len++;
		}
		return len;
	}


	// �������� ������������ ��� char*
	char* operator=(const char* s) {
		delete[] p;
		int n = strlen(s);
		p = new char[1 + n];
		strcpy(p, s);
		return p;
	}

	// ����������� �����
	string(string& s) {
		int n = length(s);
		p = new char[1 + n];
		strcpy(p, s.p);
	}

};


string get() {
	string y("abc");
	return y;
}

void foo(string x) {
	x = "xyz";
}



int main(void) {

	//string a("abc");

	//// ��������� p ��������� �� ���� � ��� �� ������� ������ ��� a � b
	//string a(""), b("abc");
	//a = b;
	//strcpy(b.p, "xyz");

	//char* pa = 0, * pb = 0;
	//// ��������� ���� ���������, ��� ������ �� ������� a � b ������������
	//{
	//	string a("123"), b("abc");
	//	pa = a.p;
	//	pb = b.p;
	//	a = b;
	//	strcpy(a.p, "---");
	//	strcpy(b.p, "xyz");
	//}
	//// ��� ������ �� ���� ���������, pa � pb �� ��� ��� ��������� �� ���������� ������� ������
	//std::cout << pa << std::endl;
	//std::cout << pb << std::endl;

	//string a("123"), b("abc"), c("xyz");
	//c = a = b = "---";

	// ���������� ���������� ������ ��� �����������, ������� ����� ����������� �����
	string a("123");
	string b = a;
	foo(a);
	//b = get();
}