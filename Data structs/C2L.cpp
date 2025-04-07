#include "C2L.h"
#include <stdio.h>

C2L::C2L(int n) {
	this->key = n;
	this->prev = this->next = this;
}

void C2L::precede(C2L* q, C2L* r) {
	C2L* p = r->prev;
	q->prev = p;
	q->next = r;
	p->next = r->prev = q;
}

void C2L::follow(C2L* q, C2L* r) {
	C2L* p = q->next;
	r->prev = q;
	r->next = p;
	q->next = p->prev = r;
}

void C2L::unlink(C2L* q) {
	C2L* p = q->prev;
	C2L* r = q->next;
	p->next = r;
	r->prev = p;
	q->prev = q->next = q;
}

C2L::~C2L() {
	unlink(this);
}