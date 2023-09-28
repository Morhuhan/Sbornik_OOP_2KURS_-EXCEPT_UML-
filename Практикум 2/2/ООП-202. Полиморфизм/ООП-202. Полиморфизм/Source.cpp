#include <iostream>
#include "header.h"

using namespace std;


void showaddr(figure* o) {
	//Адрес объекта o
	printf("obj = 0x%p\n", o);
	//vptr - элемент 0
	int vptr = ((int*)o)[0];
	printf("vptr = 0x%p\n", vptr);
	//адрес метода 0
	int meth = ((int*)vptr)[0];
	printf("draw = 0x%p\n", meth);
}

int main() {

	//paintapp app;
	//app.add(new circle());
	//app.add(new square());

	// 16
	//cout << "sizeof(circle) = " << sizeof(circle) << endl;

	//app.draw();

	// 24
	//cout << "sizeof(circle) = " << sizeof(circle) << endl;

	//figure* f = new figure;
	//showaddr(f);
	//f = new circle;
	//showaddr(f);
	
	//figure* f = new circle;
		
	//// Раннее связывание
	//figure x = *(new circle);
	//printf("%s\n", typeid(x).name());
	//x.draw();

	//// Позднее связывание
	//figure* y = new circle;
	//printf("%s\n", typeid(*y).name());
	//y->draw();

	paintapp app;
	app.add(new square());
	app.add(new circle());
	app.add(new square());
	app.add(new circle());
	app.drawrtti();
}
