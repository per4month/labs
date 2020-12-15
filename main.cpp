#include <iostream>
#include "Advert.h"
#include "locale.h"
#include <iomanip>
#include <windows.h>
#include <fstream>
#include <ctime>
#include "List.h"
using namespace std;

int main(){
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	setlocale(LC_ALL, "Russian");
	char fname[20] = "TEST.txt";
	Advert j('s',2,21,12,2020,"Game of thrones", "88005553535");
	Advert j1('b',3,4,5,2021,"Balalaika", "88005553535");
	Advert j2;
	Advert j3;
/*	ofstream of;
	of.open(fname);
	of.close();*/
	FList<Advert> *fl = new FList<Advert>(fname);
	//*fl << j;
	//*fl << j1;
	fl->seekp(0);
	*fl >> j2;
	fl->seekp(ios::end);
	*fl >> j3;
	fl->close();
	cout << j2;
	cout << endl;
	cout << j3;
	return 0;
}