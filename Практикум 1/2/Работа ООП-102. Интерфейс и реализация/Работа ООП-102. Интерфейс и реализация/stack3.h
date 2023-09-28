#pragma once
#include <assert.h>
#define MAX_STACK_SIZE 10

class stack {

    struct stack_el {
        int value;
        stack_el* next;
        stack_el(int element) : value(element), next(0) {}
    };

    stack_el* home;
    int size;

public:

    // ��������� ������������ ��������
    static const int SUCCESS = 1;
    static const int STACK_OVERFLOW = -1;
    static const int STACK_UNDERFLOW = -2;

    stack();

    // �������������
    int push(int element);

    // ������������
    int pop(int& element);

    // ������� �� �������
    int top(int& element);

    // �������� ������� ��������� � �����
    int stack_empty();
};

stack::stack() {
    home = 0;
    size = 0;
}

int stack::stack_empty() {
    // ���� ����, ���� home ����� 0
    return home == 0;
}

int stack::push(int element) {
    // ���������, �� ���������� �� ����
    if (size >= MAX_STACK_SIZE) {
        return STACK_OVERFLOW;
    }

    // ������� ����� ������� �����
    stack_el* new_el = new stack_el(element);
    // ����� ������� ���������� ��������
    new_el->next = home;
    home = new_el;
    size++;
    return SUCCESS;
}

int stack::pop(int& element) {
    // ���������, �� ���� �� ����
    if (home == 0) {
        return STACK_UNDERFLOW;
    }

    // �������� �������� �������� �� ������� �����
    element = home->value;
    // ������� ������� �� ������� �����
    stack_el* to_delete = home;
    home = home->next;
    delete to_delete;
    size--;
    return SUCCESS;
}

int stack::top(int& element) {
    // ���������, �� ���� �� ����
    if (home == 0) {
        return STACK_UNDERFLOW;
    }

    // �������� �������� �������� �� ������� �����
    element = home->value;
    return SUCCESS;
}