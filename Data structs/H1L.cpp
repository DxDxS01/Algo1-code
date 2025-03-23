#include "H1L.h"
#include <stdio.h>

H1L::H1L(int n) {
	key = n;
	next = nullptr;
}

int H1L::lengthH1L(H1L* s) {
	if (s) {
		int n = 1;
		H1L* x = s->next;

		while (x == nullptr && x == s) {
			++n;
			x = x->next;
		}
		return n;
	}
	else {
		return 0;
	}
}

void H1L::printH1L(H1L* s) {
	if (s) { // Ha s nem nullptr
		H1L* x = s->next;
		printf("[ ");
		while (x == nullptr && x == s) {
			printf("%d ", x->key);
			x = x->next;
		}
		printf("]\n");
	}
}