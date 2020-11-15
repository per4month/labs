#include "Test.h"
#include "SignedBigFloat.h"
#include <iostream>
using namespace std;

Test::Test() {
	suc = 0;
	fail = 0;
}

bool Test::test_constructror_bigfloat_default() {
	const char* expected = "0.0";
	BigFloat obj;
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

bool Test::test_constructror_bigfloat_long() {
	const char* expected = "12441.435467";
	BigFloat obj(12441,435467);
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

bool Test::test_constructror_bigfloat_char() {
	const char* expected = "2325323632.484684558";
	BigFloat obj("2325323632","484684558");
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

bool Test::test_constructror_bigfloat_copy() {
	const char* expected = "53.484684";
	BigFloat obj1("53", "484684");
	BigFloat obj2(obj1);
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

bool Test::test_bigfloat_add_null() {
	const char* expected = "123.824749";
	BigFloat obj1;
	BigFloat obj2("123","824749");
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

bool Test::test_bigfloat_add_number1() {
	const char* expected = "12478.70003663632";
	BigFloat obj1("53", "484684");
	BigFloat obj2("12425","21535263632");
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

bool Test::test_bigfloat_add_number2() {
	const char* expected = "1.12635264";
	BigFloat obj1("0", "99895454");
	BigFloat obj2("0", "12739810");
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

bool Test::test_bigfloat_deduct_number_equal() {
	const char* expected = "0.000";
	BigFloat obj1("4", "454");
	BigFloat obj2("4", "454");
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

bool Test::test_bigfloat_deduct_number1() {
	const char* expected = "445.1029149";
	BigFloat obj1("1242", "2412149");
	BigFloat obj2("797", "1383");
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

bool Test::test_bigfloat_deduct_number2() {
	const char* expected = "0.01872425";
	BigFloat obj1("0", "2344");
	BigFloat obj2("0", "21567575");
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

bool Test::test_bigfloat_mult_null() {
	const char* expected = "0.00000";
	BigFloat obj1("2342", "2344");
	BigFloat obj2;
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

bool Test::test_bigfloat_mult_number1() {
	const char* expected = "288385835.58381538656";
	BigFloat obj1("2342", "2344");
	BigFloat obj2("123124","2422124");
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

bool Test::test_bigfloat_mult_number2() {
	const char* expected = "0.2266648";
	BigFloat obj1("0", "2344");
	BigFloat obj2("0", "967");
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

bool Test::test_constructror_signedbigfloat_default() {
	const char* expected = "0.0";
	SignedBigFloat obj;
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

bool Test::test_constructror_signedbigfloat_positive_long() {
	const char* expected = "12441.435467";
	SignedBigFloat obj(' ', 12441, 435467);
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

bool Test::test_constructror_signedbigfloat_negative_long() {
	const char* expected = "-12441.435467";
	SignedBigFloat obj('-', 12441, 435467);
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

bool Test::test_constructror_signedbigfloat_positive_char() {
	const char* expected = "99.32523";
	SignedBigFloat obj(' ', "99", "32523");
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

bool Test::test_constructror_signedbigfloat_negative_char() {
	const char* expected = "-99.32523";
	SignedBigFloat obj('-', "99", "32523");
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

bool Test::test_constructror_signedbigfloat_copy() {
	const char* expected = "-53.484684";
	SignedBigFloat obj1('-',"53", "484684");
	SignedBigFloat obj2(obj1);
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

bool Test::test_signedbigfloat_pos_add_pos() {
	const char* expected = "1.12635264";
	SignedBigFloat obj1(' ',"0", "99895454");
	SignedBigFloat obj2(' ',"0", "12739810");
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

bool Test::test_signedbigfloat_neg_add_pos1() {
	const char* expected = "-0.87155644";
	SignedBigFloat obj1('-', "0", "99895454");
	SignedBigFloat obj2(' ', "0", "12739810");
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

bool Test::test_signedbigfloat_neg_add_pos2() {
	const char* expected = "0.20502632";
	SignedBigFloat obj1('-', "0", "12244155");
	SignedBigFloat obj2(' ', "0", "32746787");
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

bool Test::test_signedbigfloat_pos_add_neg1() {
	const char* expected = "0.49500868";
	SignedBigFloat obj1(' ', "0", "82247655");
	SignedBigFloat obj2('-', "0", "32746787");
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

bool Test::test_signedbigfloat_pos_add_neg2() {
	const char* expected = "-0.30401787";
	SignedBigFloat obj1(' ', "0", "02345");
	SignedBigFloat obj2('-', "0", "32746787");
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

bool Test::test_signedbigfloat_neg_add_neg() {
	const char* expected = "-11894.78084766";
	SignedBigFloat obj1('-', "8658", "34646321");
	SignedBigFloat obj2('-', "3236", "43438445");
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

bool Test::test_signedbigfloat_pos_ded_pos1() {
	const char* expected = "5421.91207876";
	SignedBigFloat obj1(' ', "8658", "34646321");
	SignedBigFloat obj2(' ', "3236", "43438445");
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

bool Test::test_signedbigfloat_pos_ded_pos2() {
	const char* expected = "-1339.55652555";
	SignedBigFloat obj1(' ', "1896", "87785890");
	SignedBigFloat obj2(' ', "3236", "43438445");
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

bool Test::test_signedbigfloat_neg_ded_pos1() {
	const char* expected = "-37879.75991645";
	SignedBigFloat obj1('-', "34643", "3255320");
	SignedBigFloat obj2(' ', "3236", "43438445");
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

bool Test::test_signedbigfloat_neg_ded_pos2() {
	const char* expected = "-5133.31224335";
	SignedBigFloat obj1('-', "1896", "87785890");
	SignedBigFloat obj2(' ', "3236", "43438445");
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

bool Test::test_signedbigfloat_pos_ded_neg() {
	const char* expected = "5133.31224335";
	SignedBigFloat obj1(' ', "1896", "87785890");
	SignedBigFloat obj2('-', "3236", "43438445");
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

bool Test::test_signedbigfloat_neg_ded_neg1() {
	const char* expected = "-0.08978901";
	SignedBigFloat obj1('-', "0", "21224255");
	SignedBigFloat obj2('-', "0", "12245354");
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

bool Test::test_signedbigfloat_neg_ded_neg2() {
	const char* expected = "0.60712775";
	SignedBigFloat obj1('-', "0", "32521578");
	SignedBigFloat obj2('-', "0", "93234353");
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

bool Test::test_signedbigfloat_pos_mult_pos1() {
	const char* expected = "0.0076620837768";
	SignedBigFloat obj1(' ', "0", "32521578");
	SignedBigFloat obj2(' ', "0", "02356");
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

bool Test::test_signedbigfloat_pos_mult_pos2() {
	const char* expected = "698057.2256522078422";
	SignedBigFloat obj1(' ', "214", "32521578");
	SignedBigFloat obj2(' ', "3256", "99999");
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

bool Test::test_signedbigfloat_neg_mult_pos() {
	const char* expected = "-16.229745";
	SignedBigFloat obj1('-', "2", "345");
	SignedBigFloat obj2(' ', "6", "921");
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

bool Test::test_signedbigfloat_pos_mult_neg() {
	const char* expected = "-91.927647";
	SignedBigFloat obj1(' ', "12", "543");
	SignedBigFloat obj2('-', "7", "329");
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

bool Test::test_signedbigfloat_neg_mult_neg() {
	const char* expected = "91.927647";
	SignedBigFloat obj1('-', "12", "543");
	SignedBigFloat obj2('-', "7", "329");
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