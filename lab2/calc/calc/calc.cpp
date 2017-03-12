#include "stdafx.h"
#include <stdlib.h>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

char*  ip = "192.255.192.4";
char*  mask = "255.240.0.0";
string subnet;
string host;

using namespace std;

bool CheckAddress(char* correct, bool flag = false) {
	int points = 0,   // ���������������   
		numbers = 0,    // �������� ������
		countOne = 0;
	char* buff = new char[3];    // ������ ��� ������ ������ 

	for (int i = 0; correct[i] != '\0'; i++) {  // ��� ������ IP-������  
		if (correct[i] <= '9' && correct[i] >= '0') {  // ���� �����
			if (numbers > 3) return false;  //���� ������ ���� ����� � ������ � ������     
			buff[numbers++] = correct[i];     //����������� � ������    
			if (atoi(buff) == 1) countOne++;
		}
		else if (correct[i] == '.') {       // ���� �����
			if (atoi(buff) > 255) return false;  // ��������� �������� ������ 
			if (numbers == 0)	   return false;  //���� ����� ��� - ������
			numbers = 0;
			points++;
			delete[] buff;
			buff = new char[3];
		}
		else return false;
	}

	if (points != 3) return false;  // ���� ��������� ����� � IP-������ �� 3 - ������ 
	if (countOne > 3) return false;
	if (flag) {
		int temp = 0;
		int count = 0;
		int point = 0;
		while (point != 4) {
			char* buffer = new char[3];    // ������ ��� ������ ������
			for (int i = 0; correct[count] != '.' && correct[count] != '\0'; i++, count++)
				buffer[i] = correct[count];

			temp = atoi(buffer);
			if (atoi(buffer) != 255 && point == 0) return false;
			if (atoi(buffer) > temp && point > 0) return false;
			point++; count++;
			delete[] buffer;
		}
	}
	return true;
}

void CreateSubnetAndHost(char* ip_, char* mask_, std::string& subnet, std::string& host) {
	int symbolsIP = 0;
	int symbolsMask = 0;
	int points = 0;   // ���������� �����  ip 
	int countIP = 0;
	int countMask = 0;
	while (points != 4) {
		char* buffIp = new char[3];    // ������ ��� ������ ������ 
		char* buffMask = new char[3];    // ������ ��� ������ ������ 
		char* buffSubnet = new char[3];    // ������ ��� ������ ������ 
		char* buffHost = new char[3];    // ������ ��� ������ ������ 
		for (int i = 0; ip_[countIP] != '.' && ip_[countIP] != '\0'; i++, countIP++)
			buffIp[i] = ip_[countIP];
		for (int i = 0; mask_[countMask] != '.' && ip_[countMask] != '\0'; i++, countMask++)
			buffMask[i] = mask_[countMask];

		int sub = atoi(buffIp) & atoi(buffMask);
		int hos = atoi(buffIp) & ~atoi(buffMask);
		sprintf_s(buffSubnet, sizeof(buffSubnet), "%d", sub);
		sprintf_s(buffHost, sizeof(buffHost), "%d", hos);
		subnet += buffSubnet;
		host += buffHost;

		points++; countIP++; countMask++;
		if (points != 4) {
			subnet += ".";
			host += ".";
		}
	}
}

unsigned long  CharToULong(char* correct) {
	unsigned long out = 0; //����� ��� IP-������  
	char *buff = new char[3]; //����� ��� �������� ������ ������    

	for (int i = 0, j = 0; correct[i] != '\0'; i++, j++) {
		if (correct[i] != '.')							// ���� �� �����
			buff[j] = correct[i];						// �������� ������ � ����� 
		if (correct[i] == '.' || correct[i + 1] == '\0') {	// ���� ��������� ����� ��� ��������� 
			out <<= 8;								 //�������� ����� �� 8 ���     
			if (atoi(buff) > 255) return NULL;			 // �������������� 255 � ������    
			out += (unsigned long)atoi(buff);		 //������������� � �������� � ����� IP-������        
			j = -1;
		}
	}
	return out;
}

void Print() {
	cout << "IP: " << setw(30 - strlen("IP")) << setfill(' ') << ip << endl;
	cout << "�����: " << setw(29 - strlen("�����")) << setfill(' ') << mask << endl;
	cout << "ID �������:" << setw(29 - strlen("ID �������")) << setfill(' ') << subnet << endl;
	cout << "ID �����:  " << setw(26 - strlen("ID �����")) << setfill(' ') << host << endl;
}

int _tmain(int argc, _TCHAR* argv[]) {
	setlocale(0, "");
	if (!CheckAddress(ip)) return -1;
	if (!CheckAddress(mask, true)) return -1;
	CreateSubnetAndHost(ip, mask, subnet, host);
	Print();
	return 0;
}