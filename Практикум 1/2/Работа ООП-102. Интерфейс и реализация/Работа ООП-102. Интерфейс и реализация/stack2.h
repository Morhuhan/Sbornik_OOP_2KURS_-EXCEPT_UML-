#pragma once
#include <assert.h>
#define MAX_STACK_SIZE 10

class stack {

	struct stack_el {

		// �������� ��������
		int value;

		// ��������� �� ��������� �������
		stack_el* next;

		// �����������
		stack_el(int element) : value(element), next(0) {}

	};

	stack_el* home;

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
	int stack_empty();

};

stack::stack() {
	home = 0;
	size = 0;
}


// ���������� 1 ���� ���� ����
int stack::stack_empty() {
	return(home == 0);
}

void stack::push(int element) {
	stack_el* e;
	e = new stack_el(element);
	assert(e);
	if (stack_empty() != 1) e->next = home;
	home = e;
	size++;
}

int stack::pop() {
	assert(stack_empty() == 1);
	int value = home->value;
	stack_el* e = home;
	home = home->next;
	delete e;
	size--;
	return value;
}

int stack::top() {
	assert(size > 0);
	return home->value;
}