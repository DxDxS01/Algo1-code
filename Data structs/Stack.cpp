#include "Stack.h"
#include <stdexcept>

Stack::Stack(int s) {
	if (s < 0) {
		A = new int[m0];
	}
	else {
		A = new int[s];
		m0 = s;
	}
}
Stack::Stack() {
	A = new int[m0];
}

Stack::~Stack() {
	delete[] A;
}

void Stack::push(int x) {
	if (n >= m0) {
		throw std::out_of_range("A Stack megtelt!\n");
	}
	++n;
	A[n] = x;
}

int Stack::pop() {
	if (n < 0) { throw std::out_of_range("Üres a Stack!\n"); }
	int tmp = A[n];
	--n;
	return tmp;
}

int Stack::top() {
	if (n < 0) { throw std::out_of_range("Üres a Stack!\n"); }
	return A[n];
}

bool Stack::isEmpty() {
	return n < 0;
}

void Stack::setEmpty() {
	n = -1;
}

void Stack::printStack() {
	printf("[ ");
	for (int i = 0; i <= n;++i) {
		printf("%d ", A[i]);
	}
	printf("]\n");
}