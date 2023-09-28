#include <iostream>
using namespace std;
#pragma once


struct util {
	static void swap(int& a, int& b);
	static void sort(int* arr, int count);
	static void reverse(int* arr, int count);
	static void print(int* arr, int count);
};

void util::swap(int& a, int& b) {
	b ^= a ^= b ^= a;
}

void util::sort(int* A, int size) {
	for (int k = 1; k < size; k++) {
		for (int j = 1; j < size; j++) {
			if (A[j - 1] > A[j]) {
				swap(A[j - 1], A[j]);
			}
		}
	}
}

void util::reverse(int* A, int size) {
	for (int j = 0; j < size/2; j++){
		swap(A[j], A[size - 1 - j]);
	}
}

void util::print(int* A, int size) {
	for (int j = 0; j < size; j++) {
		cout << "" << A[j] << endl;
	}
}



