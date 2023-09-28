#pragma once
#include <iostream>
#include <assert.h>

#define MAX_OBJECT 4

struct point {
	int x, y;
	point() : x(0), y(0) {}
};

class figure {
	point tl;
public:
	virtual void draw(void) {
		printf("figure(%d %d)\n", tl.x, tl.y);
	}

	virtual void location(void) {
		printf("(%d %d)\n", tl.x, tl.y);
	}

	int getX(void) {
		return tl.x;
	}
};

// Кружочек
class circle : public figure {
protected:
	point tl;
public:
	// Конструктор
	circle() {}

	// Рисует объект
	void draw(void) {
		printf("circle(%d %d)\n", tl.x, tl.y);
	}

	int getY(void) {
		return tl.y;
	}
};


// Квадратик
class square : public figure {
protected:
	point tl;
public:
	// Конструктор
	square() {}
	// Рисует объект
	void draw(void) {
		printf("square(%d %d)\n", tl.x, tl.y);
	}
};


class paintapp {
	int count;
	figure* g[MAX_OBJECT];
	int t[MAX_OBJECT];
public:
	// Конструктор
	paintapp() : count(0) {}

	void add(figure* a) {
		assert(count < MAX_OBJECT);
		g[count++] = a;
	}

	void draw(void) {
		for (int i = 0; i < count; i++) {
			g[i]->draw();
		}
	}

	// Добавляет кружочек
	void add_c(circle* a) {
		assert(count < MAX_OBJECT);
		t[count] = 1;
		g[count] = a;
		count++;
	}

	// Добавляет квадратик
	void add_s(square* a) {
		assert(count < MAX_OBJECT);
		t[count] = 2;
		g[count] = a;
		count++;
	}

	// Рисует, выясняя тип объекта
	void drawt(void) {
		for (int i = 0; i < count; i++) {
			if (t[i] == 1) {
				(((circle*)g[i])->draw());
			}
			else if (t[i] == 2) {
				(((square*)g[i])->draw());
			}
			else {
				(((figure*)g[i])->draw());
			}

		}
	}

	// Рисует, используя RTTI
	void drawrtti(void) {
		for (int i = 0; i < count; i++) {
			circle* a = dynamic_cast<circle*>(g[i]);

			if (a) {
				a->draw();
				continue;
			}

			square* b = dynamic_cast<square*>(g[i]);

			if (b) {
				b->draw();
				continue;
			}
		}
	}
};

struct A {
	void am() {}
	virtual void am2() {}
	virtual void am3() {}
};

struct B : public A{
	void am1() {}
	virtual void am2() {}
};

struct C : public A {
	virtual void am2() {}
	virtual void cm1() {}
};

struct D : public C {
	void am1() {}
	virtual void am3() {}
};


