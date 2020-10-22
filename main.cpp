#include <iostream>
#include "BigInt.h"
#include "Test.h"
using namespace std;

int main()
{
	Test test;
	cout << "---------------------------------" << endl;
	cout << "Test 1 (sum)" << endl;
	cout << test.test_sum() << endl;
	cout << "---------------------------------" << endl;
	cout << "Test 2 (deduct)" << endl;
	cout << test.test_deduct() << endl;
	cout << "---------------------------------" << endl;
	cout << "Test 3 (add ten int)" << endl;
	cout << test.test_addTen_int() << endl;
	cout << "---------------------------------" << endl;
	cout << "Test 4 (add ten long long)" << endl;
	cout << test.test_addTen_long_long() << endl;
	cout << "---------------------------------" << endl;
	cout << "Test 5 (add ten unsigned long long)" << endl;
	cout << test.test_addTen_unsigned_long_long() << endl;
	cout << "---------------------------------" << endl;
	cout << "Test 6 (add ten null)" << endl;
	cout << test.test_addTen_null() << endl;
	cout << "---------------------------------" << endl;
	cout << "Test 7 (add ten one)" << endl;
	cout << test.test_addTen_one() << endl;
	cout << "---------------------------------" << endl;
	cout << "Test 8 (div ten int)" << endl;
	cout << test.test_divTen_int() << endl;
	cout << "---------------------------------" << endl;
	cout << "Test 9 (div ten long long)" << endl;
	cout << test.test_divTen_long_long() << endl;
	cout << "---------------------------------" << endl;
	cout << "Test 10 (div ten unsigned long long)" << endl;
	cout << test.test_divTen_unsigned_long_long() << endl;
	cout << "---------------------------------" << endl;
	cout << "Test 11 (div ten null)" << endl;
	cout << test.test_divTen_null() << endl;
	cout << "---------------------------------" << endl;
	cout << "Test 12 (div ten one)" << endl;
	cout << test.test_divTen_one() << endl;
	cout << "---------------------------------" << endl;
	cout << "Test 13 (div ten object smaller then number (length))" << endl;
	cout << test.test_divTen_first_smaller_then_number() << endl;
	cout << "---------------------------------" << endl;
	cout << "Test 14 (div ten equal numbers)" << endl;
	cout << test.test_divTen_equal() << endl;
	cout << "---------------------------------" << endl;
	cout << "Test 15 (assigning once)" << endl;
	cout << test.test_assigning_once() << endl;
	cout << "---------------------------------" << endl;
	cout << "Test 16 (assigning twice)" << endl;
	cout << test.test_assigning_twice() << endl;
	cout << "---------------------------------" << endl;
	cout << "Test 17 (assigning himself)" << endl;
	cout << test.test_assigning_himself() << endl;
	cout << "---------------------------------" << endl;
	cout << "Test 18 (unsigned long)" << endl;
	cout << test.test1_unsigned_long() << endl;
	cout << "---------------------------------" << endl;
	cout << "Test 19 (unsigned long again)" << endl;
	cout << test.test2_unsigned_long() << endl;
	cout << "---------------------------------" << endl;
	cout << "Test 20 (unsigned long overload)" << endl;
	cout << test.test_unsigned_long_overload() << endl;
	cout << "---------------------------------" << endl;
	cout << "Successful tests: " << test.suc << endl;
	cout << "Failed tests: " << test.fail << endl;
	
	cin.get();
	cin.get();
}