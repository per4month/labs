#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include "BigInt.h"
using namespace std;

void vectorTest() {
	srand(time(NULL));
	cout << "         VECTOR TEST:            " << endl;
	cout << "---------------------------------" << endl;
	cout << "         vector <int>:           " << endl;
	cout << "1. Vector insert:" << endl;
	vector <int> typeInt;
	int before = clock();
	for (int i = 0; i < 10000; i++) {
		typeInt.push_back(rand());
	}
	cout << "time: " << clock()-before << " ms" << endl;
	cout << "2. Vector find:" << endl;
	before = clock();
	vector<int>::const_iterator resultInt = find(typeInt.begin(), typeInt.end(), 96);
	try {
		if (resultInt == typeInt.end()) {
			throw exception("Element doesn't find");
		}
	}
	catch (exception& ex) {
		cout << ex.what() << endl;
	}
	cout << "time: " << clock() - before << " ms" << endl;
	cout << "3. Vector sort:" << endl;
	before = clock();
	sort(typeInt.begin(), typeInt.end());
	cout << "time: " << clock() - before << " ms" << endl;
	cout << "4. Vector delete:" << endl;
	before = clock();
	for (int i = 0; i < 10000; i++)
	{
		typeInt.pop_back();
	}
	cout << "time: " << clock() - before << " ms" << endl;
	cout << "---------------------------------" << endl;
	cout << "         vector <BigInt>:        " << endl;
	cout << "1. Vector insert:" << endl;
	vector <BigInt> typeBigInt;
	before = clock();
	for (int i = 0; i < 10000; i++) {
		BigInt num(rand());
		typeBigInt.push_back(num);
	}
	cout << "time: " << clock() - before << " ms" << endl;
	cout << "2. Vector find:" << endl;
	BigInt search(96);
	before = clock();
	vector<BigInt>::const_iterator resultBigInt = find(typeBigInt.begin(), typeBigInt.end(),search);
	try {
		if (resultBigInt == typeBigInt.end()) {
			throw exception("Element doesn't find");
		}
	}
	catch (exception& ex) {
		cout << ex.what() << endl;
	}
	cout << "time: " << clock() - before << " ms" << endl;
	cout << "3. Vector sort:" << endl;
	before = clock();
	sort(typeBigInt.begin(), typeBigInt.end());
	cout << "time: " << clock() - before << " ms" << endl;
	cout << "4. Vector delete:" << endl;
	before = clock();
	for (int i = 0; i < 10000; i++)
	{
		typeBigInt.pop_back();
	}
	cout << "time: " << clock() - before << " ms" << endl;
	cout << "---------------------------------" << endl;
	cout << endl;
}

void multisetTest() {
	cout << "         MULTISET TEST:" << endl;
	cout << "---------------------------------" << endl;
	cout << "         multiset <int>:           " << endl;
	multiset <int> typeInt;
	cout << "1. Multiset insert:" << endl;
	int before = clock();
	for (int i = 0; i < 10000; i++) {
		typeInt.insert(rand());
	}
	cout << "time: " << clock() - before << " ms" << endl;
	cout << "2. Multiset find:" << endl;
	before = clock();
	multiset <int>::const_iterator resultInt = typeInt.find(96);
	try {
		if (resultInt == typeInt.end()) {
			throw exception("Element doesn't find");
		}
	}
	catch (exception& ex) {
		cout << ex.what() << endl;
	}
	cout << "time: " << clock() - before << " ms" << endl;
	cout << "3. Multiset delete:" << endl;
	before = clock();
	typeInt.erase(typeInt.begin(), typeInt.end());
	cout << "time: " << clock() - before << " ms" << endl;
	cout << "---------------------------------" << endl;
	cout << "         multiset <BigInt>:           " << endl;
	multiset <BigInt> typeBigInt;
	cout << "1. Multiset insert:" << endl;
	before = clock();
	for (int i = 0; i < 10000; i++) {
		BigInt num(rand());
		typeBigInt.insert(num);
	}
	cout << "time: " << clock() - before << " ms" << endl;
	cout << "2. Multiset find:" << endl;
	before = clock();
	BigInt search(96);
	multiset <BigInt>::const_iterator resultBigInt = typeBigInt.find(search);
	try {
		if (resultBigInt == typeBigInt.end()) {
			throw exception("Element doesn't find");
		}
	}
	catch (exception& ex) {
		cout << ex.what() << endl;
	}
	cout << "time: " << clock() - before << " ms" << endl;
	cout << "3. Multiset delete:" << endl;
	before = clock();
	typeBigInt.erase(typeBigInt.begin(), typeBigInt.end());
	cout << "time: " << clock() - before << " ms" << endl;

}


int main()
{
	vectorTest();
	multisetTest();
	cin.get();
}