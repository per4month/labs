#include <iostream>
#include <fstream>
#include "MyDeque.h"
#include "SignedBigFloat.h"
#include "Test.h"
using namespace std;

int main()
{
	Test test;
	cout << "---------------------------------" << endl;
	cout << "Test 1 (polymorphism toString())" << endl;
	cout << test.test_polymorph_toString() << endl;
	cout << "---------------------------------" << endl;
	cout << "Test 2 (deque to string)" << endl;
	cout << test.test_toString() << endl;
	cout << "---------------------------------" << endl;
	cout << "Test 3 (deque to string reverse)" << endl;
	cout << test.test_toStringReverse() << endl;
	cout << "---------------------------------" << endl;
	cout << "Test 4 (push front to empty deque)" << endl;
	cout << test.test_push_front_empty_deque() << endl;
	cout << "---------------------------------" << endl;
	cout << "Test 5 (push front to deque)" << endl;
	cout << test.test_push_front() << endl;
	cout << "---------------------------------" << endl;
	cout << "Test 6 (pop front empty deque)" << endl;
	cout << test.test_pop_front_empty() << endl;
	cout << "---------------------------------" << endl;
	cout << "Test 7 (pop front alone element in deque)" << endl;
	cout << test.test_pop_front_alone() << endl;
	cout << "---------------------------------" << endl;
	cout << "Test 8 (pop front one element from deque)" << endl;
	cout << test.test_pop_front_one() << endl;
	cout << "---------------------------------" << endl;
	cout << "Test 9 (pop front few elements from deque)" << endl;
	cout << test.test_pop_front_few() << endl;
	cout << "---------------------------------" << endl;
	cout << "Test 10 (pop back empty deque)" << endl;
	cout << test.test_pop_back_empty() << endl;
	cout << "---------------------------------" << endl;
	cout << "Test 11 (pop back alone element in deque)" << endl;
	cout << test.test_pop_back_alone() << endl;
	cout << "---------------------------------" << endl;
	cout << "Test 12 (pop back one element from deque)" << endl;
	cout << test.test_pop_back_one() << endl;
	cout << "---------------------------------" << endl;
	cout << "Test 13 (pop front few elements from deque)" << endl;
	cout << test.test_pop_back_few() << endl;
	cout << "---------------------------------" << endl;
	cout << "Test 14 (func find() - deque without NULL elements)" << endl;
	cout << test.test_find_without_NULL() << endl;
	cout << "---------------------------------" << endl;
	cout << "Test 15 (func find() - deque with NULL element)" << endl;
	cout << test.test_find_with_NULL() << endl;
	cout << "---------------------------------" << endl;
	cout << "Successful tests: " << test.suc << endl;
	cout << "Failed tests: " << test.fail << endl;
	cin.get();
}