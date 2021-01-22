#include <iostream>
#include "BigInt.h"
#include "Test.h"
using namespace std;

int main()
{
	
	Test test;
	cout << "---------------------------------" << endl;
	
	
	
	cout << "Test 1" << endl;
	cout << test.default_constructor() << endl;
	cout << "---------------------------------" << endl;

	cout << "Test 2" << endl;
	cout << test.long_constructor() << endl;
	cout << "---------------------------------" << endl;

	cout << "Test 3" << endl;
	cout << test.char_constructor() << endl;
	cout << "---------------------------------" << endl;

	cout << "Test 3.1" << endl;
	cout << test.char_constructor_symbols() << endl;
	cout << "---------------------------------" << endl;

	cout << "Test 4" << endl;
	cout << test.addition_a_b() << endl;
	cout << "---------------------------------" << endl;

	cout << "Test 5" << endl;
	cout << test.addition_b_a() << endl;
	cout << "---------------------------------" << endl;

	cout << "Test 6" << endl;
	cout << test.addition_a_null() << endl;
	cout << "---------------------------------" << endl;

	cout << "Test 7" << endl;
	cout << test.addition_discharge_transfer() << endl;
	cout << "---------------------------------" << endl;

	cout << "Test 8" << endl;
	cout << test.mult_a_b() << endl;
	cout << "---------------------------------" << endl;

	cout << "Test 9" << endl;
	cout << test.mult_b_a() << endl;
	cout << "---------------------------------" << endl;

	cout << "Test 10" << endl;
	cout << test.mult_pos_a_null() << endl;
	cout << "---------------------------------" << endl;


	cout << "Test 11" << endl;
	cout << test.sub_a_b() << endl;
	cout << "---------------------------------" << endl;

	cout << "Test 12" << endl;
	cout << test.sub_b_a() << endl;
	cout << "---------------------------------" << endl;

	cout << "Test 13" << endl;
	cout << test.sub_a_a() << endl;
	cout << "---------------------------------" << endl;

	cout << "Test 14" << endl;
	cout << test.sub_discharge_transfer() << endl;
	cout << "---------------------------------" << endl;
	
	cout << "Test 15" << endl;
	cout << test.sub_discharge_transfer_v2() << endl;
	cout << "---------------------------------" << endl;

	cout << "Test 16" << endl;
	cout << test.convert_to_2() << endl;
	cout << "---------------------------------" << endl;
	cin.get();

	cout << "Test 17" << endl;
	cout << test.convert_to_8() << endl;
	cout << "---------------------------------" << endl;
	cin.get();

	cout << "Test 18" << endl;
	cout << test.convert_to_16() << endl;
	cout << "---------------------------------" << endl;

	cout << "Test 19" << endl;
	cout << test.convert_to_17() << endl;
	cout << "---------------------------------" << endl;

	cout << "Test 20" << endl;
	cout << test.div_a_b() << endl;
	cout << "---------------------------------" << endl;

	cout << "Test 21" << endl;
	cout << test.div_b_a() << endl;
	cout << "---------------------------------" << endl;

	cout << "Test 22" << endl;
	cout << test.div_a_0() << endl;
	cout << "---------------------------------" << endl;

	cout << "Test 23" << endl;
	cout << test.div_0_a() << endl;
	cout << "---------------------------------" << endl;

	cout << "Test 24" << endl;
	cout << test.div_a_a() << endl;
	cout << "---------------------------------" << endl;


	cin.get();
}