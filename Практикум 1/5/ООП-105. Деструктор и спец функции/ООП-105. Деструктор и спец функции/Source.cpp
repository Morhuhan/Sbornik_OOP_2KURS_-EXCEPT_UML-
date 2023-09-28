#define _CRT_SECURE_NO_WARNINGS


#include <iostream>




class string {

	// Запрет операции присваивания для string
	string operator=(string& s);

public:
	char* p;

	// Конструктор приведения
	string(const char* s) {
		int n = strlen(s);
		p = new char[1 + n];
		strcpy(p, s);
	}

	// Деструктор
	~string() {
		delete[] p;
	}

	// Метод, возвращающий длину строки
	static int length(const string& s) {
		int len = 0;
		while (s.p[len] != '\0') {
			len++;
		}
		return len;
	}


	// Оператор присваивания для char*
	char* operator=(const char* s) {
		delete[] p;
		int n = strlen(s);
		p = new char[1 + n];
		strcpy(p, s);
		return p;
	}

	// Конструктор копий
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

	//// Указатель p указывает на один и тот же участок памяти для a и b
	//string a(""), b("abc");
	//a = b;
	//strcpy(b.p, "xyz");

	//char* pa = 0, * pb = 0;
	//// Локальная зона видимости, при выходе из которой a и b уничтожаются
	//{
	//	string a("123"), b("abc");
	//	pa = a.p;
	//	pb = b.p;
	//	a = b;
	//	strcpy(a.p, "---");
	//	strcpy(b.p, "xyz");
	//}
	//// При выходе из зоны видимости, pa и pb до сих пор указывают на выделенные области памяти
	//std::cout << pa << std::endl;
	//std::cout << pb << std::endl;

	//string a("123"), b("abc"), c("xyz");
	//c = a = b = "---";

	// Деструктор уничтожает объект при копировании, поэтому нужен конструктор копий
	string a("123");
	string b = a;
	foo(a);
	//b = get();
}