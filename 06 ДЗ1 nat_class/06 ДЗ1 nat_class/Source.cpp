#include <iostream>
#include <string>

using namespace std;

class Natural {
private:
    unsigned int value; // �������� �����
public:
    // ����������� ��� ����������
    Natural() : value(0) {}

    // ����������� � ����������
    Natural(unsigned int n) : value(n) {}

    // ����������� � ���������� - �������
    Natural(std::string str) {
        // ����������� ������ � �����
        unsigned int n = std::stoi(str);
        // ���������, ��� ����� �������� �����������
        if (n < 0) {
            exit(1);
        }
        // ����������� �������� �����
        value = n;
    }

    // ����������� �����
    Natural(const Natural& other) {
        value = other.value;
    }

    // ����� ��� ��������� �������� �����
    unsigned int get_value() const {
        return value;
    }

    // ����� ��� ��������� �������� �����
    void set_value(unsigned int n) {
        value = n;
    }

    // ����� ��� ������ ����� �� �����
    void print() const {
        std::cout << value << std::endl;
    }

    // ���������� ��������� ������������
    Natural& operator=(const Natural& other) {
        if (this != &other) {
            value = other.value;
        }
        return *this;
    }

    // �������� ���������� � ���� int
    operator int() const {
        return static_cast<int>(value);
    }

    // ���������� ��������� ���������� ���� std::string
    operator std::string() const {
        return std::to_string(value);
    }

    // �������� ���������� � ���� double
    operator double() const {
        return static_cast<double>(value);
    }

    // ���������� ��������� ��������
    Natural operator+(const Natural& other) const {
        return Natural(value + other.value);
    }

    Natural operator+(unsigned int n) const {
        return Natural(value + n);
    }

    friend Natural operator+(unsigned int n, const Natural& num) {
        return num + n;
    }

    // ���������� ��������� ���������
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

    // ���������� ��������� ���������
    Natural operator*(const Natural& other) const {
        return Natural(value * other.value);
    }

    Natural operator*(unsigned int n) const {
        return Natural(value * n);
    }

    friend Natural operator*(unsigned int n, const Natural& num) {
        return num * n;
    }

    // ���������� ��������� �������
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

    // ���������� ��������� ������� �� �������
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

    // ���� ������������ ������
    n1 = (std::string)"123";
    n1.print();
    printf("---------------------\n");

    // ���� ������������ �����
    n1 = 123;
    n2 = n1; // ������� ����� ������� n1
    n1.set_value(n1.get_value() + 1); // ����������� n1 �� 1
    n1.print(); // 124
    n2.print(); // 123 - ����� n1
    printf("---------------------\n");

    // ���� ��������� ������������
    n1 = 123;
    n2 = 456;
    n2 = n1; // ����������� �������� n1 ������� n2
    n1.set_value(n1.get_value() + 1); // ����������� n1 �� 1
    n1.print(); // 124
    n2.print(); // 123 - �������� ���� ����������� �� n1 � n2
    printf("---------------------\n");

    // ���� ���������� ����������
    int result1 = n2;
    printf("%d\n", result1); // ������� ��������� �� �����

    n1 = 123;
    std::string result2 = n1; // �������� n1 � ���� std::string
    printf("%s\n", result2.c_str()); // ������� ��������� �� �����

    n1 = 123;
    double result3 = n1; // �������� n1 � ���� double
    printf("%f\n", result3);
    printf("---------------------\n");

    // ���� ���������� �������������� �������� + - * / % 
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


    // ���� ������������ ��������� ���������


    printf("---------------------\n");



}