#pragma once
#include <iostream>
#include "SignedBigFloat.h"
#include "BigFloat.h"
#include "BigInt.h"

class MyDeque
{
public:

	//MyDeque::MyDeque()
	//����������� ���� �� ���������
	//args:
	//- ��� ������� ���������� -
	// - ������ ��� �� ��������� -
	MyDeque();

	//void MyDeque::push_front(BigInt* obj)
	//������� ���������� �������� � ������ ����
	//args:
	//BigInt* obj - ������ �� ������
	//- ��������� ������� � ������ ���� -
	void push_front(BigInt* obj);

	//void MyDeque::pop_front()
	//������� �������� �������� � ������ ����
	//args:
	//- ��� ������� ���������� - 
	//- ������� ������� � ������ ���� -
	void pop_front();

	//void MyDeque::pop_back()
	//������� �������� �������� � ����� ����
	//args:
	//- ��� ������� ���������� - 
	//- ������� ������� � ����� ���� -
	void pop_back();

	//bool MyDeque::find()
	//������� ������ �� NULL ���������
	//args:
	//- ��� ������� ���������� - 
	//- true - ��� �������� �� NULL - 
	//- false - ��� ������ NULL ������� -
	bool find();

	//void MyDeque::print()
	//������� ������ ���� �� �������
	//args:
	//- ��� ������� ���������� - 
	//- ������� ��� �� ������� -
	void print();

	//void MyDeque::print()
	//������� ������ ���� �� ������� � �������� �����������
	//args:
	//- ��� ������� ���������� - 
	//- ������� ��� �� ������� � �������� ����������� -
	void reversePrint();

	//const char* MyDeque::toString()
	//������� �������� ���� ��������� ���� � ������
	//args:
	//- ��� ������� ���������� - 
	//- ������ ��� � ��������� ������������� -
	const char* toString();

	//const char* MyDeque::toStringReverse()
	//������� �������� ���� ��������� ���� � ������ (���. �����������)
	//args:
	//- ��� ������� ���������� - 
	//- ������ ��� � ��������� ������������� (���. �����������) -
	const char* toStringReverse();

	//MyDeque::~MyDeque()
	//����������
	//args:
	//- ��� ������� ���������� - 
	// - ������� ������������ ������ ���� -
	~MyDeque();

private:
	class Elem {
	public:
		//��������� �� ������
		BigInt* data = NULL;

		//��������� �� ��������� ������� ������
		Elem* next = NULL;

		//��������� �� ���������� ������� ������
		Elem* prev = NULL;
	};
	//��������� �� ������ ����
	Elem* head;

	//��������� �� ����� ����
	Elem* tail;
};

