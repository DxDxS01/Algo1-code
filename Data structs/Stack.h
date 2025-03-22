#pragma once

class Stack {
private:
	int m0 = 16;
	int* A;
	int n = -1;

public:
	Stack(int);
	Stack();
	~Stack();
	void push(int x);
	int pop();
	int top();
	bool isEmpty();
	void setEmpty();
	void printStack();
};