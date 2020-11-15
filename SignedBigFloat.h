#pragma once
#include "BigFloat.h"
class SignedBigFloat :public BigFloat
{
public:

	//---------------������������:----------------

	//SignedBigFloat::SignedBigFloat()
	//����������� ��������� �������� ����� �� ��������� 
	//args:
	//- ��� ������� ���������� -
	// - ������ ������ �� ��������� -
	SignedBigFloat();

	//SignedBigFloat::SignedBigFloat(const char sign, const char* numInt, const char* numFloat);
	//����������� �������� ������� �����, ����������� ���� const char*
	//args:
	// - const char sign - ���� ����� ('-' - �����, ' ' -�������������)
	//- const char* numInt - ������ �������� ����� �����
	//- const char* numFloat - ������ �������� ������� �����
	// - ������ ������ �� ������� ���������� const char*  -
	SignedBigFloat(const char sign, 
		const char* numInt, const char* numFloat);

	//SignedBigFloat::SignedBigFloat(const char sign, long numInt, long numFloat);
	//����������� �������� ������� �����, ����������� ���� long
	//args:
	//- const char sign - ���� �����
	//- long numInt - ������� ������������� �����
	//- long numFloat - ������� ������� �����
	//- ������ ������ �� ������� ���������� long -
	SignedBigFloat(const char sign, long numInt, 
		long numFloat);

	//SignedBigFloat::SignedBigFloat(SignedBigFloat &other)
	//����������� �������� ������� �����, �������� ����� ������� ������� ����� ������
	//args:
	//- SignedBigFloat &other - ������ ��� �����������
	// - ������ ����� �������� ������� -
	SignedBigFloat(SignedBigFloat& other);

	//---------------����������:----------------

	//SignedBigFloat::~SignedBigFloat()
	//����������
	//args:
	//- ��� ������� ���������� - 
	// - �������� ������� -
	~SignedBigFloat();

	//---------------�������:-------------------

	//bool SignedBigFloat::getSign()
	//������� �������� ����� �����
	//args:
	//- ��� ������� ���������� - 
	//return - true - ����, false - �����
	bool getSign();

	//---------------�������:-------------------

	//void SignedBigFloat::setSign(bool pos)
	//������� ������������� ���� ����� bool pos
	//args:
	//int currentLength - ������� ����� ��� ������
	//- ������������� � ������ ���� ����� bool pos -
	void setSign(bool pos);

	//------������� ��� ������ � ��������� ������:------

	//void SignedBigFloat::add(SignedBigFloat& numOne, SignedBigFloat& numTwo)
	//������� �������� ����� ��������� �������� ����
	//args:
	//SignedBigFloat& numOne - ������ ������
	//SignedBigFloat& numTwo - ������ ������
	//- ������������ ��� ����� ���� �������� ������� ������ -
	void add(SignedBigFloat& numOne, 
		SignedBigFloat& numTwo);

	//void SignedBigFloat::multiply(SignedBigFloat& numOne, SignedBigFloat& numTwo)
	//������� ��������� ����� ��������� �������� ����
	//args:
	//SignedBigFloat& numOne - ������ ������
	//SignedBigFloat& numTwo - ������ ������
	//- ���������� ��� ����� ���� �������� ������� ������-
	void multiply(SignedBigFloat& numOne,
		SignedBigFloat& numTwo);

	//void SignedBigFloat::deduct(SignedBigFloat& numOne, SignedBigFloat& numTwo)
	//������� ��������� ����� ��������� �������� ����
	//args:
	//SignedBigFloat& numOne - ������ ������
	//SignedBigFloat& numTwo - ������ ������
	//- ���������� �� ������� ����� ������� ������� ������ ����� 
	//������� ������� ��������� �������� ���� -
	void deduct(SignedBigFloat& numOne,
		SignedBigFloat& numTwo);

	//char* SignedBigFloat::toString()
	//������� �������� ����� ��������� �������� ����� � ������ char
	//args:
	//- ��� ������� ���������� -
	//return - ������ �������� char (����� �������)
	char* toString();

private:

	//���� �����
	bool positive;

	//void SignedBigFloat::writeMemory(BigFloat& obj)
	//������� ������ ������ ������� BigFloat � ������ SignedBigFloat
	//args:
	//- ��� ������� ���������� -
	//���������� ������ ������� BigFloat � ������ SignedBigFloat
	void writeMemory(BigFloat& obj);
};

