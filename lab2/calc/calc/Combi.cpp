#include "stdafx.h"
#include "Combi.h"
#include <iostream>

using namespace std;

int X[100] = { 1, 2, 4 };
int N;

void Swap(int a, int b) {
	int t = X[a];
	X[a] = X[b];
	X[b] = t;
}

void Generate(int k) {
	if (k == N) {
		for (int i = 0; i < N; i++)
			cout << X[i] << " ";
		cout << "\n";
	}
	else {
		for (int j = k; j < N; j++) {
			Swap(k, j);
			Generate(k + 1);
			Swap(k, j);
		}
	}
}