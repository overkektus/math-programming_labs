#include "stdafx.h"
#include <iostream>     // std::cout
#include <algorithm>    // std::next_permutation, std::sort
#include <vector>

using namespace std;

void Generare(int m, int n) {
	vector<int> myints;
	//заполняем массив
	for (int i = 0; i < n; i++)
		myints.push_back(i);

	sort(myints.begin(), myints.end());

	do {
		cout << "\t\t";
		for (int i = 0; i < m; i++) {
			cout << myints[i] << ' ';
		}
		cout << "\n";
	} while (next_permutation(myints.begin(), myints.end()));
}