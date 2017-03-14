#include "stdafx.h"
#include <iostream>
#include "conio.h"
#include <cstdlib> 

using namespace std;

void swap(int i, int j, int a[]) {
	int temp = 0;
	temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

void GenerateReshuffle(int l, int r, int a[]) {
	int i;
	if (l == r)
		for (i = 0; i < r; i++) {
			cout << a[i];
		}
	else {
		for (i = l; i <= r; i++) {
			swap(l, i, a);
			cout << endl;
			GenerateReshuffle(l + 1, r, a);
			swap(i, l, a);
		}
	}
}