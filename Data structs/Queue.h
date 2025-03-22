#pragma once
#include <exception>

class Queue {
private:
	int* Z;
	int m0 = 16; // Max mérete a Queue-nak
	int n = 0; // Jelenlegi mérete a Queue-nak
	int k = 0; // Következõ elem

	void doubleFullQueueArray();

public:
	Queue(int);
	Queue();

	~Queue();

	void add(int);

	int rem();

	int first();

	int length();

	bool isEmpty();

	void setEmpty();

	void printQueue();
};