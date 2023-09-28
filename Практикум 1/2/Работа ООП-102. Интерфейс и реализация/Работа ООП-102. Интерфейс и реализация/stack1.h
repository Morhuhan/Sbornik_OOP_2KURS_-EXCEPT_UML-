#pragma once
#include <assert.h>
#define MAX_STACK_SIZE 10

class stack {

	// ������ �����
	int st[MAX_STACK_SIZE];

	// ������� ���������
	int size;

public:

	stack();

	// �������������
	void push(int element);

	// ������������
	int pop();

	// ������� �� �������
	int top();

	// ���������� ���������
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

	// ���� �������� ������� ������, ��� ������������� ��������� � ����������� �� ����� ����, ��� ����� ������� ��������� �� �������
	assert(size > 0);

	return st[--size];
}

int stack::top() {
	assert(size > 0);
	return st[size - 1];
}