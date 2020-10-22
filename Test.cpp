#include "Test.h"
#include "BigInt.h"
#include <iostream>
using namespace std;

Test::Test() {
	suc = 0;
	fail = 0;
}

bool Test::test_sum() {
	const char* expected = "2586390";
	BigInt obj1("2564878");
	BigInt obj2("21512");
	BigInt obj3;
	obj3 = obj1 + obj2;
	char* actual = obj3.toString();
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

bool Test::test_deduct() {
	const char* expected = "1043366";
	BigInt obj1("2564878");
	BigInt obj2("1521512");
	BigInt obj3;
	obj3 = obj1 - obj2;
	char* actual = obj3.toString();
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

bool Test::test_addTen_int() {
	const char* expected = "104600000";
	BigInt obj("1046");
	obj = obj * 100000;
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

bool Test::test_addTen_long_long() {
	const char* expected = "10460000000000";
	BigInt obj("1046");
	obj = obj * 10000000000;
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

bool Test::test_addTen_unsigned_long_long() {
	const char* expected = "10460000000000000000000";
	BigInt obj("1046");
	obj = obj * 10000000000000000000;
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

bool Test::test_addTen_null() {
	const char* expected = "0";
	BigInt obj("104623");
	obj = obj * 0;
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

bool Test::test_addTen_one() {
	const char* expected = "104623";
	BigInt obj("104623");
	obj = obj * 1;
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

bool Test::test_divTen_int() {
	const char* expected = "104";
	BigInt obj("104623");
	obj = obj /1000;
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

bool Test::test_divTen_long_long() {
	const char* expected = "1046";
	BigInt obj("10462321312442");
	obj = obj/10000000000;
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

bool Test::test_divTen_unsigned_long_long() {
	const char* expected = "154";
	BigInt obj("1546232131244254654577");
	obj = obj / 10000000000000000000;
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

bool Test::test_divTen_null() {
	const char* expected = "E";
	BigInt obj("104623");
	obj = obj / 0;
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

bool Test::test_divTen_one() {
	const char* expected = "104623";
	BigInt obj("104623");
	obj = obj / 1;
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

bool Test::test_divTen_first_smaller_then_number() {
	const char* expected = "0";
	BigInt obj("104623");
	obj = obj / 10000000;
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

bool Test::test_divTen_equal() {
	const char* expected = "5";
	BigInt obj("5955332");
	obj = obj / 1000000;
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

bool Test::test_assigning_once() {
	const char* expected = "2564878";
	BigInt obj1("2564878");
	BigInt obj2("323");
	obj2 = obj1;
	char* actual = obj2.toString();
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

bool Test::test_assigning_twice() {
	const char* expected = "56622262";
	BigInt obj1("56622262");
	BigInt obj2("79885561");
	BigInt obj3;
	obj3 = obj2 = obj1;
	char* actual = obj3.toString();
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

bool Test::test_assigning_himself() {
	const char* expected = "8562365623";
	BigInt obj1("8562365623");
	obj1 = obj1;
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

bool Test::test1_unsigned_long() {
	unsigned long expected = 1234567890;
	BigInt obj1("1234567890");
	unsigned long actual = obj1;
	cout << "Expected: " << expected << " Actual: " << actual << " " << endl;
	if (expected == actual) {
		suc++;
		return true;
	}
	else {
		fail++;
		return false;
	}
}

bool Test::test2_unsigned_long() {
	unsigned long expected = 987654321;
	BigInt obj1("1234567890");
	BigInt obj2("987654321");
	unsigned long actual = obj1;
	actual = obj2;
	cout << "Expected: " << expected << " Actual: " << actual << " " << endl;
	if (expected == actual) {
		suc++;
		return true;
	}
	else {
		fail++;
		return false;
	}
}

bool Test::test_unsigned_long_overload() {
	unsigned long expected = 0;
	BigInt obj1("4294967345433235");
	unsigned long actual = obj1;
	cout << "Expected: " << expected << " Actual: " << actual << " " << endl;
	if (expected == actual) {
		suc++;
		return true;
	}
	else {
		fail++;
		return false;
	}
}

