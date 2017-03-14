#include "stdafx.h"
#include <iostream>
#include "Subset.h"
#include "xCombi.h"
#include "Accomodation.h"
#include "Reshuffle.h"
#include "Boat.h"
#define NN (sizeof(v)/sizeof(int))

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");
	char mass[] = { 'q', 'w', 'e', 'r', 't' };

	cout << "========��������� ��������� ���� �����������=======" << endl;
	cout << "\t�������� ���������: ";
	cout << "{ ";
	for (int i = 0; i < sizeof(mass); i++)
		cout << mass[i] << ((i < sizeof(mass) - 1) ? ", " : " ");
	cout << "}";
	Subset::subset s1(sizeof(mass));
	int  n = s1.getfirst();

	while (n >= 0) {
		cout << endl << "\t\t{ ";
		for (int i = 0; i < n; i++)
			cout << mass[s1.ntx(i)] << ((i < n - 1) ? ", " : " ");
		cout << "}";
		n = s1.getnext();
	};
	cout << endl << "==================================================" << endl << endl;

	cout << "================��������� ���������===============" << endl;
	char  AA[][2] = { "q", "w", "e", "r", "t" };
	cout << endl << "  �������� ���������: ";
	cout << "{ ";
	for (int i = 0; i < sizeof(AA) / 2; i++)
		cout << AA[i] << ((i < sizeof(AA) / 2 - 1) ? ", " : " ");
	cout << "}";
	combi::xcombination xc(sizeof(AA) / 2, 3);
	cout << "�� " << xc.n << " �� " << xc.m;
	int  h = xc.getfirst();
	while (h >= 0) {
		cout << endl << "\t\t" << xc.nc << ": { ";
		for (int i = 0; i < h; i++)
			cout << AA[xc.ntx(i)] << ((i < h - 1) ? ", " : " ");
		cout << "}";
		h = xc.getnext();
	};
	cout << endl;
	cout << "==================================================" << endl << endl;

	cout << "===============��������� ������������=============" << endl;
	const int lmax = 100;
	int length;
	cout << "Input the number" << endl;
	cin >> length;
	int a[lmax] = { 0, 1, 2, 3 };
	for (int i = 0; i < length; i++)
		a[i] = i + 1;	
	GenerateReshuffle(1, length, a);
	cout << "==================================================" << endl;

	cout << "================��������� ����������==============" << endl;
	Generare(3, 4);
	cout << "==================================================" << endl;

	int V = 1500,
	#define MM 5
		v[] = { 100,  200,   300,  400,  500,  150 },
		c[NN] = { 10,   15,    20,   25,   30,  25 };
	short  r[MM];
	int cc = boat(
		V,   // [in]  ������������ ��� �����
		MM,  // [in]  ���������� ���� ��� �����������     
		NN,  // [in]  ����� �����������  
		v,   // [in]  ��� ������� ����������  
		c,   // [in]  ����� �� ��������� ������� ����������     
		r    // [out] ���������: ������� ��������� �����������  
	);
	cout << endl << "- ������ � ���������� ����������� �� �����";
	cout << endl << "- ����� ���������� �����������    : " << NN;
	cout << endl << "- ���������� ���� ��� ����������� : " << MM;
	cout << endl << "- ����������� �� ���������� ����  : " << V;
	cout << endl << "- ��� �����������                 : ";
	for (int i = 0; i < NN; i++)
		cout << v[i] << " ";
	cout << endl << "- ����� �� ���������              : ";
	for (int i = 0; i < NN; i++)
		cout << c[i] << " ";
	cout << endl << "- ������� ���������� (0,1,...,m-1): ";
	for (int i = 0; i < MM; i++)
		cout << r[i] << " ";
	cout << endl << "- ����� �� ���������              : " << cc;
	cout << endl << "- ����� ��� ��������� ����������� : ";
	int s = 0; for (int i = 0; i < MM; i++) s += v[r[i]]; cout << s;
	cout << endl << endl;

	return 0;	
}