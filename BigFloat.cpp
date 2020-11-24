#include "BigFloat.h"

char* BigFloat::toStringConcat() {
	int length = this->getLength() + lengthFloat;
	char* str = new char[length + 1];
	for (int i = 0; i < this->getLength(); i++) {
		str[i] = getLongNumberValue(i) + '0';
	}
	for (int i = this->getLength(), j = 0; i < length; i++) {
		str[i] = floatNumber[j++] + '0';
	}
	str[length] = '\0';
	return str;
}

char* BigFloat::addNulls(BigFloat& obj, int length) {
	char* temp = new char[length + 1];
	for (int i = 0; i < obj.getLength(); i++) {
		temp[i] = obj.getLongNumberValue(i) + '0';
	}
	for (int i = obj.getLength(), j = 0; i < length; i++) {
		if (j < obj.lengthFloat) {
			temp[i] = obj.floatNumber[j++] + '0';
		}
		else {
			temp[i] = '0';
		}
	}
	temp[length] = '\0';
	return temp;
}

BigFloat::BigFloat() : BigInt() {
	lengthFloat = 1;
	floatNumber = new int[lengthFloat];
	floatNumber[0] = 0;
	//cout << "Construktor Float" << endl;
}

BigFloat::BigFloat(long numInt, long numFloat) :BigInt(numInt) {
	lengthFloat = 0;
	long buffer = numFloat;
	lengthFloat = 1;
	while ((buffer /= 10) > 0)
	{
		lengthFloat++;
	}
	floatNumber = new int[lengthFloat];
	for (int i = lengthFloat - 1; i >= 0; i--)
	{
		floatNumber[i] = numFloat % 10;
		numFloat /= 10;
	}
	//cout << "Construktor Float" << endl;
}

BigFloat::BigFloat(const char* numInt, 
	const char* numFloat):BigInt(numInt) {
	try {
		lengthFloat = 0;
		int count = 0;
		for (int i = 0; numFloat[i] != '\0'; i++) {
			lengthFloat++;
			if (numFloat[i] >= '0' && numFloat[i] <= '9') {
				count++;
			}
		}
		if (lengthFloat == count) {
			floatNumber = new int[lengthFloat];
			for (int i = 0; numFloat[i] != '\0'; i++)
				floatNumber[i] = numFloat[i] - '0';
		}
		else {
			throw exception("Error! Invalid keyboard input.");
		}
	}
	catch (std::exception& ex) {
		lengthFloat = 1;
		floatNumber = new int[lengthFloat];
		floatNumber[0] = 0;
		std::cerr << ex.what() << std::endl;
	}
	//cout << "Construktor Float" << endl;
}

BigFloat::BigFloat(const BigFloat& other): BigInt(other) {
	lengthFloat = other.lengthFloat;
	floatNumber = new int[lengthFloat];
	for (int i = 0; i < lengthFloat; i++)
	{
		floatNumber[i] = other.floatNumber[i];
	}
	//cout << "Construktor Float" << endl;
}

BigFloat::~BigFloat() {
	delete[] floatNumber;
	//cout << "Destruktor Float" << endl;
}

int BigFloat::getLengthFloat() {
	return lengthFloat;
}

int BigFloat::getFloatNumberValue(int i) {
	return floatNumber[i];
}

void BigFloat::setLengthFloat(int currentLength) {
	lengthFloat = currentLength;
}

void BigFloat::setFloatNumberValue(int i, int value) {
	floatNumber[i] = value;
}

void BigFloat::setFloatArray() {
	delete[] floatNumber;
	floatNumber = NULL;
	floatNumber = new int[lengthFloat];
}

char* BigFloat::toString() {
	
	int length = this->getLength() + lengthFloat + 1;
	char* str = new char[length + 1];
	for (int i = 0; i < this->getLength(); i++) {
		str[i] = getLongNumberValue(i) + '0';
	}
	str[this->getLength()] = '.';
	for (int i = this->getLength()+1, j = 0; i < length; i++) {
		str[i] = floatNumber[j++] + '0';
	}
	str[length] = '\0';
	return str;
}

char* BigFloat::toStringInt() {
	int length = this->getLength();
	char* str = new char[length + 1];
	for (int i = 0; i < this->getLength(); i++) {
		str[i] = getLongNumberValue(i) + '0';
	}
	str[length] = '\0';
	return str;
}

char* BigFloat::toStringFloat() {
	int length = lengthFloat;
	char* str = new char[length + 1];
	for (int i = 0; i < length; i++) {
		str[i] = floatNumber[i] + '0';
	}
	str[length] = '\0';
	return str;
}

void BigFloat::add(BigFloat& numOne, BigFloat& numTwo) {
	int tempLengthOne = numOne.getLength() + numOne.lengthFloat;
	int tempLengthTwo = numTwo.getLength() + numTwo.lengthFloat;
	int maxLengthFloat = 0;
	if (numOne.lengthFloat > numTwo.lengthFloat) {
		maxLengthFloat = numOne.lengthFloat;
		tempLengthTwo = tempLengthTwo +
			numOne.lengthFloat - numTwo.lengthFloat;
	}
	else {
		maxLengthFloat = numTwo.lengthFloat;
		tempLengthOne = tempLengthOne +
			numTwo.lengthFloat - numOne.lengthFloat;
	}
	const char* tempOne = addNulls(numOne, tempLengthOne);
	const char* tempTwo = addNulls(numTwo, tempLengthTwo);
	BigInt obj1(tempOne);
	BigInt obj2(tempTwo);
	obj1.add(obj1, obj2);
	
	int lengthInt = obj1.getLength() - maxLengthFloat;
	this->setLength(lengthInt);
	this->setArray();
	for (int i = 0; i < lengthInt; i++) {
		this->setLongNumberValue(i, obj1.getLongNumberValue(i));
	}

	this->setLengthFloat(maxLengthFloat);
	this->setFloatArray();
	for (int i = lengthInt, j = 0; i < obj1.getLength(); i++) {
		this->setFloatNumberValue(j++, obj1.getLongNumberValue(i));
	}
}

void BigFloat::multiply(BigFloat& numOne, BigFloat& numTwo) {
	int tempLengthOne = numOne.getLength() + numOne.lengthFloat;
	int tempLengthTwo = numTwo.getLength() + numTwo.lengthFloat;
	int afterDot = numOne.lengthFloat + numTwo.lengthFloat;
	char* tempOne = numOne.toStringConcat();
	char* tempTwo = numTwo.toStringConcat();
	BigInt obj1(tempOne);
	BigInt obj2(tempTwo);
	obj1.multiply(obj1, obj2);
	if (obj1.getLength() <= afterDot) {
		
		this->setLength(1);
		this->setArray();
		this->setLongNumberValue(0, 0);

		this->setLengthFloat(afterDot);
		this->setFloatArray();
		for (int i = 0; i < afterDot - obj1.getLength(); i++) {
			this->setFloatNumberValue(i, 0);
		}
		for (int i = afterDot - obj1.getLength(), j = 0; i < afterDot; i++) {
			this->setFloatNumberValue(i, obj1.getLongNumberValue(j++));
		}
	}
	else {
		int lengthInt = obj1.getLength() - afterDot;
		this->setLength(lengthInt);
		this->setArray();
		for (int i = 0; i < lengthInt; i++) {
			this->setLongNumberValue(i, obj1.getLongNumberValue(i));
		}

		this->setLengthFloat(afterDot);
		this->setFloatArray();
		for (int i = lengthInt, j = 0; i < obj1.getLength(); i++) {
			this->setFloatNumberValue(j++, obj1.getLongNumberValue(i));
		}
	}
}

bool BigFloat::deduct(BigFloat& numOne, BigFloat& numTwo) {
	bool pos = true;
	int tempLengthOne = numOne.getLength() + numOne.lengthFloat;
	int tempLengthTwo = numTwo.getLength() + numTwo.lengthFloat;
	int maxLengthFloat = 0;
	if (numOne.lengthFloat > numTwo.lengthFloat) { //для того, чтобы точка стояла друг под другом
		maxLengthFloat = numOne.lengthFloat;
		tempLengthTwo = tempLengthTwo +
			numOne.lengthFloat - numTwo.lengthFloat;
	}
	else {
		maxLengthFloat = numTwo.lengthFloat;
		tempLengthOne = tempLengthOne +
			numTwo.lengthFloat - numOne.lengthFloat;
	}
	const char* tempOne = addNulls(numOne, tempLengthOne);
	const char* tempTwo = addNulls(numTwo, tempLengthTwo);
	BigInt obj1(tempOne);
	BigInt obj2(tempTwo);
	pos = obj1.deduct(obj1, obj2);

	if (obj1.getLength() <= maxLengthFloat) {
		this->setLength(1);
		this->setArray();
		this->setLongNumberValue(0, 0);

		this->setLengthFloat(maxLengthFloat);
		this->setFloatArray();
		for (int i = 0; i < maxLengthFloat - obj1.getLength(); i++) {
			this->setFloatNumberValue(i, 0);
		}
		for (int i = maxLengthFloat - obj1.getLength(), j = 0; i < maxLengthFloat; i++) {
			this->setFloatNumberValue(i, obj1.getLongNumberValue(j++));
		}
	}
	else {
		int lengthInt = obj1.getLength() - maxLengthFloat;
		this->setLength(lengthInt);
		this->setArray();
		for (int i = 0; i < lengthInt; i++) {
			this->setLongNumberValue(i, obj1.getLongNumberValue(i));
		}

		this->setLengthFloat(maxLengthFloat);
		this->setFloatArray();
		for (int i = lengthInt, j = 0; i < obj1.getLength(); i++) {
			this->setFloatNumberValue(j++, obj1.getLongNumberValue(i));
		}
	}
	return pos;
}
