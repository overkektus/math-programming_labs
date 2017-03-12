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
	int points = 0,   // количествоточек   
		numbers = 0,    // значение октета
		countOne = 0;
	char* buff = new char[3];    // буффер для одного октета 

	for (int i = 0; correct[i] != '\0'; i++) {  // для строки IP-адреса  
		if (correct[i] <= '9' && correct[i] >= '0') {  // если цифра
			if (numbers > 3) return false;  //если больше трех чисел в октете – ошибка     
			buff[numbers++] = correct[i];     //скопировать в буффер    
			if (atoi(buff) == 1) countOne++;
		}
		else if (correct[i] == '.') {       // если точка
			if (atoi(buff) > 255) return false;  // проверить диапазон октета 
			if (numbers == 0)	   return false;  //если числа нет - ошибка
			numbers = 0;
			points++;
			delete[] buff;
			buff = new char[3];
		}
		else return false;
	}

	if (points != 3) return false;  // если количство точек в IP-адресе не 3 - ошибка 
	if (countOne > 3) return false;
	if (flag) {
		int temp = 0;
		int count = 0;
		int point = 0;
		while (point != 4) {
			char* buffer = new char[3];    // буффер для одного октета
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
	int points = 0;   // количество точек  ip 
	int countIP = 0;
	int countMask = 0;
	while (points != 4) {
		char* buffIp = new char[3];    // буффер для одного октета 
		char* buffMask = new char[3];    // буффер для одного октета 
		char* buffSubnet = new char[3];    // буффер для одного октета 
		char* buffHost = new char[3];    // буффер для одного октета 
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
	unsigned long out = 0; //число для IP-адреса  
	char *buff = new char[3]; //буфер для хранения одного октета    

	for (int i = 0, j = 0; correct[i] != '\0'; i++, j++) {
		if (correct[i] != '.')							// если не точка
			buff[j] = correct[i];						// записать символ в буфер 
		if (correct[i] == '.' || correct[i + 1] == '\0') {	// если следующий октет или последний 
			out <<= 8;								 //сдвинуть число на 8 бит     
			if (atoi(buff) > 255) return NULL;			 // елиоктетбольше 255 – ошибка    
			out += (unsigned long)atoi(buff);		 //преобразовать и добавить к числу IP-адреса        
			j = -1;
		}
	}
	return out;
}

void Print() {
	cout << "IP: " << setw(30 - strlen("IP")) << setfill(' ') << ip << endl;
	cout << "Маска: " << setw(29 - strlen("Маска")) << setfill(' ') << mask << endl;
	cout << "ID подсети:" << setw(29 - strlen("ID подсети")) << setfill(' ') << subnet << endl;
	cout << "ID хоста:  " << setw(26 - strlen("ID хоста")) << setfill(' ') << host << endl;
}

int _tmain(int argc, _TCHAR* argv[]) {
	setlocale(0, "");
	if (!CheckAddress(ip)) return -1;
	if (!CheckAddress(mask, true)) return -1;
	CreateSubnetAndHost(ip, mask, subnet, host);
	Print();
	return 0;
}