#include <iostream>
#include <assert.h>

#define MAX_GARLAND 4

using namespace std;

class lamp {
protected:
	int state;
public:
	lamp() : state(1) {}

	void set(int value) {
		state = value;
	}

	int get() {
		return state;
	}
};

class colorlamp {
	int state, color;
public:
	colorlamp() : state(1), color(2) {}
};

class cola : public lamp {
protected:
	int color;
public:

	cola() : color(2) {}

	int getc() {
		return color;
	}

	void setc(int value) {
		color = value;
	}

	//void set(int value) {
	//	lamp::set(value);
	//}

	//int get() {
	//	return lamp::get();
	//}

};

class garland {
	lamp* g[MAX_GARLAND];
	int count;
public:
	garland() {
		count = 0;
	}

	void add(lamp* a) {
		assert(count < MAX_GARLAND);
		g[count++] = a;
	}

	void set(int value) {
		for (int i = 0; i < MAX_GARLAND; i++) {
			g[i]->set(value);
		}
	}

	void show() {
		for (int i = 0; i < MAX_GARLAND; i++) {
			cout << "" << g[i]->get() << " ";
		}
		cout << endl;
	}
};

class micola : public lamp, public cola {


};

int main() {

	lamp a;
	colorlamp b;
	cola c;


	//// Жульнический код (физическое устройство объектов не отличается)
	//cout << sizeof(b) << endl;
	//cout << *((int*)&b + 0) << endl;
	//cout << *((int*)&b + 1) << endl;
	//cout << sizeof(c) << endl;
	//cout << *((int*)&c + 0) << endl;
	//cout << *((int*)&c + 1) << endl;

	//cout << "c.get = " << c.get() << endl;
	//c.set(0);
	//cout << "c.get = " << c.get() << endl;
	//cout << "a.get = " << a.get() << endl;
	//a.set(0);
	//cout << "a.get = " << a.get() << endl;

	//lamp* g[] = { &c, &a };
	//g[0]->set(5);
	//g[1]->set(6);
	//cout << "g[0]->get=" << g[0]->get() << endl;
	//cout << "g[1]->get=" << g[1]->get() << endl;

	//garland g;
	//lamp a1;
	//lamp a2;
	//cola a3;
	//cola a4;
	//g.add(&a1);
	//g.add(&a2);
	//g.add(&a3);
	//g.add(&a4);
	//g.set(0);
	//g.show();
	//g.set(1);
	//g.show();

	//micola m;
	//m.setc(7);

	//lamp* x = new cola;
	//cola* y = (cola*)x;
	//y->setc(3);

	lamp* x = new lamp;
	cola* y = (cola*)x;
	int z = y->getc();

}
