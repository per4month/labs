#include <iostream>
#include "Advert.h"
#include "locale.h"
#include <iomanip>
#include <windows.h>
#include <fstream>
#include <ctime>
using namespace std;

int main(){
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	setlocale(LC_ALL, "Russian");
	Advert j;
	Advert j1;
	cin >> j;
	fstream of("text.dat", ios::binary);
	of << j;
	of.close();
	fstream ifs("text.dat", ios::binary);
	ifs >> j1;
	ifs.close();
	
	cout << j;
	cout << j1;

	cin.get();
	return 0;
}