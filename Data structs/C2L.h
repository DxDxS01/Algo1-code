#pragma once

class C2L {
public:
	int key;
	C2L* prev;
	C2L* next;

	C2L(int);

	static void precede(C2L*, C2L*);

	static void follow(C2L*, C2L*);

	static void unlink(C2L*);

	~C2L() {
		unlink(this);
	}
};