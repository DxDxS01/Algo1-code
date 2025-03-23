#pragma once

class H1L {
public:
	int key;
	H1L* next;

	H1L(int n);

	static int lengthH1L(H1L* s);

	static void printH1L(H1L* s);
};