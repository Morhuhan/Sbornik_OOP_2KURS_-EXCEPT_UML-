#include <iostream>
#include <string>

using namespace std;

class Natural {
private:
    unsigned int value; // значение числа
public:
    // конструктор без параметров
    Natural() : value(0) {}

    // конструктор с параметром
    Natural(unsigned int n) : value(n) {}

    // конструктор с параметром - строкой
    Natural(std::string str) {
        // преобразуем строку в число
        unsigned int n = std::stoi(str);
        // проверяем, что число является натуральным
        if (n < 0) {
            exit(1);
        }
        // присваиваем значение числа
        value = n;
    }

    // конструктор копий
    Natural(const Natural& other) {
        value = other.value;
    }

    // метод для получения значения числа
    unsigned int get_value() const {
        return value;
    }

    // метод для установки значения числа
    void set_value(unsigned int n) {
        value = n;
    }

    // метод для вывода числа на экран
    void print() const {
        std::cout << value << std::endl;
    }

    // Перегрузка оператора присваивания
    Natural& operator=(const Natural& other) {
        if (this != &other) {
            value = other.value;
        }
        return *this;
    }

    // Оператор приведения к типу int
    operator int() const {
        return static_cast<int>(value);
    }

    // перегрузка оператора приведения типа std::string
    operator std::string() const {
        return std::to_string(value);
    }

    // Оператор приведения к типу double
    operator double() const {
        return static_cast<double>(value);
    }

    // перегрузка оператора сложения
    Natural operator+(const Natural& other) const {
        return Natural(value + other.value);
    }

    Natural operator+(unsigned int n) const {
        return Natural(value + n);
    }

    friend Natural operator+(unsigned int n, const Natural& num) {
        return num + n;
    }

    // перегрузка оператора вычитания
    Natural operator-(const Natural& other) const {
        if (value < other.value) {
            exit(1); 
        }
        return Natural(value - other.value);
    }

    Natural operator-(unsigned int n) const {
        if (value < n) {
            exit(1); 
        }
        return Natural(value - n);
    }

    friend Natural operator-(unsigned int n, const Natural& num) {
        if (num.value < n) {
            exit(1); 
        }
        return Natural(n - num.value);
    }

    // перегрузка оператора умножения
    Natural operator*(const Natural& other) const {
        return Natural(value * other.value);
    }

    Natural operator*(unsigned int n) const {
        return Natural(value * n);
    }

    friend Natural operator*(unsigned int n, const Natural& num) {
        return num * n;
    }

    // перегрузка оператора деления
    Natural operator/(const Natural& other) const {
        if (other.value == 0) {
            exit(1); 
        }
        return Natural(value / other.value);
    }

    Natural operator/(unsigned int n) const {
        if (n == 0) {
            exit(1); 
        }
        return Natural(value / n);
    }

    friend Natural operator/(unsigned int n, const Natural& num) {
        if (num.value == 0) {
            exit(1); 
        }
        return Natural(n / num.value);
    }

    // перегрузка оператора остатка от деления
    Natural operator%(const Natural& other) const {
        if (other.value == 0) {
            exit(1); 
        }
        return Natural(value % other.value);
    }

    Natural operator%(unsigned int n) const {
        if (n == 0) {
            exit(1); 
        }
        return Natural(value % n);
    }

    friend Natural operator%(unsigned int n, const Natural& num) {
        if (num.value == 0) {
            exit(1); 
        }
        return Natural(n % num.value);
    }
    



};



int main() {

    Natural n1;
    Natural n2;

    // Тест конструктора строки
    n1 = (std::string)"123";
    n1.print();
    printf("---------------------\n");

    // Тест конструктора копии
    n1 = 123;
    n2 = n1; // создаем копию объекта n1
    n1.set_value(n1.get_value() + 1); // увеличиваем n1 на 1
    n1.print(); // 124
    n2.print(); // 123 - копия n1
    printf("---------------------\n");

    // Тест оператора присваивания
    n1 = 123;
    n2 = 456;
    n2 = n1; // присваиваем значение n1 объекту n2
    n1.set_value(n1.get_value() + 1); // увеличиваем n1 на 1
    n1.print(); // 124
    n2.print(); // 123 - значение было скопировано из n1 в n2
    printf("---------------------\n");

    // Тест операторов приведения
    int result1 = n2;
    printf("%d\n", result1); // выводим результат на экран

    n1 = 123;
    std::string result2 = n1; // приводим n1 к типу std::string
    printf("%s\n", result2.c_str()); // выводим результат на экран

    n1 = 123;
    double result3 = n1; // приводим n1 к типу double
    printf("%f\n", result3);
    printf("---------------------\n");

    // Тест перегрузки арифметических операций + - * / % 
    n1 = 10;
    n2 =5;
    Natural n3;

    n3 = n1 + n2;
    cout << "n1 + n2 = " << n3.get_value() << endl;

    n3 = n1 - n2;
    cout << "n1 - n2 = " << n3.get_value() << endl;

    n3 = n1 * n2;
    cout << "n1 * n2 = " << n3.get_value() << endl;

    n3 = n1 / n2;
    cout << "n1 / n2 = " << n3.get_value() << endl;

    n3 = n1 % n2;
    cout << "n1 % n2 = " << n3.get_value() << endl;

    n3 = n1.operator+(5);
    cout << "n1 + 5 = " << n3.get_value() << endl;
    printf("---------------------\n");


    // Тест одноместного оператора вычитания


    printf("---------------------\n");



}