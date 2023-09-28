#pragma once
#include <assert.h>
#define MAX_STACK_SIZE 10

class stack {

	// Массив стека
	int st[MAX_STACK_SIZE];

	// Счетчик элементов
	int size;

public:

	stack();

	// Проталкивание
	void push(int element);

	// Выталкивание
	int pop();

	// Элемент на вершине
	int top();

	// Количество элементов
	int count();

};

stack::stack() {
	size = 0;
}


int stack::count() {
	return size;
}

void stack::push(int element) {
	assert(size < MAX_STACK_SIZE);
	st[size++] = element;
}

int stack::pop() {

	// Если аргумент функции ложный, она останавливает программу и выбрасывает ее после того, как будет закрыто сообщение об условии
	assert(size > 0);

	return st[--size];
}

int stack::top() {
	assert(size > 0);
	return st[size - 1];
}