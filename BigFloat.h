#pragma once
#include "BigInt.h"
class BigFloat : public BigInt
{
public:
	//---------------������������:----------------

	//BigFloat::BigFloat()
	//����������� ������� ����� �� ��������� 
	//args:
	//- ��� ������� ���������� -
	// - ������ ������ �� ��������� -
	BigFloat();

	//BigFloat::BigFloat(long numInt, long numFloat)
	//����������� ������� �����, ����������� ���� long
	//args:
	//- long numInt - ������� ������������� �����
	//- long numFloat - ������� ������� �����
	//- ������ ������ �� ������� ���������� long -
	BigFloat(long numInt, long numFloat);

	//BigFloat::BigFloat(const char* numInt, const char* numFloat)
	//����������� ������� �����, ����������� ���� const char*
	//args:
	//- const char* numInt - ������ �������� ����� �����
	//- const char* numFloat - ������ �������� ������� �����
	// - ������ ������ �� ������� ���������� const char*  -
	BigFloat(const char* numInt, const char* numFloat);

	//BigFloat::BigFloat(BigFloat &other)
	//����������� ������������, �������� ����� ������� ������� ����� ������
	//args:
	//- BigFloat &other - ������ ��� �����������
	// - ������ ����� �������� ������� -
	BigFloat(const BigFloat& other);

	//---------------����������:----------------

	//BigFloat::~BigFloat()
	//����������
	//args:
	//- ��� ������� ���������� - 
	// - �������� ������� -
	~BigFloat();

	//---------------�������:-------------------

	//int BigFloat::getLengthFloat()
	//������� �������� ����� ����� ����� ������� � �������
	//args:
	//- ��� ������� ���������� - 
	//return - ����� ����� ����� ������� � �������
	int getLengthFloat();

	//int BigFloat::getFloatNumberValue(int i)
	//������� �������� �������� ������� �������� �������� ����� � ������� i
	//args:
	//int i - ���������� ����� ������� �������� ����� (����� �������)
	//return - ������� ������� �������� �������� ����� � ������� i
	int getFloatNumberValue(int i);

	//---------------�������:-------------------

	//void BigFloat::setLength(int currentLength)
	//������� ������������� ����� �������� ����� �������� ����� currentLength
	//args:
	//int currentLength - ������� ����� ��� ������
	//- ������������� � ������ ����� �������� ����� currentLength -
	void setLengthFloat(int currentLength);

	//void BigFloat::setLongNumberValue(int i, int value)
	//������� ������������� ����� �������� ����� value � ������ i �������� �����
	//args:
	//int i - ���������� ����� ������� ����� 
	//int value - ����� ��������������� �������� �������
	//- ������������� ����� �������� ����� value � ������ i -
	void setFloatNumberValue(int i, int value);

	//void BigFloat::setArray()
	//������� ������ ����� ������ �������� �������� ����� ����������� lengthFloat
	//args:
	//- ��� ������� ���������� -
	//- �������� ����� ������ ����� -
	void setFloatArray();

	//------������� ��� ������ � ��������� ������:------

	//void BigFloat::add(BigFloat& numOne, BigFloat& numTwo)
	//������� �������� ����� �������� ����
	//args:
	//BigFloat& numOne - ������ ������
	//BigFloat& numTwo - ������ ������
	//- ������������ ��� ����� ���� �������� ������� ������ -
	void add(BigFloat& numOne, BigFloat& numTwo);

	//void BigFloat::multiply(BigFloat& numOne, BigFloat& numTwo)
	//������� ��������� ����� �������� ����
	//args:
	//BigFloat& numOne - ������ ������
	//BigFloat& numTwo - ������ ������
	//- ���������� ��� ����� ���� �������� ������� ������-
	void multiply(BigFloat& numOne, BigFloat& numTwo);

	//void BigFloat::deduct(BigFloat& numOne, BigFloat& numTwo)
	//������� ��������� ����� �������� ����
	//args:
	//BigFloat& numOne - ������ ������
	//BigFloat& numTwo - ������ ������
	//- ���������� �� ������� ����� ������� ������� ������ ����� ������� ������� �������� ���� -
	bool deduct(BigFloat& numOne, BigFloat& numTwo);
	
	//const char* divide(BigFloat& numOne, BigFloat& numTwo);

	//char* BigFloat::toString()
	//������� �������� ����� �������� ����� � ������ char
	//args:
	//- ��� ������� ���������� -
	//return - ������ �������� char (����� �������)
	char* toString();

	//char* BigFloat::toStringInt()
	//������� �������� ����� ����� ����� � ������ char
	//args:
	//- ��� ������� ���������� -
	//return - ������ �������� char 
	char* toStringInt();

	//char* BigFloat::toStringFloat()
	//������� �������� ������� ����� ����� � ������ char
	//args:
	//- ��� ������� ���������� -
	//return - ������ �������� char 
	char* toStringFloat();

private:

	//����� ������� ����� �����
	int lengthFloat;

	//������� ����� �����
	int* floatNumber;

	//char* BigFloat::toStringConcat()
	//������� �������� ����� � ������� ����� ����� � ������ char
	//args:
	//- ��� ������� ���������� -
	//return - ������ �������� char 
	char* toStringConcat();

	//char* BigFloat::addNulls(BigFloat& obj, int length)
	//������� ���������� ����� (����� ����� ���� ��� ������)
	//args:
	//BigFloat& obj - ������ ������ (�����)
	//length - �����, � ������� ����� ������� �����
	//return - ������ �������� char 
	char* addNulls(BigFloat& obj, int length);
};