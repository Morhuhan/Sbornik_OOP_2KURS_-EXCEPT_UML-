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

    // Константы возвращаемых значений
    static const int SUCCESS = 1;
    static const int STACK_OVERFLOW = -1;
    static const int STACK_UNDERFLOW = -2;

    stack();

    // Проталкивание
    int push(int element);

    // Выталкивание
    int pop(int& element);

    // Элемент на вершине
    int top(int& element);

    // Проверка наличия элементов в стеке
    int stack_empty();
};

stack::stack() {
    home = 0;
    size = 0;
}

int stack::stack_empty() {
    // Стек пуст, если home равен 0
    return home == 0;
}

int stack::push(int element) {
    // Проверяем, не переполнен ли стек
    if (size >= MAX_STACK_SIZE) {
        return STACK_OVERFLOW;
    }

    // Создаем новый элемент стека
    stack_el* new_el = new stack_el(element);
    // Новый элемент становится домашним
    new_el->next = home;
    home = new_el;
    size++;
    return SUCCESS;
}

int stack::pop(int& element) {
    // Проверяем, не пуст ли стек
    if (home == 0) {
        return STACK_UNDERFLOW;
    }

    // Получаем значение элемента на вершине стека
    element = home->value;
    // Удаляем элемент на вершине стека
    stack_el* to_delete = home;
    home = home->next;
    delete to_delete;
    size--;
    return SUCCESS;
}

int stack::top(int& element) {
    // Проверяем, не пуст ли стек
    if (home == 0) {
        return STACK_UNDERFLOW;
    }

    // Получаем значение элемента на вершине стека
    element = home->value;
    return SUCCESS;
}