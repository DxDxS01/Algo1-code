#include "InsertionSort.h"

void InsertionSort(int t[], int n) {
	for (int i = 1; i < n - 1; ++i) {
		if (t[i - 1] > t[i]) {
			int x = t[i]; // Seg�dv�ltoz�ban elt�roljuk a vizsg�lt elemet
			t[i] = t[i - 1]; // Legal�bb ezzel lentebb kell tolnunk a vizsg�lt elemet

			int j = i - 2; 
			while (j >= 0 && t[j] > x) { // Addig toljuk lentebb a vizsg�lt elemet ameddig kell
				t[j + 1] = t[j];
				--j;
			}
			t[j + 1] = x; // Berakjuk a hej�re az elemet
		}
	}
}