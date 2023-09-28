#include <iostream>
#include <conio.h>

using namespace std;

// Предварительное объявление класса
class garland;

// Сильная инкапсуляция
class lamp {

	// Я разрешаю этому классу всё
	friend garland;

	// Я разрешаю этим функциям всё
	friend void turn_on_lamp(lamp& a);
	friend void turn_off_lamp(lamp& a);

	int state;

public:
	lamp() {
		state = 0;
	}

	int is_off() {
		if (state == 0) {
			return 1;
		}
		else {
			return 0;
		}
	}

	int is_on() {
		if (state == 0) {
			return 0;
		}
		else {
			return 1;
		}
	}
};


#define MAX_GARLAND 8
class garland {

	// Лампочки гирлянды
	lamp L[MAX_GARLAND];

public:

	void print_garland_4_column() {
		for (int i = 0; i < MAX_GARLAND; i++) {
			cout << "" << L[i].state << "" << L[i].state << "" << L[i].state << "" << L[i].state << endl;
		}
	}

	//void on() {
	//	for (int i = 0; i < MAX_GARLAND; i++) {
	//		L[i].state = 1;
	//		cout << "" << L[i].state << endl;
	//	}
	//}

	void on() {

		char stop = 0;
		char input[2];
		int i = 0;

		while (stop != '0') {

			L[i].state = 1;
			print_garland_4_column();
			L[i].state = 0;
			i++;

			if (i == MAX_GARLAND) {
				i = 0;
			}

			L[i].state = 1;
			print_garland_4_column();

			if (_kbhit()) {
				stop = getchar(); 
			}
		}
	}

	void off() {}
};


class rat {

	friend rat operator+(rat a, rat b);
	friend rat operator-(rat a, rat b);

	int num;
	int den;

public:

	rat() {
		num = 0;
		den = 1;
	}

	rat(int n, int d) {
		num = n;
		den = d < 1 ? 1 : d;
	}

	// Конструктор приведения
	rat(int n) {
		num = n;
		den = 1;
	}

	void print_rat() {
		cout << "num = " << num << endl;
		cout << "den = " << den << endl;
	}

	rat cancel() {
		int a = abs(num), b = abs(den);
		while (b) { b ^= a ^= b ^= a %= b; }
		num /= a;
		den /= a;
		return *this;
	}


};


struct RAT { int num, den; };


class Counter {
private:
	int value;
	int modulus;

	Counter(int start, int mod) : value(start), modulus(mod) {}

	int getNextValue() {
		value = (value + 1) % modulus;
		return value;
	}

	friend int getNextCounterValue(Counter& counter);

public:
	static Counter create(int start, int mod) {
		return Counter(start, mod);
	}
};

int getNextCounterValue(Counter& counter) {
	return counter.getNextValue();
}

// Сложение рац чисел
rat operator+ (rat a, rat b) {
	return rat(a.num * b.den + b.num * a.den, a.den * b.den).cancel();
}

rat operator- (rat a, rat b) {
	return rat(a.num * b.den - b.num * a.den, a.den * b.den).cancel();
}


void turn_on_lamp(lamp& a) {
	a.state = 1;
}

void turn_off_lamp(lamp& a) {
	a.state = 0;
}





int main() {

	//lamp a;
	//*(int*)&a = 9;
	//cout << "on = " << a.is_on() << endl;
	//cout << "off = " << a.is_off() << endl;

	//rat x;
	//RAT* X = (RAT*)&x;
	//(*X).num = 909;
	//x.print_rat();

	//lamp a;
	//turn_on_lamp(a);
	//cout << "on = " << a.is_on() << endl;
	//cout << "off = " << a.is_off() << endl;
	//turn_off_lamp(a);
	//cout << "on = " << a.is_on() << endl;
	//cout << "off = " << a.is_off() << endl;

	//rat a, b(122, 3), c(2, 3);
	//a = b + c;
	//a.print_rat();

	//rat a, b(122, 32), c(2, 3);
	//a = b - c;
	//a.print_rat();

	//rat a, b(1, 32), c(2, 3);
	//a = b - 1;
	//a.print_rat();
	//a = 1 + b;
	//a.print_rat();
	//a = 1 - b;
	//a.print_rat();

	//garland L;
	//L.on();

	Counter counter = Counter::create(0, 5);

	for (int i = 0; i < 10; i++) {
		int nextValue = getNextCounterValue(counter);
		cout << nextValue << endl;
	}

}