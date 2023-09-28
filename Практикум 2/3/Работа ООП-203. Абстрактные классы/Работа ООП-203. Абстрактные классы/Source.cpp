#include <iostream>
#include <assert.h>
//#define BASECLASS figure
#define BASECLASS linkable

// Интерфейс связываемых объектов
class linkable {
public: 
	virtual void set_next(linkable*) = 0;
	virtual linkable* get_next(void) = 0;
};

// Интерфейс рисуемых объектов
class drawable {
public:
		virtual void draw(void) = 0;
};

// Интерфейс перемещаемых объектов
class moveable {
public:
	virtual void move(int a, int b) = 0;
};




class figure : public drawable, public linkable, public moveable {

public: 
	int x, y;
	figure* next;
	
	figure(int a, int b) : next(0), x(a), y(b) {}

	// Чистая виртуальная функция
	virtual void draw(void) = 0;

	virtual void locatin(void) {
		printf("(%d, %d)", x, y);
	}

	int getX() { return x; }

	int getY() { return y; }

	void move(int a, int b) {
		x = a;
		y = b;
	}

	void set_next(linkable* a) {
		next = static_cast<figure*>(a);
	}

	linkable* get_next(void) {
		return static_cast<linkable*>(next);
	}
};

class circle : public figure {
public:

	void draw(void) {
		printf("(%d, %d) circle\n", x, y);
	}

	// Если базовый класс не определяет конструктор по умолчанию - производный класс обязан иметь конструктор, который вызывает конструктор базового класса
	circle(int a = 0, int b = 0) : figure(a,b) {}
};

class square : public figure {
public:

	void draw(void) {
		printf("(%d, %d) square\n", x, y);
	}

	// Если базовый класс не определяет конструктор по умолчанию - производный класс обязан иметь конструктор, который вызывает конструктор базового класса
	square(int a = 0, int b = 0) : figure(a, b) {}
};


class paintapp {
	BASECLASS* first;

public:
	paintapp() : first(0) {}

	//~paintapp() {
	//	BASECLASS* temp = first;
	//	while (temp) {
	//		BASECLASS* next = temp->get_next();
	//		delete temp;
	//		temp = next;
	//	}
	//}

	void add(BASECLASS* ob) {

		assert(dynamic_cast<drawable*>(ob));

		if (first == 0) {
			first = ob;
		}
		else {
			BASECLASS* temp = first;
			while (temp->get_next()) {
				temp = temp->get_next();
			}
			temp->set_next(ob);
		}
	}

	void draw(void) {
		BASECLASS* temp = first;
		while (temp) {
			dynamic_cast<drawable*>(temp)->draw();
			temp = temp->get_next();
		}
	}

	BASECLASS* item(int index) {
		index = abs(index);
		assert(first != NULL);
		BASECLASS* temp = first;
		while (temp) {
			if (--index == 0) return temp;
			temp->get_next();
		}
		int index_overflow = 0;
		assert(index_overflow);
	}
};


struct text: public drawable, public linkable {
	
	linkable* next;
	
	text() : next(0) {}

	void set_next(linkable* a) {
		next = a;
	}

	linkable* get_next(void) {
		return next;
	}

	void draw(void) {
		printf("text\n");
	}

};


int main(void) {
	paintapp app;
	app.add(new circle(1, 1));
	app.add(new square(2, 2));

	moveable* m = dynamic_cast<moveable*>(app.item(2));

	if (m) m->move(3, 3);

	app.add(new text());

	app.draw();
}