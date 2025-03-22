#include "InsertionSort.h"

void InsertionSort(int t[], int n) {
	for (int i = 1; i < n - 1; ++i) {
		if (t[i - 1] > t[i]) {
			int x = t[i]; // Segédváltozóban eltároljuk a vizsgált elemet
			t[i] = t[i - 1]; // Legalább ezzel lentebb kell tolnunk a vizsgált elemet

			int j = i - 2; 
			while (j >= 0 && t[j] > x) { // Addig toljuk lentebb a vizsgált elemet ameddig kell
				t[j + 1] = t[j];
				--j;
			}
			t[j + 1] = x; // Berakjuk a hejére az elemet
		}
	}
}