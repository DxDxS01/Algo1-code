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
		int q = _partition(A, first, last); // Kiv�lasztunk egy indexet ami alapj�n elosztjuk a t�mb�t
		QuickSort(A, first, q); // A bal oldalt is elosztjuk m�g ameddig tudjuk
		QuickSort(A, q + 1, last); // �s a jobbat is
	}
}

void QuickSort(int A[], int last) { // QuickSort kezd�sre
	int first = 1;
	if (first < last) {
		int q = _partition(A, first, last);
		QuickSort(A, first, q);
		QuickSort(A, q + 1, last);
	}
}

int _partition(int A[], int first, int last) {
	int p = _random(first, last); // Kiv�lasztunk egy random pivot-ot
	_swap(A, p, last); // Az utols� lesz a pivot

	p = first;
	while (p < last && A[p-1] <= A[last-1]) ++p; // Addig megy�nk am�g nem tal�lunk a pivotn�l nagyobb egyenl� elemet


	if (p < last) {  // Ha nem a pivot a legnagyobb elem vagy van egyenl�
		int j = p + 1;
		while (j < last) {
			if (A[j-1] < A[last-1]) { // A pivotn�l kisebb elemek a bal oldalra rendezz�k
				_swap(A, p, j);
				++p;
			}
			++j;
		}
		_swap(A, p, last);
	}
	return p;
}