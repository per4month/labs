#include "Test.h"
#include "SignedBigFloat.h"
#include "MyDeque.h"
#include <iostream>
using namespace std;

Test::Test() {
	suc = 0;
	fail = 0;
}

bool Test::test_polymorph_toString() {
	const char* expected[5];
	expected[0] = "121512616";
	expected[1] = "616.352637";
	expected[2] = "-0.7889787";
	expected[3] = "12342.788974";
	expected[4] = "655757353";
	BigInt* objects[5];
	objects[0] = new BigInt("121512616");
	objects[1] = new BigFloat("616","352637");
	objects[2] = new SignedBigFloat('-',"0","7889787");
	objects[3] = new BigFloat("12342", "788974");
	objects[4] = new BigInt("655757353");
	char* actual[5];
	int count = 0;
	for (int i = 0; i < 5; i++) {
		actual[i] = objects[i]->toString();
		if (strcmp(actual[i], expected[i]) == 0) {
			count++;
		}
		cout << "Expected: " << expected[i] << " Actual: " << actual[i] << " " << endl;
	}
	if (count == 5) {
		suc++;
		return true;
	}
	else {
		fail++;
		return false;
	}
}

bool Test::test_toString() {
	const char* expected = "-0.02131 0.0 123242.2312141 2312141 112122";
	BigInt* A = new BigInt("112122");
	BigInt* B = new BigInt("2312141");
	BigInt* C = new BigFloat("123242", "2312141");
	BigInt* D = new BigFloat("0", "0");
	BigInt* E = new SignedBigFloat('-', "0", "02131");
	MyDeque objects;
	objects.push_front(A);
	objects.push_front(B);
	objects.push_front(C);
	objects.push_front(D);
	objects.push_front(E);
	const char* actual = objects.toString();
	cout << "Expected: " << expected << endl;
	cout << "Actual: " << actual << " " << endl;
	if (strcmp(actual, expected) == 0) {
		suc++;
		return true;
	}
	else {
		fail++;
		return false;
	}
}

bool Test::test_toStringReverse() {
	const char* expected = "112122 2312141 123242.2312141 0.0 -0.02131";
	BigInt* A = new BigInt("112122");
	BigInt* B = new BigInt("2312141");
	BigInt* C = new BigFloat("123242", "2312141");
	BigInt* D = new BigFloat("0", "0");
	BigInt* E = new SignedBigFloat('-', "0", "02131");
	MyDeque objects;
	objects.push_front(A);
	objects.push_front(B);
	objects.push_front(C);
	objects.push_front(D);
	objects.push_front(E);
	const char* actual = objects.toStringReverse();
	cout << "Expected: " << expected << endl;
	cout << "Actual: " << actual << " " << endl;
	if (strcmp(actual, expected) == 0) {
		suc++;
		return true;
	}
	else {
		fail++;
		return false;
	}
}

bool Test::test_push_front_empty_deque() {
	const char* expected = "-0.02131";
	BigInt* E = new SignedBigFloat('-', "0", "02131");
	MyDeque objects;
	objects.push_front(E);
	const char* actual1 = objects.toString();
	const char* actual2 = objects.toStringReverse();
	cout << "Expected: " << expected << endl;
	cout << "Actual: " << actual1 << " " << endl;
	if ((strcmp(actual1, expected) == 0) && 
		(strcmp(actual2, expected) == 0)) {
		suc++;
		return true;
	}
	else {
		fail++;
		return false;
	}
}

bool Test::test_push_front() {
	const char* expected1 = "-0.02131 0.0 123242.2312141 2312141 112122";
	const char* expected2 = "112122 2312141 123242.2312141 0.0 -0.02131";
	BigInt* A = new BigInt("112122");
	BigInt* B = new BigInt("2312141");
	BigInt* C = new BigFloat("123242", "2312141");
	BigInt* D = new BigFloat("0", "0");
	BigInt* E = new SignedBigFloat('-', "0", "02131");
	MyDeque objects;
	objects.push_front(A);
	objects.push_front(B);
	objects.push_front(C);
	objects.push_front(D);
	objects.push_front(E);
	const char* actual1 = objects.toString();
	const char* actual2 = objects.toStringReverse();
	cout << "Expected: " << expected1 << endl;
	cout << "Actual: " << actual1 << " " << endl;
	if ((strcmp(actual1, expected1) == 0)&&
	(strcmp(actual2, expected2) == 0)){
		suc++;
		return true;
	}
	else {
		fail++;
		return false;
	}
}

bool Test::test_pop_front_empty() {
	const char* expected1 = "Empty";
	const char* expected2 = "Empty";
	MyDeque objects;
	objects.pop_front();
	const char* actual1 = objects.toString();
	const char* actual2 = objects.toStringReverse();
	cout << "Expected: " << expected1 << endl;
	cout << "Actual: " << actual1 << " " << endl;
	if ((strcmp(actual1, expected1) == 0) &&
		(strcmp(actual2, expected2) == 0)) {
		suc++;
		return true;
	}
	else {
		fail++;
		return false;
	}
}

bool Test::test_pop_front_alone() {
	const char* expected1 = "Empty";
	const char* expected2 = "Empty";
	BigInt* A = new BigFloat("123242", "2312141");
	MyDeque objects;
	objects.push_front(A);
	objects.pop_front();
	const char* actual1 = objects.toString();
	const char* actual2 = objects.toStringReverse();
	cout << "Expected: " << expected1 << endl;
	cout << "Actual: " << actual1 << " " << endl;
	if ((strcmp(actual1, expected1) == 0) &&
		(strcmp(actual2, expected2) == 0)) {
		suc++;
		return true;
	}
	else {
		fail++;
		return false;
	}
}

bool Test::test_pop_front_one() {
	const char* expected1 = "0.0 123242.2312141 2312141 112122";
	const char* expected2 = "112122 2312141 123242.2312141 0.0";
	BigInt* A = new BigInt("112122");
	BigInt* B = new BigInt("2312141");
	BigInt* C = new BigFloat("123242", "2312141");
	BigInt* D = new BigFloat("0", "0");
	BigInt* E = new SignedBigFloat('-', "0", "02131");
	MyDeque objects;
	objects.push_front(A);
	objects.push_front(B);
	objects.push_front(C);
	objects.push_front(D);
	objects.push_front(E);
	objects.pop_front();
	const char* actual1 = objects.toString();
	const char* actual2 = objects.toStringReverse();
	cout << "Expected: " << expected1 << endl;
	cout << "Actual: " << actual1 << " " << endl;
	if ((strcmp(actual1, expected1) == 0) &&
		(strcmp(actual2, expected2) == 0)) {
		suc++;
		return true;
	}
	else {
		fail++;
		return false;
	}
}

bool Test::test_pop_front_few() {
	const char* expected1 = "2312141 112122";
	const char* expected2 = "112122 2312141";
	BigInt* A = new BigInt("112122");
	BigInt* B = new BigInt("2312141");
	BigInt* C = new BigFloat("123242", "2312141");
	BigInt* D = new BigFloat("0", "0");
	BigInt* E = new SignedBigFloat('-', "0", "02131");
	MyDeque objects;
	objects.push_front(A);
	objects.push_front(B);
	objects.push_front(C);
	objects.push_front(D);
	objects.push_front(E);
	objects.pop_front();
	objects.pop_front();
	objects.pop_front();
	const char* actual1 = objects.toString();
	const char* actual2 = objects.toStringReverse();
	cout << "Expected: " << expected1 << endl;
	cout << "Actual: " << actual1 << " " << endl;
	if ((strcmp(actual1, expected1) == 0) &&
		(strcmp(actual2, expected2) == 0)) {
		suc++;
		return true;
	}
	else {
		fail++;
		return false;
	}
}

bool Test::test_pop_back_empty() {
	const char* expected1 = "Empty";
	const char* expected2 = "Empty";
	MyDeque objects;
	objects.pop_back();
	const char* actual1 = objects.toString();
	const char* actual2 = objects.toStringReverse();
	cout << "Expected: " << expected1 << endl;
	cout << "Actual: " << actual1 << " " << endl;
	if ((strcmp(actual1, expected1) == 0) &&
		(strcmp(actual2, expected2) == 0)) {
		suc++;
		return true;
	}
	else {
		fail++;
		return false;
	}
}

bool Test::test_pop_back_alone() {
	const char* expected1 = "Empty";
	const char* expected2 = "Empty";
	BigInt* A = new BigFloat("123242", "2312141");
	MyDeque objects;
	objects.push_front(A);
	objects.pop_back();
	const char* actual1 = objects.toString();
	const char* actual2 = objects.toStringReverse();
	cout << "Expected: " << expected1 << endl;
	cout << "Actual: " << actual1 << " " << endl;
	if ((strcmp(actual1, expected1) == 0) &&
		(strcmp(actual2, expected2) == 0)) {
		suc++;
		return true;
	}
	else {
		fail++;
		return false;
	}
}

bool Test::test_pop_back_one() {
	const char* expected1 = "-0.02131 0.0 123242.2312141 2312141";
	const char* expected2 = "2312141 123242.2312141 0.0 -0.02131";
	BigInt* A = new BigInt("112122");
	BigInt* B = new BigInt("2312141");
	BigInt* C = new BigFloat("123242", "2312141");
	BigInt* D = new BigFloat("0", "0");
	BigInt* E = new SignedBigFloat('-', "0", "02131");
	MyDeque objects;
	objects.push_front(A);
	objects.push_front(B);
	objects.push_front(C);
	objects.push_front(D);
	objects.push_front(E);
	objects.pop_back();
	const char* actual1 = objects.toString();
	const char* actual2 = objects.toStringReverse();
	cout << "Expected: " << expected1 << endl;
	cout << "Actual: " << actual1 << " " << endl;
	if ((strcmp(actual1, expected1) == 0) &&
		(strcmp(actual2, expected2) == 0)) {
		suc++;
		return true;
	}
	else {
		fail++;
		return false;
	}
}

bool Test::test_pop_back_few() {
	const char* expected1 = "-0.02131 0.0";
	const char* expected2 = "0.0 -0.02131";
	BigInt* A = new BigInt("112122");
	BigInt* B = new BigInt("2312141");
	BigInt* C = new BigFloat("123242", "2312141");
	BigInt* D = new BigFloat("0", "0");
	BigInt* E = new SignedBigFloat('-', "0", "02131");
	MyDeque objects;
	objects.push_front(A);
	objects.push_front(B);
	objects.push_front(C);
	objects.push_front(D);
	objects.push_front(E);
	objects.pop_back();
	objects.pop_back();
	objects.pop_back();
	const char* actual1 = objects.toString();
	const char* actual2 = objects.toStringReverse();
	cout << "Expected: " << expected1 << endl;
	cout << "Actual: " << actual1 << " " << endl;
	if ((strcmp(actual1, expected1) == 0) &&
		(strcmp(actual2, expected2) == 0)) {
		suc++;
		return true;
	}
	else {
		fail++;
		return false;
	}
}

bool Test::test_find_without_NULL() {
	bool expected = true;
	BigInt* A = new BigInt("112122");
	BigInt* B = new BigInt("2312141");
	BigInt* C = new BigFloat("123242", "2312141");
	BigInt* D = new BigFloat("0", "0");
	BigInt* E = new SignedBigFloat('-', "0", "02131");
	MyDeque objects;
	objects.push_front(A);
	objects.push_front(B);
	objects.push_front(C);
	objects.push_front(D);
	objects.push_front(E);
	bool actual = objects.find();
	cout << "Expected: " << expected << endl;
	cout << "Actual: " << actual << " " << endl;
	if (expected == actual) {
		suc++;
		return true;
	}
	else {
		fail++;
		return false;
	}
}

bool Test::test_find_with_NULL() {
	bool expected = false;
	BigInt* A = new BigInt("112122");
	BigInt* B = new BigInt("2312141");
	BigInt* C = NULL;
	BigInt* D = new BigFloat("0", "0");
	BigInt* E = new SignedBigFloat('-', "0", "02131");
	MyDeque objects;
	objects.push_front(A);
	objects.push_front(B);
	objects.push_front(C);
	objects.push_front(D);
	objects.push_front(E);
	bool actual = objects.find();
	cout << "Expected: " << expected << endl;
	cout << "Actual: " << actual << " " << endl;
	if (expected == actual) {
		suc++;
		return true;
	}
	else {
		fail++;
		return false;
	}
}