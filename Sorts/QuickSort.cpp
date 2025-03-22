#include "QuickSort.h"
#include <ctime>
#include <random>

int _random(int low, int high) {
	srand(time(0));
	if (high - low == 0) return low;
	return low + rand() % (high - low);
}

void _swap(int A[], int i, int j) {
	int x = A[i-1];
	A[i-1] = A[j-1];
	A[j-1] = x;
}

void QuickSort(int A[], int first, int last) {
	if (first < last) {
		int q = _partition(A, first, last); // Kiválasztunk egy indexet ami alapján elosztjuk a tömböt
		QuickSort(A, first, q); // A bal oldalt is elosztjuk még ameddig tudjuk
		QuickSort(A, q + 1, last); // És a jobbat is
	}
}

void QuickSort(int A[], int last) { // QuickSort kezdésre
	int first = 1;
	if (first < last) {
		int q = _partition(A, first, last);
		QuickSort(A, first, q);
		QuickSort(A, q + 1, last);
	}
}

int _partition(int A[], int first, int last) {
	int p = _random(first, last); // Kiválasztunk egy random pivot-ot
	_swap(A, p, last); // Az utolsó lesz a pivot

	p = first;
	while (p < last && A[p-1] <= A[last-1]) ++p; // Addig megyünk amíg nem találunk a pivotnál nagyobb egyenlõ elemet


	if (p < last) {  // Ha nem a pivot a legnagyobb elem vagy van egyenlõ
		int j = p + 1;
		while (j < last) {
			if (A[j-1] < A[last-1]) { // A pivotnál kisebb elemek a bal oldalra rendezzük
				_swap(A, p, j);
				++p;
			}
			++j;
		}
		_swap(A, p, last);
	}
	return p;
}