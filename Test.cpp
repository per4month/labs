#include "Test.h"
#include "BigInt.h"
#include <iostream>
using namespace std;

Test::Test() {
	suc = 0;
	fail = 0;
}

bool Test :: default_constructor() {
	const char* expected = "0";
	BigInt obj;
	char* actual = obj.toString();
	cout << "Expected: " << expected << " Actual: " << actual << " " << endl;
	if (strcmp(actual, expected) == 0) {
		suc++;
		return true;
	}
	else {
		fail++;
		return false;
	}
}


bool Test::long_constructor() {
	BigInt obj(665522);
	const char* expected = "665522";
	char* actual = obj.toString();
	cout << "Expected: " << expected << " Actual: " << actual << " " << endl;
	if (strcmp(actual, expected) == 0) {
		suc++;
		return true;
	}
	else {
		fail++;
		return false;
	}
}

bool Test::char_constructor() {
	BigInt obj("2151223665522");
	const char* expected = "2151223665522";
	char* actual = obj.toString();
	cout << "Expected: " << expected << " Actual: " << actual << " " << endl;
	if (strcmp(actual, expected) == 0) {
		suc++;
		return true;
	}
	else {
		fail++;
		return false;
	}
}

bool Test::char_constructor_symbols() {
	BigInt obj("21dscsv45515");
	const char* expected = "0";
	char* actual = obj.toString();
	cout << "Expected: " << expected << " Actual: " << actual << " " << endl;
	if (strcmp(actual, expected) == 0) {
		suc++;
		return true;
	}
	else {
		fail++;
		return false;
	}
}


bool Test::addition_a_b() {
	BigInt obj1("12222");
	BigInt obj2("258");
	const char* expected = "12480";
	obj1.add(obj1, obj2);
	char* actual = obj1.toString();
	cout << "Expected: " << expected << " Actual: " << actual << " " << endl;
	if (strcmp(actual, expected) == 0) {
		suc++;
		return true;
	}
	else {
		fail++;
		return false;
	}
}

bool Test::addition_b_a() {
	BigInt obj1("356");
	BigInt obj2("221555544");
	const char* expected = "221555900";
	obj1.add(obj1, obj2);
	char* actual = obj1.toString();
	cout << "Expected: " << expected << " Actual: " << actual << " " << endl;
	if (strcmp(actual, expected) == 0) {
		suc++;
		return true;
	}
	else {
		fail++;
		return false;
	}
}

bool Test::addition_a_null() {
	BigInt obj1("5445");
	BigInt obj2("0");
	const char* expected = "5445";
	obj1.add(obj1, obj2);
	char* actual = obj1.toString();
	cout << "Expected: " << expected << " Actual: " << actual << " " << endl;
	if (strcmp(actual, expected) == 0) {
		suc++;
		return true;
	}
	else {
		fail++;
		return false;
	}
}

bool Test::addition_discharge_transfer() {
	BigInt obj1("509");
	BigInt obj2("613");
	const char* expected = "1122";
	obj1.add(obj1, obj2);
	char* actual = obj1.toString();
	cout << "Expected: " << expected << " Actual: " << actual << " " << endl;
	if (strcmp(actual, expected) == 0) {
		suc++;
		return true;
	}
	else {
		fail++;
		return false;
	}
}

bool Test::mult_a_b() {
	BigInt obj1("5090");
	BigInt obj2("613");
	const char* expected = "3120170";
	obj1.multiply(obj1, obj2);
	char* actual = obj1.toString();
	cout << "Expected: " << expected << " Actual: " << actual << " " << endl;
	if (strcmp(actual, expected) == 0) {
		suc++;
		return true;
	}
	else {
		fail++;
		return false;
	}
}

bool Test::mult_b_a() {
	BigInt obj1("613");
	BigInt obj2("5090");
	const char* expected = "3120170";
	obj1.multiply(obj1, obj2);
	char* actual = obj1.toString();
	cout << "Expected: " << expected << " Actual: " << actual << " " << endl;
	if (strcmp(actual, expected) == 0) {
		suc++;
		return true;
	}
	else {
		fail++;
		return false;
	}
}

bool Test::mult_pos_a_null() { //неправильно
	BigInt obj1("613");
	BigInt obj2("0");
	const char* expected = "0";
	obj1.multiply(obj1, obj2);
	char* actual = obj1.toString();
	cout << "Expected: " << expected << " Actual: " << actual << " " << endl;
	if (strcmp(actual, expected) == 0) {
		suc++;
		return true;
	}
	else {
		fail++;
		return false;
	}
}


bool Test::sub_a_b() {  
	BigInt obj1("520");
	BigInt obj2("365");
	const char* expected = "155";
	obj1.deduct(obj1, obj2);
	char* actual = obj1.toString();
	cout << "Expected: " << expected << " Actual: " << actual << " " << endl;
	if (strcmp(actual, expected) == 0) {
		suc++;
		return true;
	}
	else {
		fail++;
		return false;
	}
}

bool Test::sub_b_a() {
	BigInt obj1("278");
	BigInt obj2("1562");
	const char* expected = "1284";
	obj1.deduct(obj1, obj2);
	char* actual = obj1.toString();
	cout << "Expected: " << expected << " Actual: " << actual << " " << endl;
	if (strcmp(actual, expected) == 0) {
		suc++;
		return true;
	}
	else {
		fail++;
		return false;
	}
}

bool Test::sub_a_a() {
	BigInt obj1("123654789");
	BigInt obj2("123654789");
	const char* expected = "0";
	obj1.deduct(obj1, obj2);
	char* actual = obj1.toString();
	cout << "Expected: " << expected << " Actual: " << actual << " " << endl;
	if (strcmp(actual, expected) == 0) {
		suc++;
		return true;
	}
	else {
		fail++;
		return false;
	}
}

bool Test::sub_discharge_transfer() {
	BigInt obj1("100000000");
	BigInt obj2("91");
	const char* expected = "99999909";
	obj1.deduct(obj1, obj2);
	char* actual = obj1.toString();
	cout << "Expected: " << expected << " Actual: " << actual << " " << endl;
	if (strcmp(actual, expected) == 0) {
		suc++;
		return true;
	}
	else {
		fail++;
		return false;
	}
}

bool Test::sub_discharge_transfer_v2() {
	BigInt obj1("1020078");
	BigInt obj2("20089");
	const char* expected = "999989";
	obj1.deduct(obj1, obj2);
	char* actual = obj1.toString();
	cout << "Expected: " << expected << " Actual: " << actual << " " << endl;
	if (strcmp(actual, expected) == 0) {
		suc++;
		return true;
	}
	else {
		fail++;
		return false;
	}
}

bool Test::convert_to_2() {
	BigInt obj1("1020078");
	const char* expected = "11111001000010101110";
	const char* actual = obj1.convertTo(2);
	cout << "Expected: " << expected << " Actual: " << actual << " " << endl;
	if (strcmp(actual, expected) == 0) {
		suc++;
		return true;
	}
	else {
		fail++;
		return false;
	}
}

bool Test::convert_to_8() {
	BigInt obj1("1020078");
	const char* expected = "3710256";
	const char* actual = obj1.convertTo(8);
	cout << "Expected: " << expected << " Actual: " << actual << " " << endl;
	if (strcmp(actual, expected) == 0) {
		suc++;
		return true;
	}
	else {
		fail++;
		return false;
	}
}

bool Test::convert_to_16() {
	BigInt obj1("1020078");
	const char* expected = "F90AE";
	const char* actual = obj1.convertTo(16);
	cout << "Expected: " << expected << " Actual: " << actual << " " << endl;
	if (strcmp(actual, expected) == 0) {
		suc++;
		return true;
	}
	else {
		fail++;
		return false;
	}
}

bool Test::convert_to_17() {
	BigInt obj1("1020078");
	const char* expected = "Error";
	const char* actual = obj1.convertTo(17);
	cout << "Expected: " << expected << " Actual: " << actual << " " << endl;
	if (strcmp(actual, expected) == 0) {
		suc++;
		return true;
	}
	else {
		fail++;
		return false;
	}
}

bool Test::div_a_b() {
	BigInt obj1("44558522");
	BigInt obj2("326");
	const char* expected1 = "136682";
	const char* expected2 = "190";
	const char* actual2 = obj1.divide(obj1, obj2);
	char* actual1 = obj1.toString();
	cout << "Expected1: " << expected1 << " Actual1: " << actual1 << " " << endl;
	cout << "Expected1: " << expected2 << " Actual1: " << actual2 << " " << endl;
	if ((strcmp(actual1, expected1) == 0) && (strcmp(actual2, expected2) == 0)) {
		suc++;
		return true;
	}
	else {
		fail++;
		return false;
	}
}

bool Test::div_b_a() {
	BigInt obj1("326");
	BigInt obj2("4251");
	const char* expected1 = "0";
	const char* expected2 = "0";
	const char* actual2 = obj1.divide(obj1, obj2);
	char* actual1 = obj1.toString();
	cout << "Expected1: " << expected1 << " Actual1: " << actual1 << " " << endl;
	cout << "Expected1: " << expected2 << " Actual1: " << actual2 << " " << endl;
	if ((strcmp(actual1, expected1) == 0) && (strcmp(actual2, expected2) == 0)) {
		suc++;
		return true;
	}
	else {
		fail++;
		return false;
	}
}

bool Test::div_a_0() {
	BigInt obj1("51515");
	BigInt obj2("0");
	const char* expected1 = "51515";
	const char* expected2 = "Error";
	const char* actual2 = obj1.divide(obj1, obj2);
	char* actual1 = obj1.toString();
	cout << "Expected1: " << expected1 << " Actual1: " << actual1 << " " << endl;
	cout << "Expected1: " << expected2 << " Actual1: " << actual2 << " " << endl;
	if ((strcmp(actual1, expected1) == 0) && (strcmp(actual2, expected2) == 0)) {
		suc++;
		return true;
	}
	else {
		fail++;
		return false;
	}
}

bool Test::div_0_a() {
	BigInt obj1("0");
	BigInt obj2("214212");
	const char* expected1 = "0";
	const char* expected2 = "0";
	const char* actual2 = obj1.divide(obj1, obj2);
	char* actual1 = obj1.toString();
	cout << "Expected1: " << expected1 << " Actual1: " << actual1 << " " << endl;
	cout << "Expected1: " << expected2 << " Actual1: " << actual2 << " " << endl;
	if ((strcmp(actual1, expected1) == 0) && (strcmp(actual2, expected2) == 0)) {
		suc++;
		return true;
	}
	else {
		fail++;
		return false;
	}
}

bool Test::div_a_a() {
	BigInt obj1("214212");
	BigInt obj2("214212");
	const char* expected1 = "1";
	const char* expected2 = "0";
	const char* actual2 = obj1.divide(obj1, obj2);
	char* actual1 = obj1.toString();
	cout << "Expected1: " << expected1 << " Actual1: " << actual1 << " " << endl;
	cout << "Expected1: " << expected2 << " Actual1: " << actual2 << " " << endl;
	if ((strcmp(actual1, expected1) == 0) && (strcmp(actual2, expected2) == 0)) {
		suc++;
		return true;
	}
	else {
		fail++;
		return false;
	}
}
