#include <iostream>
#include "class.h"

using namespace std;

class lamp {
	static int counter;
public:
	int id;

	// Конструктор по умолчанию
	lamp() {
		id = ++counter;
	}

	// Устанавливает статический счетчик
	static void put_counter(int newvalue) {
		counter = newvalue;
	}

	// Возвращает статический счетчик
	static int get_counter(void) {
		return counter;
	}

	// Изменяет идентификатор объекта
	static void change_id(lamp& o, int newvalue) {
		o.id = newvalue;
	}

};

int lamp::counter = 0;



int main(int) {

	//cout << "lamp::counter = " << lamp::counter << endl;
	//lamp::counter = 1;
	//lamp x;
	//cout << "x.counter = " << x.counter << endl;

	//lamp a, b, c;
	//cout << "a.id = " << a.id << endl;
	//cout << "b.id = " << b.id << endl;
	//cout << "c.id = " << c.id << endl;
	//cout << "lamp::get_counter = " << lamp::get_counter() << endl;
	//cout << "a.get_counter = " << a.get_counter() << endl;
	//lamp::put_counter(5);
	//cout << "lamp::get_counter = " << lamp::get_counter() << endl;
	//a.put_counter(10);
	//cout << "a.get_counter = " << a.get_counter() << endl;
	//lamp::change_id(a, 22);
	//cout << "a.id = " << a.id << endl;

	//int arr[] = { 5, 2, 3, 4, 1 };
	//util::sort(arr, sizeof(arr) / sizeof(int));
	//util::reverse(arr, sizeof(arr) / sizeof(int));
	//util::print(arr, sizeof(arr) / sizeof(int));



}