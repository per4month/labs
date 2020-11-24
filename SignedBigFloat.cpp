#include "SignedBigFloat.h"

void SignedBigFloat::writeMemory(BigFloat& obj) {
	this->setLength(obj.getLength());
	this->setArray();
	for (int i = 0; i < obj.getLength(); i++) {
		this->setLongNumberValue(i, obj.getLongNumberValue(i));
	}

	this->setLengthFloat(obj.getLengthFloat());
	this->setFloatArray();
	for (int i = 0; i < obj.getLengthFloat(); i++) {
		this->setFloatNumberValue(i, obj.getFloatNumberValue(i));
	}
}

SignedBigFloat::SignedBigFloat() : BigFloat() {
	positive = true;
}

SignedBigFloat::SignedBigFloat(const char sign, 
	const char* numInt, const char* numFloat) : BigFloat(numInt,numFloat) {
	try {
		if (sign != '-' && sign != ' ') {
			throw exception("Error! Incorrect entry of the number sign");
		}
	}
	catch (exception& ex) {
		cout << ex.what();
	}
	if (sign == '-') {
		positive = false;
	}
	else {
		positive = true;
	}
	
}

SignedBigFloat::SignedBigFloat(const char sign, 
	long numInt, long numFloat) :
	BigFloat(numInt,numFloat) {
	try {
		if (sign != '-' && sign != ' ') {
			throw exception("Error! Incorrect entry of the number sign");
		}
	}
	catch (exception& ex) {
		cout << ex.what();
	}
	if (sign == '-') {
		positive = false;
	}
	else {
		positive = true;
	}
}

SignedBigFloat::SignedBigFloat(SignedBigFloat& other) : BigFloat(other) {
	positive = other.positive;
}

SignedBigFloat::~SignedBigFloat() {

}

char* SignedBigFloat::toString() {
	int length = 0;
	int n = 0;
	if (positive) {
		length = this->getLength() + this->getLengthFloat() + 1;
		n = 0;
	}
	else {
		length = this->getLength() + this->getLengthFloat() + 2;
		n = 1;
	}
	char* str = new char[length + 1];
	if (!positive) {
		str[0] = '-';
	}
	for (int i = n, j = 0; j < this->getLength(); i++) {
		str[i] = getLongNumberValue(j++) + '0';
	}
	str[this->getLength()+n] = '.';
	for (int i = this->getLength() + (n + 1), j = 0; i < length; i++) {
		str[i] = getFloatNumberValue(j++) + '0';
	}
	str[length] = '\0';
	return str;
}

bool SignedBigFloat::getSign() {
	return this->positive;
}

void SignedBigFloat::setSign(bool pos) {
	this->positive = pos;
}

void SignedBigFloat::add(SignedBigFloat& numOne,
	SignedBigFloat& numTwo) {
	bool pos = true;
	char* tempIntOne = numOne.toStringInt();
	char* tempFloatOne = numOne.toStringFloat();
	char* tempIntTwo = numTwo.toStringInt();
	char* tempFloatTwo = numTwo.toStringFloat();
	BigFloat tempOne(tempIntOne, tempFloatOne);
	BigFloat tempTwo(tempIntTwo, tempFloatTwo);
	if (numOne.positive && numTwo.positive) {
		tempOne.add(tempOne, tempTwo);
		numOne.writeMemory(tempOne);
		positive = true;
	}
	else if (numOne.positive && !numTwo.positive) {
		numTwo.positive = true;
		pos = tempOne.deduct(tempOne, tempTwo);
		numOne.writeMemory(tempOne);
		positive = pos;
	}
	else if (!numOne.positive && numTwo.positive) {
		numOne.positive = true;
		pos = tempTwo.deduct(tempTwo, tempOne);
		numOne.writeMemory(tempTwo);
		positive = pos;
	}
	else if (!numOne.positive && !numTwo.positive) {
		tempOne.add(tempTwo, tempOne);
		numOne.writeMemory(tempOne);
		positive = false;
	}
}

void SignedBigFloat::multiply(SignedBigFloat& numOne,
	SignedBigFloat& numTwo) {
	char* tempIntOne = numOne.toStringInt();
	char* tempFloatOne = numOne.toStringFloat();
	char* tempIntTwo = numTwo.toStringInt();
	char* tempFloatTwo = numTwo.toStringFloat();
	BigFloat tempOne(tempIntOne, tempFloatOne);
	BigFloat tempTwo(tempIntTwo, tempFloatTwo);
	tempOne.multiply(tempOne, tempTwo);
	numOne.writeMemory(tempOne);
	if ((numOne.positive && numTwo.positive) ||
		(!numOne.positive && !numTwo.positive)) {
		positive = true;
	}
	else {
		positive = false;
	}
}

void SignedBigFloat::deduct(SignedBigFloat& numOne,
	SignedBigFloat& numTwo) {
	bool pos = true;
	char* tempIntOne = numOne.toStringInt();
	char* tempFloatOne = numOne.toStringFloat();
	char* tempIntTwo = numTwo.toStringInt();
	char* tempFloatTwo = numTwo.toStringFloat();
	BigFloat tempOne(tempIntOne, tempFloatOne);
	BigFloat tempTwo(tempIntTwo, tempFloatTwo);
	if (numOne.positive && numTwo.positive) {
		pos = tempOne.deduct(tempOne, tempTwo);
		numOne.writeMemory(tempOne);
		positive = pos;
	}
	else if (numOne.positive && !numTwo.positive) {
		numTwo.positive = true;
		tempOne.add(tempOne, tempTwo);
		numOne.writeMemory(tempOne);
		positive = pos;
	}
	else if (!numOne.positive && numTwo.positive) {
		tempOne.add(tempOne, tempTwo);
		numOne.writeMemory(tempOne);
		positive = false;
	}
	else if (!numOne.positive && !numTwo.positive) {
		numOne.positive = true;
		numOne.positive = true;
		pos = tempOne.deduct(tempTwo, tempOne);
		numOne.writeMemory(tempOne);
		positive = pos;
	}
}