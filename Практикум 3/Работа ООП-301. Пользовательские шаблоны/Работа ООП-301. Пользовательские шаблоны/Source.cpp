#include <iostream>
#include <assert.h>

using namespace std;

struct point {
	int x, y;
	point(int a = 0, int b = 0) : x(a), y(b) {}

};

std::ostream& operator<<(std::ostream& os, const point& p) {
	os << "(" << p.x << ", " << p.y << ")";
	return os;
}

template <class T>
void mySwap(T& a, T& b) {
	T c = a;
	a = b;
	b = c;
}

template <class T>
void bsort(T* a, int size, int(*cfunc)(T,T)) {
	for (int k = 1; k < size; k++) {
		for (int j = 1; j < size; j++) {
			if (cfunc(a[j - 1], a[j])) {
				mySwap(a[j - 1], a[j]);
			}
		}
	}
}

template <class T>
void print_array(T a, int size) {
	for (int i = 0; i < size; i++) {
		cout << "" << a[i] << endl;
	}
	cout << endl;
}

template <class T>
int compare_number(T a, T b) {
	return a < b;
}

int compare_points(point a, point b) {
	if (a.x + a.y > b.x + b.y) {
		return 1;
	}
	else { return 0; }
}

//////////////////////////////////////
template <class T, int N>
class Array {
	T a[N];

public:
	Array() {
		for (int i = 0; i < N; i++) a[i] = 0;
	}

	T& operator [] (int index) {
		assert(index >= 0 && index < N);
		return a[index];
	}
};

//////////////////////////////////////
template <typename T>
class tstack {
	T a[10];
	int count;

public:
	// конструктор
	tstack() : count(0) {}

	// глубина стека
	int size() const {
		return count;
	}

	// проталкивает элемент
	bool push(const T& element) {
		if (count >= 10) {
			return false; // Стек полон, невозможно добавить элемент
		}
		a[count++] = element;
		return true;
	}

	// выталкивает элемент
	T pop() {
		if (count <= 0) {
			return false; // Стек пуст, невозможно вытолкнуть элемент
		}
		return a[--count];
	}

	// элемент на вершине
	T top() const {
		if (count <= 0) {
			return false; // Стек пуст, нет элемента на вершине
		}
		return a[count - 1];
	}
};

int main(void) {
	int a[] = { 5,1,2,4,3 };
	bsort(a, sizeof(a) / sizeof(int), compare_number<int>);
	print_array(a, sizeof(a) / sizeof(int));

	double b[] = { 1.4, 1.5, 3.4, 1.2, 5.4 };
	bsort(b, sizeof(b) / sizeof(double), compare_number<double>);
	print_array(b, sizeof(b) / sizeof(double));

	point p[] = { (11,2), (32,4), (3,62), (3,6) };
	bsort(p, sizeof(p) / sizeof(point), compare_points);
	print_array(p, sizeof(p) / sizeof(point));

	Array<int, 10> arr;
	arr[0] = 1;
	print_array(arr, 10);

	tstack<int> intStack;
	intStack.push(1);
	intStack.push(2);
	intStack.push(3);
	intStack.push(4);
	intStack.push(5);
	intStack.push(6);
	intStack.pop();
	cout << intStack.size() << endl;
	cout << intStack.top() << endl;
	cout << endl;

	tstack<double> doubleStack;
	doubleStack.push(1.4);
	doubleStack.push(2.5);
	doubleStack.push(3.1);
	doubleStack.push(4.5);
	doubleStack.push(5.8);
	doubleStack.push(6.7);
	doubleStack.pop();
	cout << doubleStack.size() << endl;
	cout << doubleStack.top() << endl;
	cout << endl;

	tstack<int>* stackPtr = new tstack<int>();
}