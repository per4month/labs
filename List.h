#pragma once
#include <iostream>
#include <fstream>
#include "Advert.h"
using namespace std;
 
template <class DataT> class FList : public fstream
{
public:
	FList();
	FList(const FList&);
	FList(char*);
	long getHead();
	long getTail();
	/*
	//*������� � �����*
	void push_back(long pos, DataT &_value);
	//*������� �� ����������� ������*
	void insert(long pos, DataT &_value);
	//*����������*
	long ��� DataT getElem(long pos);
	//*�������� �� ����� �������?*
	Data T pop(long pos, DataT &_value);
	//*���������� ������*
	void update(long pos, DataT &_value);
	//*�����*
	long find(long pos, DataT &key); 
	//*������� � ����������� �������*
	//���� ����������� ����� ���������� (����� ��� ������)
	void insertSort(long pos, DataT &_value);
	//*����������(�����, ���� ���������)*
	void sort();
	//*������������ ��������?*
	//*������*
	void compress();
	//*������ ������ �� �������*
	void printList(long pos);
	//~TDeque();  //����� �� ����������?*/

private:
	class Elem { //���� ������������ ������ � ������
	public:
		Elem():next(NULL),prev(NULL){};
		DataT data; //��������� �������� 
		Elem* next; 
		Elem* prev; 
	};

	class FElem { //���� ������������ ������ � �����
	public: 
		FElem():next(-1),prev(-1){};
		DataT data; //��������� ��������
		long next; //��������� �� ��������� ���� � �����
		long prev; //��������� �� ���������� ���� � �����
	};
	
	long head; //��������� �� "������" � �����
	long tail; //��������� �� "�����" � �����
	int size; //����� ������
	char *fname; //�������� �����
};

template <class DataT> FList<DataT> ::FList():fstream() {
	fname = new char[10]{"test.dat"};
	ofstream f(fname); //������� �������� �����, ��� �� ������� ����
	f.close(); //��������� ����
	open(fname, ios::in | ios::out | ios::ate | ios::binary);	//��������� ���� � ������� ������
	head = -1;
	tail = -1;
	size = 0;
}

template <class DataT> FList<DataT>::FList( const FList& other) : fstream(other)
{
	head = 0; //??????
	fname = _strdup(other.fname);
}

template <class DataT> FList<DataT>::FList(char *_fname) : fstream(_fname, ios::in | ios::out | ios::ate | ios::binary )
{
	fname = _strdup(_fname);	
	if (fail())
	{
		ofstream f(_fname);	
		f.close();	
		fstream::open(_fname, ios::in | ios::out | ios::ate | ios::binary);	//��������� ���� � ������� ������
	}
	if ((int)tellp() == 0)	//���� ������� ���������� �������� � ����� ����� ����, ������ ���� ����
	{
		head = -1;	//�������� ��������� �� ������
		tail = -1;  //�������� ��������� �� �����
	}
	else
	{
		seekp(ios::beg);	//��������� � ������ �����
		read((char*)&head, sizeof(long)); //��������� ��������� �� �������� �������
		//��� ��� ���������?
		//seekp(n); //��������� � ����� �����
		//read((char*)&tail, sizeof(long)); //��������� ��������� �� ��������� �������
	}
}

template <class DataT> long FList<DataT>::getHead(){
	return head;
}

template <class DataT> long FList<DataT>::getTail(){
	return tail;
}

template <class DataT> 
void pushBack(long pos, DataT &value) { //�� ������
   
	if (tmp == NULL) {
        exit(3);
    }
    tmp->value = value;
    tmp->next = NULL;
    tmp->prev = list->tail;
    if (list->tail) {
        list->tail->next = tmp;
    }
    list->tail = tmp;
 
    if (list->head == NULL) {
        list->head = tmp;
    }
    list->size++;
}

/*template <class DataT> FList<DataT>::~FList():
{
	
	delete[] fname;
	fname = NULL;
}*/