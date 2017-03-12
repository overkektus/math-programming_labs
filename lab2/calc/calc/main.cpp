#include "stdafx.h"
#include <iostream>
#include "Combi.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");

	char mass[] = { 'q', 'r', 't', 'y', 'x' };

	cout << "========��������� ��������� ���� �����������=======" << endl;
	cout <<	"\t�������� ���������: ";

	cout << "{ ";
	for (int i = 0; i < sizeof(mass); i++)
		cout << mass[i] << ((i < sizeof(mass) - 1) ? ", " : " ");
	cout << "}";

	cout << endl << "\t��������� ���� �����������:";
	combi::subset s1(sizeof(mass));
	int  n = s1.getfirst();

	while (n >= 0)
	{
		cout << endl << "\t\t{ ";
		for (int i = 0; i < n; i++)
			cout << mass[s1.ntx(i)] << ((i < n - 1) ? ", " : " ");
		cout << "}";
		n = s1.getnext();
	};
	cout << endl << "\n===================�����: " << s1.count() << " =====================" << endl << endl;

	return 0;
}