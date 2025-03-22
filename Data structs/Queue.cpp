#include <exception>
#include <stdio.h>
#include "Queue.h"

void Queue::doubleFullQueueArray() {
	int s = m0 * 2;
	printf("A Queue-t %d -re növeltük\n", s);
	int* Y = new int[m0 * 2];

	for (int i = 0; i < m0; ++i) {
		if (k == n) k = 0;

		Y[i] = Z[k];
		++k;
	}

	Z = Y;
	m0 = m0 * 2;
	k = 0;
}

Queue::Queue(int m) {
	if (m <= 0) throw std::exception("Túl kicsi méret!, min 1!");
	Z = new int[m];
	m0 = m;
}
Queue::Queue() {
	Z = new int[16];
	m0 = 16;
}

Queue::~Queue() {
	delete[](Z);
}

void Queue::add(int x) {
	if (n == m0) {
		doubleFullQueueArray();
	}

	Z[(k + n) % m0] = x;
	++n;
}

int Queue::rem() {
	if (n > 0) {
		int x = Z[k];
		if (k < n) {
			++k;
		}
		else {
			k = 0;
		}
		--n;
		return x;
	}
	else {
		throw std::exception("Queue-ba nincs elég elem!");
	}
}

int Queue::first() {
	if (n > 0) {
		return Z[k];
	}
	else {
		throw std::exception("Queue-ba nincs elég elem!");
	}
}

int Queue::length() {
	return n;
}

bool Queue::isEmpty() {
	return n == 0;
}

void Queue::setEmpty() {
	n = 0;
	k = 0;
}

void Queue::printQueue() {
	printf("[ ");
	for (int i = 0; i < n; ++i) {
		printf("%d ", Z[(k + i) % m0]);
	}
	printf("]\n");
}