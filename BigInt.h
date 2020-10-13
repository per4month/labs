#pragma once
class BigInt
{
public:
	//---------------������������:----------------

	//BigInt::BigInt()
	//����������� �� ��������� (����� ������� = 1, ������� ������� = 0)
	//args:
	//- ��� ������� ���������� -
	// - ������ ������ �� ��������� -
	BigInt();

	//BigInt::BigInt(long num)
	//�����������, ����������� ��� long
	//args:
	//- long num - ������� ������������� �����
	// - ������ ������ �� �������� ��������� long-
	BigInt(long num); 

	//BigInt::BigInt(const char* s)
	//�����������, ����������� ��� const char* s
	//args:
	//- const char* s - ������ �������� 
	// - ������ ������ �� �������� ��������� const char* s -
	BigInt(const char* s);

	//BigInt::BigInt(BigInt &other)
	//�����������, �������� ����� ������� �������
	//args:
	//- BigInt &other - ������ ��� �����������
	// - ������ ����� �������� ������� -
	BigInt(const BigInt &other);

	//---------------����������:----------------

	//BigInt::~BigInt()
	//����������
	//args:
	//- ��� ������� ���������� - 
	// - ������� ������������ ������ ������� -
	~BigInt();

	//---------------�������:-------------------

	//int BigInt::getLength()
	//������� �������� ����� ����� � �������
	//args:
	//- ��� ������� ���������� - 
	//return - ����� ����� � �������
	int getLength(); 

	//int BigInt::getLongNumberValue(int i)
	//������� �������� �������� ������� �������� ����� � ������� i
	//args:
	//int i - ���������� ����� ������� �����
	//return - ������� ������� �������� ����� � ������� i
	int getLongNumberValue(int i);

	//int BigInt::getNumber()
	//������� �������� ����������� ���������� ���-�� ��������� ��������
	//args:
	//- ��� ������� ���������� -
	//return - ���-�� ��������� ��������
	static int getNumber();

	//---------------�������:-------------------

	//void BigInt::setLength(int currentLength)
	//������� ������������� ����� �������� ����� currentLength
	//args:
	//int currentLength - ������� ����� ��� ������
	//- ������������� � ������ ����� �������� ����� currentLength -
	void setLength(int currentLength); 

	//void BigInt::setLongNumberValue(int i, int value)
	//������� ������������� ����� �������� ����� value � ������ i
	//args:
	//int i - ���������� ����� ������� ����� 
	//int value - ����� ��������������� �������� �������
	//- ������������� ����� �������� ����� value � ������ i -
	void setLongNumberValue(int i, int value);
	
	//void BigInt::setArray()
	//������� ������ ����� ������ �������� ����� ����������� length
	//args:
	//- ��� ������� ���������� -
	//- �������� ����� ������ ����� -
	void setArray();

	//------������� ��� ������ � ��������� ������:------

	//void BigInt::add(BigInt& numOne, BigInt& numTwo)
	//������� ��������
	//args:
	//BigInt& numOne - ������ ������
	//BigInt& numTwo - ������ ������
	//- ������������ ��� ����� ���� �������� -
	void add(BigInt& numOne, BigInt& numTwo);

	//void BigInt::multiply(BigInt& numOne, BigInt& numTwo)
	//������� ���������
	//args:
	//BigInt& numOne - ������ ������
	//BigInt& numTwo - ������ ������
	//- ���������� ��� ����� ���� �������� -
	void multiply(BigInt& numOne, BigInt& numTwo);

	//void BigInt::deduct(BigInt& numOne, BigInt& numTwo)
	//������� ���������
	//args:
	//BigInt& numOne - ������ ������
	//BigInt& numTwo - ������ ������
	//- ���������� �� ������� ����� ������� ������� ������ ����� ������� ������� -
	void deduct(BigInt& numOne, BigInt& numTwo);

	//const char* BigInt::divide(BigInt& numOne, BigInt& numTwo)
	//������� �������
	//args:
	//BigInt& numOne - ������ ������
	//BigInt& numTwo - ������ ������
	//return - ������� �����
	const char* divide(BigInt& numOne, BigInt& numTwo);

	//const char* BigInt::convertTo(int base)
	//������� �������� ����� � ������ ������� ���������
	//args:
	//int base - �����, � ������� ������� ����� ���������
	//return - ����������� ����� � base-������� ����������
	const char* convertTo(int base);

	//char* BigInt::toString()
	//������� �������� ����� �� ������� int � ������ char
	//args:
	//- ��� ������� ���������� -
	//return - ������ �������� char (����� �������)
	char* toString();

	//-----------------���������� ����������--------------

	//BigInt operator+(BigInt& obj1, BigInt& obj2)
	//���������� ��������� �������� (����������� ����� ������������� �������)
	//args:
	//BigInt& obj1 � BigInt& obj2 - ���������
	//return - result - ������ �����
	friend BigInt operator+(BigInt& obj1, BigInt& obj2);

	//BigInt operator+(BigInt& obj1, BigInt& obj2)
	//���������� ��������� ��������� (����������� ����� ������������� �������)
	//args:
	//BigInt& obj1 - ����������� � BigInt& obj2 - ����������
	//return - result - ������ ��������
	friend BigInt operator-(BigInt& obj1, BigInt& obj2);

	//BigInt BigInt::operator*(int number)
	//���������� ��������� ��������� �� 10^n (int) (����������� ����� ����� ������)
	//args:
	//int number - ����� 10^n
	//return - result - ������ ������������
	BigInt operator*(int number);
	
	//BigInt BigInt::operator*(long long number)
	//���������� ��������� ��������� �� 10^n (long long) (����������� ����� ����� ������)
	//args:
	//long long number - ����� 10^n
	//return - result - ������ ������������
	BigInt operator*(long long number);

	//BigInt BigInt::operator*(unsigned long long number)
	//���������� ��������� ��������� �� 10^n (unsigned long long) (����������� ����� ����� ������)
	//args:
	//unsigned long long number - ����� 10^n
	//return - result - ������ ������������
	BigInt operator*(unsigned long long number);

	//BigInt BigInt::operator/(int number)
	//���������� ��������� ������� �� 10^n (int) (����������� ����� ����� ������)
	//args:
	//int number - ����� 10^n
	//return - result - ������ ������������
	BigInt operator/(int number);

	//BigInt BigInt::operator/(long long number)
	//���������� ��������� ������� �� 10^n (long long) (����������� ����� ����� ������)
	//args:
	//long long number - ����� 10^n
	//return - result - ������ ������������
	BigInt operator/(long long number);

	//BigInt BigInt::operator/(unsigned long long number)
	//���������� ��������� ������� �� 10^n (unsigned long long) (����������� ����� ����� ������)
	//args:
	//unsigned long long number - ����� 10^n
	//return - result - ������ ������������
	BigInt operator/(unsigned long long number);

	//BigInt& BigInt::operator= (const BigInt& obj)
	//���������� ��������� ������������ (������ ����� ����� ������)
	//args:
	//const BigInt& obj - ������������� ������
	//return - *this - ������ ������������
	BigInt& operator=(const BigInt& obj);

	//BigInt& BigInt::operator unsigned long()
	//���������� ������� ���������� � ���� unsigned long
	//args:
	//- ��� ������� ���������� -
	//return - ����� ���� unsigned long
	operator unsigned long();

	

private:
	//------------����������:-------------

	//����� �����
	int length; 

	//�����
	int *longNumber;

	//���-�� ��������
	static int counter;

	//--------���.������� ��� ������ � public ��������-------------------

	//void BigInt::addNull(int maxLength, int tempArray[], BigInt& object)
	//������� ���������� �������� ����� ����� ������ (���. � ��������)
	//args:
	//int maxLength - ���������� ����� ����� ���� ��������
	//int tempArray[] - ������ �������� �� ���� �����, � ������� ����� ����
	//BigInt& object - ������ � ������� ������
	//-��������� �������� ���� ����� ���������� ������-
	void addNull(int maxLength, int tempArray[], BigInt& object);

	//void BigInt::sum(int maxLength, int resultArray[], int tempArray[], int &carry, BigInt& object)
	//������� ������������ (���. � ��������)
	//args:
	//int maxLength - ���������� ����� ����� ���� ��������
	//int resultArray[] - ������ ���������� ��������
	//int tempArray[] - ������ �������� �� ���� �����, �� ��������� ������,
	//int& carry - ���. �������
	//BigInt& object - ������ � ������� ������ �����
	//- ��������� ��� ����� -
	void sum(int maxLength, int resultArray[], int tempArray[], int& carry, BigInt& object);

	//int* BigInt::addMemory(int &maxLength, int tempArray[], int resultArray[], int &carry)
	//������� ���������� ����� ������ ������� (���������� ������) (���. � ��������)
	//args:
	//int maxLength - ���������� ����� ����� ���� ��������
	//int resultArray[] - ������ ���������� ��������
	//int tempArray[] - ������ �������� �� ���� �����, �� ��������� ������,
	//int& carry - ���. �������
	//return - resultArray[] - ������ � ��� ���������
	int* addMemory(int& maxLength, int tempArray[], int resultArray[], int& carry);

	//int* BigInt::reverseArray(BigInt& object)
	//������� ��������������� ������� ����� (���. � ���������, ���������, �������)
	//args:
	//BigInt& object - ����������� ������, ����� �������� ����� �����������
	//return - ������������ ������ ����� �������
	int* reverseArray(BigInt& object);

	//int* BigInt::makeArrayForSub(BigInt& object, int currentLength)
	//������� �������������� ������ � ��������� �������� ���� � ����� (���.� ���������)
	//args:
	//BigInt& object - ����������� ������, ����� �������� ����� ����������� � �������� ����. ����
	//int currentLength - ���������� ����� �� ���� �����
	//return - ������������ ������ ����� ������� �� ��������� ������
	int* makeArrayForSub(BigInt& object, int currentLength);

	//int BigInt::digitToInt(char num)
	//������� ��������� ������ � ���������� ��� �������� � int (���. � �������� ��)
	//args:
	//char num - ������, ������� ����� ��������� � int
	//return - �������� ������� � int
	int digitToInt(char num);

	//int BigInt::digitToChar(int num)
	//������� ��������� �������� � int � ��������� ��� � �������������� ������ (���. � �������� ��)
	//args:
	//int num - �������� int, ������� ����� ��������� � ������
	//return - ������ �������� int
	char digitToChar(int num);

	//int BigInt::helpConvert(char* a, int base, char* c)
	//����������� �� 10-CC � base-��
	//args:
	//char* a - ������� ������ ��������
	//int base - �� ��� �������� � ��
	//char* c - ���������������� ������ ��������
	//return - ���-�� �������� � �������� �������
	int helpConvert(char* a, int base, char* c);

	//int BigInt::compare(BigInt& numOne, BigInt& numTwo, int& currentLength)
	//������� ��������� ����� ���� ��������
	//args:
	//int& currentLength - ������������ ����� �� ���� �����
	//return - �������� ���������
	int compare(BigInt& numOne, BigInt& numTwo, int& currentLength);

	//int* BigInt::sub(BigInt& obj1, BigInt& obj2, int currentLength)
	//������� ��������� ����� ������� 2 �� ����� ������� 1 (���. � ���������)
	//args:
	//BigInt& obj1 - �����������
	//BigInt& obj2 - ����������
	//int currentLength - ����� �����������
	//return - ������ �������� ���� �����
	int* sub(BigInt& obj1, BigInt& obj2, int currentLength);

	//int* BigInt::mult(int tempA[], int tempB[], int lenA, int lenB, int &maxLength )
	//������� ��������� ���� ����� � �������� (���. � ���������, �������)
	//args:
	//int tempA[] - ��������� 1
	//int tempB[] - ��������� 2
	//int lenA - ����� ����� ��������� 1
	//int lenB - ����� ����� ��������� 2
	//int &maxLength - ����� ��������������� �������
	//return - ������ ������������
	int* mult(int tempA[], int tempB[], int lenA, int lenB, int& maxLength);

	//void BigInt::reverseArrayForDiv(int tempArray[], int len)
	//������� �������������� ������ ����� ������� (���. � �������)
	//args:
	//int tempArray[] - ������, ������� ����� �����������
	//int len - ����� ��������� �������
	//- �������������� �������� ������ - 
	void reverseArrayForDiv(int tempArray[], int len);

	//bool BigInt::cmp(int arrayOne[], int arrayTwo[], int lengthOne, int lengthTwo)
	//������� ���������� ����� � ��������
	//args:
	//int arrayOne[] - ������ �����
	//int arrayTwo[] - ������ �����
	//int lengthOne - ����� ������� �����
	//int lengthTwo - ����� ������� �����
	//return - �������� ���������
	bool cmp(int arrayOne[], int arrayTwo[], int lengthOne, int lengthTwo);
	
	//void BigInt::subForDiv(int tempArrayOne[], int tempArrayTwo[], int currentLength)
	//������� ��������� ����� � �������� (���. � �������)
	//args:
	//int tempArrayOne[] - �����������
	//int tempArrayTwo[] - ����������
	//int currentLength - ����� �����������
	//- �������� ����������� � tempArrayOne[] -
	void subForDiv(int tempArrayOne[], int tempArrayTwo[], int currentLength);

	//void BigInt::searchLenght(int &lenght, int tempArray[])
	//������� ������ ����� ������� ����� ��� �������� ����� (���. � �������)
	//args:
	//int tempArray[] - �������� ������ �� ��������� ������
	//int &lenght - ���������� �����
	//- ������ ����� -
	void searchLenght(int& lenght, int tempArray[]);

	//void BigInt::putValue (BigInt& object, int currentLength, int tempArray[])
	//������� ��������� �������� ������� ����� � ������ (���. � �������)
	//args:
	//BigInt& object - ����������� ������
	//int currentLength - ����� ������� �����
	//int tempArray[] - ������ �����
	//- � ������ ������������ ������ ����� -
	void putValue(BigInt& object, int currentLength, int tempArray[]);

};