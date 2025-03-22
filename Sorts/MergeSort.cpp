#include "MergeSort.h"
//
void _merge(int B[], int A[], int first, int mid, int last) {
	int k = first; // k az A elemein fog mennni
	int i = first; // i a B elemein mid-ig
	int j = mid; // j is B elemein last-ig

	while (i < mid && j < last) { // Addig megy amíg mind 2 részben van elem
		if (B[i] <= B[j]) {
			A[k] = B[i];
			++i;
		}
		// Itt a 2 rész elemei közül választjuk a kisebbet
		else {
			A[k] = B[j];
			++j;
		}
		++k; // Közben A indexét mozgatjuk
	}

	// A megmaradt elemek is berakjuk A-ba
	if (i < mid) {
		while (i < mid) {
			A[k] = B[i];
			++i;
		}
	}
	else {
		while (j < last) {
			A[k] = B[j];
			++j;
		}

	}
}

void MergeSort(int B[], int A[], int first, int last) { // Jegyzetben lévõ stuki szerint (31. oldal)
	if (last - first > 1) { // Akkor fut le ha van még hova osztani a listát, basically ha az elsõ és utolsó index között még 2 elem van
		int mid = (first + last) / 2;
		MergeSort(A, B, first, mid); // Bal oldalra osztjuk
		MergeSort(A, B, mid, last); // Aztán pedig jobbra
		_merge(B, A, first, mid, last); // És összeillesztjük õket
	}
}

void MergeSort(int A[], int first, int last) { // Arra az esetre ha lusta vagy 2 listát csinálni
	//
	int* B = new int[last];
	for (int i = 0; i < last;++i) {
		B[i] = A[i];
	}
	//
	if (last - first > 1) {
		int mid = (first + last) / 2;
		MergeSort(A, B, first, mid);
		MergeSort(A, B, mid, last);
		_merge(B, A, first, mid, last);
	}
}